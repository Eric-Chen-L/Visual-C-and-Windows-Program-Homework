
// MFC200511_1Doc.h : CMFC200511_1Doc ��Ľӿ�
//


#pragma once
#include "MFC200511_1Set.h"


class CMFC200511_1Doc : public CDocument
{
protected: // �������л�����
	CMFC200511_1Doc();
	DECLARE_DYNCREATE(CMFC200511_1Doc)

// ����
public:
	CMFC200511_1Set m_MFC200511_1Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC200511_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ�����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};