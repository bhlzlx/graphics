#ifndef __MD5_MODEL_H__
#define __MD5_MODEL_H__

#include "md5.h"
#include <core/bufferogl.h>
#include <core/texogl.h>
#include <core/effectogl.h>
using namespace model;

#define ANIMATION_MAX 16

namespace Graphics
{
	typedef struct md5Model
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
		// 要传送的骨骼矩阵
		matrix_4x4*				m_pUniformBoneMatrices;
		
		int32_t					m_iActivedAnimID;
		
		// 解析 并 创建mesh相关的 buffer object
		void Init( const char * _szMeshFile );
		void Deinit();
		// 
		void ActiveAnim( uint32_t _iAnimID );
		// 解析anim添加到anim列表中
		void AddAnimation( const char * _szAnimFile);
		// 求变换矩阵
		void Tick( long long _animTime );
		// 渲染~
		void Render( EffectOGL * _pEffect, uint8_t _wiredframe );
	};
}

#endif // __MD5_MODEL_H__
