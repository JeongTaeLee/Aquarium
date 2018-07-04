#pragma once
#include "Fish.h"
class CFish01 :
	public CFish
{
public:

	CFish01();
	~CFish01();

	virtual void Release()	override;
	virtual void Update()	override;

	void Animation();
	void Move();
};

