#include "framework.h"
#include "cHeightMap.h"

cHeightMap::cHeightMap()
	:
	m_pMesh(NULL),
	m_pTexture(NULL)
{
}

cHeightMap::~cHeightMap()
{
	Destroy();
}

void cHeightMap::Setup(char* szFolder, char* szRaw, char* szTex, DWORD dwBytePerPixel)
{
	std::string sFolder(szFolder);
	std::string sRaw = sFolder + std::string(szRaw);
	std::string sTex = sFolder + std::string(szTex);
	m_pTexture = g_pTextureManager->GetTexture(sTex);

	FILE* fp = NULL;
	fopen_s(&fp, sRaw.c_str(), "rb");
	fseek(fp, 0, SEEK_END);
	int nFileSize = ftell(fp);

	int nNumVertex = nFileSize / dwBytePerPixel;

	int nRow = (int)(sqrt((float)nNumVertex) + 0.0001f);
	int nCol = nRow;
	int nTileN = nRow - 1;
	m_nTileN = nTileN;

	fseek(fp, 0, SEEK_SET);

	std::vector<ST_PNT_VERTEX> vecVertex(nNumVertex);
	m_vecVertex.resize(nNumVertex);

	std::vector<DWORD> vecIndex;
	vecIndex.reserve(nTileN * nTileN * 2 * 3);

	for (int i = 0; i < nNumVertex; i++)
	{
		ST_PNT_VERTEX v;
		v.p = D3DXVECTOR3(i % nCol, ((unsigned char)fgetc(fp)) / 10.0f, i / nCol);
		v.n = D3DXVECTOR3(0, 1, 0);
		v.t = D3DXVECTOR2((i % nCol) / (float)nCol, (i / nCol) / (float)nCol);

		vecVertex[i] = v;
		m_vecVertex[i] = v.p;
		if (dwBytePerPixel == 3)
		{
			fgetc(fp); fgetc(fp);
		}
	}
	fclose(fp);

	for (int x = 1; x < nTileN; x++)
	{
		for (int z = 1; z < nTileN; z++)
		{
			int left = (z + 0) * nCol + x - 1;
			int right = (z + 0) * nCol + x + 1;
			int up = (z + 1) * nCol + x + 0;
			int down = (z - 1) * nCol + x + 0;

			D3DXVECTOR3 leftToRight = m_vecVertex[right] - m_vecVertex[left];
			D3DXVECTOR3 downToup = m_vecVertex[up] - m_vecVertex[down];
			D3DXVECTOR3 normal;
			D3DXVec3Cross(&normal, &downToup, &leftToRight);
			D3DXVec3Normalize(&normal, &normal);
			int nIndex = z * nCol + x;
			vecVertex[nIndex].n = normal;

		}
	}
	for (int x = 0; x < nTileN; x++)
	{
		for (int z = 0; z < nTileN; z++)
		{
			int _0 = (z + 0) * nCol + x + 0;
			int _1 = (z + 1) * nCol + x + 0;
			int _2 = (z + 0) * nCol + x + 1;
			int _3 = (z + 1) * nCol + x + 1;

			vecIndex.push_back(_0); vecIndex.push_back(_1); vecIndex.push_back(_2);
			vecIndex.push_back(_3); vecIndex.push_back(_2); vecIndex.push_back(_1);

			D3DXCreateMeshFVF(vecIndex.size() / 3, vecVertex.size(), D3DXMESH_MANAGED | D3DXMESH_32BIT,
				ST_PNT_VERTEX::FVF, g_pD3DDevice, &m_pMesh);

			ST_PNT_VERTEX* pV = NULL;
			m_pMesh->LockVertexBuffer(0, (LPVOID*)&pV);
			memcpy(pV, &vecVertex[0], vecVertex.size() * sizeof(ST_PNT_VERTEX));
			m_pMesh->UnlockVertexBuffer();

			DWORD* pI = NULL;
			m_pMesh->LockIndexBuffer(0, (LPVOID*)&pI);
			memcpy(pI, &vecIndex[0], vecIndex.size() * sizeof(DWORD));
			m_pMesh->UnlockIndexBuffer();

		}
	}
}

void cHeightMap::Render()
{
}

bool cHeightMap::GetHeight(IN float x, OUT float& y, IN float z)
{
	return false;
}

void cHeightMap::Destroy()
{
	Safe_release(m_pTexture);
	Safe_release(m_pMesh);
}
