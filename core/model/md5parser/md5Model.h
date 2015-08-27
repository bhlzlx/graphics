#ifndef __MD5_MODEL_H__
#define __MD5_MODEL_H__

#include "md5.h"
#include <core/bufferogl.h>
#include <core/texogl.h>
using namespace model;

#define ANIMATION_MAX 4

namespace Graphics
{
	struct md5Model
	{
		struct md5MeshBuffer
		{
			// VAO属性
			uint32_t 						m_nNumElement;				// 顶点绘制数
			Graphics::VertexArray*			m_pVertexArray;				// 渲染此 Mesh 的 VAO
			// 以下是 顶点数据
			Graphics::VertexBuffer*			m_pBindposeVertexBuffer;	// VAO  ==>  Bindpose vertices（默认绑定的 vertex buffer）
			Graphics::VertexBuffer*			m_pIndexBuffer;				// VAO  ==>  IBO
			Graphics::VertexBuffer*  		m_pUVBuffer;				// VAO  ==>  UV
			Graphics::VertexBuffer*			m_pWeightBuffer;			// VAO  ==>  Weight（权重数据）
			Graphics::TexOGL*				m_pTexture;					// Texture
		};
		
		// md5 mesh模块
		md5MeshModel			m_meshModel;
		// md5 动画模块
		uint32_t 				m_nNumAnimation;
		md5AnimModel			m_animModels[ANIMATION_MAX];
		// meshes buffer 信息
		uint32_t				m_nNumMeshes;
		md5MeshBuffer*			m_pMeshBuffers;
		// 默认绑定骨骼的逆矩阵数组
		matrix_4x4*				m_pInverseBoneMatrices;
		// 计算帧插值所用的临时骨骼数据
		md5Joint*				m_pTJointsA;
		md5Joint*				m_pTJointsB;
		
		// 解析 并 创建mesh相关的 buffer object
		void Init( const char * _szMeshFile );
		// 解析anim添加到anim列表中
		void AddAnimation( const char * _szAnimFile);
	};
}

#endif // __MD5_MODEL_H__
