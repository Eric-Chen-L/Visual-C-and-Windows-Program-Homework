// ADD_DLG.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCDataControl0519.h"
#include "ADD_DLG.h"
#include "afxdialogex.h"


// ADD_DLG 对话框

IMPLEMENT_DYNAMIC(ADD_DLG, CDialogEx)

ADD_DLG::ADD_DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, sno(0)
	, point(0)
{

}

ADD_DLG::~ADD_DLG()
{
}

void ADD_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sno);
	DDX_Text(pDX, IDC_EDIT2, point);
}


BEGIN_MESSAGE_MAP(ADD_DLG, CDialogEx)
END_MESSAGE_MAP()


// ADD_DLG 消息处理程序
