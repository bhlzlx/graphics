#include "CModelParser.h"
#include <TexOGL.h>

using namespace Graphics;

CModelParser::CModelParser()
{
    //ctor
}

CModelParser::~CModelParser()
{
	std::vector<ModelData>::iterator iter = m_models.begin();
	while(iter!=m_models.end())
	{
		iter->Release();
		iter++;
	}
    //dtor
}

bool CModelParser::LoadModel(const char * szFilepath)
{
    float minX,maxX,minY,maxY,minZ,maxZ;
    minX = maxX = minY = maxY = maxZ = minZ = 0.0f;
    Assimp::Importer importer;
    const aiScene * pModel = importer.ReadFile(
                                    szFilepath,
                                    aiProcess_CalcTangentSpace       |
                                    aiProcess_Triangulate            |
                                    aiProcess_JoinIdenticalVertices  |
                                    aiProcess_SortByPType
                                );
    if(NULL == pModel)
        return false;
    aiMesh * pMesh;
    
    for(int i = 0;i<pModel->mNumMeshes;++i)
    {
        pMesh = pModel->mMeshes[i];
        //aiBone ** pBones = pMesh->mBones;
        ModelData meshData;
        aiMaterial * material = pModel->mMaterials[pMesh->mMaterialIndex];
        if(material == NULL)
        {
            meshData.m_material.m_texDiffuse = TexOGL::CreateChessTex();
            meshData.m_material.m_texNormal = TexOGL::CreateBlackTex();
            meshData.m_material.m_texSpecular = TexOGL::CreateWhiteTex();
        }
        else
        {
            assert(material);
            aiString path;
            IBuffer * pBuff;
            Image * image;
            
            material->GetTexture(aiTextureType_DIFFUSE,0,&path);
            if(path.length > 0)
            {
                pBuff = BufferFromFile(path.C_Str());
                if(pBuff)
                {
                    image = Image::ImageFromPng(pBuff);
                    meshData.m_material.m_texDiffuse = TexOGL::CreateTexWidthImage(image,1);
                    pBuff->Release();
                    image->Release();
                }
                else
                {
                    meshData.m_material.m_texDiffuse = TexOGL::CreateChessTex();
                }
            }
            else
            {
                meshData.m_material.m_texDiffuse = TexOGL::CreateChessTex();
            }
            path.Clear();
            // ·¨ÏßÌùÍ¼
            material->GetTexture(aiTextureType_NORMALS,0,&path);
            if(path.length > 0)
            {
                pBuff = BufferFromFile(path.C_Str());
                if(pBuff)
                {
                    image = Image::ImageFromPng(pBuff);
                    meshData.m_material.m_texNormal = TexOGL::CreateTexWidthImage(image,1);
                    pBuff->Release();
                    image->Release();
                }
                else
                {
                    pBuff->Release();
                    meshData.m_material.m_texNormal = TexOGL::CreateBlackTex();
                }                                    
            }
            else
            {
                meshData.m_material.m_texNormal = TexOGL::CreateBlackTex();
            }
            path.Clear();
            // ¸ß¹âÌùÍ¼
            material->GetTexture(aiTextureType_SPECULAR,0,&path);
            if(path.length > 0)
            {
                pBuff = BufferFromFile(path.C_Str());
                if(pBuff)
                {
                    image = Image::ImageFromPng(pBuff);
                    meshData.m_material.m_texSpecular = TexOGL::CreateTexWidthImage(image,1);
                    pBuff->Release();
                    image->Release();
                }
                else
                {
                    pBuff->Release();
                    meshData.m_material.m_texSpecular = TexOGL::CreateWhiteTex();
                }
            }
            else
            {
                meshData.m_material.m_texSpecular = TexOGL::CreateWhiteTex();
            }
        }
        // Ë÷Òý¸öÊý
        meshData.m_nNumIndices = pMesh->mNumFaces * 3;
        unsigned* pIndexBuffer = new unsigned[meshData.m_nNumIndices];
        // IBO
        for(int j = 0;j<pMesh->mNumFaces;++j)
        {
            assert(pMesh->mFaces[j].mNumIndices == 3);
            memcpy(pIndexBuffer + j * 3,pMesh->mFaces[j].mIndices,sizeof(unsigned) * 3);
        }
        // ´´½¨VAO °ó¶¨VAO
        meshData.m_vertData.m_pVertexArray = VertexArray::CreateVertexArray();
        // ´´½¨IBO ,°ó¶¨IBO,Ìî³äIBO
        meshData.m_vertData.m_pIBO = VertexBuffer::CreateBuffer(pIndexBuffer,meshData.m_nNumIndices * sizeof(unsigned));
        delete []pIndexBuffer;
        // ´´½¨¶¥µã×ø±ê m_VBO_vertex
       // meshData.m_vertData.m_pVertices = VertexBuffer::CreateBuffer(pAnimMeshes[0]->mVertices,pMesh->mNumVertices * sizeof(aiVector3D));
        meshData.m_vertData.m_pVertices = VertexBuffer::CreateBuffer(pMesh->mVertices,pMesh->mNumVertices * sizeof(aiVector3D));
		// ±éÀúÇó·¶Î§
        for(int j = 0;j<pMesh->mNumVertices ; ++j)
        {
            aiVector3D * pVert = pMesh->mVertices + j;
            if(minX > pVert->x)
                minX = pVert->x;
            if(maxX < pVert->x)
                maxX = pVert->x;
            if(minY > pVert->y)
                minY = pVert->y;
            if(maxY < pVert->y)
                maxY = pVert->y;
            if(minZ > pVert->z)
                minZ = pVert->z;
            if(maxZ < pVert->z)
                maxZ = pVert->z;
        }
        // ´´½¨tangents
        meshData.m_vertData.m_pTangent = VertexBuffer::CreateBuffer(pMesh->mTangents,pMesh->mNumVertices * sizeof(aiVector3D));
        // normalize
        meshData.m_vertData.m_pNormals = VertexBuffer::CreateBuffer(pMesh->mNormals,pMesh->mNumVertices * sizeof(aiVector3D));
        // ´´½¨UV
        if(pMesh->HasTextureCoords(0))
        {
            aiVector3D * pUVBuffer = new aiVector3D[pMesh->mNumVertices];
            for(int j = 0;j<pMesh->mNumVertices;++j)
            {
                memcpy(pUVBuffer + j,&pMesh->mTextureCoords[0][j],sizeof(aiVector3D));
            }
            meshData.m_vertData.m_pUV = VertexBuffer::CreateBuffer(pUVBuffer,pMesh->mNumVertices * sizeof(aiVector3D));
        }
        else
        {
            meshData.m_vertData.m_pUV = VertexBuffer::CreateBuffer(NULL,pMesh->mNumVertices * sizeof(aiVector3D));
        }
        meshData.m_vertData.m_pVertexArray->SetVertexBuffer(0,meshData.m_vertData.m_pVertices,3,0,NULL);
        meshData.m_vertData.m_pVertexArray->SetVertexBuffer(1,meshData.m_vertData.m_pNormals,3,0,NULL);
        meshData.m_vertData.m_pVertexArray->SetVertexBuffer(2,meshData.m_vertData.m_pUV,3,0,NULL);
        meshData.m_vertData.m_pVertexArray->SetVertexBuffer(3,meshData.m_vertData.m_pTangent,3,0,NULL);
        meshData.m_vertData.m_pVertexArray->SetIndexBuffer(meshData.m_vertData.m_pIBO);
        
        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER,0);
        // Ìí¼ÓÊý¾Ýµ½¶ÓÁÐ
        this->m_models.push_back(meshData);
    }

    float diffX = maxX - minX;
    m_ptCenter.x = (maxX + minX)/2;
    float diffY = maxY - minY;
    m_ptCenter.y = (maxY + minY)/2;
    float diffZ = maxZ - minZ;
    m_ptCenter.z = (maxZ + minZ)/2;

    if(diffX > diffY)
        m_fMaxBound = diffX;
    else
        m_fMaxBound = diffY;
    if(diffZ > m_fMaxBound)
        m_fMaxBound = diffZ;
	return true;
}

void CModelParser::Render(Graphics::EffectOGL * _pEffect, bool _wiredframe )
{
    int renderMode = 0;
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    _pEffect->m_pShader->SetUniformData(&renderMode,"RENDER_MODE");
	std::vector<ModelData>::iterator iter = m_models.begin();
	while(iter!=m_models.end())
	{
        _pEffect->m_pShader->SetTexture(0,iter->m_material.m_texDiffuse);
        _pEffect->m_pShader->SetTexture(1,iter->m_material.m_texNormal);
        _pEffect->m_pShader->SetTexture(2,iter->m_material.m_texSpecular);
		iter->m_vertData.m_pVertexArray->Bind();
        iter->m_vertData.m_pVertexArray->Draw( iter->m_nNumIndices);
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
        iter = m_models.begin();
        while(iter!=m_models.end())
        {
            iter->m_vertData.m_pVertexArray->Bind();
            iter->m_vertData.m_pVertexArray->Draw( iter->m_nNumIndices);
            ++iter;
        }
        glPolygonOffset(0,0);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        glDisable(GL_POLYGON_OFFSET_LINE);
    }
    
}
