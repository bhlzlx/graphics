//
// Created by phantom on 2015/5/18.
//
#include <cassert>
#include <cstring>
#include <cstdio>
#include "common/log/logger.h"
#include "ShaderOGL.h"

namespace Graphics
{


GLuint load_shader(const char* szShader, GLuint mode)
{
    GLuint id;
    id = glCreateShader(mode);
    glShaderSource(id, 1, &szShader, NULL);
    glCompileShader(id);

    GLint compileState;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compileState);
    if(compileState == GL_FALSE) {
        char error[1024];
        glGetShaderInfoLog(id, 1024, NULL, error);
        phantom::Logger::GetInstance(NULL)->Write(error);
        glDeleteShader(id);
        return 0;
    } else {
        return id;
    }
}

ShaderOGL* ShaderOGL::ShaderFromStrings(const char* szVertex, const char* szFragment)
{
    ShaderOGL* pShader = new ShaderOGL();
    pShader->m_vertexFunc = shaderFuncFromStringWithMode(szVertex, GL_VERTEX_SHADER);
    pShader->m_framentFunc = shaderFuncFromStringWithMode(szFragment, GL_FRAGMENT_SHADER);
    pShader->m_program = glCreateProgram();
    glAttachShader(pShader->m_program, pShader->m_vertexFunc);
    glAttachShader(pShader->m_program, pShader->m_framentFunc);
    glLinkProgram(pShader->m_program);

    GLint nUniform;
    glGetProgramiv(pShader->m_program, GL_ACTIVE_UNIFORMS, &nUniform);

    static char namebuff[1024];

    GLsizei name_len;
    GLenum type;
    GLint size;
    GLint loc;

    pShader->m_uniforms.clear();

    for(GLint idx = 0; idx < nUniform; ++idx) {
        glGetActiveUniform(pShader->m_program, idx, 1024, &name_len, &size, &type, namebuff);
        loc = glGetUniformLocation(pShader->m_program, namebuff);
        ShaderVariable var;
        var.id = loc;
        var.type = type;
        var.size = size;
        strcpy(var.name, namebuff);
        pShader->m_uniforms.push_back(var);
    }
    return pShader;
}

void ShaderOGL::Active()
{
    glUseProgram(this->m_program);
}

void ShaderOGL::Release()
{
    glDetachShader(this->m_program, this->m_vertexFunc);
    glDetachShader(this->m_program, this->m_framentFunc);
    glDeleteShader(this->m_vertexFunc);
    glDeleteShader(this->m_framentFunc);
    glDeleteProgram(this->m_program);
    delete this;
}

GLuint ShaderOGL::shaderFuncFromStringWithMode(const char* szShader, GLuint mode)
{
    GLuint id;
    id = glCreateShader(mode);
    glShaderSource(id, 1, &szShader, NULL);
    glCompileShader(id);
    // �������ǲ���������
    GLint compileState;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compileState);
    if(compileState == GL_FALSE) {
        static char error[1024];
        glGetShaderInfoLog(id, 1024, NULL, error);
        printf("%s\n",error);
        phantom::Logger::GetInstance(NULL)->Write(error);
        glDeleteShader(id);
        return 0;
    } else {
        return id;
    }
}

void ShaderOGL::UseNullShader()
{
    glUseProgram(0);
}

void ShaderOGL::SetTexture(GLuint _index,TexOGL * _pTex)
{
    assert(_index < TEXTURE_SHADOW_00);
    char samplerName[32];
    sprintf(samplerName, "TEXTURE%02d", _index);
    GLuint texture_slot = GL_TEXTURE0 + _index;

    std::vector<ShaderVariable>::iterator iter = m_uniforms.begin();

    while(iter != m_uniforms.end()) 
    {
        if(strcmp(iter->name, samplerName) == 0) 
        {
            GLuint tex = _pTex->m_texture;
            glActiveTexture(texture_slot);
            glBindTexture(GL_TEXTURE_2D, tex);
            glUniform1i(iter->id, _index);
            return;
        }
        iter++;
    }
}
void ShaderOGL::SetShadowTexture(GLuint _index,TexOGL * _pTex)
{
    assert(_index < TEXTURE_SHADOW_MAX);
    char samplerName[32];
    sprintf(samplerName, "SHADOW_TEXTURE%02d", _index);
    GLuint texture_slot = GL_TEXTURE0 + TEXTURE_SHADOW_00 + _index;

    std::vector<ShaderVariable>::iterator iter = m_uniforms.begin();
    while(iter != m_uniforms.end()) 
    {
        if(strcmp(iter->name, samplerName) == 0) 
        {
            glActiveTexture(texture_slot);
            glBindTexture(GL_TEXTURE_2D, _pTex->m_texture);
            glUniform1i(iter->id, _index + TEXTURE_SHADOW_MAX);
            return;
        }
        iter++;
    }
}

void ShaderOGL::SetUniformData(void* _pData, const char* szName,unsigned int nElement)
{
    // ����uniform��
    std::vector<ShaderVariable>::iterator iter = m_uniforms.begin();

    while(iter != m_uniforms.end()) {
        if(strcmp(iter->name, szName) == 0) {
            /*
             * GL_FLOAT, GL_FLOAT_VEC2, GL_FLOAT_VEC3, GL_FLOAT_VEC4, GL_INT, GL_INT_VEC2, GL_INT_VEC3, GL_INT_VEC4,
             * GL_BOOL, GL_BOOL_VEC2, GL_BOOL_VEC3, GL_BOOL_VEC4, GL_FLOAT_MAT2, GL_FLOAT_MAT3, GL_FLOAT_MAT4,
             * GL_SAMPLER_2D, or GL_SAMPLER_CUBE
             */
            switch(iter->type) {
            case GL_FLOAT: {
                glUniform1fv(iter->id, nElement, (float*)_pData);return ;
                break;
            }
            case GL_FLOAT_VEC2: {
                glUniform2fv(iter->id, nElement, (float*)_pData);return ;
                break;
            }
            case GL_FLOAT_VEC3: {
                glUniform3fv(iter->id, nElement, (float*)_pData);return ;
                break;
            }
            case GL_FLOAT_VEC4: {
                glUniform4fv(iter->id, nElement, (float*)_pData);return ;
                break;
            }
            case GL_INT: {
                glUniform1iv(iter->id, nElement, (int*)_pData);return ;
                break;
            }
            case GL_INT_VEC2: {
                glUniform2iv(iter->id, nElement, (int*)_pData);return ;
                break;
            }
            case GL_INT_VEC3: {
                glUniform3iv(iter->id, nElement, (int*)_pData);return ;
                break;
            }
            case GL_INT_VEC4: {
                glUniform4iv(iter->id, nElement, (int*)_pData);return ;
                break;
            }
            case GL_FLOAT_MAT2: {
                glUniformMatrix2fv(iter->id, nElement, GL_FALSE, (float*)_pData);return ;
                break;
            }
            case GL_FLOAT_MAT3: {
                glUniformMatrix3fv(iter->id, nElement, GL_FALSE, (float*)_pData);return ;
                break;
            }
            case GL_FLOAT_MAT4: {
                glUniformMatrix4fv(iter->id, nElement, GL_FALSE, (float*)_pData);return ;
                break;
            }
            case GL_SAMPLER_2D: {
                glUniform1i(iter->id, *(GLint*)_pData);return ;
                break;
            }
            case GL_SAMPLER_2D_SHADOW: {
                glUniform1i(iter->id, *(GLint*)_pData);return ;
                break;
            }
            }
        }
        iter++;
    }
}

};