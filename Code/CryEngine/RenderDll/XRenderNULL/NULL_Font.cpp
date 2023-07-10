/*=============================================================================
  nullptr_Font.cpp : nullptr font functions.
  Copyright (c) 2001 Crytek Studios. All Rights Reserved.

  Revision history:
    * Created by Honitch Andrey

=============================================================================*/

#undef THIS_FILE
static char THIS_FILE[] = __FILE__;

#include "RenderPCH.h"
#include "nullptr_Renderer.h"

#include "../CryFont/FBitmap.h"

bool CnullptrRenderer::FontUpdateTexture(int nTexId, int X, int Y, int USize, int VSize, byte* pData) {
    return true;
}

bool CnullptrRenderer::FontUploadTexture(class CFBitmap* pBmp, ETEX_Format eTF) {
    return true;
}
void CnullptrRenderer::FontReleaseTexture(class CFBitmap* pBmp) {}

void CnullptrRenderer::FontSetTexture(class CFBitmap* pBmp, int nTexFiltMode) {}

void CnullptrRenderer::FontSetRenderingState(unsigned long nVPWidth, unsigned long nVPHeight) {}

void CnullptrRenderer::FontSetBlending(int blendSrc, int blendDest) {}

void CnullptrRenderer::FontRestoreRenderingState() {}

void CnullptrRenderer::FontSetState(bool bRestore) {}

void CnullptrRenderer::PrintToScreen(float x, float y, float size, const char* buf) {}
