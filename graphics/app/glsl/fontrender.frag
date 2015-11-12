SHADER_TEXT(
\n#version 410 core\n

uniform	vec3 FONT_COLOR;
uniform int  DRAW_TYPE;
uniform sampler2D       TEXTURE00;
// uv����
in vec2                 frag_uv;
in vec2					font_uv;
// Ƭ����ɫ�������ɫ
out vec4                color;

void main()
{
	color =	texture(TEXTURE00,font_uv);
	if(DRAW_TYPE == 0)
	{
		color.a = color.r;
		color.rgb = FONT_COLOR;
	}
}
);