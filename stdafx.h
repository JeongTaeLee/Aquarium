#pragma once

using namespace std;

#define g_device DXUTGetD3D9Device()

inline HRESULT LoadTexture(const TCHAR * _path, D3DXIMAGE_INFO info, LPDIRECT3DTEXTURE9 texture) {
	return D3DXCreateTextureFromFileEx(g_device, _path, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &texture);
}
#define SAFE_DELETE(p) if(p) {delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p; p = nullptr;}
#define SAFE_RELEASE(p) if(p) {p->Release(); p = nullptr;}

#define DEBUG_LOG(s) cout << s << endl

const int WINWIDTH = 1280;
const int WINHEIGHT	= 720;

#include <iostream>
#include <memory>

#include <map>
#include <list>
#include <vector>
#include <string>

#include "ImageManager.h"