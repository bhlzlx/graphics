SHADER_TEXT(
\n#version 410 core\n

uniform		vec4 DRAW_RECT;
out			vec2 font_uv;
void main()
{
	vec2 pts[6] = vec2[](vec2(1,1),vec2(0,1),vec2(0,0),vec2(1,0),vec2(1,1),vec2(0,0));

	font_uv = pts[gl_VertexID];
	vec2 pt = pts[gl_VertexID];
	pt.x = pt.x * DRAW_RECT.z;
	pt.y = pt.y * DRAW_RECT.w;
	pt.x = pt.x + DRAW_RECT.x;
	pt.y = pt.y + DRAW_RECT.y;
	pt = pt * 2.0f - 1.0f;
	gl_Position = vec4(pt.x,pt.y,0.0f,1.0f);
}
);