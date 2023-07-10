//////////////////////////////////////////////////////////////////////
//
//  Crytek CryENGINE Source code
//
//  File:nullptr_Renderer.cpp
//  Description: Implementation of the nullptr renderer API
//
//  History:
//  -Jan 31,2001:Originally created by Marco Corbetta
//    -: taken over by Andrey Khonich
//
//////////////////////////////////////////////////////////////////////

#include "RenderPCH.h"
#include "nullptr_Renderer.h"

// init memory pool usage
#ifndef PS2
#ifndef _XBOX
// #if !defined(LINUX)
_ACCESS_POOL;
// #endif
#endif
#endif

#include "limits.h"

CnullptrRenderer* gcpnullptr = nullptr;

//////////////////////////////////////////////////////////////////////
CnullptrRenderer::CnullptrRenderer() {
    gcpnullptr = this;

#ifdef DEBUGALLOC
#undef new
#endif
    m_TexMan = new CnullptrTexMan;
#ifdef DEBUGALLOC
#define new DEBUG_CLIENTBLOCK
#endif
}

#include <cstdio>
//////////////////////////////////////////////////////////////////////
CnullptrRenderer::~CnullptrRenderer() {
    ShutDown();
}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::EnableTMU(bool enable) {}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::CheckError(const char* comment) {}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::BeginFrame() {}

//////////////////////////////////////////////////////////////////////
bool CnullptrRenderer::ChangeDisplay(unsigned int width, unsigned int height, unsigned int bpp) {
    return false;
}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::ChangeViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) {}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::Update() {
    m_TexMan->Update();
}

void CnullptrRenderer::GetMemoryUsage(ICrySizer* Sizer) {}

WIN_HWND CnullptrRenderer::GetHWND() {
    return nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// IMAGES DRAWING
////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::Draw2dImage(float xpos, float ypos, float w, float h, int texture_id, float s0, float t0, float s1, float t1, float angle, float r, float g, float b, float a,
                                float z) {}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::DrawImage(float xpos, float ypos, float w, float h, int texture_id, float s0, float t0, float s1, float t1, float r, float g, float b, float a) {}

///////////////////////////////////////////
void CnullptrRenderer::SetCullMode(int mode) {}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// ENVI/BLEND MODES
////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////
// FOG
////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////
void CnullptrRenderer::SetFog(float density, float fogstart, float fogend, const float* color, int fogmode) {}

///////////////////////////////////////////
bool CnullptrRenderer::EnableFog(bool enable) {
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// TEXGEN
////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////
void CnullptrRenderer::EnableTexGen(bool enable) {}

///////////////////////////////////////////
void CnullptrRenderer::SetTexgen(float scaleX, float scaleY, float translateX, float translateY) {}

void CnullptrRenderer::SetTexgen3D(float x1, float y1, float z1, float x2, float y2, float z2) {}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// MISC EXTENSIONS
////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////
void CnullptrRenderer::SetLodBias(float value) {}

///////////////////////////////////////////
void CnullptrRenderer::EnableVSync(bool enable) {}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::SelectTMU(int tnum) {}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// MATRIX FUNCTIONS
////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////
void CnullptrRenderer::PushMatrix() {}

///////////////////////////////////////////
void CnullptrRenderer::RotateMatrix(float a, float x, float y, float z) {}

void CnullptrRenderer::RotateMatrix(const Vec3d& angles) {}

///////////////////////////////////////////
void CnullptrRenderer::TranslateMatrix(float x, float y, float z) {}

void CnullptrRenderer::MultMatrix(float* mat) {}

void CnullptrRenderer::TranslateMatrix(const Vec3d& pos) {}

///////////////////////////////////////////
void CnullptrRenderer::ScaleMatrix(float x, float y, float z) {}

///////////////////////////////////////////
void CnullptrRenderer::PopMatrix() {}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void CnullptrRenderer::LoadMatrix(const Matrix44* src) {}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// MISC
////////////////////////////////////////////////////////////////////////////////////////////////////////

void CnullptrRenderer::Flush3dBBox(const Vec3d& mins, const Vec3d& maxs, const bool bSolid) {}

///////////////////////////////////////////
void CnullptrRenderer::Draw3dBBox(const Vec3d& mins, const Vec3d& maxs, int nPrimType) {}

///////////////////////////////////////////
int CnullptrRenderer::SetPolygonMode(int mode) {
    return 0;
}

///////////////////////////////////////////
void CnullptrRenderer::SetPerspective(const CCamera& cam) {}

///////////////////////////////////////////
void CnullptrRenderer::SetCamera(const CCamera& cam) {
    m_cam = cam;
}

void CnullptrRenderer::SetViewport(int x, int y, int width, int height) {}

void CnullptrRenderer::SetScissor(int x, int y, int width, int height) {}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::GetModelViewMatrix(float* mat) {}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::GetModelViewMatrix(double* mat) {}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::GetProjectionMatrix(double* mat) {}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::GetProjectionMatrix(float* mat) {}

//////////////////////////////////////////////////////////////////////
Vec3d CnullptrRenderer::GetUnProject(const Vec3d& WindowCoords, const CCamera& cam) {
    return (Vec3d(0, 0, 0));
}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::DrawQuad(const Vec3d& right, const Vec3d& up, const Vec3d& origin, int nFlipmode /*=0*/) {}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::ProjectToScreen(float ptx, float pty, float ptz, float* sx, float* sy, float* sz) {}

int CnullptrRenderer::UnProject(float sx, float sy, float sz, float* px, float* py, float* pz, const float modelMatrix[16], const float projMatrix[16], const int viewport[4]) {
    return 0;
}

//////////////////////////////////////////////////////////////////////
int CnullptrRenderer::UnProjectFromScreen(float sx, float sy, float sz, float* px, float* py, float* pz) {
    return 0;
}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::Draw2dLine(float x1, float y1, float x2, float y2) {}

void CnullptrRenderer::DrawLine(const Vec3d& vPos1, const Vec3d& vPos2) {}

void CnullptrRenderer::DrawLineColor(const Vec3d& vPos1, const CFColor& vColor1, const Vec3d& vPos2, const CFColor& vColor2) {}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::ScreenShot(const char* filename) {}

int CnullptrRenderer::ScreenToTexture() { // for death effects
    return 0;
}

void CnullptrRenderer::ResetToDefault() {}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// FONT RENDERING
////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////
void CnullptrRenderer::WriteXY(CXFont* currfont, int x, int y, float xscale, float yscale, float r, float g, float b, float a, const char* message, ...) {}

void CnullptrRenderer::SetMaterialColor(float r, float g, float b, float a) {}

char* CnullptrRenderer::GetStatusText(ERendStats type) {
    return nullptr;
}

void CnullptrRenderer::DrawBall(float x, float y, float z, float radius) {}

void CnullptrRenderer::DrawBall(const Vec3d& pos, float radius) {}

void CnullptrRenderer::DrawPoint(float x, float y, float z, float fSize) {}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::ClearDepthBuffer() {}

void CnullptrRenderer::ClearColorBuffer(const Vec3d vColor) {}

void CnullptrRenderer::ReadFrameBuffer(unsigned char* pRGB, int nSizeX, int nSizeY, bool bBackBuffer, bool bRGBA, int nScaledX, int nScaledY) {}

void CnullptrRenderer::SetFogColor(float* color) {}

void CnullptrRenderer::TransformTextureMatrix(float x, float y, float angle, float scale) {}

void CnullptrRenderer::ResetTextureMatrix() {}

void CnullptrRenderer::SetClipPlane(int id, float* params) {}

void CnullptrRenderer::DrawQuad(float dy, float dx, float dz, float x, float y, float z) {}

void CnullptrRenderer::EnableAALines(bool bEnable) {}

//////////////////////////////////////////////////////////////////////
void CnullptrRenderer::Set2DMode(bool enable, int ortox, int ortoy) {}

// ps2 to create matrix
void CnullptrRenderer::MakeMatrix(const Vec3d& pos, const Vec3d& angles, const Vec3d& scale, Matrix44* mat) {}

//=========================================================================================
