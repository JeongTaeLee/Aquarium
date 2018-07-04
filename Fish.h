#pragma once

#define ANISIZE 80

class CFish
{
protected:
	enum FISHSTATES
	{
		LEFT,
		RIGHT
	};

protected:
	shared_ptr<texture> m_image;
	shared_ptr<texture> m_mirrorImage;

	D3DXVECTOR2			m_pos;
	int					m_state;

	DWORD				m_aniTime;

	RECT				m_rect;
	int					m_frameCount;

	bool				m_rotate;
public:
	CFish();
	~CFish();

	virtual void Init(const wstring & key, const D3DXVECTOR2 & pos);
	virtual void Release()	PURE;
	virtual void Update()	PURE;
	virtual void Render();
};

