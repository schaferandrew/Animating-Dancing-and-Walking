
// ChildView.h : interface of the CChildView class
//


#pragma once

#include "graphics/OpenGLWnd.h"
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

	double m_spinAngle;
	UINT_PTR m_spinTimer;
	CSGPtr<CSGRotationTranslation> m_hook1;
	CSGPtr<CSGRotationTranslation> m_hook2;
protected:
	DECLARE_MESSAGE_MAP()
public:
	void OnGLDraw(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnAnimationStart();
};

