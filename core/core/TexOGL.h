#ifndef __TEXOGL_H__
#define __TEXOGL_H__

#include "device.h"

namespace Graphics
{    
    struct SamplerOGL;

    struct TexOGL:public ITex
    {
        TexDesc         m_desc;
        GLuint          m_texture;
        
        void Release();
        TexDesc * GetDesc();
		void Bind();
        void ApplySamplerState(SamplerOGL * _pSampler);
        
        static TexOGL * CreateTex(TexDesc * _pTexDesc , bool autoMip = false);
        static TexOGL * CreateChessTex();
        static TexOGL * CreateBlackTex();
        static TexOGL * CreateWhiteTex();
        static TexOGL * CreateTexWidthImage( Image * ,bool);
    };
    /*
     *  TEX_ADDRESS     AddressU;
        TEX_ADDRESS     AddressV;
        TEX_ADDRESS     AddressW;
        
        TEX_FILTER      MinFilter;
        TEX_FILTER      MagFilter;
        bool            MipFilter;
     */
    struct SamplerOGL
    {
        GLuint addressMode_S;
        GLuint addressMode_T;
        GLuint minFilter;
        GLuint magFilter;
        SamplerOGL(SamplerState & samplerState);
        SamplerOGL(bool);
    };
}

#endif // __TEXOGL_H__
