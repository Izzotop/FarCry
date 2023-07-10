/*=============================================================================
  PS2_Textures.cpp : PS2 specific texture manager implementation.
  Copyright (c) 2001 Crytek Studios. All Rights Reserved.

  Revision history:
    * Created by Honitch Andrey

=============================================================================*/

#include "RenderPCH.h"
#include "nullptr_Renderer.h"

TTextureMap CnullptrTexMan::m_RefTexs;
CnullptrTexUnit CnullptrTexMan::m_TUState[8];
int nTexSize = 0;
int nFrameTexSize = 0;
int BindSizes[TX_LASTBIND];
int BindFrame[TX_LASTBIND];

//=================================================================================

byte* STexPic::GetData32() {
    return nullptr;
}

bool STexPic::SetFilter(int nFilter) {
    return true;
}

void STexPic::SaveJPG(const char* nam, bool bMips) {}

void STexPic::SaveTGA(const char* nam, bool bMips) {}

void STexPic::ReleaseDriverTexture() {}

void STexPic::SetWrapping() {}

void STexPic::SetFilter() {}

STexPic* CnullptrTexMan::GetByID(int Id) {
    if (Id >= TX_FIRSTBIND) {
        int n = Id - TX_FIRSTBIND;
        if (n < m_Textures.Num()) {
            STexPic* tp = m_Textures[n];
            if (tp && tp->m_Bind == Id)
                return tp;
        }
    }
    TTextureMapItor it = m_RefTexs.find(Id);
    if (it != m_RefTexs.end())
        return it->second;
    return nullptr;
}

void CnullptrTexMan::RemoveFromHash(int Id, STexPic* ti) {
    TTextureMapItor it = m_RefTexs.find(Id);
    if (it != m_RefTexs.end()) {
        if (ti)
            assert(ti == it->second);
        m_RefTexs.erase(Id);
    }
}

STexPic* CnullptrTexMan::AddToHash(int Id, STexPic* ti) {
    TTextureMapItor it = m_RefTexs.find(Id);
    if (it == m_RefTexs.end())
        m_RefTexs.insert(TTextureMapItor::value_type(Id, ti));
    else
        assert(ti == it->second);
    return ti;
}

void STexPic::SetClamp(bool bEnable) {}

void CnullptrTexMan::SetTexture(int Id, ETexType eTT) {}

void STexPic::Set(int nTexSlot) {}

int STexPic::DstFormatFromTexFormat(ETEX_Format eTF) {
    return 0;
}
int STexPic::TexSize(int Width, int Height, int DstFormat) {
    return 0;
}

int SShaderTexUnit::mfSetTexture(int nt) {
    return 1;
}

bool SShaderPass::mfSetTextures() {
    return true;
}
void SShaderPass::mfResetTextures() {}

CnullptrTexMan::~CnullptrTexMan() {}

STexPic* CnullptrTexMan::CreateTexture() {
#ifdef DEBUGALLOC
#undef new
#endif
    return new STexPic;
#ifdef DEBUGALLOC
#define new DEBUG_CLIENTBLOCK
#endif
}

bool CnullptrTexMan::SetFilter(char* tex) {
    return true;
}

void CnullptrTexMan::CalcMipsAndSize(STexPic* ti) {}

ETEX_Format CnullptrTexMan::GetTexFormat(int PS2Format) {
    return eTF_Unknown;
}

int CnullptrTexMan::GetTexDstFormat(ETEX_Format eTF) {
    return 0;
}

int CnullptrTexMan::GetTexSrcFormat(ETEX_Format eTF) {
    return 0;
}

int CnullptrTexMan::TexSize(int wdt, int hgt, int mode) {
    return 0;
}

//==================================================================================
extern int nTexSize;
extern int nFrameTexSize;

int TexCallback(const void* arg1, const void* arg2) {
    STexPic** pi1 = (STexPic**)arg1;
    STexPic** pi2 = (STexPic**)arg2;
    STexPic* ti1 = *pi1;
    STexPic* ti2 = *pi2;
    if (ti1->m_Size > ti2->m_Size)
        return -1;
    if (ti1->m_Size < ti2->m_Size)
        return 1;
    return 0;
}

STexPic* CnullptrTexMan::CopyTexture(const char* name, STexPic* tiSrc, int CubeSide) {
    return nullptr;
}

STexPic* CnullptrTexMan::CreateTexture(const char* name, int wdt, int hgt, int Depth, uint flags, uint flags2, byte* dst, ETexType eTT, float fAmount1, float fAmount2, int DXTSize,
                                    STexPic* ti, int bind, ETEX_Format eTF, const char* szSourceName) {
    return nullptr;
}

byte* CnullptrTexMan::GenerateDXT_HW(STexPic* ti, EImFormat eF, byte* dst, int* numMips, int* DXTSize, bool bMips) {
    return nullptr;
}

void CnullptrTexMan::UpdateTextureData(STexPic* pic, byte* data, int USize, int VSize, bool bProc, int State, bool bPal) {}

//=========================================================================
// Offscreen drawing functions

//=========================================================================
// Renderer interface functions

void CnullptrRenderer::SetTexture(int tnum, ETexType Type) {}

void CnullptrRenderer::SetTexture3D(int tid3d) {}

uint CnullptrRenderer::DownLoadToVideoMemory(unsigned char* data, int w, int h, ETEX_Format eTFSrc, ETEX_Format eTFDst, int nummipmap, bool repeat, int filter, int Id,
                                          char* szCacheName, int flags) {
    return 0;
}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::UpdateTextureInVideoMemory(uint tnum, unsigned char* newdata, int posx, int posy, int w, int h, ETEX_Format eTF) {}

void CnullptrRenderer::RemoveTexture(ITexPic* pTexPic) {
    if (!pTexPic)
        return;

    STexPic* pSTexPic = (STexPic*)pTexPic;
    pSTexPic->Release(false);
}

void CnullptrRenderer::RemoveTexture(unsigned int nTextureId) {
    if (nTextureId) {
        STexPic* tp = m_TexMan->GetByID(nTextureId);
        if (tp)
            tp->Release(false);
    }
}

///////////////////////////////////////////////////////////////////////////////////
uint CnullptrRenderer::LoadTexture(const char* _filename, int* tex_type, unsigned int def_tid, bool compresstodisk, bool bWarn) {
    return m_TexMan->m_Text_NoTexture->GetTextureID();
}

int CnullptrRenderer::LoadAnimatedTexture(const char* szFileNameFormat, const int nCount) {
    return 0;
}

void CnullptrRenderer::SetTexClampMode(bool clamp) {}

void CnullptrRenderer::DrawObjSprites(list2<CStatObjInst*>* pList, float fMaxViewDist, CObjManager* pObjMan) {}

uint CnullptrRenderer::MakeSprite(float _object_scale, int nTexSize, float angle, IStatObj* pStatObj, uchar* _pTmpBuffer, uint def_tid) {
    return 0;
}

uint CnullptrRenderer::Make3DSprite(int nTexSize, float fAngleStep, IStatObj* pStatObj) {
    return 0;
}

int CnullptrRenderer::GenerateAlphaGlowTexture(float k) {
    return 0;
}

bool CnullptrRenderer::EF_SetLightHole(Vec3d vPos, Vec3d vNormal, int idTex, float fScale, bool bAdditive) {
    return false;
}

STexPic* CnullptrRenderer::EF_MakePhongTexture(int Exp) {
    return nullptr;
}

void STexPic::Preload(int Flags) {}
