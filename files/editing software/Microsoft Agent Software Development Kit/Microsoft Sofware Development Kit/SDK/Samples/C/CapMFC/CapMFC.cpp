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


#include "stdafx.h"
#include "CapMFC.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Application Title

extern const LPTSTR kpszAppTitle = _T("Microsoft Agent Character Previewer");


BEGIN_MESSAGE_MAP(CCapMFCApp, CWinApp)
	//{{AFX_MSG_MAP(CCapMFCApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


CCapMFCApp::CCapMFCApp() {
}

CCapMFCApp theApp;


BOOL CCapMFCApp::InitInstance() {

	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CCapMFCDlg dlg;
	m_pMainWnd = &dlg;
	
	dlg.DoModal();

	return FALSE;
}
