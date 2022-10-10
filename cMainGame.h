#pragma once
class cCubePC;
class cGrid;
class cCamera;
class cCubeMan;
class cGroup;

class cMainGame
{

public:
	cMainGame();
	~cMainGame();


public:
	void Setup();
	void Update();
	void Render();

	void Setup_Line();
	void Setup_Triangle();
	void Draw_Line();
	void Draw_Triangle();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void Setup_Light();
	void Setup_Texture();
	void Draw_Texture();

	void Setup_Obj();
	void Draw_Obj();

	void Setup_Map();
	void Draw_Map();
	void Setup_Surface();


	void Setup_HeightMap();
	void Draw_heightMap();
private:
	std::vector<ST_PC_VERTEX> m_vecLineVertex;
	std::vector<ST_PC_VERTEX> m_vecTriangleVertex;

	cCubePC* m_pCubePC;
	cGrid* m_pGrid;
	cCamera* m_pCamera;
	cCubeMan* m_pCubeMan;
	std::vector<cGroup*> m_vecGroup;
	std::vector<cGroup*> m_vecMap;
	//
	LPDIRECT3DTEXTURE9 m_pTexture;
	std::vector<ST_PT_VERTEX> m_vecVertex;
	//

	iMap* m_pMap;
};

