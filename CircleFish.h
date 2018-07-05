#pragma once
#include "Fish.h"
class CCircleFish :
	public CFish
{
private:
	D3DXVECTOR2 Benchmark;

	int			r;   //������
	int			ban; //�Ÿ�

	float angle = 0;
	float oldAngle = 0;
public:
	CCircleFish(const wstring & key, const D3DXVECTOR2 & Benchmark, float r);
	~CCircleFish();

	void Release();
	void Update();

	void Animation();
	void Move();
};

