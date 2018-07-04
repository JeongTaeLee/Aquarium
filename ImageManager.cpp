#include "DXUT.h"
#include "ImageManager.h"

LPD3DXSPRITE g_lpSprite = nullptr;


CImageManager::CImageManager()
{
	D3DXCreateSprite(g_device, &m_lpSprite);
	g_lpSprite = m_lpSprite;
}


CImageManager::~CImageManager()
{
	SAFE_RELEASE(m_lpSprite);
	g_lpSprite = nullptr;
}

shared_ptr<texture> CImageManager::GetTexture(const wstring & key, const wstring & path)
{
	auto find = m_images.find(key);

	if (find != m_images.end())
		return find->second;


	LPDIRECT3DTEXTURE9	lpTexture;
	D3DXIMAGE_INFO		info;
	if (D3DXCreateTextureFromFileEx(g_device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &lpTexture) == S_OK);
	{
		return m_images.insert(make_pair(key, make_shared<texture>(lpTexture, info))).first->second;
	}
	
	return nullptr;
}

void texture::Render(const D3DXVECTOR2 & pos)
{
	if (lpTexture)
	{
		D3DXMATRIX mat;

		D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, 0.f, &D3DXVECTOR2(pos.x, pos.y));
		g_lpSprite->SetTransform(&mat);
		g_lpSprite->Draw(lpTexture, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

void texture::CenterRender(const D3DXVECTOR2 & pos, const RECT & rect)
{
	if (lpTexture)
	{
		D3DXMATRIX mat;

		D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, 0.f, &D3DXVECTOR2(pos.x, pos.y));
		g_lpSprite->SetTransform(&mat);
		g_lpSprite->Draw(lpTexture, &rect, &D3DXVECTOR3(80 / 2, 80 / 2, 0.f), nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

void texture::CenterRender(const D3DXVECTOR2 & pos)
{
	if (lpTexture)
	{
		D3DXMATRIX mat;

		D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, 0.f, &D3DXVECTOR2(pos.x - info.Width / 2, pos.y - info.Height / 2));
		g_lpSprite->SetTransform(&mat);
		g_lpSprite->Draw(lpTexture, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}
