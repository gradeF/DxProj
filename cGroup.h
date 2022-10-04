#pragma once
#include "cObject.h"
#include "cMtlTex.h"

class cMtlTex;

class cGroup : public cObject
{
public:
	cGroup();
	~cGroup();
	void Render();
private:
	Synthesize_Pass_By_Ref(std::vector<ST_PNT_VERTEX>, m_vecVertex, Vertex);
	Synthesize_Pass_By_Ref(cMtlTex*, m_pMtlTex, MtlTex);
};

