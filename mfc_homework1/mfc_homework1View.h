
// mfc_homework1View.h: Cmfchomework1View 클래스의 인터페이스
//

#pragma once


class Cmfchomework1View : public CView
{
protected: // serialization에서만 만들어집니다.
	Cmfchomework1View() noexcept;
	DECLARE_DYNCREATE(Cmfchomework1View)

// 특성입니다.
public:
	Cmfchomework1Doc* GetDocument() const;
	COLORREF color;
	int r;
	int g;
	int b;
	CString str;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~Cmfchomework1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnColorRed();
	afx_msg void OnColorBlue();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue_();
	afx_msg void OnColorGreen_();
	afx_msg void OnColorRed_();
};

#ifndef _DEBUG  // mfc_homework1View.cpp의 디버그 버전
inline Cmfchomework1Doc* Cmfchomework1View::GetDocument() const
   { return reinterpret_cast<Cmfchomework1Doc*>(m_pDocument); }
#endif

