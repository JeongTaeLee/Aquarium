#pragma once
class CBackGround
{
private:
	shared_ptr<texture> m_image;
public:
	CBackGround();
	~CBackGround();

	void Init();
	void Release();
	void Update();
	void Render();
};

