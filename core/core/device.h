#ifndef __GPAPHICS_DEVICE_H__
#define __GPAPHICS_DEVICE_H__

#include <stdint.h>
#include "buffer/buffer.h"
#include <gl/glew.h>

#define BOOL GLboolean

#define __check_error__  uint32_t error = glGetError(); if(error != GL_OK)

namespace Graphics
{   
    template < class T>
    struct Size
    {
        T width,height;
        Size(T _w = 0,T _h = 0)
        {
            width = _w;
            height = _h;
        }
    };
    template < class T>
    struct Rect
    {
      T x,y,width,height;
      Rect(T _x = 0,T _y = 0,T _width = 0,T _height = 0)
      {
          x = _x;
          y = _y;
          width = _width;
          height = _height;
      }
      
      Size<T> GetSize()
      {
          return Size<T>(this->width,this->height);
      }
    };
    enum DRAW_TYPE
    {
        DRAW_TYPE_WIREDFRAME,
        DRAW_TYPE_TRINGLE
    };
    
    enum CULL_MODE
    {
        CULL_MODE_NONE,
        CULL_MODE_FRONT,
        CULL_MODE_BACK,
    };
    
    enum CMP_FUNC
    {
        CMP_FUNC_GREATER,
        CMP_FUNC_GREATER_EQUAL,
        CMP_FUNC_EQUAL,
        CMP_FUNC_NOT_EQUAL,
        CMP_FUNC_LESS_EQUAL,
        CMP_FUNC_LESS,
        CMP_FUNC_ALWAYS,
        CMP_FUNC_NEVER
    };
    
    enum BLEND_FACTOR
    {
        BLEND_FACTOR_ZERO,
        BLEND_FACTOR_ONE,
        BLEND_FACTOR_SRCCOLOR,
        BLEND_FACTOR_INVSRCCOLOR,
        BLEND_FACTOR_SRCALPHA,
        BLEND_FACTOR_INVSRCALPHA,
        BLEND_FACTOR_DESTCOLOR,
        BLEND_FACTOR_INVDESTCOLOR,
        BLEND_FACTOR_DESTALPHA,
        BLEND_FACTOR_INVDESTALPHA
    };
    
    enum BLEND_OP
    {
        BLEND_OP_ADD,
        BLEND_OP_SUBTRACT,
        BLEND_OP_REVSUBTRACT
    };
    
    enum STENCIL_OP
    {
        STENCIL_OP_KEEP,
        STENCIL_OP_ZERO,
        STENCIL_OP_REPLACE,
    };
    
    // texture ref
    enum TEX_ADDRESS
    {
        TEX_ADDRESS_REPEAT,
        TEX_ADDRESS_CLAMP,
        TEX_ADDRESS_MIRROR,
        TEX_ADDRESS_CLAMP_TO_ZERO,
        TEX_ADDRESS_CLAMP_TO_ONE,
    };
    
    enum TEX_FILTER
    {
        TEX_FILTER_NONE,
        TEX_FILTER_POINT,
        TEX_FILTER_LINEAR,
        TEX_FILTER_MIP_POINT,
        TEX_FILTER_MIP_LINEAR
    };
    
    struct SamplerState
    {
        TEX_ADDRESS     AddressU;
        TEX_ADDRESS     AddressV;
        TEX_ADDRESS     AddressW;
        
        TEX_FILTER      MinFilter;
        TEX_FILTER      MagFilter;
    };
    
    enum TEX_CLASS
    {
        TEX_CLASS_STATIC_RAW,
        TEX_CLASS_STATIC_COMPRESSED,
        TEX_CLASS_DYNAMIC,
        TEX_CLASS_RENDERTARGET,
    };
    
    enum PIXEL_FORMAT
    {
        PIXEL_FORMAT_RGBA8888,
        PIXEL_FORMAT_A8,
        PIXEL_FORMAT_PVRT,
        PIXEL_FORMAT_DEPTH_STENCIL,
        PIXEL_FORMAT_DEPTH_32,
        PIXEL_FORMAT_STENCIL_8
    };
    
    //// 基本数据结构
    
    struct ClearOP
    {
        GLboolean           bClearColor;
        float               vClearColors[4];
        GLboolean           bClearDepth;
        float               fDepthValue;
        GLboolean           bClearStencil;
        int16_t             nStencilValue;
        
        ClearOP()
        {
            bClearColor = GL_TRUE;
            vClearColors[0] = 1.0f;
            vClearColors[1] = 1.0f;
            vClearColors[2] = 1.0f;
            vClearColors[3] = 1.0f;
            bClearDepth = GL_TRUE;
            fDepthValue = 1.0f;
            bClearStencil = false;
        }
        
        void SetClearColor(float red,float green,float blue,float alpha)
        {
            this->vClearColors[0] = red;
            this->vClearColors[1] = green;
            this->vClearColors[2] = blue;
            this->vClearColors[3] = alpha;
        }
    };
    
    struct TexDesc
    {
        TEX_CLASS           eTexClass;
        PIXEL_FORMAT        ePixelFormat;
        uint16_t            nSizeX;
        uint16_t            nSizeY;
    };
    
    struct RenderState
    {
        BOOL            depthWritable;
        BOOL            depthTestable;
        CMP_FUNC        depthFunc;
        
        BOOL            redChannelWritable;
        BOOL            greenChannelWritable;
        BOOL            blueChannelWritable;
        BOOL            alphaChannelWritable;
        
        CULL_MODE       cullMode;
        
        BOOL            scissorable;
        
        BOOL            blendable;
        BLEND_FACTOR    blendSrc;
        BLEND_FACTOR    blendDest;
        BLEND_OP        blendOpt;
        RenderState()
        {
            depthWritable = true;
            depthTestable = true;
            depthFunc = CMP_FUNC_LESS_EQUAL;
            
            redChannelWritable = true;
            greenChannelWritable = true;
            blueChannelWritable = true;
            
            cullMode = CULL_MODE_BACK;
            blendable = false;
            scissorable = false;
        }
    };
    
    
    enum SEMANTICS_ENUM
    {
        VERTEX_POINT1,
        VERTEX_POINT2,
        VERTEX_POINT3,
        VERTEX_POINT4,
    };
    
    enum VERTICES_SLOT
    {
        VERTICES_SLOT_00 = 0,
        VERTICES_SLOT_01,
        VERTICES_SLOT_02,
        VERTICES_SLOT_03,
        VERTICES_SLOT_04,
        VERTICES_SLOT_05,
        VERTICES_SLOT_MAX
    };
    
    enum TEXTURE_ENUM
    {
        TEXTURE_00 = 0,
        TEXTURE_01,
        TEXTURE_02,
        TEXTURE_03,
        TEXTURE_04,
        TEXTURE_05,
        TEXTURE_06,
        TEXTURE_07,
        TEXTURE_SHADOW_00,
        TEXTURE_SHADOW_01,
        TEXTURE_SHADOW_02,
        TEXTURE_SHADOW_03,
        TEXTURE_SHADOW_MAX
    };
    
    struct DepthStencilDesc
    {
        int16_t nWidth;
        int16_t nHeight;
    };
    
    struct RenderTargetDesc
    {
        int16_t         nWidth;
        int16_t         nHeight;
        PIXEL_FORMAT    eFormat;
    };
    
    struct EffectDesc
    {
        const char *            szVertexShaderText;
        const char *            szPixelShaderText;
        RenderState             renderState;
        SamplerState            samplerState;
        EffectDesc()
        {
            
        }
    };
    
    struct ITex
    {
        virtual void Release() = 0;
    };
    
    struct IRenderTarget
    {
        virtual ITex * GetColorTex() = 0;
        virtual const RenderTargetDesc * GetDesc() = 0;
        virtual void Release() = 0;
    };
    
    struct IDepthStencil
    {   
        virtual const DepthStencilDesc * GetDesc() = 0;
        virtual void Release() = 0;
    };
    
    const int8_t MAX_RENDER_TARGETS = 4;
    
    struct RenderPipelineDesc
    {
        IRenderTarget * pRenderTargets[MAX_RENDER_TARGETS];
        IDepthStencil * pDepthStencil;
        int8_t          nRendertargetCount;
        ClearOP         clearOP;
    };
    
    struct IRenderPipeline
    {
        virtual bool Begin() = 0;
        virtual void End() = 0;
        virtual const RenderPipelineDesc * GetDesc() = 0;
        virtual void Release() = 0;
    };
    
    struct ISampler
    {
        virtual void SetTexture(ITex * _pTex) = 0;
    };
    
    struct IVertexBuffer
    {
        virtual void Release();
    };
    
    struct Image
    {
        uint16_t    nWidth;
        uint16_t    nHeight;
        uint8_t *   pData;
        static Image * ImageFromPng( iBuffer *);
        void Release();
    };
    
    extern Size<int> GetWindowSize();
};
#endif
