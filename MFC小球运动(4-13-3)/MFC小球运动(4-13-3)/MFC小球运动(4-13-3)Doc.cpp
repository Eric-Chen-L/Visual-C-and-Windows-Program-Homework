
// MFC小球运动(4-13-3)Doc.cpp : CMFC小球运动4133Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC小球运动(4-13-3).h"
#endif

#include "MFC小球运动(4-13-3)Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFC小球运动4133Doc

IMPLEMENT_DYNCREATE(CMFC小球运动4133Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFC小球运动4133Doc, CDocument)
END_MESSAGE_MAP()


// CMFC小球运动4133Doc 构造/析构

CMFC小球运动4133Doc::CMFC小球运动4133Doc()
{
	// TODO: 在此添加一次性构造代码

}

CMFC小球运动4133Doc::~CMFC小球运动4133Doc()
{
}

BOOL CMFC小球运动4133Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFC小球运动4133Doc 序列化

void CMFC小球运动4133Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMFC小球运动4133Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMFC小球运动4133Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMFC小球运动4133Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFC小球运动4133Doc 诊断

#ifdef _DEBUG
void CMFC小球运动4133Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC小球运动4133Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFC小球运动4133Doc 命令
