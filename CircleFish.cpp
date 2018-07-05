#include "DXUT.h"
#include "CircleFish.h"


CCircleFish::CCircleFish(const wstring & key, const D3DXVECTOR2 & Benchmark, float r)
{
	CFish::Init(key, Benchmark);

	this->Benchmark = Benchmark;

	this->r = r;
}


CCircleFish::~CCircleFish()
{
}

void CCircleFish::Release()
{
}

void CCircleFish::Update()
{
	Animation();
	Move();
}

void CCircleFish::Animation()
{
	if (timeGetTime() > m_aniTime)
	{
		m_frameCount++;
		m_aniTime = timeGetTime() + 30;

		switch (m_state)
		{
		case FISHSTATES::LEFT:

			if (m_rotate)
			{
				m_rect.left = 720 - ANISIZE * m_frameCount;
				m_rect.top = 160;
			}
			else
			{
				m_rect.left = 0 + ANISIZE * m_frameCount;
				m_rect.top = 0;
			}

			m_rect.right = m_rect.left + ANISIZE;
			m_rect.bottom = m_rect.top + ANISIZE;
			break;
		case FISHSTATES::RIGHT:

			if (m_rotate)
				m_rect.top = 160;
			else
				m_rect.top = 80;

			m_rect.left = 0 + ANISIZE * m_frameCount;
			m_rect.right = m_rect.left + ANISIZE;
			m_rect.bottom = m_rect.top + ANISIZE;
			break;
		}

		if (m_frameCount == 9)
		{
			m_frameCount = 0;
			m_rotate = false;
		}
	}
}

void CCircleFish::Move()
{

	angle += 0.008;

	if (angle > D3DX_PI * 2)
		angle = 0.0f;

	float cosAngle = cos(angle);
	float sinAngle = sin(angle);

	m_pos.x = (cosAngle * r) + Benchmark.x;
	m_pos.y = (sinAngle * r) + Benchmark.y;

	if (m_state == FISHSTATES::RIGHT && sinAngle < oldAngle)
	{
		m_rotate = true;
		m_state = FISHSTATES::LEFT;

		m_frameCount = 0;
	}
	else if (m_state == FISHSTATES::LEFT && sinAngle > oldAngle)
	{
		m_rotate = true;
		m_state = FISHSTATES::RIGHT;

		m_aniTime = timeGetTime() + 30;
	}

	oldAngle = sinAngle;
}
