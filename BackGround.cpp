#include "DXUT.h"
#include "BackGround.h"


CBackGround::CBackGround()
{
}


CBackGround::~CBackGround()
{
}

void CBackGround::Init()
{
	m_image = IMAGEMANAGER->GetTexture(L"BackGround", L"./Image/BackGround.png");
}

void CBackGround::Release()
{
}

void CBackGround::Update()
{
}

void CBackGround::Render()
{
	m_image->Render(D3DXVECTOR2(0, 0));
}
