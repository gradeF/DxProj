#pragma once
#include "cCharacter.h"

class cCubeNode;

class cCubeMan :
    public cCharacter
{
public:
    cCubeMan();
    virtual ~cCubeMan();

public:
    virtual void Setup() override;
    virtual void Update() override;
    virtual void Render() override;
protected:
    cCubeNode* m_pRoot;
    D3DMATERIAL9 m_stMt1;


};

