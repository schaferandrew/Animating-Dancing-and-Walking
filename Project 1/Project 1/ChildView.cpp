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
	m_spinAngle = 0;
	m_spinTimer = 0;
	CreateSceneGraph();
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_COMMAND(ID_ANIMATION_START, &CChildView::OnAnimationStart)
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
CSGPtr<CSGPolygon> poly1 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly2 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly3 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly4 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly5 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly6 = new CSGPolygon();
	CSGPtr<CSGRotationTranslation> rt = new CSGRotationTranslation();

	CGrVector a(0, 0, 0);
	CGrVector b(2.5, 0, 0);
	CGrVector c(0, 2.5, 0);
	CGrVector d(0, 0, 2.5);
	CGrVector e(2.5, 2.5, 0);
	CGrVector f(0, 2.5, 2.5);
	CGrVector g(2.5, 0, 2.5);
	CGrVector h(2.5, 2.5, 2.5);

	poly1->AddVertex(a);//"Bottom" of the cube
	poly1->AddVertex(b);
	poly1->AddVertex(e);
	poly1->AddVertex(c);
	poly1->ComputeNormal();

	poly2->AddVertex(a);//"front" of the cube
	poly2->AddVertex(b);
	poly2->AddVertex(g);
	poly2->AddVertex(d);
	poly2->ComputeNormal();

	poly3->AddVertex(a); //"left" of the cube
	poly3->AddVertex(c);
	poly3->AddVertex(f);
	poly3->AddVertex(d);
	poly3->ComputeNormal();

	poly4->AddVertex(b); //"right" of the cube
	poly4->AddVertex(e);
	poly4->AddVertex(h);
	poly4->AddVertex(g);
	poly4->ComputeNormal();

	poly5->AddVertex(c); //"back" of the cube
	poly5->AddVertex(e);
	poly5->AddVertex(h);
	poly5->AddVertex(f);
	poly5->ComputeNormal();

	poly6->AddVertex(d); //"top" of the cube
	poly6->AddVertex(f);
	poly6->AddVertex(h);
	poly6->AddVertex(g);
	poly6->ComputeNormal();

	rt->AddChild(poly1);
	rt->AddChild(poly2);
	rt->AddChild(poly3);
	rt->AddChild(poly4);
	rt->AddChild(poly5);
	rt->AddChild(poly6);

	CSGPtr<CSGPolygon> rect1 = new CSGPolygon();
	CSGPtr<CSGPolygon> rect2 = new CSGPolygon();
	CSGPtr<CSGPolygon> rect3 = new CSGPolygon();
	CSGPtr<CSGPolygon> rect4 = new CSGPolygon();
	CSGPtr<CSGPolygon> rect5 = new CSGPolygon();
	CSGPtr<CSGPolygon> rect6 = new CSGPolygon();
	CSGPtr<CSGRotationTranslation> rect = new CSGRotationTranslation();

	CGrVector one(0, 0, 0);
	CGrVector two(3, 0, 0);
	CGrVector three(0, 1, 0);
	CGrVector four(0, 0, 1);
	CGrVector five(3, 1, 0);
	CGrVector six(0, 1, 1);
	CGrVector seven(3, 0, 1);
	CGrVector eight(3, 1, 1);

	rect1->AddVertex(one);//"Bottom"
	rect1->AddVertex(two);
	rect1->AddVertex(five);
	rect1->AddVertex(three);
	rect1->ComputeNormal();

	rect2->AddVertex(one);//"front"
	rect2->AddVertex(two);
	rect2->AddVertex(seven);
	rect2->AddVertex(four);
	rect2->ComputeNormal();

	rect3->AddVertex(one); //"left"
	rect3->AddVertex(three);
	rect3->AddVertex(six);
	rect3->AddVertex(four);
	rect3->ComputeNormal();

	rect4->AddVertex(two); //"right"
	rect4->AddVertex(five);
	rect4->AddVertex(eight);
	rect4->AddVertex(seven);
	rect4->ComputeNormal();

	rect5->AddVertex(three); //"back"
	rect5->AddVertex(five);
	rect5->AddVertex(eight);
	rect5->AddVertex(six);
	rect5->ComputeNormal();

	rect6->AddVertex(four); //"top"
	rect6->AddVertex(six);
	rect6->AddVertex(eight);
	rect6->AddVertex(seven);
	rect6->ComputeNormal();

	rect->AddChild(rect1);
	rect->AddChild(rect2);
	rect->AddChild(rect3);
	rect->AddChild(rect4);
	rect->AddChild(rect5);
	rect->AddChild(rect6);

	CSGPtr<CSGRotationTranslation> root = new CSGRotationTranslation();
	CSGPtr<CSGRotationTranslation> rt1 = new CSGRotationTranslation();
	CSGPtr<CSGRotationTranslation> rt2 = new CSGRotationTranslation();
	//CSGPtr<CSGRotationTranslation> rt3 = new CSGRotationTranslation();

	root->AddChild(rt1);
	root->AddChild(rt2);
	//root->AddChild(rt3);

	rt1->AddChild(rt);
	rt2->AddChild(rect);
	//rt3->AddChild(rect);

	rt1->SetTranslate(5, 0, 0);
	rt2->SetTranslate(-5, 0, 0);
	//rt3->SetTranslate(0, 0, 0);

	m_scenegraph = root;
	m_hook1 = rt1;
	m_hook2 = rt2;
}

void CChildView::OnGLDraw(CDC* pDC)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//
	// Set up the camera
	//

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Determine the screen size so we can determine the aspect ratio
	int width, height;
	GetSize(width, height);
	GLdouble aspectratio = GLdouble(width) / GLdouble(height);

	// Set the camera parameters
	gluPerspective(25.,         // Vertical FOV degrees.
		aspectratio, // The aspect ratio.
		10.,         // Near clipping 40/130
		200.);       // Far clipping

					 // Set the camera location
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(20., 10., 50.,    // eye x,y,z
		0., 0., 0.,       // center x,y,z
		0., 1., 0.);      // Up direction

						  //
						  // Some standard parameters
						  //

						  // Enable depth test
	glEnable(GL_DEPTH_TEST);

	// Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Cull backfacing polygons
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	//Animation
	m_hook1->SetRotate(m_spinAngle, 0, 1, 0);
	m_hook2->SetRotate(-m_spinAngle, 0, 0, 1);

	m_scenegraph->Render();
}

void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	m_spinAngle += 5;		// 5 degrees every 30ms about
	Invalidate();

	COpenGLWnd::OnTimer(nIDEvent);
}


void CChildView::OnAnimationStart()
{
	if (m_spinTimer == 0)
	{
		// Create the timer
		m_spinTimer = SetTimer(1, 30, NULL);
	}
	else
	{
		// Destroy the timer
		KillTimer(m_spinTimer);
		m_spinTimer = 0;
	}
}