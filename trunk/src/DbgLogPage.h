//-----------------------------------------------------------------------------
//
//	GraphStudioNext
//
//	Author : CPlusSharp
//
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
//
//	CDbgLogPage class
//
//-----------------------------------------------------------------------------
class CDbgLogPage : public CDSPropertyPage
{
protected:
	DECLARE_MESSAGE_MAP()

public:
	GraphStudio::TitleBar	title;
    bool                    isActiv;
	CButton					btn_refresh;
	CButton					btn_settings;
	CButton					btn_locate;
	CEdit					edit_log;
	CFont			        font_log;
	CEdit					edit_filter;

	const CString			filterFile;
	const CString			logFile;

	CAtlRegExp<>			filterRegex;

    enum { IDD = IDD_PROPPAGE_DBGLOG };
public:
	CDbgLogPage(LPUNKNOWN pUnk, HRESULT *phr, LPCTSTR strTitle, const CString& filterFile, const CString& logFile);
	virtual ~CDbgLogPage();
	
	// overriden
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void OnSize(UINT nType, int cx, int cy);

    virtual HRESULT OnConnect(IUnknown *pUnknown);
    virtual HRESULT OnDisconnect();
	virtual HRESULT OnActivate();
	virtual HRESULT OnApplyChanges();
    afx_msg void OnBnClickedRefresh();
	afx_msg void OnBnClickedSettings();
	afx_msg void OnLocateClick();
	afx_msg void OnUpdateFilterString();
};

