
// MFC02View.cpp : CMFC02View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC02.h"
#endif

#include "MFC02Doc.h"
#include "MFC02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC02View

IMPLEMENT_DYNCREATE(CMFC02View, CView)

BEGIN_MESSAGE_MAP(CMFC02View, CView)
END_MESSAGE_MAP()

// CMFC02View 构造/析构

CMFC02View::CMFC02View()
{
	// TODO: 在此处添加构造代码

}

CMFC02View::~CMFC02View()
{
}

BOOL CMFC02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC02View 绘制

void CMFC02View::OnDraw(CDC* pDC)
{
	CMFC02Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDoc->S.Format(pDoc->S + "%d", pDoc->A);
	pDC->TextOutW(200, 200,pDoc->S);
}


// CMFC02View 诊断

#ifdef _DEBUG
void CMFC02View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC02View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC02Doc* CMFC02View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC02Doc)));
	return (CMFC02Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC02View 消息处理程序
