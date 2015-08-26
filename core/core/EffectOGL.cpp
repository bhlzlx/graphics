#include "ShaderOGL.h"
#include "EffectOGL.h"
#include <memory.h>




namespace Graphics
{
    GLenum CullMode2OGL(Graphics::CULL_MODE cullmode)
    {
        switch( cullmode )
        {
            case CULL_MODE_BACK: return GL_BACK;
            case CULL_MODE_FRONT: return GL_FRONT;
            default :return GL_NONE;
        }
    }
    
    GLenum DepthFunc2OGL(Graphics::CMP_FUNC func)
    {
        switch( func )
        {
            case CMP_FUNC_ALWAYS: return GL_ALWAYS;
            case CMP_FUNC_EQUAL: return GL_EQUAL;
            case CMP_FUNC_GREATER: return GL_GREATER;
            case CMP_FUNC_GREATER_EQUAL: return GL_GEQUAL;
            case CMP_FUNC_LESS: return GL_LESS;
            case CMP_FUNC_LESS_EQUAL: return GL_LEQUAL;
            case CMP_FUNC_NEVER: return GL_NEVER;
            case CMP_FUNC_NOT_EQUAL: return GL_NOTEQUAL;
            default: return GL_LEQUAL;
        }
    }

    EffectOGL::EffectOGL()
    {
    }

    EffectOGL::~EffectOGL()
    {
    }
    
    EffectOGL * EffectOGL::CreateEffect( EffectDesc * _pDesc)
    {
        EffectOGL * pEffect = new EffectOGL();
        memcpy(&pEffect->m_desc,_pDesc,sizeof(EffectDesc));
        pEffect->m_pShader = ShaderOGL::ShaderFromStrings(_pDesc->szVertexShaderText,_pDesc->szPixelShaderText);
        return pEffect;
    }
    
    bool EffectOGL::Begin()
    {
        // 设置shader
        this->m_pShader->Active();
        // cull mode
        if(this->m_desc.renderState.cullMode == CULL_MODE_NONE)
        {
            glDisable(GL_CULL_FACE);
        }
        else
        {
            glCullFace(CullMode2OGL(m_desc.renderState.cullMode));
        }
        // 开启深度测试
        if(m_desc.renderState.depthTestable)
        {
            glEnable(GL_DEPTH_TEST);
            // 深度没试函数
            glDepthFunc(DepthFunc2OGL(m_desc.renderState.depthFunc));
        }
        else
        {
            glDisable(GL_DEPTH_TEST);
        }
        // 深度缓冲可写性
        if(m_desc.renderState.depthWritable)
        {
            glDepthMask(GL_TRUE);
        }
        else
        {
            glDepthMask(GL_FALSE);
        }
        // 可裁剪
        if(m_desc.renderState.scissorable)
        {
            glEnable(GL_SCISSOR_TEST);
        }
        else
        {
            glDisable(GL_SCISSOR_TEST);
        }
    }
    
    void EffectOGL::End()
    {
        m_pShader->UseNullShader();
        glDisable(GL_SCISSOR_TEST); 
    }
    
    void EffectOGL::Release()
    {
        this->m_pShader->Release();
        delete this;
    }
}

