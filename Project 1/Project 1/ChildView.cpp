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
	m_angle1 = 0;
	m_angle2 = 0;
	m_angle3 = 0;
	m_angle4 = 0;
	m_angle5 = 0;
	m_angle6 = 0;
	m_angle7 = 0;
	m_angle8 = 0;
	m_angle9 = 0;

	m_phase = 1;

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
	ON_COMMAND(ID_ANIMATION_WALK, &CChildView::OnAnimationWalk)
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
	CGrVector a(-.5, 0, 0.5);
	CGrVector b(1, 0, 0.5);
	CGrVector c(1, 1, 0.5);
	CGrVector d(-0.5, 1, 0.5);
	CGrVector e(-0.5, 0, 0);
	CGrVector f(1, 0, 0);
	CGrVector g(1, 1, 0);
	CGrVector h(-0.5, 1, 0);

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
	CGrVector b(1.3, 0, 0.5);
	CGrVector c(1.3, 1, 0.5);
	CGrVector d(0, 1, 0.5);
	CGrVector e(0, 0, 0);
	CGrVector f(1.3, 0, 0);
	CGrVector g(1.3, 1, 0);
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

	CGrVector a2(0, 0, 1.25);
	CGrVector b2(1.25, 0, 1.25);
	CGrVector c2(1.25, 1.25, 1.25);
	CGrVector d2(0, 1.25, 1.25);
	CGrVector e2(0, 0, 0);
	CGrVector f2(1.25, 0, 0);
	CGrVector g2(1.25, 1.25, 0);
	CGrVector h2(0, 1.25, 0);

	CSGPtr<CSGRotationTranslation> left_knee = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> elbow1 = new CSGPolygon(); //it's called elbow because I'm too lazy to switch it.
	CSGPtr<CSGPolygon> elbow2 = new CSGPolygon();
	CSGPtr<CSGPolygon> elbow3 = new CSGPolygon();
	CSGPtr<CSGPolygon> elbow4 = new CSGPolygon();
	CSGPtr<CSGPolygon> elbow5 = new CSGPolygon();
	CSGPtr<CSGPolygon> elbow6 = new CSGPolygon();

	elbow1->AddVertex(a2);
	elbow1->AddVertex(b2);
	elbow1->AddVertex(c2);
	elbow1->AddVertex(d2);
	elbow1->ComputeNormal();

	elbow2->AddVertex(c2);
	elbow2->AddVertex(b2);
	elbow2->AddVertex(f2);
	elbow2->AddVertex(g2);
	elbow2->ComputeNormal();

	elbow3->AddVertex(h2);
	elbow3->AddVertex(g2);
	elbow3->AddVertex(f2);
	elbow3->AddVertex(e2);
	elbow3->ComputeNormal();

	elbow4->AddVertex(d2);
	elbow4->AddVertex(h2);
	elbow4->AddVertex(e2);
	elbow4->AddVertex(a2);
	elbow4->ComputeNormal();

	elbow5->AddVertex(d2);
	elbow5->AddVertex(c2);
	elbow5->AddVertex(g2);
	elbow5->AddVertex(h2);
	elbow5->ComputeNormal();

	elbow6->AddVertex(e2);
	elbow6->AddVertex(f2);
	elbow6->AddVertex(b2);
	elbow6->AddVertex(a2);
	elbow6->ComputeNormal();

	left_knee->AddChild(elbow1);
	left_knee->AddChild(elbow2);
	left_knee->AddChild(elbow3);
	left_knee->AddChild(elbow4);
	left_knee->AddChild(elbow5);
	left_knee->AddChild(elbow6);

	CSGPtr<CSGRotationTranslation> legbot = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> lega = new CSGPolygon();
	CSGPtr<CSGPolygon> legb = new CSGPolygon();
	CSGPtr<CSGPolygon> legc = new CSGPolygon();
	CSGPtr<CSGPolygon> legd = new CSGPolygon();
	CSGPtr<CSGPolygon> lege = new CSGPolygon();
	CSGPtr<CSGPolygon> legf = new CSGPolygon();

	lega->AddVertex(a1);
	lega->AddVertex(b1);
	lega->AddVertex(c1);
	lega->AddVertex(d1);
	lega->ComputeNormal();

	legb->AddVertex(c1);
	legb->AddVertex(b1);
	legb->AddVertex(f1);
	legb->AddVertex(g1);
	legb->ComputeNormal();

	legc->AddVertex(h1);
	legc->AddVertex(g1);
	legc->AddVertex(f1);
	legc->AddVertex(e1);
	legc->ComputeNormal();

	legd->AddVertex(d1);
	legd->AddVertex(h1);
	legd->AddVertex(e1);
	legd->AddVertex(a1);
	legd->ComputeNormal();

	lege->AddVertex(d1);
	lege->AddVertex(c1);
	lege->AddVertex(g1);
	lege->AddVertex(h1);
	lege->ComputeNormal();

	legf->AddVertex(e1);
	legf->AddVertex(f1);
	legf->AddVertex(b1);
	legf->AddVertex(a1);
	legf->ComputeNormal();

	legbot->AddChild(leg1);
	legbot->AddChild(leg2);
	legbot->AddChild(leg3);
	legbot->AddChild(leg4);
	legbot->AddChild(leg5);
	legbot->AddChild(leg6);


	leg->SetTranslate(-0.25, -4, -0.25);
	left_knee->SetTranslate(-.15, -0.75, -.1);
	legbot->SetTranslate(0.15, -4, .1);

	root->AddChild(leg);
	leg->AddChild(left_knee);
	left_knee->AddChild(legbot);

	leg->SetTranslate(-0.25, -4, -0.25);

	root->AddChild(leg);

	m_hook9 = left_knee;
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

	CGrVector a2(0, 0, 1.25);
	CGrVector b2(1.25, 0, 1.25);
	CGrVector c2(1.25, 1.25, 1.25);
	CGrVector d2(0, 1.25, 1.25);
	CGrVector e2(0, 0, 0);
	CGrVector f2(1.25, 0, 0);
	CGrVector g2(1.25, 1.25, 0);
	CGrVector h2(0, 1.25, 0);

	CSGPtr<CSGRotationTranslation> right_knee = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> elbow1 = new CSGPolygon(); //it's called elbow because I'm too lazy to switch it.
	CSGPtr<CSGPolygon> elbow2 = new CSGPolygon();
	CSGPtr<CSGPolygon> elbow3 = new CSGPolygon();
	CSGPtr<CSGPolygon> elbow4 = new CSGPolygon();
	CSGPtr<CSGPolygon> elbow5 = new CSGPolygon();
	CSGPtr<CSGPolygon> elbow6 = new CSGPolygon();

	elbow1->AddVertex(a2);
	elbow1->AddVertex(b2);
	elbow1->AddVertex(c2);
	elbow1->AddVertex(d2);
	elbow1->ComputeNormal();

	elbow2->AddVertex(c2);
	elbow2->AddVertex(b2);
	elbow2->AddVertex(f2);
	elbow2->AddVertex(g2);
	elbow2->ComputeNormal();

	elbow3->AddVertex(h2);
	elbow3->AddVertex(g2);
	elbow3->AddVertex(f2);
	elbow3->AddVertex(e2);
	elbow3->ComputeNormal();

	elbow4->AddVertex(d2);
	elbow4->AddVertex(h2);
	elbow4->AddVertex(e2);
	elbow4->AddVertex(a2);
	elbow4->ComputeNormal();

	elbow5->AddVertex(d2);
	elbow5->AddVertex(c2);
	elbow5->AddVertex(g2);
	elbow5->AddVertex(h2);
	elbow5->ComputeNormal();

	elbow6->AddVertex(e2);
	elbow6->AddVertex(f2);
	elbow6->AddVertex(b2);
	elbow6->AddVertex(a2);
	elbow6->ComputeNormal();

	right_knee->AddChild(elbow1);
	right_knee->AddChild(elbow2);
	right_knee->AddChild(elbow3);
	right_knee->AddChild(elbow4);
	right_knee->AddChild(elbow5);
	right_knee->AddChild(elbow6);

	CSGPtr<CSGRotationTranslation> legbot = new CSGRotationTranslation();
	CSGPtr<CSGPolygon> lega = new CSGPolygon();
	CSGPtr<CSGPolygon> legb = new CSGPolygon();
	CSGPtr<CSGPolygon> legc = new CSGPolygon();
	CSGPtr<CSGPolygon> legd = new CSGPolygon();
	CSGPtr<CSGPolygon> lege = new CSGPolygon();
	CSGPtr<CSGPolygon> legf = new CSGPolygon();

	lega->AddVertex(a1);
	lega->AddVertex(b1);
	lega->AddVertex(c1);
	lega->AddVertex(d1);
	lega->ComputeNormal();

	legb->AddVertex(c1);
	legb->AddVertex(b1);
	legb->AddVertex(f1);
	legb->AddVertex(g1);
	legb->ComputeNormal();

	legc->AddVertex(h1);
	legc->AddVertex(g1);
	legc->AddVertex(f1);
	legc->AddVertex(e1);
	legc->ComputeNormal();

	legd->AddVertex(d1);
	legd->AddVertex(h1);
	legd->AddVertex(e1);
	legd->AddVertex(a1);
	legd->ComputeNormal();

	lege->AddVertex(d1);
	lege->AddVertex(c1);
	lege->AddVertex(g1);
	lege->AddVertex(h1);
	lege->ComputeNormal();

	legf->AddVertex(e1);
	legf->AddVertex(f1);
	legf->AddVertex(b1);
	legf->AddVertex(a1);
	legf->ComputeNormal();

	legbot->AddChild(leg1);
	legbot->AddChild(leg2);
	legbot->AddChild(leg3);
	legbot->AddChild(leg4);
	legbot->AddChild(leg5);
	legbot->AddChild(leg6);


	leg->SetTranslate(-0.25, -4, -0.25);
	right_knee->SetTranslate(-.15, -0.75, -.1);
	legbot->SetTranslate(0.15, -4, .1);

	root->AddChild(leg);
	leg->AddChild(right_knee);
	right_knee->AddChild(legbot);
	leg->SetTranslate(-0.25, -4, -0.25);

	root->AddChild(leg);

	m_hook8 = right_knee;
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
	m_hook7 = right_leg;
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

	//head bob
	m_hook5->SetRotate(m_angle5, 0., 1., 0.);

	//phase choreography
	if (m_phase == 1 || m_phase == 2){
		m_hook2->SetRotate(m_angle1, 0, 1., 0);
		m_hook3->SetRotate(m_angle3, 1, 0, 0);
		m_hook6->SetRotate(m_angle6, 0., 0., -1.);
	}
	else if (m_phase == 3 || m_phase == 4) {
		m_hook2->SetRotate(m_angle1, 0, 0, -1);
		m_hook3->SetRotate(m_angle3, 0, 1, 0);
	}
	else if (m_phase == 5 || m_phase == 6) {
		m_hook2->SetRotate(m_angle1, 1, 0, -1);
		m_hook3->SetRotate(m_angle3, 1, 1, 0);
	}
	else if (m_phase == 7 || m_phase == 8 || m_phase == 9 || m_phase == 10) {
		m_hook6->SetRotate(m_angle6, 1, 0, 0);
		m_hook7->SetRotate(m_angle7, 1, 0, 0);
		m_hook8->SetRotate(m_angle8, 1, 0, 0);
		m_hook9->SetRotate(m_angle9, 1, 0, 0);
	}

	m_scenegraph->Render();
}

void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	/*
	hook1 (left arm)
	hook2 (left shoulder)
	hook3 (right arm)
	hook4 (right shoulder)
	hook5 (head)*/
	if (m_phase == 1 || m_phase == 3 || m_phase == 5){
		if (m_angle1 <= -120 && m_angle3 >= 120) {
			m_phase += 1;
		}
		if (m_angle1 > -120){
			m_angle1 -= 5;
		}

		if (m_angle3 < 120){
			m_angle3 += 5;
		}
		m_angle5 += 1;
		m_angle6 += 1;
	}
	else if (m_phase == 2 || m_phase == 4 || m_phase == 6) {
		if (m_angle1 >= 0 && m_angle3 <= 0) {
			if (m_phase != 6) {
				m_phase += 1;
			}
			else {
				m_phase = 1;
			}
		}
		if (m_angle1 < 0) {
			m_angle1 += 5;
		}

		if (m_angle3 > 0) {
			m_angle3 -= 5;
		}

		m_angle5 -= 1;
		m_angle6 -= 1;
	}
	else if (m_phase == 7) {
		/*
		6 = left leg
		7 = right leg
		8 = right knee
		9 = left knee
		*/

		m_angle6 -= 2;
		m_angle7 += 2;
		m_angle9 -= 1;
		if (m_angle6 < -40)
		{
			m_phase = 8;
		}
	}
	else if (m_phase == 8) {
		m_angle6 += 2;
		m_angle7 -= 2;
		m_angle8 += .5;

		if (m_angle6 > 0 )
		m_phase = 9;
	}
	else if (m_phase == 9) {
		m_angle6 += 2;
		m_angle7 -= 2;
		m_angle9 += 0.5;
		m_angle8 += .5;
		if (m_angle6 > 40)
		{
			m_phase = 10;
		}
		
	}
	else if (m_phase == 10) {

		m_angle6 -= 2;
		m_angle7 += 2;
		m_angle9 += .5;
		m_angle8 -= 1.;
		if (m_angle6 < 0)
		{
			m_phase = 7;
		}
		
	}
	
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
	m_phase = 1;
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


void CChildView::OnAnimationWalk()
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
	m_phase = 7;
	m_angle9 = 20;
}
