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
	backGround = new CBackGround;
	backGround->Init();

	m_fishList.push_back(new CFish01);
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
