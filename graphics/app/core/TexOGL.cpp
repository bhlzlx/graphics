#include <gl/glew.h>
#include "TexOGL.h"
#include <memory.h>
#include <GL/gl.h>
#include <assert.h>


class SamplerOGL;
class PIXEL_FORMAT_A8;
namespace Graphics
{    
    GLenum TexAddr2OGL(TEX_ADDRESS &addr)
    {
        switch(addr)
        {
            case TEX_ADDRESS_MIRROR: return GL_MIRRORED_REPEAT;
            case TEX_ADDRESS_REPEAT: return GL_REPEAT;
            case TEX_ADDRESS_CLAMP_TO_ZERO: return GL_CLAMP_TO_EDGE;
            case TEX_ADDRESS_CLAMP: return GL_CLAMP_TO_BORDER;
            default: return GL_REPEAT;
        }
    }
    
    GLenum TexFilter2OGL(TEX_FILTER &filter)
    {
        switch(filter)
        {
            case TEX_FILTER_LINEAR: return GL_LINEAR;
            case TEX_FILTER_POINT: return GL_NEAREST;
            case TEX_FILTER_MIP_LINEAR: return GL_LINEAR_MIPMAP_LINEAR;
            case TEX_FILTER_MIP_POINT: return GL_NEAREST_MIPMAP_NEAREST;
			case TEX_FILTER_NONE: return GL_NEAREST;
        }
		return GL_NEAREST;
    }
    GLenum PixelFormat2OGL( PIXEL_FORMAT format)
    {
        switch(format)
        {
            case PIXEL_FORMAT_RGBA8888:
            {
                return GL_RGBA;
            }
            case PIXEL_FORMAT_A8:
            {
                return GL_RED;
            }
            case PIXEL_FORMAT_DEPTH_STENCIL:
            {
                return GL_DEPTH_STENCIL;
            }
            case PIXEL_FORMAT_DEPTH_32: return GL_DEPTH_COMPONENT;
            case PIXEL_FORMAT_STENCIL_8: return GL_STENCIL_INDEX;
            case PIXEL_FORMAT_PVRT: return GL_FALSE;
        }
        return GL_FALSE;
    }
	
	Size<uint32_t>& TexOGL::GetSize()
	{
		return m_desc.size;
	}
    
    
    TexDesc* TexOGL::GetDesc()
    {
        return &this->m_desc;
    }
    
    void TexOGL::Release()
    {
        glDeleteTextures(1,&m_texture);
        delete this;
    }
    
    TexOGL * TexOGL::CreateTex(TexDesc * _pTexDesc , bool autoMip)
    {
        TexOGL * pTex = new TexOGL();
        
        glGenTextures(1,&pTex->m_texture);        
        glBindTexture(GL_TEXTURE_2D,pTex->m_texture);
        
        GLenum format = PixelFormat2OGL(_pTexDesc->ePixelFormat);
        
        switch(_pTexDesc->ePixelFormat)
        {
            case PIXEL_FORMAT_DEPTH_STENCIL:
            {
                glTexImage2D(GL_TEXTURE_2D,0,GL_DEPTH24_STENCIL8,_pTexDesc->size.width,_pTexDesc->size.height,0,GL_DEPTH_STENCIL,GL_UNSIGNED_INT_24_8,NULL);
                break;
            }
            case PIXEL_FORMAT_DEPTH_32:
            {
                glTexImage2D(GL_TEXTURE_2D,0,GL_DEPTH_COMPONENT32F,_pTexDesc->size.width,_pTexDesc->size.height,0,GL_DEPTH_COMPONENT,GL_FLOAT,NULL);
                break;
            }
            case PIXEL_FORMAT_STENCIL_8:
            {
                glTexImage2D(GL_TEXTURE_2D,0,GL_STENCIL_INDEX8,_pTexDesc->size.width,_pTexDesc->size.height,0,GL_STENCIL_INDEX,GL_UNSIGNED_BYTE,NULL);
                break;
            }
            default:
            {
                glTexImage2D(GL_TEXTURE_2D,0,format,_pTexDesc->size.width,_pTexDesc->size.height,0,format,GL_UNSIGNED_BYTE,NULL);
                if(autoMip)
                    glGenerateMipmap(GL_TEXTURE_2D);
            }
        }
        
        SamplerOGL sampler(autoMip);
        pTex->ApplySamplerState(&sampler);

        memcpy(&pTex->m_desc,_pTexDesc,sizeof(TexDesc));
        
        return pTex;
    }
    
    TexOGL * TexOGL::CreateChessTex()
    {
        static const unsigned while_color = 0xffffffff;
        static const unsigned black_color = 0xff000000;

        unsigned bitmap[64][64] = {black_color};

        int _w,_ww;
        for(int i = 0;i<64;++i)
        {
			int _s,_ss;
            _ss = 1;
            _s = i/4;
            if( _s % 2 == 0)
            {
                _ss = 0;
            }
            for(int j = 0;j<64;++j)
            {
                _ww = 1;
                _w  = j/4;
                if( _w % 2 == 0)
                {
                    _ww = 0;
                }
                if(_ww == _ss)
                {
                    bitmap[i][j] = while_color;
                }
            }
        }

        int error;
        error = glGetError();
        TexOGL * pTex = new TexOGL;
		pTex->m_desc.size.height = pTex->m_desc.size.width = 64;
        glGenTextures(1,&pTex->m_texture);
        error = glGetError();

        glBindTexture(GL_TEXTURE_2D,pTex->m_texture);
        
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap);
        glGenerateMipmap(GL_TEXTURE_2D);
        // 新版api的创建方式
        //glTexStorage2D(GL_TEXTURE_2D,4,GL_RGBA8,64,64);
        //glTexSubImage2D(GL_TEXTURE_2D,0,0,0,64,64,GL_RGBA,GL_UNSIGNED_BYTE,bitmap);
        error = glGetError();
        SamplerOGL sampler(true);
        pTex->ApplySamplerState(&sampler);

        assert(GL_NO_ERROR == error);
        
        return pTex;
    }
    
    TexOGL * TexOGL::CreateBlackTex()
    {
        static const unsigned black_color = 0xff000000;

        unsigned bitmap[64][64] = {black_color};

        int error;
        error = glGetError();
        TexOGL * pTex = new TexOGL;
        glGenTextures(1,&pTex->m_texture);
        error = glGetError();

        glBindTexture(GL_TEXTURE_2D,pTex->m_texture);
        
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap);
        glGenerateMipmap(GL_TEXTURE_2D);
        // 新版api的创建方式
        //glTexStorage2D(GL_TEXTURE_2D,4,GL_RGBA8,64,64);
        //glTexSubImage2D(GL_TEXTURE_2D,0,0,0,64,64,GL_RGBA,GL_UNSIGNED_BYTE,bitmap);
        error = glGetError();
        SamplerOGL sampler(true);
        pTex->ApplySamplerState(&sampler);

        assert(GL_NO_ERROR == error);
        return pTex;
    }
    
    TexOGL * TexOGL::CreateWhiteTex()
    {
        static const unsigned while_color = 0xffffffff;

        unsigned bitmap[64][64] = {while_color};

        int error;
        error = glGetError();
        TexOGL * pTex = new TexOGL;
        glGenTextures(1,&pTex->m_texture);
        error = glGetError();

        glBindTexture(GL_TEXTURE_2D,pTex->m_texture);
        
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap);
        glGenerateMipmap(GL_TEXTURE_2D);
        // 新版api的创建方式
        //glTexStorage2D(GL_TEXTURE_2D,4,GL_RGBA8,64,64);
        //glTexSubImage2D(GL_TEXTURE_2D,0,0,0,64,64,GL_RGBA,GL_UNSIGNED_BYTE,bitmap);
        error = glGetError();
        SamplerOGL sampler(true);
        pTex->ApplySamplerState(&sampler);
        assert(GL_NO_ERROR == error);
        return pTex;
    }
    
    void TexOGL::ApplySamplerState(SamplerOGL * _pSampler)
    {
        glBindTexture(GL_TEXTURE_2D,this->m_texture);        
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,_pSampler->addressMode_S);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,_pSampler->addressMode_T);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,_pSampler->magFilter);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,_pSampler->minFilter);
        glBindTexture(GL_TEXTURE_2D,0);
    }
    
    SamplerOGL::SamplerOGL(SamplerState & samplerState)
    {
        this->magFilter = TexFilter2OGL(samplerState.MagFilter);
        this->minFilter = TexFilter2OGL(samplerState.MinFilter);
        this->addressMode_S = TexAddr2OGL(samplerState.AddressU);
        this->addressMode_T = TexAddr2OGL(samplerState.AddressV);
    }
    
    TexOGL * TexOGL::CreateTexWidthImage( Image * _pImage,bool _mipmap )
    {
        GLint error;
        TexOGL * pTex = new TexOGL;
        pTex->m_desc.ePixelFormat = PIXEL_FORMAT_RGBA8888;
        pTex->m_desc.eTexClass = TEX_CLASS_STATIC_RAW;
		pTex->m_desc.size.width = _pImage->nWidth;
		pTex->m_desc.size.height = _pImage->nHeight;
        glGenTextures(1,&pTex->m_texture);
        error = glGetError();
        glBindTexture(GL_TEXTURE_2D,pTex->m_texture);        
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, _pImage->nWidth, _pImage->nHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, _pImage->pData);
        if(_mipmap)
        {
            glGenerateMipmap(GL_TEXTURE_2D);            
        }
        // 新版api的创建方式
        //glTexStorage2D(GL_TEXTURE_2D,4,GL_RGBA8,64,64);
        //glTexSubImage2D(GL_TEXTURE_2D,0,0,0,64,64,GL_RGBA,GL_UNSIGNED_BYTE,bitmap);
        error = glGetError();
        SamplerOGL sampler(_mipmap);
        pTex->ApplySamplerState(&sampler);
        assert(GL_NO_ERROR == error);
        return pTex;
    }
    
    SamplerOGL::SamplerOGL( bool _bMipmap)
    {
        if(_bMipmap)
        {
            this->magFilter = GL_NEAREST;
            this->minFilter = GL_LINEAR_MIPMAP_NEAREST;
        }
        else
        {
            this->magFilter = GL_NEAREST;
            this->minFilter = GL_LINEAR;
        }
        this->addressMode_S = GL_REPEAT;
        this->addressMode_T = GL_REPEAT;
    }
	
	void TexOGL::Bind()
	{
		glBindTexture(GL_TEXTURE_2D,this->m_texture);
	}

}

