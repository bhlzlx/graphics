SHADER_TEXT(

\n#version 410 core \n

layout(location = 0) in vec3 vert;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;

uniform mat4x4  MODEL;
uniform mat4x4  VIEW;
uniform mat4x4  PROJECTION;

out vec2  frag_uv;

void main()
{
    gl_Position         = PROJECTION * VIEW * MODEL * vec4(vert,1.0f);
    frag_uv             = uv.xy;
}
);