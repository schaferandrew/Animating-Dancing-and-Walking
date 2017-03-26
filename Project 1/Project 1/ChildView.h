
// ChildView.h : interface of the CChildView class
//


#pragma once

#include "graphics/OpenGLWnd.h"
#include "graphics/GrCamera.h"
#include "SGNode.h"
#include "SGRotationTranslation.h"

// CChildView window

class CChildView : public COpenGLWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
private:
	void CreateSceneGraph();
	CSGPtr<CSGNode> m_scenegraph;
	CGrCamera m_camera;
	double m_spinAngle;
	UINT_PTR m_spinTimer;
	CSGPtr<CSGRotationTranslation> Create_Head();
	CSGPtr<CSGRotationTranslation> Create_Body();
	CSGPtr<CSGRotationTranslation> Create_Left_Arm();
	CSGPtr<CSGRotationTranslation> Create_Right_Arm();
	CSGPtr<CSGRotationTranslation> Create_Left_Leg();
	CSGPtr<CSGRotationTranslation> Create_Right_Leg();
	CSGPtr<CSGRotationTranslation> m_hook1;
	CSGPtr<CSGRotationTranslation> m_hook2;
	CSGPtr<CSGRotationTranslation> m_hook3;
	CSGPtr<CSGRotationTranslation> m_hook4;
	CSGPtr<CSGRotationTranslation> m_hook5;
	CSGPtr<CSGRotationTranslation> m_hook6;
	CSGPtr<CSGRotationTranslation> m_hook7;
	CSGPtr<CSGRotationTranslation> m_hook8;
	CSGPtr<CSGRotationTranslation> m_hook9;
	CSGPtr<CSGRotationTranslation> m_hook10;
	CSGPtr<CSGRotationTranslation> m_hook11;
	double m_angle1;
	double m_angle2;
	double m_angle3;
	double m_angle4;
	double m_angle5;
	int m_phase;

protected:
	DECLARE_MESSAGE_MAP()
public:
	void OnGLDraw(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnAnimationStart();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

