// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <cassert>


#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

extern HWND g_hWnd;
#define Safe_release(p) {if(p) p->Release(); p = NULL; }
#define Safe_Delete(p) {if(p) delete p; p = NULL;}\
// \ -> 이거 뒤에 공백 확인
#define Singletone(class_name)\
						private:\
							class_name(void);\
							~class_name(void);\
						public:\
							static class_name* GetInstance()\
							{\
							static class_name instance; \
							return &instance;\
							}

#define Synthesize(varType, varName, funName) \
		protected : varType varName;\
		public: inline varType Get##funName(void) const { return varName; }\
			public: inline void Set##funName(varType var){varName = var;}


#define Synthesize_Pass_By_Ref(varType, varName, funName)\
	protected: varType varName;\
	public: inline varType& Get##funName(void) {return varName;}\
	public: inline void Set##funName(varType& var) { varName = var; }

#define Safe_Add_Ref(p) {if(p) p->AddRef();}

#define Synthesize_Add_Ref(varType, varName, funName) \
		protected : varType varName;\
		public: inline varType Get##funName(void) const { return varName; }\
		public: inline void Set##funName(varType var){\
						if(varName != var){\
							Safe_Add_Ref(var);\
							Safe_release(varName);\
							varName = var;\
						}\
					}


struct ST_PC_VERTEX
{
	D3DXVECTOR3 p;
	D3DCOLOR c;
	enum{ FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE};

};

struct ST_PNT_VERTEX
{
	D3DXVECTOR3 p;
	D3DXVECTOR3 n;
	D3DXVECTOR2 t;
	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 };

};

struct ST_PT_VERTEX
{
	D3DXVECTOR3 p;
	D3DXVECTOR2 t;
	enum { FVF = D3DFVF_XYZ | D3DFVF_TEX1 };

};
#include "cDeviceManager.h"
#include "cObject.h"
#include "cObjectManager.h"
#include "cTextureManager.h"
#include "iMap.h"