SHADER_TEXT(
\#version 410 core\n
uniform		vec4 DRAW_RECT;
uniform		vec4 FONT_RECT;

out			vec2 font_uv;
void main()
{
	vec2 pts[6] = vec2[](vec2(1,1),vec2(0,1),vec2(0,0),vec2(1,0),vec2(1,1),vec2(0,0));

	// 字体贴图上的字对应的uv
	vec2 font_uvs[6] = vec2[](
	vec2(FONT_RECT.x + FONT_RECT.z,FONT_RECT.y + FONT_RECT.w),
	vec2(FONT_RECT.x,FONT_RECT.y + FONT_RECT.w),
	vec2(FONT_RECT.x,FONT_RECT.y),
	vec2(FONT_RECT.x + FONT_RECT.z,FONT_RECT.y),
	vec2(FONT_RECT.x + FONT_RECT.z,FONT_RECT.y + FONT_RECT.w),
	vec2(FONT_RECT.x,FONT_RECT.y)
	);

	font_uv = font_uvs[gl_VertexID];

	vec2 pt = pts[gl_VertexID];
	pt.x = pt.x * DRAW_RECT.z;
	pt.y = pt.y * DRAW_RECT.w;
	pt.x = pt.x + DRAW_RECT.x;
	pt.y = pt.y + DRAW_RECT.y;
	pt = pt * 2.0f - 1.0f;
	gl_Position = vec4(pt.x,pt.y,0.0f,1.0f);
}
);