
// MFC键盘输入_2View.cpp : CMFC键盘输入_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC键盘输入_2.h"
#endif

#include "MFC键盘输入_2Doc.h"
#include "MFC键盘输入_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC键盘输入_2View

IMPLEMENT_DYNCREATE(CMFC键盘输入_2View, CView)

BEGIN_MESSAGE_MAP(CMFC键盘输入_2View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC键盘输入_2View 构造/析构

CMFC键盘输入_2View::CMFC键盘输入_2View()
{
	// TODO: 在此处添加构造代码
	mo = 504;
	c_width = c_height = 0;
	flag = 0;
	line = 1;
	h = l = 0;
	num = min = left = leftNum = 0;
	r.left = 20; r.right = 524;
	r.top = 60; r.bottom = 80;
	p.SetPoint(-1, -1);
	
}

CMFC键盘输入_2View::~CMFC键盘输入_2View()
{
}

BOOL CMFC键盘输入_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC键盘输入_2View 绘制

void CMFC键盘输入_2View::OnDraw(CDC* pDC)
{
	CMFC键盘输入_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(r);
	CClientDC dc(this);
	CSize size = dc.GetTextExtent(s);
	c_width = size.cx, c_height = size.cy;
	CString s1 = _T("（只针对数字输入或者是相同像素大小的字符）单击左键进行插入、单击右键恢复正常输入");
	dc.TextOutW(0, 20, s1);
	if (!s.IsEmpty()) {
		line = c_width / mo;
		min = c_width / s.GetLength();
		left = c_width % mo;
		leftNum = left / min;
		num = mo / min;
		if (left != 0) line++;
		if (c_width < mo) {
			dc.TextOutW(20, 60, s);
		}
		else {
			for (int i = 1; i <= line; i++) {
				if (i == 1) {
					CString ss = s.Left(num);
					dc.TextOutW(20, 60 , ss);
				}
				else if (i<line) {
					CString ss = s.Mid(num*(i - 1), num);
					dc.TextOutW(20, 60 + (i - 1)*c_height, ss);
				}
				else {
					CString ss;
					if (leftNum == 0)
						ss = s.Right(num);
					else
						ss = s.Right(leftNum);
					dc.TextOutW(20, 60 + (i - 1)*c_height, ss);
				}
			}
		}
		r.SetRect(20, 60, mo+20, 60 + c_height*line);
		CBrush *OldBrush;
		OldBrush = (CBrush*)dc.SelectStockObject(NULL_BRUSH);//创建一个不填充的画刷
		dc.Rectangle(r);
		dc.SelectObject(OldBrush);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC键盘输入_2View 诊断

#ifdef _DEBUG
void CMFC键盘输入_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC键盘输入_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC键盘输入_2Doc* CMFC键盘输入_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC键盘输入_2Doc)));
	return (CMFC键盘输入_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC键盘输入_2View 消息处理程序


void CMFC键盘输入_2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	char ch = (char)nChar;
	if (flag == 0)
		s += (TCHAR)nChar;
	else {
		s.Insert(h*num + l, ch);
	}
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC键盘输入_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 1;
	CPoint insert = point;
	int len = s.GetLength();
	h = (insert.y - 60) / c_height;//插入行的位置
	l = (insert.x - 20) / (c_width / len); //计算列的的位置
	CView::OnLButtonDown(nFlags, point);
}


void CMFC键盘输入_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 0;
	CView::OnRButtonDown(nFlags, point);
}
