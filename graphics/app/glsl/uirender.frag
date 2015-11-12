SHADER_TEXT(
\n#version 410 core\n

uniform sampler2D       TEXTURE00;
in vec2                 frag_uv;
in vec2					font_uv;

out vec4                color;

void main()
{
	color =	texture(TEXTURE00,font_uv);
}
);