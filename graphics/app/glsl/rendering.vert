SHADER_TEXT(

\n#version 410 core \n

layout(location = 0) in vec3 vert;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec3 uv;
layout(location = 3) in vec3 tangent;

uniform mat4x4 PROJECTION;
uniform mat4x4 VIEW;
uniform mat4x4 MODEL;
uniform mat4x4 SHADOW_VIEW;

uniform vec3 LIGHT_POSITION0;
uniform vec3 LIGHT_POSITION1;
uniform vec3 LIGHT_POSITION2;
uniform vec3 LIGHT_POSITION3;

out vec2  frag_uv;

void main()
{
    gl_Position         = PROJECTION * VIEW * MODEL * vec4(vert,1.0f);
    frag_uv             = uv.xy;
}
);
