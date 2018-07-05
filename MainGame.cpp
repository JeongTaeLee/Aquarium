#include "DXUT.h"
#include "MainGame.h"

#include "BackGround.h"

#include "Fish01.h"
#include "CircleFish.h"

MainGame::MainGame(){
	m_CreateTime = 0;
}


MainGame::~MainGame()
{
}

void MainGame::Init()
{
	IMAGEMANAGER->GetTexture(L"Fish01", L"./Image/fish/fish01.png");
	IMAGEMANAGER->GetTexture(L"Fish02", L"./Image/fish/fish02.png");
	backGround = new CBackGround;
	backGround->Init();

	m_fishList.push_back(new CFish01(L"Fish02", D3DXVECTOR2(WINWIDTH / 2, WINHEIGHT / 2), 150, false));
	m_fishList.push_back(new CFish01(L"Fish02", D3DXVECTOR2(WINWIDTH / 2, WINHEIGHT / 2), 150, true));


	m_fishList.push_back(new CFish01(L"Fish01", D3DXVECTOR2(100, WINHEIGHT / 2), 320, true));
	m_fishList.push_back(new CFish01(L"Fish02", D3DXVECTOR2(1180, WINHEIGHT / 2), 320, true));
}

void MainGame::Release()
{
	SAFE_DELETE(backGround);

	for (auto Iter : m_fishList)
	{
		SAFE_DELETE(Iter);
	}
	m_fishList.clear();

	CImageManager::ReleaseInstance();
}

void MainGame::Update()
{
	backGround->Update();

	if (m_fishList.size() < 66)
	{
		if (timeGetTime() > m_CreateTime)
		{
			m_CreateTime = timeGetTime() + 400;

			m_fishList.push_back(new CCircleFish(L"Fish01", D3DXVECTOR2(WINWIDTH / 2, WINHEIGHT / 2), 200));
			m_fishList.push_back(new CCircleFish(L"Fish02", D3DXVECTOR2(WINWIDTH / 2, WINHEIGHT / 2), 300));
		}
	}

	


	for (auto Iter : m_fishList)
	{
		Iter->Update();
	}
}

void MainGame::Render()
{
	IMAGEMANAGER->Begin();

	backGround->Render();

	for (auto Iter : m_fishList)
	{
		Iter->Render();
	}


	IMAGEMANAGER->End();
}
