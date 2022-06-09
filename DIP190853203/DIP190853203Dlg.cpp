
// DIP190853203Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "DIP190853203.h"
#include "DIP190853203Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace cv;
using namespace std;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDIP190853203Dlg 对话框



CDIP190853203Dlg::CDIP190853203Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIP190853203_DIALOG, pParent)
	, m_width(0)
	, m_height(0)
	, m_angle(0)
	, m_shearRatio(0)
	, m_a(0)
	, m_b(0)
	, m_ga(0)
	, m_gb(0)
	, m_pseudoMode(0)
	, m_kernalSize(3)
	, m_filterType(0)
	, m_sharpType(0)
	, m_th(0)
	, m_blockSize(0)
	, m_bias(0)
	, m_seedX(0)
	, m_seedY(0)
	, m_regionTh(0)
	, m_fSeedX(0)
	, m_fSeedY(0)
	, m_fTh(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDIP190853203Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_width);
	DDX_Text(pDX, IDC_EDIT2, m_height);
	DDX_Text(pDX, IDC_EDIT3, m_angle);
	DDX_Text(pDX, IDC_EDIT4, m_shearRatio);
	DDX_Text(pDX, IDC_EDIT5, m_a);
	DDX_Text(pDX, IDC_EDIT6, m_b);
	DDX_Text(pDX, IDC_EDIT7, m_ga);
	DDX_Text(pDX, IDC_EDIT8, m_gb);
	DDX_Radio(pDX, IDC_RADIO1, m_pseudoMode);
	DDX_Text(pDX, IDC_EDIT9, m_kernalSize);
	DDX_Radio(pDX, IDC_RADIO3, m_filterType);
	DDX_Radio(pDX, IDC_RADIO6, m_sharpType);
	DDX_Text(pDX, IDC_EDIT10, m_th);
	DDX_Text(pDX, IDC_EDIT11, m_blockSize);
	DDX_Text(pDX, IDC_EDIT12, m_bias);
	DDX_Text(pDX, IDC_EDIT13, m_seedX);
	DDX_Text(pDX, IDC_EDIT14, m_seedY);
	DDX_Text(pDX, IDC_EDIT15, m_regionTh);
	DDX_Text(pDX, IDC_EDIT16, m_fSeedX);
	DDX_Text(pDX, IDC_EDIT17, m_fSeedY);
	DDX_Text(pDX, IDC_EDIT18, m_fTh);
}

BEGIN_MESSAGE_MAP(CDIP190853203Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN, &CDIP190853203Dlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_VIDEO, &CDIP190853203Dlg::OnBnClickedVideo)
	ON_BN_CLICKED(IDC_RESIZE, &CDIP190853203Dlg::OnBnClickedResize)
	ON_BN_CLICKED(IDC_ROTATE, &CDIP190853203Dlg::OnBnClickedRotate)
	ON_BN_CLICKED(IDC_HSHEAR, &CDIP190853203Dlg::OnBnClickedHshear)
	ON_BN_CLICKED(IDC_VSHEAR, &CDIP190853203Dlg::OnBnClickedVshear)
	ON_BN_CLICKED(IDC_LINEAR, &CDIP190853203Dlg::OnBnClickedLinear)
	ON_BN_CLICKED(IDC_NONLINEAR, &CDIP190853203Dlg::OnBnClickedNonlinear)
	ON_BN_CLICKED(IDC_HISTEQ, &CDIP190853203Dlg::OnBnClickedHisteq)
	ON_BN_CLICKED(IDC_PSEUDO, &CDIP190853203Dlg::OnBnClickedPseudo)
	ON_BN_CLICKED(IDC_SMOOTH, &CDIP190853203Dlg::OnBnClickedSmooth)
	ON_BN_CLICKED(IDC_SHARP, &CDIP190853203Dlg::OnBnClickedSharp)
	ON_BN_CLICKED(IDC_THRE, &CDIP190853203Dlg::OnBnClickedThre)
	ON_BN_CLICKED(IDC_ADTHRE, &CDIP190853203Dlg::OnBnClickedAdthre)
	ON_BN_CLICKED(IDC_REGIONGROW, &CDIP190853203Dlg::OnBnClickedRegiongrow)
	ON_BN_CLICKED(IDC_FLOOD, &CDIP190853203Dlg::OnBnClickedFlood)
	ON_BN_CLICKED(IDC_ERODE, &CDIP190853203Dlg::OnBnClickedErode)
	ON_BN_CLICKED(IDC_DILATE, &CDIP190853203Dlg::OnBnClickedDilate)
	ON_BN_CLICKED(IDC_OPENOPERATION, &CDIP190853203Dlg::OnBnClickedOpenoperation)
	ON_BN_CLICKED(IDC_CLOSEDOPERATION, &CDIP190853203Dlg::OnBnClickedClosedoperation)
	ON_BN_CLICKED(IDC_COLORCONVERSION, &CDIP190853203Dlg::OnBnClickedColorconversion)
	ON_BN_CLICKED(IDC_WHITE, &CDIP190853203Dlg::OnBnClickedWhite)
END_MESSAGE_MAP()


// CDIP190853203Dlg 消息处理程序

BOOL CDIP190853203Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	namedWindow("view");

	HWND hWnd = (HWND)cvGetWindowHandle("view");
	HWND hParent = ::GetParent(hWnd);

	::SetParent(hWnd, GetDlgItem(IDC_PIC)->m_hWnd);

	::ShowWindow(hParent, SW_HIDE);//隐藏运行程序框

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDIP190853203Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDIP190853203Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDIP190853203Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDIP190853203Dlg::OnBnClickedOpen()
{
	// TODO: 在此添加控件通知处理程序代码

	//Mat src = imread("D:\\图片\\retouch_20210224194128.jpg"); //载入图像到test

	//namedWindow("test");

	CFileDialog dlg(TRUE, _T("*.jpg"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST,
		_T("All files(*.*)|*.*|Image files(*.bmp,*.jpg)|*.bmp;*.jpg"), NULL);

	dlg.m_ofn.lpstrTitle = _T("打开图片");

	if (dlg.DoModal() != IDOK)
	{
		return;
	}

	CString filePath = dlg.GetPathName();

	string sFileName = (LPCTSTR)filePath;

	src = imread(sFileName);

	if (src.empty())
	{
		AfxMessageBox("图片打开出错！");
		return;
	}
	else
	{
		CRect rect;
		GetDlgItem(IDC_PIC)->GetClientRect(&rect);

		Mat img;

		resize(src, img, Size(rect.Width(), rect.Height()));
		imshow("view", img);
		//waitKey(0);
	}

	
}


void CDIP190853203Dlg::OnBnClickedVideo()
{
	// TODO: 在此添加控件通知处理程序代码

	CFileDialog dlg(TRUE, _T("*.avi"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST,
		_T("All files(*.*)|*.*|Video files(*.avi)|*.avi"), NULL);

	dlg.m_ofn.lpstrTitle = _T("打开视频");

	if (dlg.DoModal() != IDOK)
	{
		return;
	}

	CString filePath = dlg.GetPathName();
	string sFileName = (LPCTSTR)filePath;

	VideoCapture capture;
	int re = capture.open(sFileName);
	if (!re)
	{
		AfxMessageBox("视频无法打开！");
		return;
	}

	CRect rect;
	GetDlgItem(IDC_PIC)->GetClientRect(&rect);
	Mat vid;
	Mat frame;
	while (1)
	{
		capture >> frame;
		if (frame.empty())
		{
			//AfxMessageBox(_T("视频播放出现错误！"));
			return;
		}
		else
		{
			resize(frame, vid, Size(rect.Width(), rect.Height()));
			imshow("view", vid);
			waitKey(10);
		}
	}

}


void CDIP190853203Dlg::OnBnClickedResize()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	Mat dst;

	resize(src, dst, Size(m_width, m_height));

	imshow("resize缩放", dst);
}


void CDIP190853203Dlg::OnBnClickedRotate()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	Mat rot_mat(2, 3, CV_32FC1);//旋转矩阵
	Mat dst;

	//计算选装之后画布大小
	double sin_value = sin(m_angle * CV_PI / 180);
	double cos_value = cos(m_angle * CV_PI / 180);

	int width = src.cols;
	int height = src.rows;

	int rotate_width = (int)(height * fabs(sin_value) + width * fabs(cos_value));
	int rotate_height = (int)(width * fabs(sin_value) + height * fabs(cos_value));

	//计算旋转矩阵
	Point center = Point(src.cols / 2, src.rows / 2);
	double angle = m_angle;
	double scale = 1;

	rot_mat = getRotationMatrix2D(center, angle, scale);

	//计算平移量
	rot_mat.at<double>(0, 2) += (rotate_width - width) / 2;
	rot_mat.at<double>(1, 2) += (rotate_height - height) / 2;

	//利用仿射变换进行旋转
	warpAffine(src, dst, rot_mat, Size(rotate_width, rotate_height));

	imshow("rotate旋转", dst);


}


void CDIP190853203Dlg::OnBnClickedHshear()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	Mat dst;

	Mat hShear_mat(2, 3, CV_32FC1);//水平错切矩阵

	Point2f srcPoints[3];//原图像中的三个点
	Point2f dstPoints[3];//目标图像中的三个点

	//原图像的点
	srcPoints[0] = Point2f(0, 0);//左上角
	srcPoints[1] = Point2f(0, src.rows);//左下角
	srcPoints[2] = Point2f(src.cols, 0);//右上角

	//目标图像的点
	if (m_shearRatio >= 0)
	{
		dstPoints[0] = Point2f(src.rows * m_shearRatio, 0);//左上角
		dstPoints[1] = Point2f(0, src.rows);//左下角
		dstPoints[2] = Point2f(src.cols + src.rows * m_shearRatio, 0);//右上角
	}
	else
	{
		dstPoints[0] = Point2f(0, 0);//左上角
		dstPoints[1] = Point2f(src.rows * (-m_shearRatio), src.rows);//左下角
		dstPoints[2] = Point2f(src.cols , 0);//右上角
	}

	hShear_mat = getAffineTransform(srcPoints, dstPoints);//通过三个点对计算变换矩阵

	//计算变换后的画布大小
	int dst_width = src.cols + src.rows * fabs(m_shearRatio);
	int dst_height = src.rows;

	warpAffine(src, dst, hShear_mat, Size(dst_width, dst_height));

	imshow("hshear水平错切", dst);
}


void CDIP190853203Dlg::OnBnClickedVshear()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	Mat dst;

	Mat hShear_mat(2, 3, CV_32FC1);//水平错切矩阵

	Point2f srcPoints[3];//原图像中的三个点
	Point2f dstPoints[3];//目标图像中的三个点

	//原图像的点
	srcPoints[0] = Point2f(0, 0);//左上角
	srcPoints[1] = Point2f(0, src.rows);//左下角
	srcPoints[2] = Point2f(src.cols, 0);//右上角

	//目标图像的点
	if (m_shearRatio >= 0)
	{
		dstPoints[0] = Point2f(0, 0);//左上角
		dstPoints[1] = Point2f(0, src.rows);//左下角
		dstPoints[2] = Point2f(src.cols, src.cols * m_shearRatio);//右上角
	}
	else
	{
		dstPoints[0] = Point2f(0, src.rows * (-m_shearRatio));//左上角
		dstPoints[1] = Point2f(0, src.rows + src.rows * (-m_shearRatio));//左下角
		dstPoints[2] = Point2f(src.cols, 0);//右上角
	}

	hShear_mat = getAffineTransform(srcPoints, dstPoints);//通过三个点对计算变换矩阵

	//计算变换后的画布大小
	int dst_width = src.cols;
	int dst_height = src.rows + src.rows * fabs(m_shearRatio);

	warpAffine(src, dst, hShear_mat, Size(dst_width, dst_height));

	imshow("vshear垂直错切", dst);
}


void CDIP190853203Dlg::OnBnClickedLinear()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst;
	cvtColor(src, g_src, CV_BGR2GRAY);
	dst.create(src.size(), g_src.type());

	UpdateData(TRUE);

	if (m_a < 0 || m_b>255 || m_ga < 0 || m_gb>255)
	{
		AfxMessageBox(_T("输入的灰度范围有误！"));
		return;
	}

	for (int i = 0; i < g_src.rows; i++)
	{
		for (int j = 0; j < g_src.cols; j++)
		{
			int tmp = g_src.at<uchar>(i, j);

			if (tmp < m_a)
			{
				dst.at<uchar>(i, j) = tmp * m_ga / m_a;
			}
			else if (tmp < m_b)
			{
				dst.at<uchar>(i, j) = (tmp - m_a) * (m_ga - m_gb) / (m_b - m_a) + m_ga;
			}
			else
			{
				dst.at<uchar>(i, j) = (tmp - m_gb) * (255 - m_gb) / (255 - m_b) + m_gb;
			}
		}
	}

	imshow("线性对比度展宽",dst);
	 
}


void CDIP190853203Dlg::OnBnClickedNonlinear()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst;
	cvtColor(src, g_src, CV_BGR2GRAY);
	dst.create(src.size(), g_src.type());

	for (int i = 0; i < g_src.rows; i++)
	{
		for (int j = 0; j < g_src.cols; j++)
		{
			int tmp = g_src.at<uchar>(i, j);

			dst.at<uchar>(i, j) = tmp * log10((float)(1 + tmp));
		}
	}

	imshow("非线性动态范围调整", dst);

}


void CDIP190853203Dlg::OnBnClickedHisteq()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst;
	cvtColor(src, g_src, CV_BGR2GRAY);
	dst.create(src.size(), g_src.type());

	equalizeHist(g_src, dst);

	imshow("直方图均衡", dst);
}


void CDIP190853203Dlg::OnBnClickedPseudo()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst;
	//int lut[256];
	cvtColor(src, g_src, CV_BGR2GRAY);
	dst.create(src.size(), CV_8UC3); 

	UpdateData(TRUE);

	switch (m_pseudoMode)
	{
	case 0://密度分层法
		for (int i = 0; i < g_src.rows; i++)
		{
			for (int j = 0; j < g_src.cols; j++)
			{
				int tmp = g_src.at<uchar>(i, j);

				if (tmp < 64)
				{
					dst.at<Vec3b>(i, j)[0] = 255;	//蓝色分量
					dst.at<Vec3b>(i, j)[1] = 0;	//绿色分量
					dst.at<Vec3b>(i, j)[2] = 255;	//红色分量
				}
				else if (tmp < 128)
				{
					dst.at<Vec3b>(i, j)[0] = 255;	//蓝色分量
					dst.at<Vec3b>(i, j)[1] = 0;	//绿色分量
					dst.at<Vec3b>(i, j)[2] = 0;	//红色分量
				}
				else if (tmp < 192)
				{
					dst.at<Vec3b>(i, j)[0] = 0;	//蓝色分量
					dst.at<Vec3b>(i, j)[1] = 255;	//绿色分量
					dst.at<Vec3b>(i, j)[2] = 0;	//红色分量
				}
				else
				{
					dst.at<Vec3b>(i, j)[0] = 0;	//蓝色分量
					dst.at<Vec3b>(i, j)[1] = 255;	//绿色分量
					dst.at<Vec3b>(i, j)[2] = 255;	//红色分量
				}
			}
		}
		break;
	case 1://灰度变换法
		for (int i = 0; i < g_src.rows; i++)
		{
			for (int j = 0; j < g_src.cols; j++)
			{
				int tmp = g_src.at<uchar>(i, j);

				if (tmp < 64)
				{
					dst.at<Vec3b>(i, j)[0] = 255;	//蓝色分量
					dst.at<Vec3b>(i, j)[1] = tmp * 256 / 64;	//绿色分量
					dst.at<Vec3b>(i, j)[2] = 0;	//红色分量
				}
				else if (tmp < 128)
				{
					dst.at<Vec3b>(i, j)[0] = (127 - tmp) * 4;	//蓝色分量
					dst.at<Vec3b>(i, j)[1] = 255;	//绿色分量
					dst.at<Vec3b>(i, j)[2] = 0;	//红色分量
				}
				else if(tmp < 192)
				{
					dst.at<Vec3b>(i, j)[0] = 0;	//蓝色分量
					dst.at<Vec3b>(i, j)[1] = 255;	//绿色分量
					dst.at<Vec3b>(i, j)[2] = (tmp - 127) * 4;	//红色分量
				}
				else
				{
					dst.at<Vec3b>(i, j)[0] = 0;	//蓝色分量
					dst.at<Vec3b>(i, j)[1] = (255 - tmp) * 4;	//绿色分量
					dst.at<Vec3b>(i, j)[2] = 255;	//红色分量
				}
			}
		}	
		break;
	}
	imshow("伪彩色增强", dst);
}


void CDIP190853203Dlg::OnBnClickedSmooth()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst;
	cvtColor(src, g_src, CV_BGR2GRAY);
	dst.create(src.size(), CV_8UC1); 

	UpdateData(TRUE);

	if (m_kernalSize <= 0 || m_kernalSize % 2 == 0)
	{
		AfxMessageBox("窗口大小错误！");
		return;
	}

	switch (m_filterType)
	{
	case 0:
		//均值滤波
		blur(g_src, dst, Size(m_kernalSize, m_kernalSize));
		imshow("均值滤波",dst);
		break;

	case 1:
		//中值滤波
		medianBlur(g_src, dst, m_kernalSize);
		imshow("中值滤波", dst);
		break;

	case 2:
		//高斯滤波
		GaussianBlur(g_src, dst, Size(m_kernalSize, m_kernalSize), 0, 0);
		imshow("高斯滤波", dst);
		break;

	}

}


void CDIP190853203Dlg::OnBnClickedSharp()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst;
	cvtColor(src, g_src, CV_BGR2GRAY);
	dst.create(src.size(), CV_8UC1);

	UpdateData(TRUE);

	Mat grad_x, grad_y,abs_grad_x,abs_grad_y,grad;
	Mat kernal;

	switch (m_sharpType)
	{
	case 0://Sobel
		//X方向的梯度
		Sobel(g_src, grad_x, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(grad_x, abs_grad_x);

		//Y方向的梯度
		Sobel(g_src, grad_y, CV_16S, 0, 1, 3, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(grad_y, abs_grad_y);

		//合并梯度(近似求法)
		addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
		
		imshow("Sobel", dst);

		break;

	case 1:
		//Laplacian
		Laplacian(g_src, grad, CV_16S, 3, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(grad, dst);

		imshow("Laplacian", dst);

		break;

	case 2://自定义Laplacian
		kernal = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
		filter2D(g_src, dst, CV_8UC1, kernal);

		imshow("自定义Laplacian", dst);

		break;

	}

}


void CDIP190853203Dlg::OnBnClickedThre()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst;
	cvtColor(src, g_src, CV_BGR2GRAY);
	dst.create(src.size(), CV_8UC1);

	UpdateData(TRUE);

	if (m_th < 0 || m_th>255)
	{
		AfxMessageBox(_T("阈值设定错误！"));
		return;
	}

	threshold(g_src,dst,m_th,255,CV_THRESH_BINARY);

	imshow("固定阈值", dst);
}


void CDIP190853203Dlg::OnBnClickedAdthre()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst;
	cvtColor(src, g_src, CV_BGR2GRAY);
	dst.create(src.size(), CV_8UC1);

	UpdateData(TRUE);

	if (m_blockSize % 2 == 0)
		m_blockSize++;
	adaptiveThreshold(g_src, dst, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, m_blockSize, m_bias);

	imshow("动态阈值", dst);
}


void CDIP190853203Dlg::OnBnClickedRegiongrow()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst;
	cvtColor(src, g_src, CV_BGR2GRAY);
	//dst.create(src.size(), CV_8UC1);

	dst = Mat::zeros(g_src.size(), CV_8UC1);

	UpdateData(TRUE);

	if (m_seedX<0 || m_seedX>(src.rows - 1) || m_seedY<0 || m_seedY >(src.cols - 1))
	{
		AfxMessageBox("种子坐标错误！");
		return;
	}

	Point2i pt(m_seedY, m_seedX);//种子点

	int th = m_regionTh;

	Point2i ptGrowing;//待上涨点坐标
	int nGowLable = 0;//标记是否生长过
	int nSrcValue = 0;//生长起点灰度值
	int nCurValue = 0;//当前待生长点的灰度值

	//8邻域点
	int DIR[8][2] = { {-1,-1} ,{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1} };

	std::vector<Point2i>vcGrowPt;//生长点栈

	vcGrowPt.push_back(pt);//种子点入栈

	dst.at<uchar>(pt.y, pt.x) = 255;

	nSrcValue = g_src.at<uchar>(pt.y, pt.x);//记录种子点的灰度值

	while (!vcGrowPt.empty())
	{
		pt = vcGrowPt.back();//取生长点
		vcGrowPt.pop_back();

		//判断8邻域点是否生长
		for (int i = 0; i < 8; i++)
		{
			ptGrowing.x = pt.x + DIR[i][0];
			ptGrowing.y = pt.y + DIR[i][1];

			//检查边缘点
			if (ptGrowing.x<0 || ptGrowing.x>(src.cols - 1) || ptGrowing.y<0 || ptGrowing.y >(src.rows - 1))
			{
				continue;
			}

			nGowLable = dst.at<uchar>(ptGrowing.y, ptGrowing.x);//判断待生长点的灰度值

			if (nGowLable == 0)
			{
				nCurValue = g_src.at<uchar>(ptGrowing.y, ptGrowing.x);
				if (abs(nCurValue - nSrcValue) < th)
				{
					dst.at<uchar>(ptGrowing.y, ptGrowing.x) = 255;//满足条件，设置为白色
					vcGrowPt.push_back(ptGrowing);//生长点入栈
				}
			}
		}
	}
	imshow("region区域生长", dst);
}


void CDIP190853203Dlg::OnBnClickedFlood()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}
	Mat dst;

	dst = src.clone();

	UpdateData(TRUE);

	if (m_seedX<0 || m_seedX>(src.rows - 1) || m_seedY<0 || m_seedY >(src.cols - 1))
	{
		AfxMessageBox("种子坐标错误！");
		return;
	}

	Point2i pt(m_fSeedY, m_fSeedX);//种子点

	int th = m_fTh;

	Rect ccomp;
	floodFill(dst, pt, Scalar(255, 0, 255), &ccomp, Scalar(th, th, th), Scalar(th, th, th));

	imshow("flood漫水分割",dst);
}


void CDIP190853203Dlg::OnBnClickedErode()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst;
	cvtColor(src, g_src, CV_BGR2GRAY);
	dst.create(src.size(), CV_8UC1);

	UpdateData(TRUE);

	Mat ele = getStructuringElement(MORPH_RECT, Size(5, 5));
	erode(g_src, dst, ele);

	imshow("腐蚀",dst);
}


void CDIP190853203Dlg::OnBnClickedDilate()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst;
	cvtColor(src, g_src, CV_BGR2GRAY);
	dst.create(src.size(), CV_8UC1);

	UpdateData(TRUE);

	Mat ele = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(g_src, dst, ele);

	imshow("膨胀", dst);
}


void CDIP190853203Dlg::OnBnClickedOpenoperation()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst, tmp;
	cvtColor(src, g_src, CV_BGR2GRAY);
	dst.create(src.size(), CV_8UC1);

	UpdateData(TRUE);

	Mat ele = getStructuringElement(MORPH_RECT, Size(5, 5));
	erode(g_src, tmp, ele);
	dilate(g_src, dst, ele);

	imshow("开运算", dst);
}


void CDIP190853203Dlg::OnBnClickedClosedoperation()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst, tmp;
	cvtColor(src, g_src, CV_BGR2GRAY);
	dst.create(src.size(), CV_8UC1);

	UpdateData(TRUE);

	Mat ele = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(g_src, tmp, ele);
	erode(g_src, dst, ele);

	imshow("闭运算", dst);
}


void CDIP190853203Dlg::OnBnClickedColorconversion()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat dst;
	Mat image_HSV, image_XYZ, image_YCrCb, image_hsvtrgb;
	cvtColor(src, image_HSV, CV_BGR2HSV);
	cvtColor(src, image_XYZ, CV_BGR2XYZ);
	cvtColor(src, image_YCrCb, CV_BGR2YCrCb);
	//dst.create(src.size(), CV_8UC1);

	UpdateData(TRUE);

	imshow("RGB TO HSV", image_HSV);
	imshow("HSV TO XYZ", image_XYZ);
	imshow("RGB TO YCrCb", image_YCrCb);

}


void CDIP190853203Dlg::OnBnClickedWhite()
{
	// TODO: 在此添加控件通知处理程序代码
	if (src.empty())
	{
		AfxMessageBox(_T("请先打开图像！"));
		return;
	}

	Mat g_src, dst, tmp;
	//cvtColor(src, g_src, CV_BGR2GRAY);

	std::vector<Mat>channels(3);
	split(src, channels);

	double R, G, B;
	B = mean(channels[0])[0];
	G = mean(channels[1])[0];
	R = mean(channels[2])[0];

	double KR, KG, KB;
	KB = (R + G + B) / (3 * B);
	KG = (R + G + B) / (3 * G);
	KR = (R + G + B) / (3 * R);

	channels[0] = channels[0] * KB;
	channels[1] = channels[1] * KG;
	channels[2] = channels[2] * KR;

	merge(channels, dst);

	imshow("白平衡", dst);


}
