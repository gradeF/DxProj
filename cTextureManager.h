#pragma once
#define g_pTextureManager cTextureManager::GetInstance()
class cTextureManager
{
public:
	LPDIRECT3DTEXTURE9 GetTexture(char* szFullPath);
	LPDIRECT3DTEXTURE9 GetTexture(std::string& szFullPath);
	void Destroy()
	{
		for (auto it : m_mapTexture)
		{
			Safe_release(it.second);
		}
		m_mapTexture.clear();
	}
private:
	Singletone(cTextureManager);

	std::map<std::string, LPDIRECT3DTEXTURE9> m_mapTexture;
};

