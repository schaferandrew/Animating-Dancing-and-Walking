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
	m_camera.Set(20, 10, 50, 0, 0, 0, 0, 1, 0);

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_COMMAND(ID_ANIMATION_START, &CChildView::OnAnimationStart)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
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

CSGPtr<CSGRotationTranslation> CChildView::Create_Body()
{
	CGrVector a(0, 0, 3);
	CGrVector b(5, 0, 3);
	CGrVector c(5, 8, 3);
	CGrVector d(0, 8, 3);
	CGrVector e(0, 0, 0);
	CGrVector f(5, 0, 0);
	CGrVector g(5, 8, 0);
	CGrVector h(0, 8, 0);

	CSGPtr<CSGRotationTranslation> root = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> poly1 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly2 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly3 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly4 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly5 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly6 = new CSGPolygon();

	poly1->AddVertex(a);
	poly1->AddVertex(b);
	poly1->AddVertex(c);
	poly1->AddVertex(d);
	poly1->ComputeNormal();

	poly2->AddVertex(c);
	poly2->AddVertex(b);
	poly2->AddVertex(f);
	poly2->AddVertex(g);
	poly2->ComputeNormal();

	poly3->AddVertex(h);
	poly3->AddVertex(g);
	poly3->AddVertex(f);
	poly3->AddVertex(e);
	poly3->ComputeNormal();

	poly4->AddVertex(d);
	poly4->AddVertex(h);
	poly4->AddVertex(e);
	poly4->AddVertex(a);
	poly4->ComputeNormal();

	poly5->AddVertex(d);
	poly5->AddVertex(c);
	poly5->AddVertex(g);
	poly5->AddVertex(h);
	poly5->ComputeNormal();

	poly6->AddVertex(e);
	poly6->AddVertex(f);
	poly6->AddVertex(b);
	poly6->AddVertex(a);
	poly6->ComputeNormal();

	root->AddChild(poly1);
	root->AddChild(poly2);
	root->AddChild(poly3);
	root->AddChild(poly4);
	root->AddChild(poly5);
	root->AddChild(poly6);

	return root;
}

CSGPtr<CSGRotationTranslation> CChildView::Create_Left_Arm()
{
	//Vertex of arm hook
	CGrVector a(0, 0, 0.5);
	CGrVector b(1, 0, 0.5);
	CGrVector c(1, 1, 0.5);
	CGrVector d(0, 1, 0.5);
	CGrVector e(0, 0, 0);
	CGrVector f(1, 0, 0);
	CGrVector g(1, 1, 0);
	CGrVector h(0, 1, 0);

	CSGPtr<CSGRotationTranslation> root = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> poly1 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly2 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly3 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly4 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly5 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly6 = new CSGPolygon();

	poly1->AddVertex(a);
	poly1->AddVertex(b);
	poly1->AddVertex(c);
	poly1->AddVertex(d);
	poly1->ComputeNormal();

	poly2->AddVertex(c);
	poly2->AddVertex(b);
	poly2->AddVertex(f);
	poly2->AddVertex(g);
	poly2->ComputeNormal();

	poly3->AddVertex(h);
	poly3->AddVertex(g);
	poly3->AddVertex(f);
	poly3->AddVertex(e);
	poly3->ComputeNormal();

	poly4->AddVertex(d);
	poly4->AddVertex(h);
	poly4->AddVertex(e);
	poly4->AddVertex(a);
	poly4->ComputeNormal();

	poly5->AddVertex(d);
	poly5->AddVertex(c);
	poly5->AddVertex(g);
	poly5->AddVertex(h);
	poly5->ComputeNormal();

	poly6->AddVertex(e);
	poly6->AddVertex(f);
	poly6->AddVertex(b);
	poly6->AddVertex(a);
	poly6->ComputeNormal();

	root->AddChild(poly1);
	root->AddChild(poly2);
	root->AddChild(poly3);
	root->AddChild(poly4);
	root->AddChild(poly5);
	root->AddChild(poly6);


	//shoulder
	CGrVector a1(0, 0, 1);
	CGrVector b1(0.5, 0, 1);
	CGrVector c1(0.5, 4, 1);
	CGrVector d1(0, 4, 1);
	CGrVector e1(0, 0, 0);
	CGrVector f1(0.5, 0, 0);
	CGrVector g1(0.5, 4, 0);
	CGrVector h1(0, 4, 0);

	CSGPtr<CSGRotationTranslation> shoulder = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> shoulder1 = new CSGPolygon();
	CSGPtr<CSGPolygon> shoulder2 = new CSGPolygon();
	CSGPtr<CSGPolygon> shoulder3 = new CSGPolygon();
	CSGPtr<CSGPolygon> shoulder4 = new CSGPolygon();
	CSGPtr<CSGPolygon> shoulder5 = new CSGPolygon();
	CSGPtr<CSGPolygon> shoulder6 = new CSGPolygon();

	shoulder1->AddVertex(a1);
	shoulder1->AddVertex(b1);
	shoulder1->AddVertex(c1);
	shoulder1->AddVertex(d1);
	shoulder1->ComputeNormal();

	shoulder2->AddVertex(c1);
	shoulder2->AddVertex(b1);
	shoulder2->AddVertex(f1);
	shoulder2->AddVertex(g1);
	shoulder2->ComputeNormal();

	shoulder3->AddVertex(h1);
	shoulder3->AddVertex(g1);
	shoulder3->AddVertex(f1);
	shoulder3->AddVertex(e1);
	shoulder3->ComputeNormal();

	shoulder4->AddVertex(d1);
	shoulder4->AddVertex(h1);
	shoulder4->AddVertex(e1);
	shoulder4->AddVertex(a1);
	shoulder4->ComputeNormal();

	shoulder5->AddVertex(d1);
	shoulder5->AddVertex(c1);
	shoulder5->AddVertex(g1);
	shoulder5->AddVertex(h1);
	shoulder5->ComputeNormal();

	shoulder6->AddVertex(e1);
	shoulder6->AddVertex(f1);
	shoulder6->AddVertex(b1);
	shoulder6->AddVertex(a1);
	shoulder6->ComputeNormal();

	shoulder->AddChild(shoulder1);
	shoulder->AddChild(shoulder2);
	shoulder->AddChild(shoulder3);
	shoulder->AddChild(shoulder4);
	shoulder->AddChild(shoulder5);
	shoulder->AddChild(shoulder6);

	shoulder->SetRotate(90, 1, 0, 0);
	shoulder->SetTranslate(-0.5, 1, 0);
	root->AddChild(shoulder);
	m_hook2 = shoulder;
	return root;
}

CSGPtr<CSGRotationTranslation> CChildView::Create_Right_Arm()
{
	//Vertex of arm hook
	CGrVector a(0, 0, 0.5);
	CGrVector b(1, 0, 0.5);
	CGrVector c(1, 1, 0.5);
	CGrVector d(0, 1, 0.5);
	CGrVector e(0, 0, 0);
	CGrVector f(1, 0, 0);
	CGrVector g(1, 1, 0);
	CGrVector h(0, 1, 0);

	CSGPtr<CSGRotationTranslation> root = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> poly1 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly2 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly3 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly4 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly5 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly6 = new CSGPolygon();

	poly1->AddVertex(a);
	poly1->AddVertex(b);
	poly1->AddVertex(c);
	poly1->AddVertex(d);
	poly1->ComputeNormal();

	poly2->AddVertex(c);
	poly2->AddVertex(b);
	poly2->AddVertex(f);
	poly2->AddVertex(g);
	poly2->ComputeNormal();

	poly3->AddVertex(h);
	poly3->AddVertex(g);
	poly3->AddVertex(f);
	poly3->AddVertex(e);
	poly3->ComputeNormal();

	poly4->AddVertex(d);
	poly4->AddVertex(h);
	poly4->AddVertex(e);
	poly4->AddVertex(a);
	poly4->ComputeNormal();

	poly5->AddVertex(d);
	poly5->AddVertex(c);
	poly5->AddVertex(g);
	poly5->AddVertex(h);
	poly5->ComputeNormal();

	poly6->AddVertex(e);
	poly6->AddVertex(f);
	poly6->AddVertex(b);
	poly6->AddVertex(a);
	poly6->ComputeNormal();

	root->AddChild(poly1);
	root->AddChild(poly2);
	root->AddChild(poly3);
	root->AddChild(poly4);
	root->AddChild(poly5);
	root->AddChild(poly6);


	//shoulder
	CGrVector a1(0, 0, 1);
	CGrVector b1(0.5, 0, 1);
	CGrVector c1(0.5, 4, 1);
	CGrVector d1(0, 4, 1);
	CGrVector e1(0, 0, 0);
	CGrVector f1(0.5, 0, 0);
	CGrVector g1(0.5, 4, 0);
	CGrVector h1(0, 4, 0);

	CSGPtr<CSGRotationTranslation> shoulder = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> shoulder1 = new CSGPolygon();
	CSGPtr<CSGPolygon> shoulder2 = new CSGPolygon();
	CSGPtr<CSGPolygon> shoulder3 = new CSGPolygon();
	CSGPtr<CSGPolygon> shoulder4 = new CSGPolygon();
	CSGPtr<CSGPolygon> shoulder5 = new CSGPolygon();
	CSGPtr<CSGPolygon> shoulder6 = new CSGPolygon();

	shoulder1->AddVertex(a1);
	shoulder1->AddVertex(b1);
	shoulder1->AddVertex(c1);
	shoulder1->AddVertex(d1);
	shoulder1->ComputeNormal();

	shoulder2->AddVertex(c1);
	shoulder2->AddVertex(b1);
	shoulder2->AddVertex(f1);
	shoulder2->AddVertex(g1);
	shoulder2->ComputeNormal();

	shoulder3->AddVertex(h1);
	shoulder3->AddVertex(g1);
	shoulder3->AddVertex(f1);
	shoulder3->AddVertex(e1);
	shoulder3->ComputeNormal();

	shoulder4->AddVertex(d1);
	shoulder4->AddVertex(h1);
	shoulder4->AddVertex(e1);
	shoulder4->AddVertex(a1);
	shoulder4->ComputeNormal();

	shoulder5->AddVertex(d1);
	shoulder5->AddVertex(c1);
	shoulder5->AddVertex(g1);
	shoulder5->AddVertex(h1);
	shoulder5->ComputeNormal();

	shoulder6->AddVertex(e1);
	shoulder6->AddVertex(f1);
	shoulder6->AddVertex(b1);
	shoulder6->AddVertex(a1);
	shoulder6->ComputeNormal();

	shoulder->AddChild(shoulder1);
	shoulder->AddChild(shoulder2);
	shoulder->AddChild(shoulder3);
	shoulder->AddChild(shoulder4);
	shoulder->AddChild(shoulder5);
	shoulder->AddChild(shoulder6);

	shoulder->SetRotate(90, 1, 0, 0);
	shoulder->SetTranslate(0.5, 1, 0);
	root->AddChild(shoulder);
	m_hook4 = shoulder;
	return root;
}

CSGPtr<CSGRotationTranslation> CChildView::Create_Left_Leg()
{
	//Vertex of arm hook
	CGrVector a(0, 0, 0.5);
	CGrVector b(0.5, 0, 0.5);
	CGrVector c(0.5, 0.5, 0.5);
	CGrVector d(0, 0.5, 0.5);
	CGrVector e(0, 0, 0);
	CGrVector f(0.5, 0, 0);
	CGrVector g(0.5, 0.5, 0);
	CGrVector h(0, 0.5, 0);

	CSGPtr<CSGRotationTranslation> root = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> poly1 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly2 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly3 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly4 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly5 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly6 = new CSGPolygon();

	poly1->AddVertex(a);
	poly1->AddVertex(b);
	poly1->AddVertex(c);
	poly1->AddVertex(d);
	poly1->ComputeNormal();

	poly2->AddVertex(c);
	poly2->AddVertex(b);
	poly2->AddVertex(f);
	poly2->AddVertex(g);
	poly2->ComputeNormal();

	poly3->AddVertex(h);
	poly3->AddVertex(g);
	poly3->AddVertex(f);
	poly3->AddVertex(e);
	poly3->ComputeNormal();

	poly4->AddVertex(d);
	poly4->AddVertex(h);
	poly4->AddVertex(e);
	poly4->AddVertex(a);
	poly4->ComputeNormal();

	poly5->AddVertex(d);
	poly5->AddVertex(c);
	poly5->AddVertex(g);
	poly5->AddVertex(h);
	poly5->ComputeNormal();

	poly6->AddVertex(e);
	poly6->AddVertex(f);
	poly6->AddVertex(b);
	poly6->AddVertex(a);
	poly6->ComputeNormal();

	root->AddChild(poly1);
	root->AddChild(poly2);
	root->AddChild(poly3);
	root->AddChild(poly4);
	root->AddChild(poly5);
	root->AddChild(poly6);


	//shoulder
	CGrVector a1(0, 0, 1);
	CGrVector b1(1, 0, 1);
	CGrVector c1(1, 4, 1);
	CGrVector d1(0, 4, 1);
	CGrVector e1(0, 0, 0);
	CGrVector f1(1, 0, 0);
	CGrVector g1(1, 4, 0);
	CGrVector h1(0, 4, 0);

	CSGPtr<CSGRotationTranslation> leg = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> leg1 = new CSGPolygon();
	CSGPtr<CSGPolygon> leg2 = new CSGPolygon();
	CSGPtr<CSGPolygon> leg3 = new CSGPolygon();
	CSGPtr<CSGPolygon> leg4 = new CSGPolygon();
	CSGPtr<CSGPolygon> leg5 = new CSGPolygon();
	CSGPtr<CSGPolygon> leg6 = new CSGPolygon();

	leg1->AddVertex(a1);
	leg1->AddVertex(b1);
	leg1->AddVertex(c1);
	leg1->AddVertex(d1);
	leg1->ComputeNormal();

	leg2->AddVertex(c1);
	leg2->AddVertex(b1);
	leg2->AddVertex(f1);
	leg2->AddVertex(g1);
	leg2->ComputeNormal();

	leg3->AddVertex(h1);
	leg3->AddVertex(g1);
	leg3->AddVertex(f1);
	leg3->AddVertex(e1);
	leg3->ComputeNormal();

	leg4->AddVertex(d1);
	leg4->AddVertex(h1);
	leg4->AddVertex(e1);
	leg4->AddVertex(a1);
	leg4->ComputeNormal();

	leg5->AddVertex(d1);
	leg5->AddVertex(c1);
	leg5->AddVertex(g1);
	leg5->AddVertex(h1);
	leg5->ComputeNormal();

	leg6->AddVertex(e1);
	leg6->AddVertex(f1);
	leg6->AddVertex(b1);
	leg6->AddVertex(a1);
	leg6->ComputeNormal();

	leg->AddChild(leg1);
	leg->AddChild(leg2);
	leg->AddChild(leg3);
	leg->AddChild(leg4);
	leg->AddChild(leg5);
	leg->AddChild(leg6);

	
	leg->SetTranslate(-0.25, -4, -0.25);

	root->AddChild(leg);
	return root;
}

CSGPtr<CSGRotationTranslation> CChildView::Create_Right_Leg()
{
	//Vertex of arm hook
	CGrVector a(0, 0, 0.5);
	CGrVector b(0.5, 0, 0.5);
	CGrVector c(0.5, 0.5, 0.5);
	CGrVector d(0, 0.5, 0.5);
	CGrVector e(0, 0, 0);
	CGrVector f(0.5, 0, 0);
	CGrVector g(0.5, 0.5, 0);
	CGrVector h(0, 0.5, 0);

	CSGPtr<CSGRotationTranslation> root = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> poly1 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly2 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly3 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly4 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly5 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly6 = new CSGPolygon();

	poly1->AddVertex(a);
	poly1->AddVertex(b);
	poly1->AddVertex(c);
	poly1->AddVertex(d);
	poly1->ComputeNormal();

	poly2->AddVertex(c);
	poly2->AddVertex(b);
	poly2->AddVertex(f);
	poly2->AddVertex(g);
	poly2->ComputeNormal();

	poly3->AddVertex(h);
	poly3->AddVertex(g);
	poly3->AddVertex(f);
	poly3->AddVertex(e);
	poly3->ComputeNormal();

	poly4->AddVertex(d);
	poly4->AddVertex(h);
	poly4->AddVertex(e);
	poly4->AddVertex(a);
	poly4->ComputeNormal();

	poly5->AddVertex(d);
	poly5->AddVertex(c);
	poly5->AddVertex(g);
	poly5->AddVertex(h);
	poly5->ComputeNormal();

	poly6->AddVertex(e);
	poly6->AddVertex(f);
	poly6->AddVertex(b);
	poly6->AddVertex(a);
	poly6->ComputeNormal();

	root->AddChild(poly1);
	root->AddChild(poly2);
	root->AddChild(poly3);
	root->AddChild(poly4);
	root->AddChild(poly5);
	root->AddChild(poly6);


	//shoulder
	CGrVector a1(0, 0, 1);
	CGrVector b1(1, 0, 1);
	CGrVector c1(1, 4, 1);
	CGrVector d1(0, 4, 1);
	CGrVector e1(0, 0, 0);
	CGrVector f1(1, 0, 0);
	CGrVector g1(1, 4, 0);
	CGrVector h1(0, 4, 0);

	CSGPtr<CSGRotationTranslation> leg = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> leg1 = new CSGPolygon();
	CSGPtr<CSGPolygon> leg2 = new CSGPolygon();
	CSGPtr<CSGPolygon> leg3 = new CSGPolygon();
	CSGPtr<CSGPolygon> leg4 = new CSGPolygon();
	CSGPtr<CSGPolygon> leg5 = new CSGPolygon();
	CSGPtr<CSGPolygon> leg6 = new CSGPolygon();

	leg1->AddVertex(a1);
	leg1->AddVertex(b1);
	leg1->AddVertex(c1);
	leg1->AddVertex(d1);
	leg1->ComputeNormal();

	leg2->AddVertex(c1);
	leg2->AddVertex(b1);
	leg2->AddVertex(f1);
	leg2->AddVertex(g1);
	leg2->ComputeNormal();

	leg3->AddVertex(h1);
	leg3->AddVertex(g1);
	leg3->AddVertex(f1);
	leg3->AddVertex(e1);
	leg3->ComputeNormal();

	leg4->AddVertex(d1);
	leg4->AddVertex(h1);
	leg4->AddVertex(e1);
	leg4->AddVertex(a1);
	leg4->ComputeNormal();

	leg5->AddVertex(d1);
	leg5->AddVertex(c1);
	leg5->AddVertex(g1);
	leg5->AddVertex(h1);
	leg5->ComputeNormal();

	leg6->AddVertex(e1);
	leg6->AddVertex(f1);
	leg6->AddVertex(b1);
	leg6->AddVertex(a1);
	leg6->ComputeNormal();

	leg->AddChild(leg1);
	leg->AddChild(leg2);
	leg->AddChild(leg3);
	leg->AddChild(leg4);
	leg->AddChild(leg5);
	leg->AddChild(leg6);


	leg->SetTranslate(-0.25, -4, -0.25);

	root->AddChild(leg);
	return root;
}

CSGPtr<CSGRotationTranslation> CChildView::Create_Head()
{
	CGrVector a(0, 0, 2);
	CGrVector b(2, 0, 2);
	CGrVector c(2, 2, 2);
	CGrVector d(0, 2, 2);
	CGrVector e(0, 0, 0);
	CGrVector f(2, 0, 0);
	CGrVector g(2, 2, 0);
	CGrVector h(0, 2, 0);

	CSGPtr<CSGRotationTranslation> root = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> poly1 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly2 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly3 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly4 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly5 = new CSGPolygon();
	CSGPtr<CSGPolygon> poly6 = new CSGPolygon();

	poly1->AddVertex(a);
	poly1->AddVertex(b);
	poly1->AddVertex(c);
	poly1->AddVertex(d);
	poly1->ComputeNormal();

	poly2->AddVertex(c);
	poly2->AddVertex(b);
	poly2->AddVertex(f);
	poly2->AddVertex(g);
	poly2->ComputeNormal();

	poly3->AddVertex(h);
	poly3->AddVertex(g);
	poly3->AddVertex(f);
	poly3->AddVertex(e);
	poly3->ComputeNormal();

	poly4->AddVertex(d);
	poly4->AddVertex(h);
	poly4->AddVertex(e);
	poly4->AddVertex(a);
	poly4->ComputeNormal();

	poly5->AddVertex(d);
	poly5->AddVertex(c);
	poly5->AddVertex(g);
	poly5->AddVertex(h);
	poly5->ComputeNormal();

	poly6->AddVertex(e);
	poly6->AddVertex(f);
	poly6->AddVertex(b);
	poly6->AddVertex(a);
	poly6->ComputeNormal();

	root->AddChild(poly1);
	root->AddChild(poly2);
	root->AddChild(poly3);
	root->AddChild(poly4);
	root->AddChild(poly5);
	root->AddChild(poly6);

	return root;
}


void CChildView::CreateSceneGraph()
{
	CSGPtr<CSGRotationTranslation> body = Create_Body();
	CSGPtr<CSGRotationTranslation> head = Create_Head();
	CSGPtr<CSGRotationTranslation> left_arm = Create_Left_Arm();
	CSGPtr<CSGRotationTranslation> right_arm = Create_Right_Arm();
	CSGPtr<CSGRotationTranslation> left_leg = Create_Left_Leg();
	CSGPtr<CSGRotationTranslation> right_leg = Create_Right_Leg();

	///Components position
	left_arm->SetTranslate(-1.0, 4, 1.5);
	right_arm->SetTranslate(5.0, 4, 1.5);
	head->SetTranslate(1.5, 8, 0.3);
	left_leg->SetTranslate(1, -0.5, 1);
	right_leg->SetTranslate(3, -0.5, 1);

	///Add components as children of the body, which is the root
	body->AddChild(left_arm);
	body->AddChild(right_arm);
	body->AddChild(head);
	body->AddChild(left_leg);
	body->AddChild(right_leg);

	
	m_scenegraph = body;
	m_hook1 = left_arm;
	m_hook3 = right_arm;
	m_hook5 = head;
	m_hook6 = left_leg;
}

void CChildView::OnGLDraw(CDC* pDC)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//
	// Set up the camera
	//
	int width, height;
	GetSize(width, height);
	m_camera.Apply(width, height);

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
	m_hook1->SetRotate(m_spinAngle, 1, 0, 0); //left arm hook
	m_hook2->SetRotate(-m_spinAngle, 0, 1., 0); //left shoulder hook
	m_hook3->SetRotate(-m_spinAngle, 1, 0, 0); // right arm hook
	m_hook4->SetRotate(-m_spinAngle, 0, 1, 0); //right shoulder hook
	m_hook5->SetRotate(m_spinAngle, 0, 1, 0); //head hook
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

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_camera.MouseDown(point.x, point.y);

	COpenGLWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_camera.MouseMove(point.x, point.y, nFlags))
		Invalidate();

	COpenGLWnd::OnMouseMove(nFlags, point);
}
