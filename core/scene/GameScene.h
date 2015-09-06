#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include <gl/glew.h>
#include <core/effectogl.h>
#include <model/md5parser/md5Model.h>
#include <model/RenderObject.h>
#include <scene/octree/Octree.h>
#include <math/camera.h>
#include <scene/sceneobject.h>
#include <model/basicModel.h>
#include <list>

class GameScene
{
public:
	GameScene();
	~GameScene();
public:
	std::list<SceneObject*>\
										m_staticObjects;
	std::list<Graphics::md5Model*>		m_animObjects;
	Graphics::EffectOGL *				m_pStaticEffect;
	Graphics::EffectOGL *				m_pAnimEffect;
	
	Graphics::Cube*						m_pCubeModel;
	
	Graphics::TexOGL*					m_pChessTexture;
	
	CCamera*							m_pGameCamera;
	
	Graphics::Octree*								m_pOctree;

	void Init();
	void Render( uint64_t time);
};

#endif // __GAME_SCENE_H__
