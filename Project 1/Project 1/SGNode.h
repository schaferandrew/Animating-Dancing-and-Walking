#pragma once

class CSGNode
{
public:
    CSGNode(void);
    virtual ~CSGNode(void);

    void IncRef() {m_refs++;}
    void DecRef() {m_refs--;  if(m_refs == 0) {delete this;}}
    int  RefCnt() const {return m_refs;}

    virtual void Render() = 0;

private:
    int     m_refs;
};
