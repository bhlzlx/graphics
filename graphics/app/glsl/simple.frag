SHADER_TEXT(
\n#version 410 core\n

uniform sampler2D       TEXTURE00;

uniform vec4            WIREDFRAME_COLOR;
uniform int             RENDER_MODE;
out vec4                color;
in vec2                 frag_uv;

#define RENDER_FILL 0
#define RENDER_WIREDFRAME 1

void main()
{
    if(RENDER_MODE !=  1)
    {
        vec4 textureColor = texture(TEXTURE00,frag_uv);
        color = textureColor;
    }
    else
    {
        color = WIREDFRAME_COLOR;
    }
}
);
