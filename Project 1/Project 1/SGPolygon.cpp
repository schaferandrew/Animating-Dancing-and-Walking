#include "StdAfx.h"
#include "SGPolygon.h"

using namespace std;

CSGPolygon::CSGPolygon(void) : m_texture(NULL)
{
}

CSGPolygon::~CSGPolygon(void)
{
}

void CSGPolygon::Render()
{
    // Create an iterator for each of the three arrays
    vector<CGrVector>::iterator v=m_vertices.begin();
    vector<CGrVector>::iterator n=m_normals.begin();
    vector<CGrVector>::iterator t=m_tvertices.begin();

    glBegin(GL_POLYGON);
    for( ; v != m_vertices.end();  v++)
    {
        // If we have an available normal, use it:
        if(n != m_normals.end())
        {
            glNormal3dv(*n);
            n++;
        }

        // If we have an available texture coordinate, use it:
        if(t != m_tvertices.end())
        {
            glTexCoord2dv(*t);
            t++;
        }

        glVertex3dv(*v);
    }

    glEnd();
}

void CSGPolygon::AddVertex(double x, double y, double z)
{
	CGrVector v(x, y, z);
	m_vertices.push_back(v);
}

void CSGPolygon::ComputeNormal()
{
	CGrVector p1 = m_vertices[0];
	CGrVector p2 = m_vertices[1];
	CGrVector p3 = m_vertices[2];

	CGrVector U = p2 - p1;
	CGrVector V = p3 - p1;

	CGrVector Normal;
	Normal.X((U.Y() * V.Z()) - (U.Z() * V.Y()));
	Normal.Y((U.Z() * V.X()) - (U.X() * V.Z()));
	Normal.Z((U.X() * V.Y()) - (U.Y() * V.X()));
	Normal.Normalize();

	this->AddNormal(Normal);
}