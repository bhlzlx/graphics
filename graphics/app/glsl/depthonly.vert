SHADER_TEXT(
\n#version 410 core\n


layout(location = 0) in vec3 vert;

uniform mat4x4 PROJECTION;
uniform mat4x4 VIEW;
uniform mat4x4 MODEL;

void main()
{
    gl_Position         = PROJECTION * VIEW * MODEL * vec4(vert,1.0f);
}
);
