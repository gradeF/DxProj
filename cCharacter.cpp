#include "framework.h"
#include "cCharacter.h"

cCharacter::cCharacter()
	:m_vPosition(0, 0, 0),
	m_vDirection(0, 0, 1),
	m_fRotY(0.0f),
	m_pMap(NULL)
{
	D3DXMatrixIdentity(&m_matWorld);
}

cCharacter::~cCharacter()
{
}

void cCharacter::Setup()
{
}

void cCharacter::Update(iMap* pMap)
{
	m_pMap = pMap;
	D3DXVECTOR3 vPos = m_vPosition;
	if (GetKeyState('A') & 0x8000)
	{
		m_fRotY -= 0.1f;
	}
	if (GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.1f;
	}
	if (GetKeyState('W') & 0x8000)
	{
		vPos = m_vPosition + (m_vDirection * 0.1f);
	}
	if (GetKeyState('S') & 0x8000)
	{
		vPos = m_vPosition - (m_vDirection * 0.1f);
	}

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);
	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);

	if (pMap)
	{
		if (pMap->GetHeight(vPos.x, vPos.y, vPos.z))
		{
			m_vPosition = vPos;
		}
	}

	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y + 0.9f, m_vPosition.z);
	m_matWorld = matR * matT;
}

void cCharacter::Render()
{
}

D3DXVECTOR3& cCharacter::GetPosition()
{
	return m_vPosition;
}
