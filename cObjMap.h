#pragma once
#include "iMap.h"
class cObjMap : public iMap
{
public:
	cObjMap(IN char* szFolder, IN char* szFile, IN D3DXMATRIXA16* pmat = NULL);
	~cObjMap(void);

	void Load(IN char* szFolder, IN char* szFile, IN D3DXMATRIXA16* pmat = NULL);

	virtual bool GetHeight(IN float x, OUT float& y, IN float z);

private:
	std::vector<D3DXVECTOR3> m_vecSurface;
};

