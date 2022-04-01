
// mfc_homework1View.cpp: Cmfchomework1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_homework1.h"
#endif

#include "mfc_homework1Doc.h"
#include "mfc_homework1View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfchomework1View

IMPLEMENT_DYNCREATE(Cmfchomework1View, CView)

BEGIN_MESSAGE_MAP(Cmfchomework1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_COLOR_RED, &Cmfchomework1View::OnColorRed)
	ON_COMMAND(ID_COLOR_BLUE, &Cmfchomework1View::OnColorBlue)
	ON_COMMAND(ID_COLOR_GREEN, &Cmfchomework1View::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE_, &Cmfchomework1View::OnColorBlue_)
	ON_COMMAND(ID_COLOR_GREEN_, &Cmfchomework1View::OnColorGreen_)
	ON_COMMAND(ID_COLOR_RED_, &Cmfchomework1View::OnColorRed_)
END_MESSAGE_MAP()

// Cmfchomework1View 생성/소멸

Cmfchomework1View::Cmfchomework1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	str.Format(_T("검정색"));

}

Cmfchomework1View::~Cmfchomework1View()
{
}

BOOL Cmfchomework1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cmfchomework1View 그리기

void Cmfchomework1View::OnDraw(CDC* /*pDC*/)
{
	Cmfchomework1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Cmfchomework1View 인쇄

BOOL Cmfchomework1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfchomework1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfchomework1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// Cmfchomework1View 진단

#ifdef _DEBUG
void Cmfchomework1View::AssertValid() const
{
	CView::AssertValid();
}

void Cmfchomework1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmfchomework1Doc* Cmfchomework1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfchomework1Doc)));
	return (Cmfchomework1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmfchomework1View 메시지 처리기


void Cmfchomework1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	//CPen pen;
	//pen.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	//CPen* oldPen = dc.SelectObject(&pen);

	CBrush brush;
	brush.CreateSolidBrush(color);
	CBrush* oldBrush = dc.SelectObject(&brush);

	dc.Ellipse(point.x - 30, point.y - 30, point.x + 30, point.y + 30);

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	pFrame->m_wndStatusBar.SetPaneText(1, str);


	CView::OnLButtonDown(nFlags, point);
}


void Cmfchomework1View::OnColorRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	str.Format(_T("빨간색"));
	r = 255;
	color = RGB(r, 0, 0);
}


void Cmfchomework1View::OnColorBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	str.Format(_T("파란색"));
	b = 255;
	color = RGB(0, 0, b);

}


void Cmfchomework1View::OnColorGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	str.Format(_T("초록색"));
	g = 255;
	color = RGB(0, b, 0);
}


void Cmfchomework1View::OnColorBlue_()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	str.Format(_T("파란색-"));
	b-=10;
	color = RGB(0, 0, b);

}


void Cmfchomework1View::OnColorGreen_()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	str.Format(_T("초록색-"));
	g-=10;
	color = RGB(0, g, 0);
}


void Cmfchomework1View::OnColorRed_()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	str.Format(_T("빨간색-"));
	r-=10;
	color = RGB(r, 0, 0);
}
