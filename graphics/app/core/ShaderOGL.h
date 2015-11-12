//
// Created by phantom on 2015/5/18.
//

#ifndef OPENGL_CSHADER_H
#define OPENGL_CSHADER_H

#include <gl/glew.h>
#include <vector>

#include "TexOGL.h"

#define SAMPLER2D_NUM_MAX           4
#define SAMPLER2DSHADOW_NUM_MAX     2

#define SHADER_TEXT(T) #T

namespace Graphics
{

struct ShaderVariable
{
    char        name[32];
    GLuint      type;
    GLint       size;
    GLint       id;
};

struct ShaderOGL
{
    std::vector<ShaderVariable> m_uniforms;

    GLuint m_vertexFunc;
    GLuint m_framentFunc;
    GLuint m_program;

    void Active();
    void Release();

    bool SetUniformData(void * _pData,const char * szName,unsigned int nElement = 1);

    void SetTexture(GLuint _index,TexOGL * _pTex);
    void SetShadowTexture(GLuint _index,TexOGL * _pTex);

    // ¾²Ì¬·½·¨
    static ShaderOGL *      ShaderFromStrings(const char * szVertex,const char * szFragment);
    static GLuint           shaderFuncFromStringWithMode(const char * szShader,GLuint mode);
    static void             UseNullShader();
};

};

#endif //OPENGL_CSHADER_H
