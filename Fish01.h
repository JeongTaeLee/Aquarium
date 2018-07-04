#pragma once
#include "Fish.h"
class CFish01 :
	public CFish
{
private:
	int ban;
public:

	CFish01(const wstring & key, float xPos, float yPos, float ban);
	~CFish01();

	virtual void Release()	override;
	virtual void Update()	override;

	void Animation();
	void Move();
};

