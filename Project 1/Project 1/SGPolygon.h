#pragma once
#include "sgnode.h"

#include <vector>
#include "graphics/GrVector.h"
#include "graphics/GrTexture.h"

class CSGPolygon :
    public CSGNode
{
public:
    CSGPolygon(void);
    ~CSGPolygon(void);

    virtual void Render();
	void ComputeNormal();

    void AddVertex(const CGrVector &v) {m_vertices.push_back(v);}
	void AddVertex(double x, double y, double z);

    void AddNormal(const CGrVector &n) {m_normals.push_back(n);}
    void AddTexCoord(const CGrVector &t) {m_tvertices.push_back(t);}
    void SetTexture(CGrTexture *texture) {m_texture = texture;}

private:
    std::vector<CGrVector>   m_vertices;
    std::vector<CGrVector>   m_normals;
    std::vector<CGrVector>   m_tvertices;
    CGrTexture               *m_texture;
};
