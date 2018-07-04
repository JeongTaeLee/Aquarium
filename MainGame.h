#pragma once

class CBackGround;
class CFish;


class MainGame
{
private:
	CBackGround * backGround;

	vector<CFish*> m_fishList;
public:
	MainGame();
	~MainGame();

	void Init();
	void Release();
	void Update();
	void Render();
};

