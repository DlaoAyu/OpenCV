
// DIP190853203Dlg.h: 头文件
//

#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
//由于opencv4+无法正常执行cvGetWindowHandle所引入

using namespace cv;
//using namespace std;

// CDIP190853203Dlg 对话框
class CDIP190853203Dlg : public CDialogEx
{
// 构造
public:
	CDIP190853203Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIP190853203_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	Mat src;

	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedVideo();
	int m_width;
	int m_height;
	afx_msg void OnBnClickedResize();
	double m_angle;
	afx_msg void OnBnClickedRotate();
	double m_shearRatio;
	afx_msg void OnBnClickedHshear();
	afx_msg void OnBnClickedVshear();
	int m_a;
	int m_b;
	int m_ga;
	int m_gb;
	afx_msg void OnBnClickedLinear();
	afx_msg void OnBnClickedNonlinear();
	afx_msg void OnBnClickedHisteq();
	int m_pseudoMode;
	afx_msg void OnBnClickedPseudo();
	int m_kernalSize;
	int m_filterType;
	afx_msg void OnBnClickedSmooth();
	int m_sharpType;
	afx_msg void OnBnClickedSharp();
	int m_th;
	afx_msg void OnBnClickedThre();
	int m_blockSize;
	int m_bias;
	afx_msg void OnBnClickedAdthre();
	int m_seedX;
	int m_seedY;
	int m_regionTh;
	afx_msg void OnBnClickedRegiongrow();
	int m_fSeedX;
	int m_fSeedY;
	int m_fTh;
	afx_msg void OnBnClickedFlood();
	afx_msg void OnBnClickedErode();
	afx_msg void OnBnClickedDilate();
	afx_msg void OnBnClickedOpenoperation();
	afx_msg void OnBnClickedClosedoperation();
	afx_msg void OnBnClickedColorconversion();
	afx_msg void OnBnClickedWhite();
};
