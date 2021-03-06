
// MFC对话框文件名显示_1View.h : CMFC对话框文件名显示_1View 类的接口
//

#pragma once


class CMFC对话框文件名显示_1View : public CView
{
protected: // 仅从序列化创建
	CMFC对话框文件名显示_1View();
	DECLARE_DYNCREATE(CMFC对话框文件名显示_1View)

// 特性
public:
	CMFC对话框文件名显示_1Doc* GetDocument() const;

// 操作
public:
	CString fileName;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC对话框文件名显示_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShow1();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC对话框文件名显示_1View.cpp 中的调试版本
inline CMFC对话框文件名显示_1Doc* CMFC对话框文件名显示_1View::GetDocument() const
   { return reinterpret_cast<CMFC对话框文件名显示_1Doc*>(m_pDocument); }
#endif

