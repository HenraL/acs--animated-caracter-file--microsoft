#include "Hello3.h"
#include "AgtSvr_i.c"
#include "Notify.h"


//==========================================================================
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
//  PURPOSE.
//
//  Copyright (C) 1997 Microsoft Corporation.  All Rights Reserved.
//
//--------------------------------------------------------------------------
//
// This sample demonstrates loading 2 characters and synchronizing
// their actions.
//
//==========================================================================


// The AgentHRESULT object makes it easier to handle errors by
// throwing a C++ exception when it is assigned a FAILED HRESULT.
// You MUST use this object only in try/catch blocks.  By using
// this object you don't have to check the return value after every
// call into Microsoft Agent.

struct AgentHRESULT {

	AgentHRESULT& operator =(const HRESULT hRes) {
		if (FAILED(hRes))
			throw hRes;
		return *this;
	}
};


// Constants

static const LPWSTR kpwszGenie = L"\\Program Files\\Microsoft Agent\\characters\\genie.acs";
static const LPWSTR kpwszMerlin = L"\\Program Files\\Microsoft Agent\\characters\\merlin.acs";
static const LPTSTR kpszAppTitle = _T("Microsoft Agent Samples");


// Globals

extern long g_lDone = 0;


// Forward references

HRESULT LoadCharacter(IAgent *pAgent, 
					  LPWSTR pwszPath, 
					  long *plID, 
					  IAgentCharacter **ppCharacter);

BOOL	InitAgent(IAgent **ppAgent, 
				  long *plSinkID, 
				  AgentNotifySink **ppSink);



extern "C" int PASCAL WinMain(HINSTANCE hInst,
							  HINSTANCE hInstPrev,
							  LPSTR lpCmdLine,
							  int nCmdShow) {

	HRESULT				hRes;
	AgentHRESULT		ahRes;
	_TCHAR				szError[256];
	BSTR				bszSpeak = NULL;
	MSG					msg;
	long				lGenieID;
	long				lMerlinID;
	long				lRequestID;
	long				lWaitID;
	long				lNotifySinkID = -1;
	IAgent			   *pAgent;
	IAgentCharacter    *pGenie = NULL;
	IAgentCharacter	   *pMerlin = NULL;
	AgentNotifySink	   *pSink = NULL;
	

	// Initialize the app

	if (!InitAgent(&pAgent, &lNotifySinkID, &pSink))
		return -1;

	try {

		// Load the characters

		ahRes = LoadCharacter(pAgent, kpwszGenie, &lGenieID, &pGenie);
		ahRes = LoadCharacter(pAgent, kpwszMerlin, &lMerlinID, &pMerlin);

		// Position them

		ahRes = pGenie->MoveTo(0, 100, 0, &lRequestID);
		ahRes = pMerlin->MoveTo(200, 100, 0, &lRequestID);

		// Show them

		ahRes = pGenie->Show(FALSE, &lRequestID);
		ahRes = pMerlin->Show(FALSE, &lRequestID);

		// Have Genie gesture towards Merlin

		ahRes = pGenie->GestureAt(150, 100, &lRequestID);

		// And have Genie say hello to Merlin

		bszSpeak = SysAllocString(L"Hi there Merlin.");

		ahRes = pGenie->Speak(bszSpeak, NULL, &lWaitID);

		SysFreeString(bszSpeak);
		bszSpeak = NULL;

		// Make Merlin wait for Genie to finish speaking

		ahRes = pMerlin->Wait(lWaitID, &lRequestID);

		// Have Merlin gesture towards Genie

		ahRes = pMerlin->GestureAt(0, 100, &lRequestID);

		// And then speak back to Genie

		bszSpeak = SysAllocString(L"Hi Genie.  See you later");

		ahRes = pMerlin->Speak(bszSpeak, NULL, &g_lDone);

		SysFreeString(bszSpeak);
		bszSpeak = NULL;

	}
	catch (HRESULT hResError) {

		hRes = hResError;

		wsprintf(szError, _T("An error occurred in Microsoft Agent, code = 0x%x"), hRes);

		MessageBox(NULL, 
				   szError, 
				   kpszAppTitle, 
				   MB_OK | MB_ICONERROR);

		SysFreeString(bszSpeak);
	}

	// Start the message loop.  A WM_QUIT message will be posted
	// when we get the RequestComplete notification from Microsoft Agent.

	if (SUCCEEDED(hRes)) {
		while (GetMessage(&msg, NULL, 0, 0) > 0)
			DispatchMessage(&msg);
	}

	// Release the character interfaces.  NOTE:  releasing the character
	// interface does NOT make the character go away.  You must
	// call Unload.

	if (pGenie) {
		pGenie->Release();
		pAgent->Unload(lGenieID);
	}
	
	if (pMerlin) {
		pMerlin->Release();
		pAgent->Unload(lMerlinID);
	}

	// Release the notify sink

	if (pSink) {
		if (lNotifySinkID != -1)
			pAgent->Unregister(lNotifySinkID);

		pSink->Release();
	}

	// We're done

	pAgent->Release();

	OleUninitialize();

	return 0;
}


// This function checks to see if the version of Microsoft Agent
// installed on the user's system is compatible with the version
// we compiled with, i.e. it's version is greater than or equal to
// constants defined in AgentServer.h.  Microsoft Agent guarantees
// backward compatibility.

BOOL IsValidAgentVersion(IAgent *pAgent) {

	HRESULT hRes;
	IDispatch *pdAgent = NULL;
	ITypeInfo *pTypeInfo = NULL;
	ITypeLib *pTypeLib = NULL;
	TLIBATTR *pTypeLibAttr = NULL;
	BOOL bValid = FALSE;
	UINT uiIndex;

	__try {

		// Query for IDispatch

		hRes = pAgent->QueryInterface(IID_IDispatch, (LPVOID *)&pdAgent);

		if (FAILED(hRes))
			__leave;

		// Get the TypeInfo

		hRes = pdAgent->GetTypeInfo(0, 0, &pTypeInfo);

		if (FAILED(hRes))
			__leave;

		// Get it's containing TypeLib

		hRes = pTypeInfo->GetContainingTypeLib(&pTypeLib, &uiIndex);

		if (FAILED(hRes))
			__leave;

		// Get the attributes of the TypeLib

		hRes = pTypeLib->GetLibAttr(&pTypeLibAttr);

		if (FAILED(hRes))
			__leave;

		// Check the major and minor versions of the type library
		// to those in AgentServer.h.

		if ((pTypeLibAttr->wMajorVerNum > AGENT_VERSION_MAJOR) ||
			((pTypeLibAttr->wMajorVerNum == AGENT_VERSION_MAJOR) &&
			 (pTypeLibAttr->wMinorVerNum >= AGENT_VERSION_MINOR)))
			bValid = TRUE;

	}
	__finally {
	}

	if (pTypeLib) {

		if (pTypeLibAttr)
			pTypeLib->ReleaseTLibAttr(pTypeLibAttr);

		pTypeLib->Release();
	}

	if (pTypeInfo)
		pTypeInfo->Release();

	if (pdAgent)
		pdAgent->Release();

	return bValid;
}


BOOL InitAgent(IAgent **ppAgent, 
			   long *plSinkID, 
			   AgentNotifySink **ppSink) {

	HRESULT	hRes;
	_TCHAR	szError[256];

	// Initialize OLE

    if (FAILED(OleInitialize(NULL))) {
		MessageBox(NULL, 
				   _T("There was an error initializing OLE."), 
				   kpszAppTitle, 
				   MB_OK | MB_ICONERROR);
        return FALSE;
	}

	// Create an instance of the Agent server

	hRes = CoCreateInstance(CLSID_AgentServer,
							NULL,
							CLSCTX_SERVER,
							IID_IAgent,
							(LPVOID *)ppAgent);
	if (FAILED(hRes)) {

		wsprintf(szError, _T("There was an error initializing Microsoft Agent, code = 0x%x"), hRes);

		MessageBox(NULL, 
				   szError, 
				   kpszAppTitle, 
				   MB_OK | MB_ICONERROR | MB_TOPMOST);
        return FALSE;
	}

	// Check to see if it is a compatible version

	if (!IsValidAgentVersion(*ppAgent)) {
		(*ppAgent)->Release();
		*ppAgent = NULL;
		MessageBox(NULL,
				   _T("The version of Microsoft Agent installed on this system is out of date.\nUpgrade to a new version of Microsoft Agent."),
				   kpszAppTitle,
				   MB_OK | MB_ICONEXCLAMATION | MB_TOPMOST);
		return FALSE;
	}

	// Create a notify sink

	*ppSink = new AgentNotifySink;

	if (*ppSink == NULL) {

		MessageBox(NULL, 
				   _T("Out of memory!"), 
				   kpszAppTitle, 
				   MB_OK | MB_ICONERROR | MB_TOPMOST);

        return FALSE;
	}

	(*ppSink)->AddRef();

	// And register it with Microsoft Agent

	hRes = (*ppAgent)->Register((IUnknown *)(*ppSink), plSinkID);

	if (FAILED(hRes))
		return FALSE;
	else
		return TRUE;
}


HRESULT LoadCharacter(IAgent *pAgent, 
					  LPWSTR pwszPath, 
					  long *plID, 
					  IAgentCharacter **ppCharacter) {

	VARIANT		vPath;
	IDispatch  *pdCharacter;
	HRESULT		hRes;
	long		lRequestID;

	// Create a VARIANT for the path

	VariantInit(&vPath);

	vPath.vt = VT_BSTR;
	vPath.bstrVal = SysAllocString(pwszPath);

	if (vPath.bstrVal == NULL)
		return E_OUTOFMEMORY;

	// Load the character

	hRes = pAgent->Load(vPath, plID, &lRequestID);

	if (FAILED(hRes))
		return hRes;

	// Get it's dispinterface

	hRes = pAgent->GetCharacter(*plID, &pdCharacter);

	if (FAILED(hRes))
		return hRes;

	// Query for IAgentCharacter

	hRes = pdCharacter->QueryInterface(IID_IAgentCharacter, (LPVOID *)ppCharacter);

	// Release the IDispatch

	pdCharacter->Release();

	return hRes;
}
