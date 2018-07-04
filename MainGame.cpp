#include "DXUT.h"
#include "MainGame.h"

#include "BackGround.h"

#include "Fish.h"
#include "Fish01.h"

MainGame::MainGame(){
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

	m_fishList.push_back(new CFish01(L"Fish01", 200, 50, 100));
	m_fishList.push_back(new CFish01(L"Fish02", 700, 150, 200));
	m_fishList.push_back(new CFish01(L"Fish01", 500, 250, 400));
	m_fishList.push_back(new CFish01(L"Fish02", 900, 350, 100));
	m_fishList.push_back(new CFish01(L"Fish02", 100, 450, 50));
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
