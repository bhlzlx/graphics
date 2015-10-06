#include "MD5Model.h"

using namespace Graphics;

namespace _MD5_
{
    MD5Model::MD5Model(MD5FramePtr _pFrame)
    {
        SubMeshPtr pMesh = NULL;
        for(int i = 0;i<_pFrame->m_nNumMeshes;++i)
        {
            pMesh = _pFrame->m_pMeshes + i;
            MD5Mesh mesh;
            mesh.m_pVertexArray = Graphics::VertexArray::CreateVertexArray();
            mesh.m_pVertexArray->Bind();
            
            mesh.m_pVertexBuffer = VertexBuffer::CreateBuffer(pMesh->m_pFinalVertices->GetBuffer(),pMesh->m_pFinalVertices->Size());
            mesh.m_pUVBuffer = VertexBuffer::CreateBuffer(pMesh->m_pUVBuffer->GetBuffer(),pMesh->m_pUVBuffer->Size());
            mesh.m_pIndexBuffer = VertexBuffer::CreateBuffer(pMesh->m_pIndicesBuffer->GetBuffer(),pMesh->m_pIndicesBuffer->Size());

            mesh.m_pVertexArray->SetVertexBuffer(0,mesh.m_pVertexBuffer,3,0,0);
            mesh.m_pVertexArray->SetVertexBuffer(2,mesh.m_pUVBuffer,2,0,0);
            mesh.m_pVertexArray->SetIndexBuffer(mesh.m_pIndexBuffer);
            mesh.m_nNumVertices = pMesh->m_nNumIndices;
			ow::owBuffer *pImageBuffer = ow::CreateFileBuffer(pMesh->m_szTexDiffuse);
			if(pImageBuffer)
			{
				Image * pImage = Image::ImageFromPng(pImageBuffer);
				mesh.m_pTexture = TexOGL::CreateTexWidthImage(pImage,true);
				pImageBuffer->Release();
				pImage->Release();
			}
			else
			{
				mesh.m_pTexture = TexOGL::CreateChessTex();
			}			
            this->m_vecMeshes.push_back(mesh);
        }
    }
    
    void MD5Model::Render(Graphics::EffectOGL * _pEffect, bool _wiredframe )
    {
        int renderMode = 0;
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        _pEffect->m_pShader->SetUniformData(&renderMode,"RENDER_MODE");
        std::vector<MD5Mesh>::iterator iter = this->m_vecMeshes.begin();
        while(iter!=m_vecMeshes.end())
        {
			_pEffect->m_pShader->SetTexture(0,iter->m_pTexture);
            iter->m_pVertexArray->Bind();
            iter->m_pVertexArray->Draw( iter->m_nNumVertices);
            ++iter;
        }
        if(_wiredframe)
        {
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);    
            glPolygonOffset(-0.5,-1.0);
            glEnable(GL_POLYGON_OFFSET_LINE);
            renderMode = 1;
            _pEffect->m_pShader->SetUniformData(&renderMode,"RENDER_MODE");
            static glm::vec4 wiredframe_color = glm::vec4(1.0,0.0,0.0,1.0);
            _pEffect->m_pShader->SetUniformData(&wiredframe_color,"WIREDFRAME_COLOR");
            iter = m_vecMeshes.begin();
            while(iter!=m_vecMeshes.end())
            {
                iter->m_pVertexArray->Bind();
                iter->m_pVertexArray->Draw( iter->m_nNumVertices );
                ++iter;
            }
            glPolygonOffset(0,0);
            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            glDisable(GL_POLYGON_OFFSET_LINE);
        }
    }
}

