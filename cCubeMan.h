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
    virtual void Update(iMap* pMap) override;
    virtual void Render() override;
protected:
    cCubeNode* m_pRoot;
    D3DMATERIAL9 m_stMt1;
    LPDIRECT3DTEXTURE9 m_pTexture;


};

