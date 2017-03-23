
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Project 1.h"
#include "ChildView.h"
#include "SGPolygon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	CreateSceneGraph();
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!COpenGLWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}


void CChildView::CreateSceneGraph()
{
	CSGPolygon *poly = new CSGPolygon();

	CGrVector a(0, 0, 2.5);
	CGrVector b(2.5, 0, -2.5);
	CGrVector c(-2.5, 0, -2.5);
	CGrVector d(0, 4, 0);

	poly->AddNormal(CGrVector(0.861411, 0.269191, 0.430706));
	poly->AddVertex(d);
	poly->AddVertex(a);
	poly->AddVertex(b);

	m_scenegraph = poly;
}

void CChildView::OnGLDraw(CDC* pDC)
{
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_scenegraph->Render();
}
