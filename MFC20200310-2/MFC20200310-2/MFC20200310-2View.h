
// MFC20200310-2View.h : CMFC202003102View ��Ľӿ�
//

#pragma once


class CMFC202003102View : public CView
{
protected: // �������л�����
	CMFC202003102View();
	DECLARE_DYNCREATE(CMFC202003102View)

// ����
public:
	CMFC202003102Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC202003102View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC20200310-2View.cpp �еĵ��԰汾
inline CMFC202003102Doc* CMFC202003102View::GetDocument() const
   { return reinterpret_cast<CMFC202003102Doc*>(m_pDocument); }
#endif
