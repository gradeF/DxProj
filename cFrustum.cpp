#include "framework.h"
#include "cFrustum.h"

cFrustum::cFrustum()
{
}

cFrustum::~cFrustum()
{
}

void cFrustum::Setup()
{
	//near
	m_vecProjVertex.push_back(D3DXVECTOR3(-1, -1, 0)); //left down
	m_vecProjVertex.push_back(D3DXVECTOR3(-1, 1, 0)); //left up
	m_vecProjVertex.push_back(D3DXVECTOR3(1, 1, 0)); //right up
	m_vecProjVertex.push_back(D3DXVECTOR3(1, -1, 0)); //right down

	//far
	m_vecProjVertex.push_back(D3DXVECTOR3(-1, -1, 1)); //left down
	m_vecProjVertex.push_back(D3DXVECTOR3(-1, 1, 1)); //left up
	m_vecProjVertex.push_back(D3DXVECTOR3(1, 1, 1)); //right up
	m_vecProjVertex.push_back(D3DXVECTOR3(1, -1, 1)); //right down

	m_vecPlane.resize(6);
	m_vecWorldVertex.resize(8);
}

void cFrustum::Update()
{
	D3DXMATRIXA16 matView, matProj;
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProj);
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
	for (size_t i = 0; i < m_vecProjVertex.size(); i++)
	{
		D3DXVec3Unproject(&m_vecWorldVertex[i], &m_vecProjVertex[i], NULL, &matProj, &matView, NULL);
	}
}

bool cFrustum::IsIn(ST_SPHERE* pSphere)
{
	return false;
}
