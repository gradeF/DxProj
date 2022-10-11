#pragma once
class cFrustum
{
public:
	cFrustum();
	~cFrustum();

	void Setup();
	void Update();
	bool IsIn(ST_SPHERE* pSphere);
private:
	std::vector<D3DXVECTOR3> m_vecProjVertex;
	std::vector<D3DXVECTOR3> m_vecWorldVertex;
	std::vector<D3DXPLANE> m_vecPlane;
};

