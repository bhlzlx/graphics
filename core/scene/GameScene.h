#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include <gl/glew.h>
#include <core/effectogl.h>
#include <model/md5parser/md5Model.h>
#include <model/RenderObject.h>
#include <math/camera.h>
#include <list>

class GameScene
{
public:
	GameScene();
	~GameScene();
public:
	std::list<Graphics::RenderObjectBase*>		m_staticObjects;
	std::list<Graphics::md5Model*>		m_animObjects;
	
	Graphics::EffectOGL *				m_pStaticEffect;
	Graphics::EffectOGL *				m_pAnimEffect;
	
	Graphics::TexOGL*					m_pChessTexture;
	
	CCamera*							m_pGameCamera;
	
	void Init();
	void Render( uint64_t time);
};

#endif // __GAME_SCENE_H__
