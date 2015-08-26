SHADER_TEXT(
\#version 410 core\n

uniform sampler2DShadow DEPTH_TEXTURE00;    // ��Ӱ��ͼ

uniform sampler2D       TEXTURE00;  // �����⣬��Ӱ��ͼ����ͨ������ͼ
uniform sampler2D       TEXTURE01;  // ������ͼ
uniform sampler2D       TEXTURE02;  // �߹ⷴ����ͼ
uniform sampler2D       TEXTURE03;  // alphaͨ����ͼ

uniform vec4            ADSA;       // ads����+alpha ����

// uv��Ϣ
in vec2                 frag_uv;
// ��Ӱuv
in vec4                 shadow_coord;
// ������ϵ��
in float                frag_diff;
// ����ƽ̨����
in mat3                 tangent_mat3;
// �۾�λ��
in vec3                 position_eye;
// ��Դλ��
in vec3                 position_light;
// ����λ��
in vec3                 vertex_world;
// Ƭ����ɫ�������ɫ
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
