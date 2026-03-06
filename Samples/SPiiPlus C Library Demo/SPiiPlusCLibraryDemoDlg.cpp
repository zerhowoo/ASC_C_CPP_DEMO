// SPiiPlusCLibraryDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SPiiPlusCLibraryDemo.h"
#include "SPiiPlusCLibraryDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//int WINAPI CallbackInput(UINT64 Param, void *UserParameter);
//int WINAPI CallbackMotionEnd(UINT64 Param, void *UserParameter);
//int WINAPI CallbackProgramEnd(UINT64 Param, void *UserParameter);

CSPiiPlusCLibraryDemoDlg *thisDlg;

/////////////////////////////////////////////////////////////////////////////
// CSPiiPlusCLibraryDemoDlg dialog

CSPiiPlusCLibraryDemoDlg::CSPiiPlusCLibraryDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSPiiPlusCLibraryDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSPiiPlusCLibraryDemoDlg)
	m_nConnectType = -1;
	m_strIPAddress = _T("");
	m_nPort = 0;
	m_dVelocity = 0.0;
	m_dKDec = 0.0;
	m_dJerk = 0.0;
	m_dDistance = 0.0;
	m_dDec = 0.0;
	m_dAcc = 0.0;
	m_strLabelName = _T("");
	m_dJogVelocity = 0.0;
	m_bSetJogVelocity = FALSE;
	m_lfPos1st = 0.0;
	m_lfPos2nd = 0.0;
	m_lfVel1st = 0.0;
	m_lfVel2nd = 0.0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	thisDlg = this;
	AfxInitRichEdit2();
}

void CSPiiPlusCLibraryDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSPiiPlusCLibraryDemoDlg)
	DDX_Control(pDX, IDC_CBO_AXIS_MULSPD, m_cboMulSpdAxis);
	DDX_Control(pDX, IDC_CBO_SYNC_SL, m_cboSLAxis);
	DDX_Control(pDX, IDC_CBO_SYNC_MS, m_cboMSAxis);
	DDX_Control(pDX, IDC_LST_CALLBACK, m_lstCallbackLog);
	DDX_Control(pDX, IDC_CBO_BUFFER_NO, m_cboBufferNo);
	DDX_Control(pDX, IDC_BTN_OUT0, m_btnOut0);
	DDX_Control(pDX, IDC_BTN_OUT1, m_btnOut1);
	DDX_Control(pDX, IDC_BTN_OUT2, m_btnOut2);
	DDX_Control(pDX, IDC_BTN_OUT3, m_btnOut3);
	DDX_Control(pDX, IDC_BTN_OUT4, m_btnOut4);
	DDX_Control(pDX, IDC_BTN_OUT5, m_btnOut5);
	DDX_Control(pDX, IDC_BTN_OUT6, m_btnOut6);
	DDX_Control(pDX, IDC_BTN_OUT7, m_btnOut7);
	DDX_Control(pDX, IDC_PIC_OUT0, m_picOut0);
	DDX_Control(pDX, IDC_PIC_OUT1, m_picOut1);
	DDX_Control(pDX, IDC_PIC_OUT2, m_picOut2);
	DDX_Control(pDX, IDC_PIC_OUT3, m_picOut3);
	DDX_Control(pDX, IDC_PIC_OUT4, m_picOut4);
	DDX_Control(pDX, IDC_PIC_OUT5, m_picOut5);
	DDX_Control(pDX, IDC_PIC_OUT6, m_picOut6);
	DDX_Control(pDX, IDC_PIC_OUT7, m_picOut7);
	DDX_Control(pDX, IDC_PIC_IN0, m_picIn0);
	DDX_Control(pDX, IDC_PIC_IN1, m_picIn1);
	DDX_Control(pDX, IDC_PIC_IN2, m_picIn2);
	DDX_Control(pDX, IDC_PIC_IN3, m_picIn3);
	DDX_Control(pDX, IDC_PIC_IN4, m_picIn4);
	DDX_Control(pDX, IDC_PIC_IN5, m_picIn5);
	DDX_Control(pDX, IDC_PIC_IN6, m_picIn6);
	DDX_Control(pDX, IDC_PIC_IN7, m_picIn7);
	DDX_Control(pDX, IDC_PIC_ES, m_picES);
	DDX_Control(pDX, IDC_PIC_RL0, m_picRL0);
	DDX_Control(pDX, IDC_PIC_RL1, m_picRL1);
	DDX_Control(pDX, IDC_PIC_RL2, m_picRL2);
	DDX_Control(pDX, IDC_PIC_RL3, m_picRL3);
	DDX_Control(pDX, IDC_PIC_RL4, m_picRL4);
	DDX_Control(pDX, IDC_PIC_RL5, m_picRL5);
	DDX_Control(pDX, IDC_PIC_RL6, m_picRL6);
	DDX_Control(pDX, IDC_PIC_RL7, m_picRL7);
	DDX_Control(pDX, IDC_PIC_LL0, m_picLL0);
	DDX_Control(pDX, IDC_PIC_LL1, m_picLL1);
	DDX_Control(pDX, IDC_PIC_LL2, m_picLL2);
	DDX_Control(pDX, IDC_PIC_LL3, m_picLL3);
	DDX_Control(pDX, IDC_PIC_LL4, m_picLL4);
	DDX_Control(pDX, IDC_PIC_LL5, m_picLL5);
	DDX_Control(pDX, IDC_PIC_LL6, m_picLL6);
	DDX_Control(pDX, IDC_PIC_LL7, m_picLL7);
	DDX_Control(pDX, IDC_EDT_PE, m_edtPE);
	DDX_Control(pDX, IDC_EDT_FPOS, m_edtFPos);
	DDX_Control(pDX, IDC_EDT_FVEL, m_edtFVel);
	DDX_Control(pDX, IDC_EDT_RPOS, m_edtRPos);
	DDX_Control(pDX, IDC_PIC_MOVE, m_picMove);
	DDX_Control(pDX, IDC_PIC_INPOS, m_picInpos);
	DDX_Control(pDX, IDC_PIC_ENABLE, m_picEnable);
	DDX_Control(pDX, IDC_PIC_ACC, m_picAcc);
	DDX_Control(pDX, IDC_CBO_AXISNO, m_cboAxisNo);
	DDX_Radio(pDX, IDC_RDO_SIMULATOR, m_nConnectType);
	DDX_Text(pDX, IDC_EDT_IP, m_strIPAddress);
	DDX_Text(pDX, IDC_EDT_PORT, m_nPort);
	DDX_Text(pDX, IDC_EDT_VEL, m_dVelocity);
	DDX_Text(pDX, IDC_EDT_KDEC, m_dKDec);
	DDX_Text(pDX, IDC_EDT_JERK, m_dJerk);
	DDX_Text(pDX, IDC_EDT_DISTANCE, m_dDistance);
	DDX_Text(pDX, IDC_EDT_DEC, m_dDec);
	DDX_Text(pDX, IDC_EDT_ACC, m_dAcc);
	DDX_Text(pDX, IDC_EDT_PROG_LABEL, m_strLabelName);
	DDX_Text(pDX, IDC_EDT_JOG_VELOCITY, m_dJogVelocity);
	DDX_Check(pDX, IDC_CHK_JOG_VELOCITY, m_bSetJogVelocity);
	DDX_Text(pDX, IDC_EDT_POS_1ST, m_lfPos1st);
	DDX_Text(pDX, IDC_EDT_POS_2ND, m_lfPos2nd);
	DDX_Text(pDX, IDC_EDT_VEL_1ST, m_lfVel1st);
	DDX_Text(pDX, IDC_EDT_VEL_2ND, m_lfVel2nd);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_REDT_CMD_RESULT, m_redtCommandRet);
}

BEGIN_MESSAGE_MAP(CSPiiPlusCLibraryDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CSPiiPlusCLibraryDemoDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CLOSE, OnBtnClose)
	ON_BN_CLICKED(IDC_BTN_CONNECT, OnBtnConnect)
	ON_BN_CLICKED(IDC_BTN_DISCONN, OnBtnDisconn)
	ON_BN_CLICKED(IDC_BTN_ENABLE, OnBtnEnable)
	ON_BN_CLICKED(IDC_BTN_DISABLE, OnBtnDisable)
	ON_BN_CLICKED(IDC_BTN_DISABLEALL, OnBtnDisableall)
	ON_CBN_SELCHANGE(IDC_CBO_AXISNO, OnSelchangeCboAxisno)
	ON_BN_CLICKED(IDC_BTN_SET_ZERO, OnBtnSetZero)
	ON_WM_TIMER()	
	ON_BN_CLICKED(IDC_BTN_MOVETOPOINT, OnBtnMovetopoint)
	ON_BN_CLICKED(IDC_BTN_MOVEDEC, OnBtnMovedec)
	ON_BN_CLICKED(IDC_BTN_MOVEINC, OnBtnMoveinc)
	ON_BN_CLICKED(IDC_BTN_STOP, OnBtnStop)
	ON_BN_CLICKED(IDC_BTN_STOPALL, OnBtnStopall)
	ON_EN_KILLFOCUS(IDC_EDT_VEL, OnKillfocusEdtVel)
	ON_EN_KILLFOCUS(IDC_EDT_ACC, OnKillfocusEdtAcc)
	ON_EN_KILLFOCUS(IDC_EDT_DEC, OnKillfocusEdtDec)
	ON_EN_KILLFOCUS(IDC_EDT_JERK, OnKillfocusEdtJerk)
	ON_EN_KILLFOCUS(IDC_EDT_KDEC, OnKillfocusEdtKdec)
	ON_BN_CLICKED(IDC_BTN_BUFFER_START, OnBtnBufferStart)
	ON_BN_CLICKED(IDC_BTN_BUFFER_STOP, OnBtnBufferStop)
	ON_BN_CLICKED(IDC_BTN_CALLBACK_MOTIONEND, OnBtnCallbackMotionend)
	ON_BN_CLICKED(IDC_BTN_CALLBACK_PROGEND, OnBtnCallbackProgend)
	ON_BN_CLICKED(IDC_BTN_CALLBACK_INPUT, OnBtnCallbackInput)
	ON_BN_CLICKED(IDC_BTN_JOG_NEGATIVE, OnBtnJogNegative)
	ON_BN_CLICKED(IDC_BTN_JOG_POSITIVE, OnBtnJogPositive)
	ON_BN_CLICKED(IDC_BTN_SYNC_SET, OnBtnSyncSet)
	ON_BN_CLICKED(IDC_BTN_SYNC_RELEASE, OnBtnSyncRelease)
	ON_BN_CLICKED(IDC_BTN_MOVE_MULSPD, OnBtnMoveMulspd)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_OUT0, IDC_BTN_OUT7, OnBtnOutput)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_SEND_CMD, &CSPiiPlusCLibraryDemoDlg::OnBnClickedBtnSendCmd)
END_MESSAGE_MAP()

//ON_COMMAND_RANGE(IDC_BTN_OUT0, IDC_BTN_OUT7, OnBtnOutput)

/////////////////////////////////////////////////////////////////////////////
// CSPiiPlusCLibraryDemoDlg message handlers

BOOL CSPiiPlusCLibraryDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CString strTemp;

	m_nConnectType = 1;						// 기본 TCP/IP 로 설정
	m_strIPAddress = _T("10.0.0.100");		// 제어기 최초 할당된 IP 주소
	m_nPort = ACSC_SOCKET_STREAM_PORT;		// TCP 포트 : 701, UDP 포트를 사용할 경우 700 번이고 ACSC_SOCKET_DGRAM_PORT 상수 이용

	/*for(i = 0; i < MAX_AXIS_COUNT; i++)
	{	
		strTemp.Format(_T("%d"), i);
		m_cboAxisNo.AddString(strTemp);
		m_cboMSAxis.AddString(strTemp);
		m_cboSLAxis.AddString(strTemp);
		m_cboMulSpdAxis.AddString(strTemp);
	}
	m_cboAxisNo.SetCurSel(0);
	m_cboMSAxis.SetCurSel(0);
	m_cboSLAxis.SetCurSel(0);
	m_cboMulSpdAxis.SetCurSel(0);

	for(i = 0; i < MAX_BUFF_COUNT; i++)
	{	
		strTemp.Format(_T("%d"), i);
		m_cboBufferNo.AddString(strTemp);
	}
	m_cboBufferNo.SetCurSel(0);
	m_nSelectedAxisNo = 0;*/
	
	m_hAcsComm = ACSC_INVALID;
	m_bConnected = FALSE;

	BITMAP_ERR.LoadBitmap(IDB_ERR);
	BITMAP_ON.LoadBitmap(IDB_ON);
	BITMAP_OFF.LoadBitmap(IDB_OFF);

	UpdateData(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSPiiPlusCLibraryDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CSPiiPlusCLibraryDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSPiiPlusCLibraryDemoDlg::OnOK()
{
	// Return, Enter 키 종료 방지
	//CDialog::OnOK();
}

void CSPiiPlusCLibraryDemoDlg::OnBtnClose() 
{
	if(m_hAcsComm != ACSC_INVALID) acsc_CloseComm(m_hAcsComm); 
	CDialog::DestroyWindow();
}

void CSPiiPlusCLibraryDemoDlg::OnBtnConnect() 
{
	int i;
	double SysInfo = 0.0;
	CString strTemp;

	UpdateData(TRUE);
	
	// Clear connections from SPiiPlus User Mode Driver
	// (User Mode Drvier is supporting up to 10 channels)
	TerminatePrevConnect();

	switch(m_nConnectType)
	{
		// Simulation Mode
		case 0:		
			m_hAcsComm = acsc_OpenCommSimulator();
			break;

		// Ethernet
		case 1:		
			// Connect to the controller via TCP socket
			m_hAcsComm = acsc_OpenCommEthernetTCP((char*)LPCTSTR(m_strIPAddress), m_nPort); 

			// UDP Socket (ACS is supporting only 1 UDP channel)
			//m_hAcsComm = acsc_OpenCommEthernetUDP((char*)LPCTSTR(m_strIPAddress), ACSC_SOCKET_DGRAM_PORT); 
			break;
	}
	
	// After connecting, if you got an invalid handle
	if(m_hAcsComm == ACSC_INVALID) 
	{
		AfxMessageBox(_T("Connection Error"));
		return;
	}
	
	// Get maximum number of axes
	SysInfo = 0.0;
	acsc_SysInfo(m_hAcsComm, 13, &SysInfo, NULL);
	g_nTotalAxes = (int)SysInfo;
	
	// Initialize ComboBox
	m_cboAxisNo.ResetContent();
	m_cboMSAxis.ResetContent();
	m_cboSLAxis.ResetContent();
	m_cboMulSpdAxis.ResetContent();
	
	for(i = 0; i < g_nTotalAxes; i++)
	{	
		strTemp.Format(_T("%d"), i);
		m_cboAxisNo.AddString(strTemp);
		m_cboMSAxis.AddString(strTemp);
		m_cboSLAxis.AddString(strTemp);
		m_cboMulSpdAxis.AddString(strTemp);
	}
	m_cboAxisNo.SetCurSel(0);
	m_cboMSAxis.SetCurSel(0);
	m_cboSLAxis.SetCurSel(0);
	m_cboMulSpdAxis.SetCurSel(0);
	
	// Get total number of buffers
	SysInfo = 0.0;
	acsc_SysInfo(m_hAcsComm, 10, &SysInfo, NULL);
	g_nTotalBuffer = (int)SysInfo;
	
	m_cboBufferNo.ResetContent();
	for(i = 0; i < g_nTotalBuffer; i++)
	{	
		strTemp.Format(_T("%d"), i);
		m_cboBufferNo.AddString(strTemp);
	}
	m_cboBufferNo.SetCurSel(0);
	m_nSelectedAxisNo = 0;
	
	m_bConnected = TRUE;
	m_cboAxisNo.SetCurSel(0);	// Set default axis index
	UpdateParameters(0);

	m_nTimerID = SetTimer(1, UPDATE_TIMER_INTERVAL, NULL);
}

void CSPiiPlusCLibraryDemoDlg::OnBtnDisconn() 
{
	KillTimer(m_nTimerID);

	if(m_hAcsComm != ACSC_INVALID)  
	{
		if(acsc_CloseComm(m_hAcsComm)) 
		{ 
			m_hAcsComm = ACSC_INVALID; 
			m_bConnected = FALSE; 
		}
	}
}

//***********************************************************************************
// Clear connections from User Mode Driver
//***********************************************************************************
void CSPiiPlusCLibraryDemoDlg::TerminatePrevConnect()
{
	char *pSeperator = "\\";
	char *pToken = NULL;
	char pApplicationName[256] = { 0x00, };

	int nConnections;
	ACSC_CONNECTION_DESC ConnectionList[10];

	if(!acsc_GetConnectionsList(ConnectionList, 10, &nConnections)) printf("Error %d\n", acsc_GetLastError());
	
	for (int i = 0; i < nConnections; i++)
	{
		// Sperate names (if the application name is "USERNAME\ACS.Fremwork.exe" in UMD list, you need to seprate it.)
		pToken = strtok(ConnectionList[i].Application, pSeperator);
		sprintf(pApplicationName, pToken);
		while (pToken)
		{
			pToken = strtok(NULL, pSeperator);	// Find next
			if(pToken != NULL) 
			{
				sprintf(pApplicationName, pToken);
			}
		}

		// Clear connection without MMI application studio
		if((strcmp(pApplicationName, "ACS.Framework.exe")) != 0)
		{
			// Terminate connection from UDM
			if(!acsc_TerminateConnection(&(ConnectionList[i])))
			{
				printf("Error closing communication of %s application: %d\n", ConnectionList[i].Application, acsc_GetLastError());
			}
			else
			{
				printf("Communication of %s application is successfully closed!\n", ConnectionList[i].Application);
			}
		}
	}
}	

//==================================================================================
// Axis Enable (Servo On)
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::OnBtnEnable()
{
	int Error;
	char ErrorStr[256];
	char MsgsStr[256];
	int Received;
	// Axis Enable command
	if (!acsc_Enable(m_hAcsComm, m_nSelectedAxisNo, NULL)) ShowErrorMsg(_T("Axis enable error"));
	// Waiting until enabled
	if (!acsc_WaitMotorEnabled(m_hAcsComm, m_nSelectedAxisNo, 1, TIMEOUT_MOTOR_ENABLED))

		if (acsc_GetMotorError(m_hAcsComm, m_nSelectedAxisNo, &Error, NULL))
		{
			if (Error > 0)
			{
				if (acsc_GetErrorString(m_hAcsComm, Error, ErrorStr, 255, &Received))
				{
					ErrorStr[Received] = '\0';
					sprintf_s(MsgsStr, "Error = % d ,%s", Error, ErrorStr);
					MessageBox(MsgsStr, _T("C Library function error"), MB_OK);
					return;
				}
			}

		}
		else
		{
			ShowErrorMsg(_T("Axis enable error"));
		}

	// If you want to enable several axes..
	// Ex) eanble (0, 1, 5, 7)
	// int AxisList[] = { 0, 1, 5, 7, -1 };		!! You must set '-1' at the last of array.
	// acsc_EnableM(m_hAcsComm, AxisList, NULL);
}

//==================================================================================
// Axis Disable (Servo Off)
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::OnBtnDisable() 
{
	// Axis disable command
	if(!acsc_Disable(m_hAcsComm, m_nSelectedAxisNo, NULL)) ShowErrorMsg(_T("Axis disable error"));
	// Waiting until disabled
	if(!acsc_WaitMotorEnabled(m_hAcsComm, m_nSelectedAxisNo, 0, TIMEOUT_MOTOR_ENABLED)) ShowErrorMsg(_T("Axis enable error"));

	// If you want to disable several axes..
	// Ex) disable (0, 1, 5, 7)
	// int AxisList[] = { 0, 1, 5, 7, -1 };		!! You must set '-1' at the last of array.
	// acsc_DisableM(m_hAcsComm, AxisList, NULL);
}

//==================================================================================
// Disable all axes
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::OnBtnDisableall() 
{
	if(!acsc_DisableAll(m_hAcsComm, NULL)) ShowErrorMsg(_T("All axes disable error"));
}

//==================================================================================
// Update motion parameters to dialog
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::UpdateParameters(int p_nAxisNo)
{
	double Vel, Acc, Dec, Jerk, KDec; // , FPos, RPos, FVel, PE;

	//==================================================================================
	// Velocity
	//==================================================================================
	if(acsc_GetVelocity(m_hAcsComm, p_nAxisNo, &Vel, NULL)) m_dVelocity = Vel;
	else { ShowErrorMsg(_T("Get Velocity Error")); m_dVelocity = 0.0; }
	
	//==================================================================================
	// Acceleration
	//==================================================================================
	if(acsc_GetAcceleration(m_hAcsComm, p_nAxisNo, &Acc, NULL)) m_dAcc = Acc;
	else { ShowErrorMsg(_T("Get Acceleration Error")); m_dAcc = 0.0; }

	//==================================================================================
	// Deceleration
	//==================================================================================
	if(acsc_GetDeceleration(m_hAcsComm, p_nAxisNo, &Dec, NULL)) m_dDec = Dec;
	else { ShowErrorMsg(_T("Get Deceleration Error")); m_dDec = 0.0; }

	//==================================================================================
	// Kill Deceleration
	//==================================================================================
	if(acsc_GetKillDeceleration(m_hAcsComm, p_nAxisNo, &KDec, NULL)) m_dKDec = KDec;
	else { ShowErrorMsg(_T("Get Kill Deceleration Error"));	m_dKDec = 0.0; }

	//==================================================================================
	// Jerk
	//==================================================================================
	if(acsc_GetJerk(m_hAcsComm, p_nAxisNo, &Jerk, NULL)) m_dJerk = Jerk;
	else { ShowErrorMsg(_T("Get Jerk Erorr")); m_dJerk = 0.0; }

	UpdateData(FALSE);
}

void CSPiiPlusCLibraryDemoDlg::OnSelchangeCboAxisno() 
{
	m_nSelectedAxisNo = m_cboAxisNo.GetCurSel();
	if(m_bConnected) UpdateParameters(m_nSelectedAxisNo);	
}

//==================================================================================
// Error message 
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::ShowErrorMsg(CString p_strMsg)
{
	CString strMessage;
	int recvCnt = 0;
	int errCode = 0;
	char errString[101];

	errCode = acsc_GetLastError();		// Get last error message from ACS library (Result of library command)
										// - If ACS got an error in the buffer, this function cannot get the error code
	if(m_bConnected)
	{
		// Get Error string from ACS controller by error code
		acsc_GetErrorString(m_hAcsComm, errCode, errString, 100, &recvCnt);
		errString[recvCnt] = '\0';
	}

	if(recvCnt > 0)	strMessage.Format(_T("%s, Code : %d\nMessage : %s"), p_strMsg, errCode, errString);
	else strMessage.Format(_T("%s, Code : %d"), p_strMsg, errCode);
	
	MessageBox(strMessage, _T("C Library function error"), MB_OK);
}

//==================================================================================
// Set Zero feedback position
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::OnBtnSetZero() 
{
	if(!acsc_SetFPosition(m_hAcsComm, m_nSelectedAxisNo, 0, NULL))  ShowErrorMsg(_T("Set Feedback Position error"));
}

void CSPiiPlusCLibraryDemoDlg::OnTimer(UINT nIDEvent) 
{
	CString strTemp;

	if(m_bConnected == FALSE) return;

	//==================================================================================
	// Read Feedback(FPOS), Reference position(FPOS, Feedback velocity(FVEL), Motor status(MST)
	//==================================================================================
	// Instruction 1. User libarary functions - acsc_GetFPosition, acsc_GetRPosition, ....
	// Instruction 2. Read ACS variable - Already defined almost things (FPOS, RPOS, ...)
	//                Motion parameters and state is array (Max length is total number of axes)
	//
	// * Library function can read only 1 axis information, so if you want to read several axes, you have to call the function many times.
	//   (This may cause communication dealy.)
	//   Recommand (if you want to read many axes) : read/write variable using acsc_ReadInteger, acsc_ReadReal, acsc_WriteInteger, acsc_WriteReal...

	// Feedback Position 
	// ACSPL+ Variable : FPOS, C-Lib : acsc_GetFPosition()
	// - Read feedback position of total axes at once
	acsc_ReadReal(m_hAcsComm, -1, "FPOS", 0, g_nTotalAxes - 1, -1, -1, m_FPosition, NULL); 
	// If you are using the get function, 
	// acsc_GetFPosition(m_hAcsComm, 0, &m_FPosition[0], NULL);
	// acsc_GetFPosition(m_hAcsComm, 1, &m_FPosition[1], NULL);
	// acsc_GetFPosition(m_hAcsComm, 2, &m_FPosition[2], NULL);
	// acsc_GetFPosition(m_hAcsComm, 3, &m_FPosition[3], NULL);
	// ...

	// Reference Position
	// ACSPL+ Variable : RPOS, C-Lib : acsc_GetRPosition()
	acsc_ReadReal(m_hAcsComm, -1, "RPOS", 0, g_nTotalAxes - 1, -1, -1, m_RPosition, NULL); 

	// Feedback Velocity
	// ACSPL+ Variable : FVEL, C-Lib : acsc_GetFVelocity()
	acsc_ReadReal(m_hAcsComm, -1, "FVEL", 0, g_nTotalAxes - 1, -1, -1, m_FVelocity, NULL); 

	// Position Error
	// ACSPL+ Variable : PE, C-Lib : there is no function
	acsc_ReadReal(m_hAcsComm, -1, "PE",   0, g_nTotalAxes - 1, -1, -1, m_PositionErr, NULL); 

	// Motor State
	// ACSPL+ : MST, C-Lib : acsc_GetMotorState()
	// Return value is integer, you have to use bitmask
	// 
	// if (m_MotorStatus[0] & ACSC_MST_MOVE ) 
	// {  
	//     Moving state
	// }
	// else 
	// { 
	//     Stand.. (in position)
    // }
	acsc_ReadInteger(m_hAcsComm, -1, "MST",  0, g_nTotalAxes -1, -1, -1, m_MotorStatus, NULL);
	
	// Motor Error Code
	// ACSPL+ : MERR, C-Lib : acsc_GetMotorError()
	acsc_ReadInteger(m_hAcsComm, -1, "MERR", 0, g_nTotalAxes -1, -1, -1, m_MotorError, NULL);

	//==================================================================================
	// Update dialog : Feedback, Reference position, Feedback velocity
	//==================================================================================
	strTemp.Format(_T("%.4lf"), m_FPosition[m_nSelectedAxisNo]); m_edtFPos.SetWindowText(strTemp); 
	strTemp.Format(_T("%.4lf"), m_RPosition[m_nSelectedAxisNo]); m_edtRPos.SetWindowText(strTemp); 
	strTemp.Format(_T("%.4lf"), m_FVelocity[m_nSelectedAxisNo]); m_edtFVel.SetWindowText(strTemp); 
	strTemp.Format(_T("%.4lf"), m_PositionErr[m_nSelectedAxisNo]); m_edtPE.SetWindowText(strTemp);
	
	//==================================================================================
	// Update dialog : Motor Status
	//==================================================================================
	if(m_MotorStatus[m_nSelectedAxisNo] & ACSC_MST_ENABLE) m_picEnable.SetBitmap(BITMAP_ON);
	else m_picEnable.SetBitmap(BITMAP_OFF);

	if(m_MotorStatus[m_nSelectedAxisNo] & ACSC_MST_MOVE) m_picMove.SetBitmap(BITMAP_ON);
	else m_picMove.SetBitmap(BITMAP_OFF);

	if(m_MotorStatus[m_nSelectedAxisNo] & ACSC_MST_ACC) m_picAcc.SetBitmap(BITMAP_ON);
	else m_picAcc.SetBitmap(BITMAP_OFF);

	if(m_MotorStatus[m_nSelectedAxisNo] & ACSC_MST_INPOS) m_picInpos.SetBitmap(BITMAP_ON);
	else m_picInpos.SetBitmap(BITMAP_OFF);
	//==================================================================================
	// Read General Input 8 bits, Output 8 bits at once (ACSPL Variable : IN(0), OUT(0))
	//==================================================================================
	acsc_GetInputPort(m_hAcsComm,  GPIO_PORT_NO, &m_GeneralInput,  NULL);
	acsc_GetOutputPort(m_hAcsComm, GPIO_PORT_NO, &m_GeneralOutput, NULL);
	UpdateGeneralIO();

	//==================================================================================
	// Left, Right Limit state
	//  - ACSPL Variable : FAULT(MAX_AXIS_COUNT)
	//  - acsc_GetFault : this function is reading fault informaton one by one
	//  - if you are using acsc_ReadInteger function, you can read all informations at once
	//==================================================================================
	for(int iAxis = 0; iAxis < g_nTotalAxes; iAxis++)
	{
		acsc_GetFaultMask(m_hAcsComm, iAxis, &m_FaultMask, NULL);
		acsc_GetFault(m_hAcsComm, iAxis, &m_MotorFault, NULL);

		UpdateRightLimit(iAxis);
		UpdateLeftLimit(iAxis);
	}
	// acsc_ReadInteger(m_hAcsComm, "FAULT", 0, g_nTotalAxes - 1, -1, -1, FaultArray, NULL);

	//==================================================================================
	// For updating Emergency Stop state (from System fault)
	//  - ACSPL variable : S_FAULT
	//   1. acsc_GetFault : Axis number is -1 (ACSC_NONE)
	//   2. acsc_ReadInteger : ACS Variable  'S_FAULT', range 0 to 0
	//==================================================================================
	acsc_GetFaultMask(m_hAcsComm, ACSC_NONE, &m_EmergencyMask, NULL);
	acsc_GetFault(m_hAcsComm, ACSC_NONE, &m_EmergencyFault, NULL);
	UpdateEmergency();

	CDialog::OnTimer(nIDEvent);
}

//==================================================================================
// Update general I/O state
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::UpdateGeneralIO()
{
	CStatic *picIn, *picOut;
	CButton *btnOut;
	int MaskBit = ACSC_MASK_INPUT_0;

	picIn  = &m_picIn0;
	picOut = &m_picOut0;
	btnOut = &m_btnOut0;

	for(int i = 0; i < MAX_GPIO_COUNT; i++)
	{
		// Input
		if(m_GeneralInput & MaskBit) picIn[i].SetBitmap(BITMAP_ON);
		else picIn[i].SetBitmap(BITMAP_OFF);

		// Ouput
		if(m_GeneralOutput & MaskBit) 
		{
			picOut[i].SetBitmap(BITMAP_ON);
			btnOut[i].SetWindowText(_T("OFF"));
		}
		else 
		{
			picOut[i].SetBitmap(BITMAP_OFF);
			btnOut[i].SetWindowText(_T("ON"));
		}
		MaskBit = MaskBit << 1;
	}
}

//==================================================================================
// On and Off digital output
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::OnBtnOutput(UINT nID)
{
	if(m_bConnected == FALSE) return;

	// On and off selected bit
	// acsc_SetOutput(Communication Handle, Port number, Bit number, ON = 1 / OFF = 0, NULL);
	switch(nID)
	{
		case IDC_BTN_OUT0: 
			if(m_GeneralOutput & ACSC_MASK_INPUT_0) acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 0, 0, NULL);
			else acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 0, 1, NULL);
			break;
		case IDC_BTN_OUT1: 
			if(m_GeneralOutput & ACSC_MASK_INPUT_1) acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 1, 0, NULL);
			else acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 1, 1, NULL);
			break;
		case IDC_BTN_OUT2: 
			if(m_GeneralOutput & ACSC_MASK_INPUT_2) acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 2, 0, NULL);
			else acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 2, 1, NULL);
			break;
		case IDC_BTN_OUT3: 
			if(m_GeneralOutput & ACSC_MASK_INPUT_3) acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 3, 0, NULL);
			else acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 3, 1, NULL);
			break;
		case IDC_BTN_OUT4: 
			if(m_GeneralOutput & ACSC_MASK_INPUT_4) acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 4, 0, NULL);
			else acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 4, 1, NULL);
			break;
		case IDC_BTN_OUT5: 
			if(m_GeneralOutput & ACSC_MASK_INPUT_5) acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 5, 0, NULL);
			else acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 5, 1, NULL);
			break; 
		case IDC_BTN_OUT6:
			if(m_GeneralOutput & ACSC_MASK_INPUT_6) acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 6, 0, NULL);
			else acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 6, 1, NULL);
			break;
		case IDC_BTN_OUT7: 
			if(m_GeneralOutput & ACSC_MASK_INPUT_7) acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 7, 0, NULL);
			else acsc_SetOutput(m_hAcsComm, GPIO_PORT_NO, 7, 1, NULL);
			break;
	}
}

//==================================================================================
// Update right hardware limit state
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::UpdateRightLimit(int p_nAxisNo)
{
	CStatic *picRL = &m_picRL0;
	
	// This limit, this sample have only 8 picture boxes
	if(p_nAxisNo > 7) return;

	if(m_FaultMask & ACSC_SAFETY_RL)	// Fault mask : use or not
	{
		if(m_MotorFault & ACSC_SAFETY_RL) picRL[p_nAxisNo].SetBitmap(BITMAP_ERR);		// If engaged limit
		else picRL[p_nAxisNo].SetBitmap(BITMAP_ON);
	}
	else picRL[p_nAxisNo].SetBitmap(BITMAP_OFF);
}
//==================================================================================
// Update left hardware limit state
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::UpdateLeftLimit(int p_nAxisNo)
{
	CStatic *picLL = &m_picLL0;

	if(p_nAxisNo > 7) return;

	if(m_FaultMask & ACSC_SAFETY_LL)
	{
		if(m_MotorFault & ACSC_SAFETY_LL) picLL[p_nAxisNo].SetBitmap(BITMAP_ERR);
		else picLL[p_nAxisNo].SetBitmap(BITMAP_ON);
	}
	else picLL[p_nAxisNo].SetBitmap(BITMAP_OFF);
}
//==================================================================================
// Update emergency stop state (hardware switch)
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::UpdateEmergency()
{
	if(m_EmergencyMask & ACSC_SAFETY_ES)
	{
		if(m_EmergencyFault & ACSC_SAFETY_ES) m_picES.SetBitmap(BITMAP_ERR);
		else m_picES.SetBitmap(BITMAP_ON);
	}
	else m_picES.SetBitmap(BITMAP_OFF);
}

void CSPiiPlusCLibraryDemoDlg::OnBtnMovetopoint() 
{	
	UpdateData(TRUE);

	// If motor is moving state, 
	if(m_MotorStatus[m_nSelectedAxisNo] & ACSC_MST_MOVE) return;
	
	// Seconds arguement '0', it means absolute position (no option)
	if(!acsc_ToPoint(m_hAcsComm, 0, m_nSelectedAxisNo, m_dDistance, NULL)) 
	{
		ShowErrorMsg(_T("Move to Position (Absolute position) command error"));
	}
}

void CSPiiPlusCLibraryDemoDlg::OnBtnMovedec() 
{
	UpdateData(TRUE);

	// If motor is moving state,
	if(m_MotorStatus[m_nSelectedAxisNo] & ACSC_MST_MOVE) return;

	// Move relative position (from current position)
	if(!acsc_ToPoint(m_hAcsComm, ACSC_AMF_RELATIVE, m_nSelectedAxisNo, m_dDistance * (-1), NULL)) 
	{
		ShowErrorMsg(_T("Move Decrement command error"));
	}
}

void CSPiiPlusCLibraryDemoDlg::OnBtnMoveinc() 
{
	UpdateData(TRUE);
	
	// If motor is moving state,
	if(m_MotorStatus[m_nSelectedAxisNo] & ACSC_MST_MOVE) return;

	// Move relative position (from current position)
	if(!acsc_ToPoint(m_hAcsComm, ACSC_AMF_RELATIVE, m_nSelectedAxisNo, m_dDistance, NULL)) 
	{
		ShowErrorMsg(_T("Move Decrement command error"));
	}
}

void CSPiiPlusCLibraryDemoDlg::OnBtnStop() 
{
	// Stop move (Normal operation)
	if(!acsc_Halt(m_hAcsComm, m_nSelectedAxisNo, NULL)) ShowErrorMsg(_T("Halt command error"));
	
	// Stop using kill deceleration
	//if(!acsc_Kill(m_hAcsComm, m_nSelectedAxisNo, NULL)) ShowErrorMsg(_T("Kill command error"));
}

void CSPiiPlusCLibraryDemoDlg::OnBtnStopall() 
{
	int Axes[MAX_AXIS_COUNT + 1];
	for (int i = 0; i < g_nTotalAxes; i++)
	{
		// Set all axes
		Axes[i] = i;
	}
	// Add '-1' at the last of array
	Axes[g_nTotalAxes] = -1;

	if(!acsc_HaltM(m_hAcsComm, Axes, NULL)) ShowErrorMsg(_T("HaltM command error"));
}

BOOL CSPiiPlusCLibraryDemoDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if(m_bConnected == FALSE) return CDialog::PreTranslateMessage(pMsg);

		UpdateData(TRUE);

		// Change motion paraters while moving
		if(pMsg->hwnd == GetDlgItem(IDC_EDT_VEL)->GetSafeHwnd())  { acsc_SetVelocityImm    (m_hAcsComm, m_nSelectedAxisNo, m_dVelocity, NULL);  }
		if(pMsg->hwnd == GetDlgItem(IDC_EDT_ACC)->GetSafeHwnd())  { acsc_SetAccelerationImm(m_hAcsComm, m_nSelectedAxisNo, m_dAcc, NULL);  }
		if(pMsg->hwnd == GetDlgItem(IDC_EDT_DEC)->GetSafeHwnd())  { acsc_SetDecelerationImm(m_hAcsComm, m_nSelectedAxisNo, m_dDec, NULL);  }
		if(pMsg->hwnd == GetDlgItem(IDC_EDT_JERK)->GetSafeHwnd()) { acsc_SetJerkImm       (m_hAcsComm, m_nSelectedAxisNo, m_dJerk, NULL);  }
		if(pMsg->hwnd == GetDlgItem(IDC_EDT_KDEC)->GetSafeHwnd()) { acsc_SetKillDecelerationImm(m_hAcsComm, m_nSelectedAxisNo, m_dKDec, NULL);  }

		// We have two functions for changing velocity as below
		//  - acsc_SetVelocity			If you send this command while moving the motor, the new velocity will be affected to the next motion
		//  - acsc_SetVelocityImm		Change immediately even the motor is moving

		if (pMsg->hwnd == GetDlgItem(IDC_EDT_COMMAND)->GetSafeHwnd())
		{
			OnBnClickedBtnSendCmd();
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CSPiiPlusCLibraryDemoDlg::OnKillfocusEdtVel() 
{	
	if(m_bConnected) 
	{ 
		UpdateData(TRUE); 
		acsc_SetVelocityImm(m_hAcsComm, m_nSelectedAxisNo, m_dVelocity, NULL); 
	}	
}

void CSPiiPlusCLibraryDemoDlg::OnKillfocusEdtAcc() 
{
	if(m_bConnected) 
	{ 
		UpdateData(TRUE); 
		acsc_SetAccelerationImm(m_hAcsComm, m_nSelectedAxisNo, m_dAcc, NULL); 
	}
}

void CSPiiPlusCLibraryDemoDlg::OnKillfocusEdtDec() 
{
	if(m_bConnected)
	{
		UpdateData(TRUE); 
		acsc_SetDecelerationImm(m_hAcsComm, m_nSelectedAxisNo, m_dDec, NULL);  
	}
}

void CSPiiPlusCLibraryDemoDlg::OnKillfocusEdtJerk() 
{
	if(m_bConnected) 
	{
		UpdateData(TRUE);
		acsc_SetJerkImm(m_hAcsComm, m_nSelectedAxisNo, m_dJerk, NULL);  
	}
}

void CSPiiPlusCLibraryDemoDlg::OnKillfocusEdtKdec() 
{
	if(m_bConnected) 
	{
		UpdateData(TRUE);
		acsc_SetKillDecelerationImm(m_hAcsComm, m_nSelectedAxisNo, m_dKDec, NULL); 
	}
}

void CSPiiPlusCLibraryDemoDlg::OnBtnBufferStart() 
{
	int ret;

	UpdateData(TRUE);

	if(m_bConnected)
	{
		// Run buffer program
		if(m_strLabelName.GetLength() > 0)
		{
			// Run buffer program from specific label name in the program
			ret = acsc_RunBuffer(m_hAcsComm, m_cboBufferNo.GetCurSel(), (char*)LPCTSTR(m_strLabelName), NULL);
		}
		else
		{
			// Run buffer program from first line
			ret = acsc_RunBuffer(m_hAcsComm, m_cboBufferNo.GetCurSel(), NULL, NULL);
		}

		if(ret == 0) ShowErrorMsg(_T("Run buffer command error"));
	}
}

void CSPiiPlusCLibraryDemoDlg::OnBtnBufferStop() 
{
	if(m_bConnected)
	{
		// Stop buffer program 
		// If you want to stop all programs, set second arguement value to '-1'
		acsc_StopBuffer(m_hAcsComm, m_cboBufferNo.GetCurSel(), NULL);
	}
}

//==================================================================================
// Motion End Callback
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::OnBtnCallbackMotionend() 
{
	int userParam = 1;
	if(m_bConnected) 
	{
		// We have two types of motion end.
		//  - ACSC_INTR_PHYSICAL_MOTION_END : by feedback position (SETTLE, TARGRAD)
		//  - ACSC_INTR_LOGICAL_MOTION_END : by AST
		if(!acsc_InstallCallback(m_hAcsComm, CallbackMotionEnd, &userParam, ACSC_INTR_PHYSICAL_MOTION_END)) ShowErrorMsg(_T("Callback Install error")); 
		else
			m_lstCallbackLog.AddString(_T("- Callback : Motion end installed"));
	}
}

int WINAPI CSPiiPlusCLibraryDemoDlg::CallbackMotionEnd(UINT64 Param, void *UserParameter)
{
	int MaskBit = 0x01;
	CString strTemp;

	for(int i = 0; i < g_nTotalAxes; i++)
	{
		if(Param & MaskBit)
		{
			strTemp.Format(_T("%d Axis is stop moving."), i);	
			thisDlg->m_lstCallbackLog.AddString(strTemp);
		}

		MaskBit = MaskBit << 1;
	}
	
	return 0;
}

//==================================================================================
// Program end callback
//  - This callback works after stopped normally. (if someone stop program by manually, this will not work)
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::OnBtnCallbackProgend() 
{
	int userParam = 1;
	if(m_bConnected) 
	{
		if(!acsc_InstallCallback(m_hAcsComm, CallbackProgramEnd, &userParam, ACSC_INTR_PROGRAM_END)) ShowErrorMsg(_T("Callback Install error")); 
		else
			m_lstCallbackLog.AddString(_T("- Callback : Program end installed"));
	}
}

int WINAPI CSPiiPlusCLibraryDemoDlg::CallbackProgramEnd(UINT64 Param, void *UserParameter)
{
	int MaskBit = 0x01;
	CString strTemp;

	for(int i = 0; i < 10; i++)
	{
		if(Param & MaskBit)
		{
			strTemp.Format(_T("%d Buffer is stop."), i);	
			thisDlg->m_lstCallbackLog.AddString(strTemp);
		}

		MaskBit = MaskBit << 1;
	}

	return 0;
}

//==================================================================================
// Input call back
//  - Not work in simutlation mode
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::OnBtnCallbackInput() 
{
	int userParam = 1;
	if(m_bConnected) 
	{
		if(!acsc_InstallCallback(m_hAcsComm, CallbackInput, &userParam, ACSC_INTR_INPUT)) ShowErrorMsg(_T("Callback Install error")); 
		else
			m_lstCallbackLog.AddString(_T("- Callback : Input installed"));
	}
}

int WINAPI CSPiiPlusCLibraryDemoDlg::CallbackInput(UINT64 Param, void *UserParameter)
{
	int MaskBit = 0x01;
	CString strTemp;

	for(int i = 0; i < 8; i++)
	{
		if(Param & MaskBit)
		{
			strTemp.Format(_T("Input No. %d is On."), i);	
			thisDlg->m_lstCallbackLog.AddString(strTemp);
		}

		MaskBit = MaskBit << 1;
	}

	return 0;
}

//==================================================================================
// JOG command
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::OnBtnJogNegative() 
{
	UpdateData(TRUE);
	if(m_bSetJogVelocity) 
	{
		// Jog command with velocity
		if(!acsc_Jog(m_hAcsComm, ACSC_AMF_VELOCITY, m_nSelectedAxisNo, m_dJogVelocity * (-1), NULL)) ShowErrorMsg(_T("Jog negative, velocity move command error"));
	}
	else
	{
		// Jog command without velocity
		if(!acsc_Jog(m_hAcsComm, 0, m_nSelectedAxisNo, ACSC_NEGATIVE_DIRECTION, NULL)) ShowErrorMsg(_T("Jog negative move command error")); 
	}
}

void CSPiiPlusCLibraryDemoDlg::OnBtnJogPositive() 
{
	UpdateData(TRUE);
	if(m_bSetJogVelocity) 
	{
		if(!acsc_Jog(m_hAcsComm, ACSC_AMF_VELOCITY, m_nSelectedAxisNo, m_dJogVelocity, NULL)) ShowErrorMsg(_T("Jog positive, velocity move command error"));
	}
	else 
	{
		if(!acsc_Jog(m_hAcsComm, 0, m_nSelectedAxisNo, ACSC_POSITIVE_DIRECTION, NULL)) ShowErrorMsg(_T("Jog positive move command error")); 
	}
}

//==================================================================================
// CONNECT example (Synchronize two or more axes)
//==================================================================================
// ACS COMMAND : CONNECT, DEPENDS function using APOS, RPOS formular
void CSPiiPlusCLibraryDemoDlg::OnBtnSyncSet() 
{
	char cmd[128] = {'\0'}; 
	int length = 0;
	int MasterAxis = m_cboMSAxis.GetCurSel();
	int SlaveAxis  = m_cboSLAxis.GetCurSel();

	// Reference axis is 0, Following axis is 1
	// ACSPL+ 
	// -------------------------------------------
	// MFLAGS(1).17 = 0				! DEFAULT : MFLAGS(1).17 = 1 ==> CONNECT RPOS(0) = APOS(0)
	// CONNECT RPOS(1) = APOS(0)	
	// DEPENDS 0, 1
	// ------------------------------------------
	length = sprintf(cmd, "MFLAGS(%d).17=0;CONNECT RPOS(%d)=APOS(%d);DEPENDS %d,%d\r", SlaveAxis, SlaveAxis, MasterAxis, SlaveAxis, MasterAxis);
	if(!acsc_Command(m_hAcsComm, cmd, length, NULL)) ShowErrorMsg(_T("acsc_Command() function error")); 
}

void CSPiiPlusCLibraryDemoDlg::OnBtnSyncRelease() 
{
	char cmd[128] = {'\0'}; 
	int length = 0;
	int SlaveAxis = m_cboSLAxis.GetCurSel();

	length = sprintf(cmd, "MFLAGS(%d).17=1\r", SlaveAxis);
	if(!acsc_Command(m_hAcsComm, cmd, length, NULL)) ShowErrorMsg(_T("acsc_Command() function error")); 
}

// Multi speed motion (using final velocity command)
// ACS COMMAND : PTP/VF		(Velocity, Final Velocity Option)
void CSPiiPlusCLibraryDemoDlg::OnBtnMoveMulspd() 
{
	UpdateData(TRUE);
	
	char Cmd[128] = { 0 };
	int length = 0;
	int AxisNo = m_cboMulSpdAxis.GetCurSel();

	// PTP command with '/F' (final velocity) option
	// Below example with 2 positions 
	// 
	// ACSPL+
	// -------------------------------------------
	// PTP/VF AxisNo, Velocity, FinalVelocity (NextSpeed)
	// PTP/VF AxisNo, NextSpeed, FinalVelocity  (NextSpeed)
	// .....	
	// -------------------------------------------
	// Example) Following command will be changed speed to 10 at position 100
	//       -------------  (Velocity = 100)
	//      /            |\
	//     /             | \
	//    /              |  \----- (Velocity = 10)
	// --/               |        \--- (Velocity = 0)
    //   |               |        |
	//   0              100      120
	// ACSPL+
	// -------------------------------------------
	// PTP/VF 0, 100, 100, 10	
	// PTP/VF 0, 120,  10,  0
	// -------------------------------------------
	// C-Library
	// -------------------------------------------
	//acsc_ExtToPoint(m_hAcsComm, ACSC_AMF_VELOCITY | ACSC_AMF_ENDVELOCITY, 0, 100, 100, 10, NULL);
	//acsc_ExtToPoint(m_hAcsComm, ACSC_AMF_VELOCITY | ACSC_AMF_ENDVELOCITY, 0, 120,  10,  0, NULL);
	// -------------------------------------------

	length = sprintf(Cmd, "PTP/vf %d,%lf,%lf,%lf;PTP/vf %d,%lf,%lf,0", AxisNo, m_lfPos1st, m_lfVel1st, m_lfVel2nd, AxisNo, m_lfPos2nd, m_lfVel2nd);
	if(!acsc_Command(m_hAcsComm, Cmd, length, NULL)) ShowErrorMsg(_T("acsc_Command() function error")); 
}

//==================================================================================
// Communication Terminal example
//==================================================================================
void CSPiiPlusCLibraryDemoDlg::OnBnClickedBtnSendCmd()
{
	HWND hWnd;
	CString strCommand;
	CString ret;

	int recvCnt = 0;
	char inBuf[32768] = { 0x0, };
	int lastError;
	int size = sizeof(inBuf);

	GetDlgItemText(IDC_EDT_COMMAND, strCommand);
	ret = "";
	strCommand.AppendChar('\r');

	if (m_bConnected)
	{
		AddString(strCommand);
		if(!acsc_Transaction(m_hAcsComm, (char*)LPCTSTR(strCommand), strCommand.GetLength(), inBuf, size, &recvCnt, NULL))
		{
			// Append error code to textbox
			lastError = acsc_GetLastError();
			ret.AppendFormat(_T("?%d\n"), lastError);
			AddString(ret);
		}
		else
		{
			AddString(inBuf);
		}

		AddString(":\n");
	}
	
	GetDlgItem(IDC_EDT_COMMAND, &hWnd);
	::PostMessage(hWnd, WM_SETFOCUS, 0, 0);
	::PostMessage(hWnd, EM_SETSEL, 0, -1);
}

void CSPiiPlusCLibraryDemoDlg::AddString(const CString& text)//const TCHAR *str)
{	
	m_redtCommandRet.SetSel(-1, -1);
	m_redtCommandRet.ReplaceSel(text);
	m_redtCommandRet.PostMessageA(WM_VSCROLL, SB_BOTTOM, 0);
}
