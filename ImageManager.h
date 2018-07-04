#pragma once
#include "singleton.h"

struct texture
{
	LPDIRECT3DTEXTURE9	lpTexture;
	D3DXIMAGE_INFO		info;

	texture(LPDIRECT3DTEXTURE9 _lpTexture, D3DXIMAGE_INFO _info) 
		: lpTexture(_lpTexture), info(_info)
	{}
	~texture() {
		SAFE_RELEASE(lpTexture);
	}

	void Render(const D3DXVECTOR2 & pos);
	void CenterRender(const D3DXVECTOR2 & pos, const RECT & rect);
	void CenterRender(const D3DXVECTOR2 & pos);
	
};

class CImageManager :
	public singleton<CImageManager>
{
private:
	map<wstring, shared_ptr<texture> > m_images;

	LPD3DXSPRITE m_lpSprite;
public:
	CImageManager();
	~CImageManager();

	void Begin()	{ m_lpSprite->Begin(D3DXSPRITE_ALPHABLEND); }
	void End()		{ m_lpSprite->End(); }

	shared_ptr<texture> GetTexture(const wstring & key, const wstring & path = L" ");
};

#define IMAGEMANAGER CImageManager::Getinstance()

