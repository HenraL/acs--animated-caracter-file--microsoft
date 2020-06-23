/*	
	Copyright (c) 1998 by Microsoft Corporation

	THE INFORMATION AND CODE PROVIDED HEREUNDER (COLLECTIVELY REFERRED TO
	AS "SOFTWARE") IS PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND, EITHER
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN
	NO EVENT SHALL MICROSOFT CORPORATION OR ITS SUPPLIERS BE LIABLE FOR
	ANY DAMAGES WHATSOEVER INCLUDING DIRECT, INDIRECT, INCIDENTAL,
	CONSEQUENTIAL, LOSS OF BUSINESS PROFITS OR SPECIAL DAMAGES, EVEN IF
	MICROSOFT CORPORATION OR ITS SUPPLIERS HAVE BEEN ADVISED OF THE
	POSSIBILITY OF SUCH DAMAGES. SOME STATES DO NOT ALLOW THE EXCLUSION OR
	LIMITATION OF LIABILITY FOR CONSEQUENTIAL OR INCIDENTAL DAMAGES SO THE
	FOREGOING LIMITATION MAY NOT APPLY.

	This software may be copied and distributed royalty-free subject to
	the following conditions:

	1. You must copy all software without modification and must include
	   all pages, if the software is distributed without inclusion in your
	   software product. If you are incorporating the software in
	   conjunction with and as a part of your software product which adds
	   substantial value, you may modify and include portions of the
	   software.

	2. You must place all copyright notices and other protective
	   disclaimers and notices contained on the software on all copies of
	   the software and your software product.

	3. Unless the software is incorporated in your software product which
	   adds substantial value, you may not distribute this software for
	   profit.

	4. You may not use Microsoft's name, logo, or trademarks to market
	   your software product.

	5. You agree to indemnify, hold harmless, and defend Microsoft and its
	   suppliers from and against any claims or lawsuits, including
	   attorneys' fees, that arise or result from the use or distribution
	   of your software product and any modifications to the software.		
*/


// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "ACComms.h"

// Dispatch interfaces referenced by this interface
#include "ACComm.h"


/////////////////////////////////////////////////////////////////////////////
// CAgentCtlCommandsEx properties

/////////////////////////////////////////////////////////////////////////////
// CAgentCtlCommandsEx operations

CAgentCtlCommandEx CAgentCtlCommandsEx::GetItem(LPCTSTR Name)
{
	LPDISPATCH pDispatch;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, parms,
		Name);
	return CAgentCtlCommandEx(pDispatch);
}

CAgentCtlCommandEx CAgentCtlCommandsEx::Command(LPCTSTR Name)
{
	LPDISPATCH pDispatch;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xf, DISPATCH_METHOD, VT_DISPATCH, (void*)&pDispatch, parms,
		Name);
	return CAgentCtlCommandEx(pDispatch);
}

long CAgentCtlCommandsEx::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString CAgentCtlCommandsEx::GetCaption()
{
	CString result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CAgentCtlCommandsEx::SetCaption(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CAgentCtlCommandsEx::GetVoice()
{
	CString result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CAgentCtlCommandsEx::SetVoice(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL CAgentCtlCommandsEx::GetVisible()
{
	BOOL result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CAgentCtlCommandsEx::SetVisible(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH CAgentCtlCommandsEx::Add(LPCTSTR Name, const VARIANT& Caption, const VARIANT& Voice, const VARIANT& Enabled, const VARIANT& Visible)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0xa, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Name, &Caption, &Voice, &Enabled, &Visible);
	return result;
}

LPDISPATCH CAgentCtlCommandsEx::Insert(LPCTSTR Name, LPCTSTR RefName, const VARIANT& Before, const VARIANT& Caption, const VARIANT& Voice, const VARIANT& Enabled, const VARIANT& Visible)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0xb, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Name, RefName, &Before, &Caption, &Voice, &Enabled, &Visible);
	return result;
}

void CAgentCtlCommandsEx::Remove(LPCTSTR Name)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Name);
}

void CAgentCtlCommandsEx::RemoveAll()
{
	InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CAgentCtlCommandsEx::SetDefaultCommand(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CAgentCtlCommandsEx::GetDefaultCommand()
{
	CString result;
	InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CAgentCtlCommandsEx::SetHelpContextID(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CAgentCtlCommandsEx::GetHelpContextID()
{
	long result;
	InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CAgentCtlCommandsEx::SetFontName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CAgentCtlCommandsEx::GetFontName()
{
	CString result;
	InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

long CAgentCtlCommandsEx::GetFontSize()
{
	long result;
	InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CAgentCtlCommandsEx::SetFontSize(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void CAgentCtlCommandsEx::SetVoiceCaption(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CAgentCtlCommandsEx::GetVoiceCaption()
{
	CString result;
	InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CAgentCtlCommandsEx::SetGlobalVoiceCommandsEnabled(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CAgentCtlCommandsEx::GetGlobalVoiceCommandsEnabled()
{
	BOOL result;
	InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}
