
// MFC_20200309_2View.h : CMFC_20200309_2View 类的接口
//

#pragma once


class CMFC_20200309_2View : public CView
{
protected: // 仅从序列化创建
	CMFC_20200309_2View();
	DECLARE_DYNCREATE(CMFC_20200309_2View)

// 特性
public:
	CMFC_20200309_2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC_20200309_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CArray<CRect, CRect&> ca;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC_20200309_2View.cpp 中的调试版本
inline CMFC_20200309_2Doc* CMFC_20200309_2View::GetDocument() const
   { return reinterpret_cast<CMFC_20200309_2Doc*>(m_pDocument); }
#endif

