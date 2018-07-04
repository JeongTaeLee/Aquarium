#include "DXUT.h"
#include "Fish.h"


CFish::CFish()
{
}


CFish::~CFish()
{
}

void CFish::Init(const wstring & key, const D3DXVECTOR2 & pos)
{
	m_image = IMAGEMANAGER->GetTexture(key);
	m_pos = pos;

	m_state = RIGHT;
	m_frameCount = 0;
	m_aniTime = 0;
	
	m_rotate = false;

	SetRect(&m_rect, 0, 0, 80, 80);
}

void CFish::Render()
{
	m_image->CenterRender(m_pos, m_rect);
}
