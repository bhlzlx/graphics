SHADER_TEXT(
\#version 410 core\n

uniform sampler2DShadow DEPTH_TEXTURE00;    // 阴影贴图

uniform sampler2D       TEXTURE00;  // 环境光，阴影贴图，普通表面贴图
uniform sampler2D       TEXTURE01;  // 法线贴图
uniform sampler2D       TEXTURE02;  // 高光反射贴图
uniform sampler2D       TEXTURE03;  // alpha通道贴图

uniform vec4            ADSA;       // ads光照+alpha 参数

// uv信息
in vec2                 frag_uv;
// 阴影uv
in vec4                 shadow_coord;
// 漫反射系数
in float                frag_diff;
// 切线平台矩阵
in mat3                 tangent_mat3;
// 眼睛位置
in vec3                 position_eye;
// 光源位置
in vec3                 position_light;
// 顶点位置
in vec3                 vertex_world;
// 片段着色器输出颜色
out vec4                color;

void main()
{
    vec4 textureColor   = texture(TEXTURE00,frag_uv);
    vec4 tangentNormal  = texture(TEXTURE01,frag_uv);
    vec4 highLight      = texture(TEXTURE02,frag_uv);

    vec4 normal = vec4(normalize(tangent_mat3 * tangentNormal.xyz),0);
    vec3 reflect_light = reflect( normalize(vertex_world - position_light) ,normalize(normal.xyz) );
    vec3 eye_vector = normalize(position_eye - vertex_world);

    float spec = max(0.0, dot(reflect_light ,eye_vector));
    spec = pow(spec,256);

    float visible = texture(DEPTH_TEXTURE00,vec3(shadow_coord.xy,shadow_coord.z - 0.00000002));

    color = (textureColor * frag_diff  + highLight * spec * 0.5 * frag_diff) * visible + textureColor * 0.3;
}
);
