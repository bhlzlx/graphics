#ifndef CMODELPARSER_H
#define CMODELPARSER_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <gl/glew.h>
#include <vector>
#include <glm/glm.hpp>

#include <EffectOGL.h>
#include <TexOGL.h>
#include <BufferOGL.h>

#define SAFE_RELEASE_STANDARD(ptr)\
    if(ptr)\
        delete ptr;

struct CMaterial
{
    Graphics::TexOGL * m_texDiffuse;
    Graphics::TexOGL * m_texNormal;
    Graphics::TexOGL * m_texSpecular;

    float  m_fSpec;

    CMaterial()
    {
        memset(this,0,sizeof(CMaterial));
    }

    void Release()
    {
        SAFE_RELEASE_STANDARD(m_texDiffuse);
        SAFE_RELEASE_STANDARD(m_texNormal);
        SAFE_RELEASE_STANDARD(m_texSpecular);
    }
};

#define SAFE_RELEASE_BUFFER_OBJ(obj)\
    if(obj != 0xffffffff)\
        glDeleteBuffers(1,&obj);

struct CVertexData
{
    Graphics::VertexArray *     m_pVertexArray;
    Graphics::VertexBuffer*     m_pVertices;
    Graphics::VertexBuffer*     m_pNormals;
    Graphics::VertexBuffer*     m_pUV;
    Graphics::VertexBuffer*     m_pTangent;
    Graphics::VertexBuffer*     m_pIBO;
    
    CVertexData()
    {
        memset(this,0xffffffff,sizeof(CVertexData));
    }

    void Release()
    {
        m_pIBO->Release();
        m_pNormals->Release();
        m_pTangent->Release();
        m_pUV->Release();
        m_pVertices->Release();
        m_pVertexArray->Release();
    }
};

class CModelParser
{
    public:
        // Á¢·½Ìå
        float       m_fMaxBound;
        glm::vec3   m_ptCenter;

        struct ModelData
        {
            CVertexData m_vertData;
            CMaterial   m_material;
            GLuint m_nNumIndices;

            void Release()
            {
                m_vertData.Release();
                m_material.Release();
            }
        };

        std::vector<ModelData> m_models;

        CModelParser();

        void Render( Graphics::EffectOGL * _pEffect, bool _wiredframe);

        virtual ~CModelParser();

        bool LoadModel(const char * szFilepath);
    protected:
    private:
};

#endif // CMODELPARSER_H
