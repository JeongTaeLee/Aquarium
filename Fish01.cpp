#include "DXUT.h"
#include "Fish01.h"

CFish01::CFish01()
{
	CFish::Init(L"Fish01", D3DXVECTOR2((float)WINWIDTH / 2, (float)WINHEIGHT / 2));

}


CFish01::~CFish01()
{
}

void CFish01::Release()
{
}

void CFish01::Update()
{
	Move();
	Animation();
}

void CFish01::Animation()
{

	if (timeGetTime() > m_aniTime)
	{
		m_frameCount++;
		m_aniTime = timeGetTime() + 30;

		switch (m_state)
		{
		case FISHSTATES::LEFT :

			if (m_rotate)
			{
				m_rect.left		= 720 - ANISIZE * m_frameCount;
				m_rect.top		= 160;
			}
			else
			{
				m_rect.left		= 0 + ANISIZE * m_frameCount;
				m_rect.top		= 0;
			}

			m_rect.right = m_rect.left + ANISIZE;
			m_rect.bottom = m_rect.top + ANISIZE;
			break;
		case FISHSTATES::RIGHT:

			if (m_rotate)
				m_rect.top		= 160;
			else
				m_rect.top		= 80;

			m_rect.left = 0 + ANISIZE * m_frameCount;
			m_rect.right = m_rect.left + ANISIZE;
			m_rect.bottom	= m_rect.top + ANISIZE;
			break;
		}
		
		if (m_frameCount == 9)
		{
			m_frameCount = 0;
			m_rotate = false;
		}
	}
}

void CFish01::Move()
{
	static float angle = 0;
	static float oldAngle = 0;
	
	angle += 0.01;

	if (angle > D3DX_PI * 2)
		angle = 0.0f;

	float sinAngle = sin(angle);

	m_pos.x = (sinAngle * 300) + 640;

	if (m_state == FISHSTATES::RIGHT && sinAngle < oldAngle)
	{
		m_rotate = true;
		m_state = FISHSTATES::LEFT;

		m_frameCount = 0;
	}
	else if(m_state == FISHSTATES::LEFT && sinAngle > oldAngle)
	{
		m_rotate = true;
		m_state = FISHSTATES::RIGHT;

		m_aniTime = timeGetTime() + 30;
	}

	oldAngle = sinAngle;
}
