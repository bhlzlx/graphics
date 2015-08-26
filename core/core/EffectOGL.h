#ifndef __EFFECT_OGL__
#define __EFFECT_OGL__

#include "device.h"
#include "ShaderOGL.h"

namespace Graphics
{

    struct EffectOGL
    {
        
        EffectOGL();
        ~EffectOGL();
        
        EffectDesc      m_desc;
        
        ShaderOGL   *   m_pShader;
        
        static EffectOGL * CreateEffect( EffectDesc * _pDesc);
        
        bool   Begin();
        void   End();
        
        void   Release();
    };
}

#endif // __EFFECT_OGL__
