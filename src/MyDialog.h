/////////////////////////////////////////
//// MyDialog.h
//
//#ifndef MYDIALOG_H
//#define MYDIALOG_H
//
//
//#include "MyButton.h"
//#include "Hyperlink.h"
//
//
//// Declaration of the CMyDialog class
//class CMyDialog : public CDialog
//{
//public:
//	CMyDialog(UINT nResID);
//	CMyDialog(LPCTSTR lpszResName);
//	void SetStatic(LPCTSTR szString);
//	virtual ~CMyDialog();
//
//protected:
//	virtual void OnDestroy();
//	virtual BOOL OnInitDialog();
//	virtual INT_PTR DialogProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
//	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
//	virtual void OnOK();
//
//private:
//	BOOL OnButton();
//	BOOL OnRadio1();
//	BOOL OnRadio2();
//	BOOL OnRadio3();
//	BOOL OnCheck1();
//	BOOL OnCheck2();
//	BOOL OnCheck3();
//
//	HMODULE m_hInstRichEdit;
//	CMyButton m_Button;
//	CHyperlink m_Hyperlink;
//	CListBox m_ListBox;
//};
//
//#endif //MYDIALOG_H


///////////////////////////////////////
// MyDialog.h

#ifndef MYDIALOG_H
#define MYDIALOG_H

#include "resource.h"
#include <string>
using namespace std;

// Declaration of the CMyDialog class
class CMyDialog: public CDialog
{
public:
	CMyDialog(UINT nResID);
	virtual ~CMyDialog();

	//Variables
	bool isStarted = false;
	bool isMobile = false;
	bool isRememCon = false;
	bool isRememApp = false;

	// Variables

	CButton _isMobile;
	CButton _isRememberCon;
	CButton _isRememberApp;
	CListBox _appLogger;
	CButton _btnStart;
	CButton _btnStop;
protected:
	virtual void OnDestroy();

	virtual BOOL OnInitDialog();
	virtual INT_PTR DialogProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual void OnOK();

private:
	/*BOOL OnButton();
	BOOL OnRadio1();
	BOOL OnRadio2();
	BOOL OnRadio3();
	BOOL OnCheck1();
	BOOL OnCheck2();
	BOOL OnCheck3();*/

	// Method
	BOOL OnStart();
	BOOL OnStop();
	BOOL OnCheckRememCon();
	BOOL OnCheckRememApp();
	BOOL OnCheckMobileAgent();
	bool DoRequest(string &msgErr);
	HMODULE m_hInstRichEdit;

	CEdit _proxyPort;
	CEdit _proxyUsr;
	CEdit _proxyPwd;

	char _strProxyPort;
	char _strProxyUsr;
	char _strProxyPwd;
};

#endif //MYDIALOG_H
