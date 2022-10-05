#pragma once
class cMtlTex;
class cGroup;
class cObjLoader
{
public:
	cObjLoader();
	~cObjLoader();

	void Load(OUT std::vector<cGroup*>& vecGroup, IN char* szFolder, IN char* szFile);
	void LoadMtlLib(char* szFolder, char* szFile);
private:
	std::map<std::string, cMtlTex*> m_mapMtlTex;
};

