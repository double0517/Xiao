
// XiaoDlg.cpp : ÊµÏÖÎÄ¼ş
//

#include "stdafx.h"
#include "Xiao.h"
#include "XiaoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ÓÃÓÚÓ¦ÓÃ³ÌĞò¡°¹ØÓÚ¡±²Ëµ¥ÏîµÄ CAboutDlg ¶Ô»°¿ò

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ¶Ô»°¿òÊı¾İ
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Ö§³Ö

// ÊµÏÖ
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CXiaoDlg ¶Ô»°¿ò




CXiaoDlg::CXiaoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CXiaoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXiaoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CXiaoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CXiaoDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CXiaoDlg ÏûÏ¢´¦Àí³ÌĞò

BOOL CXiaoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ½«¡°¹ØÓÚ...¡±²Ëµ¥ÏîÌí¼Óµ½ÏµÍ³²Ëµ¥ÖĞ¡£

	// IDM_ABOUTBOX ±ØĞëÔÚÏµÍ³ÃüÁî·¶Î§ÄÚ¡£
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ÉèÖÃ´Ë¶Ô»°¿òµÄÍ¼±ê¡£µ±Ó¦ÓÃ³ÌĞòÖ÷´°¿Ú²»ÊÇ¶Ô»°¿òÊ±£¬¿ò¼Ü½«×Ô¶¯
	//  Ö´ĞĞ´Ë²Ù×÷
	SetIcon(m_hIcon, TRUE);			// ÉèÖÃ´óÍ¼±ê
	SetIcon(m_hIcon, FALSE);		// ÉèÖÃĞ¡Í¼±ê

	// TODO: ÔÚ´ËÌí¼Ó¶îÍâµÄ³õÊ¼»¯´úÂë

	return TRUE;  // ³ı·Ç½«½¹µãÉèÖÃµ½¿Ø¼ş£¬·ñÔò·µ»Ø TRUE
}

void CXiaoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Èç¹ûÏò¶Ô»°¿òÌí¼Ó×îĞ¡»¯°´Å¥£¬ÔòĞèÒªÏÂÃæµÄ´úÂë
//  À´»æÖÆ¸ÃÍ¼±ê¡£¶ÔÓÚÊ¹ÓÃÎÄµµ/ÊÓÍ¼Ä£ĞÍµÄ MFC Ó¦ÓÃ³ÌĞò£¬
//  Õâ½«ÓÉ¿ò¼Ü×Ô¶¯Íê³É¡£

void CXiaoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ÓÃÓÚ»æÖÆµÄÉè±¸ÉÏÏÂÎÄ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ê¹Í¼±êÔÚ¹¤×÷Çø¾ØĞÎÖĞ¾ÓÖĞ
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// »æÖÆÍ¼±ê
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//µ±ÓÃ»§ÍÏ¶¯×îĞ¡»¯´°¿ÚÊ±ÏµÍ³µ÷ÓÃ´Ëº¯ÊıÈ¡µÃ¹â±ê
//ÏÔÊ¾¡£
HCURSOR CXiaoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CXiaoDlg::OnBnClickedButton1()
{
	// TODO: ï¿½Ú´ï¿½ï¿½ï¿½Ó¿Ø¼ï¿½Í¨Öªï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
}
