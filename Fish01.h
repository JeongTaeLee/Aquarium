#pragma once
#include "Fish.h"
class CFish01 :
	public CFish
{
private:
	D3DXVECTOR2 Benchmark;

	float r;

	float angle = 0;
	float oldAngle = 0;

	bool s;
public:

	CFish01(const wstring & key, const D3DXVECTOR2 & Benchmark, float r, bool s);
	~CFish01();

	virtual void Release()	override;
	virtual void Update()	override;

	void Animation();
	void Move();
};

