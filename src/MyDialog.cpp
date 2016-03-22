/////////////////////////////////////////
//// MyDialog.cpp
//
//#include "stdafx.h"
//#include "MyDialog.h"
//#include "Hyperlink.h"
//#include "resource.h"
//
//
//// Definitions for the CMyDialog class
//CMyDialog::CMyDialog(UINT nResID) : CDialog(nResID)
//{
//	// Load RichEdit version 2.0 or 3.0
//	m_hInstRichEdit = LoadLibrary(_T("riched20.dll"));
//    
//	// Load RichEdit version 1.0 as a last resort
//	if (m_hInstRichEdit == 0)
// 		m_hInstRichEdit = LoadLibrary(_T("riched32.dll"));
//
//	if (m_hInstRichEdit == 0)
//		::MessageBox(NULL, _T("CMyDialog::CMyDialog  Failed to load RICHED32.DLL"), _T("Error"), MB_ICONWARNING);
//}
//
//CMyDialog::CMyDialog(LPCTSTR lpszResName) : CDialog(lpszResName)
//{
//	// Load RichEdit version 2.0 or 3.0
//	m_hInstRichEdit = LoadLibrary(_T("riched20.dll"));
//    
//	// Load RichEdit version 1.0 as a last resort
//	if (m_hInstRichEdit == 0)
// 		m_hInstRichEdit = LoadLibrary(_T("riched32.dll"));
//
//	if (m_hInstRichEdit == 0)
//		::MessageBox(NULL, _T("CMyDialog::CMyDialog  Failed to load RICHED32.DLL"), _T("Error"), MB_ICONWARNING);
//}
//
//CMyDialog::~CMyDialog()
//{
//	::FreeLibrary(m_hInstRichEdit);
//}
//
//INT_PTR CMyDialog::DialogProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
////	switch (uMsg)
////	{
////		//Additional messages to be handled go here
////	}
//
//	// Pass unhandled messages on to parent DialogProc
//	return DialogProcDefault(uMsg, wParam, lParam); 
//}
//
//BOOL CMyDialog::OnCommand(WPARAM wParam, LPARAM lParam)
//{
//	UNREFERENCED_PARAMETER(lParam);
//
//	switch (LOWORD(wParam))
//    {
//	case IDC_BUTTON1:	return OnButton();
//	case IDC_RADIO1:	return OnRadio1();
//	case IDC_RADIO2:	return OnRadio2();
//	case IDC_RADIO3:	return OnRadio3();
//	case IDC_CHECK1:	return OnCheck1();
//	case IDC_CHECK2:	return OnCheck2();
//	case IDC_CHECK3:	return OnCheck3();
//    }
//
//	return FALSE;
//}
//
//void CMyDialog::OnDestroy()
//{
//	// End the application
//	::PostQuitMessage(0);
//}
//
//
//BOOL CMyDialog::OnInitDialog()
//{
//	// Set the Icon
//	SetIconLarge(IDW_MAIN);
//	SetIconSmall(IDW_MAIN);
//
//	// Put some text in the edit boxes
//	SetDlgItemText(IDC_EDIT1, _T("Edit Control"));
//	SetDlgItemText(IDC_RICHEDIT1, _T("Rich Edit Window"));
//
//	// Put some text in the list box
//	AttachItem(IDC_LIST1, m_ListBox);
//	for (int i = 0 ; i < 8 ; i++)
//		m_ListBox.AddString(_T("List Box"));
//
//	// Turn our button into a MyButton object
//	AttachItem(IDC_BUTTON2, m_Button);
//
//	// Turn our static control into a hyperlink
//	AttachItem(IDC_STATIC4, m_Hyperlink);
//
//	return TRUE;
//}
//
//void CMyDialog::OnOK()
//{
//	MessageBox(_T("OK Button Pressed.  Program will exit now."), _T("Button"), MB_OK);
//	CDialog::OnOK();
//}
//
//BOOL CMyDialog::OnButton()
//{
//	SetStatic(_T("Button Pressed"));
//	TRACE("Button Pressed\n");
//	return TRUE;
//}
//
//BOOL CMyDialog::OnCheck1()
//{
//	SetStatic(_T("Check Box 1"));
//	TRACE("Check Box 1\n");
//	return TRUE;
//}
//
//BOOL CMyDialog::OnCheck2()
//{
//	SetStatic(_T("Check Box 2"));
//	TRACE("Check Box 2\n");
//	return TRUE;
//}
//
//BOOL CMyDialog::OnCheck3()
//{
//	SetStatic(_T("Check Box 3"));
//	TRACE("Check Box 3\n");
//	return TRUE;
//}
//
//BOOL CMyDialog::OnRadio1()
//{
//	SetStatic(_T("Radio 1"));
//	TRACE("Radio 1\n");
//	return TRUE;
//}
//
//BOOL CMyDialog::OnRadio2()
//{
//	SetStatic(_T("Radio 2"));
//	TRACE("Radio 2\n");
//	return TRUE;
//}
//
//BOOL CMyDialog::OnRadio3()
//{
//	SetStatic(_T("Radio 3"));
//	TRACE("Radio 3\n");
//	return TRUE;
//}
//
//void CMyDialog::SetStatic(LPCTSTR szString)
//{
//	SetDlgItemText(IDC_STATIC3, szString);
//}
//
///////////////////////////////////////
// MyDialog.cpp

#include "stdafx.h"
#include "MyDialog.h"
#include "resource.h"
#include "WinHttpClient.h"
#include <windows.h>


// Definitions for the CMyDialog class
CMyDialog::CMyDialog(UINT nResID): CDialog(nResID),
_proxyPort(),
_proxyUsr(),
_proxyPwd(),
_isMobile(),
_isRememberCon(),
_isRememberApp(),
_appLogger(),
_btnStart(),
_btnStop()
{
	// Load RichEdit version 2.0 or 3.0
	m_hInstRichEdit = LoadLibrary(_T("riched20.dll"));

	// Load RichEdit version 1.0 as a last resort
	if(m_hInstRichEdit == 0)
		m_hInstRichEdit = LoadLibrary(_T("riched32.dll"));

	if(m_hInstRichEdit == 0)
		::MessageBox(NULL, _T("CMyDialog::CMyDialog  Failed to load RICHED32.DLL"), _T("Error"), MB_ICONWARNING);
}

CMyDialog::~CMyDialog()
{
	::FreeLibrary(m_hInstRichEdit);
}

void CMyDialog::OnDestroy()
{
	// End the application
	::PostQuitMessage(0);
}

INT_PTR CMyDialog::DialogProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//	switch (uMsg)
	//	{
	//Additional messages to be handled go here
	//	}

	// Pass unhandled messages on to parent DialogProc
	return DialogProcDefault(uMsg, wParam, lParam);
}

BOOL CMyDialog::OnCommand(WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	switch(LOWORD(wParam))
	{
		case ID_BUTTON_START:	return OnStart();
		case ID_BUTTON_STOP:	return OnStop();
			/*case IDC_RADIO2:	return OnRadio2();
			case IDC_RADIO3:	return OnRadio3();
			case IDC_CHECK1:	return OnCheck1();
			case IDC_CHECK2:	return OnCheck2();
			case IDC_CHECK3:	return OnCheck3();*/
	}

	return FALSE;
}

BOOL CMyDialog::OnInitDialog()
{
	// Set the Icon
	SetIconLarge(IDD_DIALOG1);
	SetIconSmall(IDD_DIALOG1);

	// Put some text in the edit boxes
	SetDlgItemText(IDC_EDIT1, _T("Edit Control"));
	SetDlgItemText(IDC_RICHEDIT1, _T("Rich Edit Window"));

	// Put some text in the list box
	for(int i = 0; i < 8; i++)
		SendDlgItemMessage(IDC_LIST_LOGGING, LB_ADDSTRING, 0, (LPARAM) _T("List Box"));

	return true;
}

void CMyDialog::OnOK()
{
	MessageBox(_T("OK Button Pressed.  Program will exit now."), _T("Button"), MB_OK);
	CDialog::OnOK();
}

BOOL CMyDialog::OnStart()
{
	try
	{
		string msgError;
		isStarted = DoRequest(msgError);

		if(!isStarted)
		{
			MessageBox((LPTSTR) msgError.c_str(), MAKEINTRESOURCE(IDD_DIALOG1), MB_ICONERROR);
			return FALSE;
		}
		_btnStart.SetCheck(isStarted);
		return TRUE;
	} catch(const CException &e)
	{
		MessageBox(e.GetText(), MAKEINTRESOURCE(IDD_DIALOG1), MB_ICONERROR);
	}
}

BOOL CMyDialog::OnStop()
{
	return TRUE;
}

BOOL CMyDialog::OnCheckRememCon()
{
	return TRUE;
}

BOOL CMyDialog::OnCheckRememApp()
{
	return TRUE;
}

BOOL CMyDialog::OnCheckMobileAgent()
{
	return TRUE;
}

bool CMyDialog::DoRequest(string &msgErr)
{
	bool requestVals = false;
	msgErr.clear();
	char copy[512];
	int res = _proxyPort.GetLine(0, (LPTSTR) copy);
	// Neu Proxy co gia tris
	if(res <= 0)
	{
		// validation proxy
		if(false)
		{
			msgErr.append("Proxy InValid.\n");
			return false;
		}
		// Set Proxy

	}

	_isMobile.IsDlgButtonChecked(IDC_CHECK_IS_MOBILE);
	// Neu Mobile Agent duoc check
	if(true)
	{
		// Set Mobible Agent
	}
	// Neu Remember Conn duoc check
	if(true)
	{
		// Luu cac cai dat hien tai
	}
	// Neu file account khong duoc load
	if(true)
	{
		// Bao loi va thoat app
	}
	// Neu Remember App duoc check
	if(true)
	{
		// Tu dong su dung file account tai thu muc do
	} else
	{
		return false;
	}

	return true;
};

//BOOL CMyDialog::OnButton()
//{
//	SetDlgItemText(IDC_STATIC3, _T("Button Pressed"));
//	TRACE("Button Pressed\n");
//	return TRUE;
//}
//
//BOOL CMyDialog::OnCheck1()
//{
//	SetDlgItemText(IDC_STATIC3, _T("Check Box 1"));
//	TRACE("Check Box 1\n");
//	return TRUE;
//}
//
//BOOL CMyDialog::OnCheck2()
//{
//	SetDlgItemText(IDC_STATIC3, _T("Check Box 2"));
//	TRACE("Check Box 2\n");
//	return TRUE;
//}
//
//BOOL CMyDialog::OnCheck3()
//{
//	SetDlgItemText(IDC_STATIC3, _T("Check Box 3"));
//	TRACE("Check Box 3\n");
//	return TRUE;
//}
//
//BOOL CMyDialog::OnRadio1()
//{
//	SetDlgItemText(IDC_STATIC3, _T("Radio 1"));
//	TRACE("Radio 1\n");
//	return TRUE;
//}
//
//BOOL CMyDialog::OnRadio2()
//{
//	SetDlgItemText(IDC_STATIC3, _T("Radio 2"));
//	TRACE("Radio 2\n");
//	return TRUE;
//}
//
//BOOL CMyDialog::OnRadio3()
//{
//	SetDlgItemText(IDC_STATIC3, _T("Radio 3"));
//	TRACE("Radio 3\n");
//	return TRUE;
//}

void SimplePostTest(void)
{
	WinHttpClient client(L"http://www.codeproject.com/");

	// Set post data.
	string data = "title=A_NEW_THREAD&content=This_is_a_new_thread.";
	client.SetAdditionalDataToSend((BYTE *) data.c_str(), data.size());

	// Set request headers.
	wchar_t szSize[50] = L"";
	swprintf_s(szSize, L"%d", data.size());
	wstring headers = L"Content-Length: ";
	headers += szSize;
	headers += L"\r\nContent-Type: application/x-www-form-urlencoded\r\n";
	client.SetAdditionalRequestHeaders(headers);

	// Send http post request.
	client.SendHttpRequest(L"POST");

	wstring httpResponseHeader = client.GetResponseHeader();
	wstring httpResponseContent = client.GetResponseContent();
}

void UserAgentTest(void)
{
	WinHttpClient client(L"http://localhost/Mobile-Detect-2.8.19/examples/demo.php");

	// Set the user agent to the same as IE8.
	client.SetUserAgent(L"Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1; Trident/4.0; .NET CLR 1.1.4322; .NET CLR 2.0.50727; .NET CLR 3.0.4506.2152; .NET CLR 3.5.30729; InfoPath.2; CIBA; MS-RTC LM 8)");

	client.SendHttpRequest();
	wstring httpResponseHeader = client.GetResponseHeader();
	wstring httpResponseContent = client.GetResponseContent();
}

void ProxyTest(void)
{
	WinHttpClient client(L"http://www.codeproject.com/");

	// Set the proxy to 192.168.0.1 with port 8080.
	client.SetProxy(L"192.168.0.1:8080");

	client.SendHttpRequest();
	wstring httpResponseHeader = client.GetResponseHeader();
	wstring httpResponseContent = client.GetResponseContent();
}

void CookiesTest(void)
{
	WinHttpClient client(L"http://www.codeproject.com/");

	// Set the cookies to send.
	client.SetAdditionalRequestCookies(L"username=jack");

	client.SendHttpRequest();

	// Get the response cookies.
	wstring httpResponseCookies = client.GetResponseCookies();

	wstring httpResponseHeader = client.GetResponseHeader();
	wstring httpResponseContent = client.GetResponseContent();
}

void HttpsTest(void)
{
	WinHttpClient client(L"https://www.google.com/");

	// Accept any certificate while performing HTTPS request.
	client.SetRequireValidSslCertificates(false);

	// Get the response cookies.
	wstring httpResponseCookies = client.GetResponseCookies();

	wstring httpResponseHeader = client.GetResponseHeader();
	wstring httpResponseContent = client.GetResponseContent();
}

void MultipleRequestsTest(void)
{
	WinHttpClient client(L"http://www.google.com/");

	client.SendHttpRequest();
	wstring httpResponseHeader = client.GetResponseHeader();
	wstring httpResponseContent = client.GetResponseContent();

	// Update the url.
	client.UpdateUrl(L"http://www.microsoft.com/");
	client.SendHttpRequest();
	httpResponseHeader = client.GetResponseHeader();
	httpResponseContent = client.GetResponseContent();
}

void CompleteTest(void)
{
	// 1. Get the initial cookie.
	WinHttpClient getClient(L"http://www.codeproject.com/script/Membership/LogOn.aspx");
	getClient.SetAdditionalRequestHeaders(L"Accept: image/gif, image/jpeg, image/pjpeg, image/pjpeg, application/x-shockwave-flash, application/x-ms-application, application/x-ms-xbap, application/vnd.ms-xpsdocument, application/xaml+xml, application/vnd.ms-excel, application/vnd.ms-powerpoint, application/msword, */*\r\nAccept-Language: en-us\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1; Trident/4.0; QQPinyin 730; .NET CLR 1.1.4322; .NET CLR 2.0.50727; .NET CLR 3.0.4506.2152; .NET CLR 3.5.30729; InfoPath.2; CIBA; MS-RTC LM 8)\r\nAccept-Encoding: gzip, deflate\r\nProxy-Connection: Keep-Alive\r\nHost: www.codeproject.com\r\n");
	if(!getClient.SendHttpRequest())
	{
		return;
	}

	// 2. Post data to get the authentication cookie.
	WinHttpClient postClient(L"http://www.codeproject.com/script/Membership/LogOn.aspx?rp=%2fscript%2fMembership%2fLogOn.aspx");

	// Post data.
	// Change this to your Codeproject username and password.
	wstring username = L"YourCodeProjectUsername";
	wstring password = L"YourPassword";
	postClient.SetAdditionalRequestCookies(getClient.GetResponseCookies());
	string data = "FormName=MenuBarForm&Email=";
	data += (char *) _bstr_t(username.c_str());
	data += "&Password=";
	data += (char *) _bstr_t(password.c_str());
	data += "&RememberMeCheck=1";
	postClient.SetAdditionalDataToSend((BYTE *) data.c_str(), data.size());

	// Post headers.
	wstring headers = L"Accept: image/gif, image/jpeg, image/pjpeg, image/pjpeg, application/x-shockwave-flash, application/x-ms-application, application/x-ms-xbap, application/vnd.ms-xpsdocument, application/xaml+xml, application/vnd.ms-excel, application/vnd.ms-powerpoint, application/msword, */*\r\nReferer: http://www.codeproject.com/script/Membership/LogOn.aspx\r\nAccept-Language: en-us\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1; Trident/4.0; QQPinyin 730; .NET CLR 1.1.4322; .NET CLR 2.0.50727; .NET CLR 3.0.4506.2152; .NET CLR 3.5.30729; InfoPath.2; CIBA; MS-RTC LM 8)\r\nContent-Type: application/x-www-form-urlencoded\r\nHost: www.codeproject.com\r\nContent-Length: %d\r\nProxy-Connection: Keep-Alive\r\nPragma: no-cache\r\n";
	wchar_t szHeaders[MAX_PATH * 10] = L"";
	swprintf_s(szHeaders, MAX_PATH * 10, headers.c_str(), data.size());
	postClient.SetAdditionalRequestHeaders(szHeaders);
	if(!postClient.SendHttpRequest(L"POST", true))
	{
		return;
	}

	// 3. Finally get the zip file.
	WinHttpClient downloadClient(L"http://www.codeproject.com/KB/IP/win_HTTP_wrapper/WinHttpClient_Src.zip");
	downloadClient.SetUserAgent(L"Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1; Trident/4.0; .NET CLR 1.1.4322; .NET CLR 2.0.50727; .NET CLR 3.0.4506.2152; .NET CLR 3.5.30729; InfoPath.2; CIBA; MS-RTC LM 8)");

	// Sending this cookie make server believe you have already logged in.
	downloadClient.SetAdditionalRequestCookies(postClient.GetResponseCookies());
	if(!downloadClient.SendHttpRequest())
	{
		return;
	}
	downloadClient.SaveResponseToFile(L"C:\\WinHttpClient_Src.zip");
}