#include "Hello2.h"
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
// This sample demonstrates the simplest Microsoft Agent application that
// uses a notification sink.
//
//==========================================================================


static const LPWSTR kpwszCharacter = L"\\Program Files\\Microsoft Agent\\characters\\genie.acs";
static const LPTSTR kpszAppTitle = _T("Microsoft Agent Samples");

extern long g_lDone = 0;


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


extern "C" int PASCAL WinMain(HINSTANCE hInst,
							  HINSTANCE hInstPrev,
							  LPSTR lpCmdLine,
							  int nCmdShow) {

	HRESULT				hRes;
	_TCHAR				szError[256];
	VARIANT				vPath;
	BSTR				bszSpeak;
	MSG					msg;
	long				lCharID;
	long				lRequestID;
	long				lNotifySinkID = -1;
	IAgent			   *pAgent;
	IDispatch		   *pdCharacter;
	IAgentCharacter    *pCharacter = NULL;
	AgentNotifySink	   *pSink = NULL;
	
	// Initialize OLE

    if (FAILED(OleInitialize(NULL))) {
		MessageBox(NULL, 
				   _T("There was an error initializing OLE."), 
				   kpszAppTitle, 
				   MB_OK | MB_ICONERROR);
        return -1;
	}

	// Create an instance of the Agent server

	hRes = CoCreateInstance(CLSID_AgentServer,
							NULL,
							CLSCTX_SERVER,
							IID_IAgent,
							(LPVOID *)&pAgent);
	if (FAILED(hRes)) {

		wsprintf(szError, _T("There was an error initializing Microsoft Agent, code = 0x%x"), hRes);

		MessageBox(NULL, 
				   szError, 
				   kpszAppTitle, 
				   MB_OK | MB_ICONERROR);
		return -1;
	}

	// Check to see if it is a compatible version

	if (!IsValidAgentVersion(pAgent)) {

		pAgent->Release();

		MessageBox(NULL,
				   _T("The version of Microsoft Agent installed on this system is out of date.\nUpgrade to a new version of Microsoft Agent."),
				   kpszAppTitle,
				   MB_OK | MB_ICONEXCLAMATION | MB_TOPMOST);
		return -1;
	}

	// Create a notify sink

	pSink = new AgentNotifySink;

	if (pSink == NULL) {

		MessageBox(NULL, 
				   _T("Out of memory!"), 
				   kpszAppTitle, 
				   MB_OK | MB_ICONERROR);

		return -1;
	}

	pSink->AddRef();

	// And register it with Microsoft Agent

	hRes = pAgent->Register((IUnknown *)pSink, &lNotifySinkID);

	if (FAILED(hRes))
		return -1;

	// Create a variant to store the full path of the character to load

	VariantInit(&vPath);

	vPath.vt = VT_BSTR;
	vPath.bstrVal = SysAllocString(kpwszCharacter);

	if (vPath.bstrVal == NULL) {

		MessageBox(NULL, 
				   _T("Out of memory!"), 
				   kpszAppTitle, 
				   MB_OK | MB_ICONERROR);

		return -1;
	}

	try {

		// Load the character

		hRes = pAgent->Load(vPath, &lCharID, &lRequestID);

		if (FAILED(hRes))
			throw hRes;

		// Get it's dispinterface

		hRes = pAgent->GetCharacter(lCharID, &pdCharacter);

		if (FAILED(hRes))
			throw hRes;

		// Query for IAgentCharacter

		hRes = pdCharacter->QueryInterface(IID_IAgentCharacter, (LPVOID *)&pCharacter);

		// Release the IDispatch

		pdCharacter->Release();

		// Did we get the IAgentCharacter interface?

		if (FAILED(hRes))
			throw hRes;

		// Show the character.  The first parameter tells Microsoft
		// Agent to show the character by playing an animation.

		hRes = pCharacter->Show(FALSE, &lRequestID);

		if (FAILED(hRes))
			throw hRes;

		// Make the character speak

		bszSpeak = SysAllocString(L"Hello World!");

		hRes = pCharacter->Speak(bszSpeak, NULL, &g_lDone);

		SysFreeString(bszSpeak);

		if (FAILED(hRes))
			throw hRes;

	}
	catch (HRESULT) {

		wsprintf(szError, _T("An error occurred in Microsoft Agent, code = 0x%x"), hRes);

		MessageBox(NULL, 
				   szError, 
				   kpszAppTitle, 
				   MB_OK | MB_ICONERROR);
	}

	// Start the message loop.  A WM_QUIT message will be posted
	// when we get the RequestComplete notification from Microsoft Agent.

	if (SUCCEEDED(hRes)) {
		while (GetMessage(&msg, NULL, 0, 0) > 0)
			DispatchMessage(&msg);
	}

	// Clean up

	if (pCharacter) {

		// Release the character interface

		pCharacter->Release();

		// Unload the character.  NOTE:  releasing the character
		// interface does NOT make the character go away.  You must
		// call Unload.

		pAgent->Unload(lCharID);
	}
	
	// Release objects

	if (pSink) {

		if (lNotifySinkID != -1)
			pAgent->Unregister(lNotifySinkID);

		pSink->Release();
	}

	pAgent->Release();

	VariantClear(&vPath);

	OleUninitialize();

	return 0;
}
