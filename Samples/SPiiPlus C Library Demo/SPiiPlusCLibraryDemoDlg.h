// SPiiPlusCLibraryDemoDlg.h : header file
//

#if !defined(AFX_SPIIPLUSCLIBRARYDEMODLG_H__CCB9D989_B07F_4529_BADD_E22CC9DD86E5__INCLUDED_)
#define AFX_SPIIPLUSCLIBRARYDEMODLG_H__CCB9D989_B07F_4529_BADD_E22CC9DD86E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSPiiPlusCLibraryDemoDlg dialog
//#pragma comment(lib, "..\\..\\ACSCL_X86.lib")
#include "..\..\ACSC.h"
#include "afxcmn.h"

#define MAX_AXIS_COUNT			128		// UI 에서 사용할 최대 축 개수 지정
#define MAX_BUFF_COUNT			64
#define UPDATE_TIMER_INTERVAL	50		// 상태 업데이트 타이머의 Interval 시간
#define GPIO_PORT_NO			0		// General Input/Ouput 의 포트 번호 (IN, OUT)
#define MAX_GPIO_COUNT			8
#define TIMEOUT_MOTOR_ENABLED	3000
#define TIMEOUT_MOTOR_DISABLE	3000

class CSPiiPlusCLibraryDemoDlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	CSPiiPlusCLibraryDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSPiiPlusCLibraryDemoDlg)
	enum { IDD = IDD_SPIIPLUSCLIBRARYDEMO_DIALOG };
	CComboBox	m_cboMulSpdAxis;
	CComboBox	m_cboSLAxis;
	CComboBox	m_cboMSAxis;
	CListBox	m_lstCallbackLog;
	CComboBox	m_cboBufferNo;
	CButton	m_btnOut0;
	CButton	m_btnOut1;
	CButton	m_btnOut2;
	CButton	m_btnOut3;
	CButton	m_btnOut4;
	CButton	m_btnOut5;
	CButton	m_btnOut6;
	CButton	m_btnOut7;
	CStatic	m_picOut0;
	CStatic	m_picOut1;
	CStatic	m_picOut2;
	CStatic	m_picOut3;
	CStatic	m_picOut4;
	CStatic	m_picOut5;
	CStatic	m_picOut6;
	CStatic	m_picOut7;
	CStatic	m_picIn0;
	CStatic	m_picIn1;
	CStatic	m_picIn2;
	CStatic	m_picIn3;
	CStatic	m_picIn4;
	CStatic	m_picIn5;
	CStatic	m_picIn6;
	CStatic	m_picIn7;
	CStatic	m_picES;
	CStatic	m_picRL0;
	CStatic	m_picRL1;
	CStatic	m_picRL2;
	CStatic	m_picRL3;
	CStatic	m_picRL4;
	CStatic	m_picRL5;
	CStatic	m_picRL6;
	CStatic	m_picRL7;
	CStatic	m_picLL0;
	CStatic	m_picLL1;
	CStatic	m_picLL2;
	CStatic	m_picLL3;
	CStatic	m_picLL4;
	CStatic	m_picLL5;
	CStatic	m_picLL6;
	CStatic	m_picLL7;
	CEdit	m_edtPE;
	CEdit	m_edtFPos;
	CEdit	m_edtFVel;
	CEdit	m_edtRPos;
	CStatic	m_picMove;
	CStatic	m_picInpos;
	CStatic	m_picEnable;
	CStatic	m_picAcc;
	CComboBox	m_cboAxisNo;
	int		m_nConnectType;
	CString	m_strIPAddress;
	int		m_nPort;
	double	m_dVelocity;
	double	m_dKDec;
	double	m_dJerk;
	double	m_dDistance;
	double	m_dDec;
	double	m_dAcc;
	CString	m_strLabelName;
	double	m_dJogVelocity;
	BOOL	m_bSetJogVelocity;
	double	m_lfPos1st;
	double	m_lfPos2nd;
	double	m_lfVel1st;
	double	m_lfVel2nd;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSPiiPlusCLibraryDemoDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSPiiPlusCLibraryDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnClose();
	afx_msg void OnBtnConnect();
	afx_msg void OnBtnDisconn();
	afx_msg void OnBtnEnable();
	afx_msg void OnBtnDisable();
	afx_msg void OnBtnDisableall();
	afx_msg void OnSelchangeCboAxisno();
	afx_msg void OnBtnSetZero();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBtnMovetopoint();
	afx_msg void OnBtnMovedec();
	afx_msg void OnBtnMoveinc();
	afx_msg void OnBtnStop();
	afx_msg void OnBtnStopall();
	afx_msg void OnKillfocusEdtVel();
	afx_msg void OnKillfocusEdtAcc();
	afx_msg void OnKillfocusEdtDec();
	afx_msg void OnKillfocusEdtJerk();
	afx_msg void OnKillfocusEdtKdec();
	afx_msg void OnBtnBufferStart();
	afx_msg void OnBtnBufferStop();
	afx_msg void OnBtnCallbackMotionend();
	afx_msg void OnBtnCallbackProgend();
	afx_msg void OnBtnCallbackInput();
	afx_msg void OnBtnJogNegative();
	afx_msg void OnBtnJogPositive();
	afx_msg void OnBtnSyncSet();
	afx_msg void OnBtnSyncRelease();
	afx_msg void OnBtnMoveMulspd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	static int WINAPI CallbackInput(UINT64 Param, void *UserParameter);
	static int WINAPI CallbackMotionEnd(UINT64 Param, void *UserParameter);
	static int WINAPI CallbackProgramEnd(UINT64 Param, void *UserParameter);

	void UpdateLeftLimit(int p_nAxisNo);
	void UpdateRightLimit(int p_nAxisNo);
	void UpdateEmergency();
	int m_FaultMask;
	int m_MotorFault;
	int m_EmergencyMask;
	int m_EmergencyFault;

	CBitmap BITMAP_ERR;
	CBitmap BITMAP_ON;
	CBitmap BITMAP_OFF;

	double m_RPosition[MAX_AXIS_COUNT];		// Reference Position
	double m_FPosition[MAX_AXIS_COUNT];		// Feedback Position
	double m_FVelocity[MAX_AXIS_COUNT];		// Feedback Velocity
	double m_PositionErr[MAX_AXIS_COUNT];	// Position Error
	int    m_MotorStatus[MAX_AXIS_COUNT];	// Motor Status
	int    m_MotorError[MAX_AXIS_COUNT];	// Motor Error

	int m_GeneralInput, m_GeneralOutput;
	void UpdateGeneralIO();					// General I/O 의 상태를 업데이트 처리
	void OnBtnOutput(UINT nID);				// On/Off 처리를 위한 클릭 이벤트 함수

	int m_nSelectedAxisNo;
	int m_nSelectedBufferNo;

	UINT_PTR m_nTimerID;
	void ShowErrorMsg(CString p_strMsg);
	void UpdateParameters(int p_nAxisNo);
	void TerminatePrevConnect();

	HANDLE m_hAcsComm;				// ACS Communication handle
	BOOL m_bConnected;
public:
	CRichEditCtrl m_redtCommandRet;
	void AddString(const CString& text);//const TCHAR* str);
	afx_msg void OnBnClickedBtnSendCmd();
};

// 전역 변수
static int g_nTotalAxes, g_nTotalBuffer;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPIIPLUSCLIBRARYDEMODLG_H__CCB9D989_B07F_4529_BADD_E22CC9DD86E5__INCLUDED_)
