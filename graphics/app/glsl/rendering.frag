SHADER_TEXT(

\n#version 410 core\n

uniform sampler2DShadow DEPTH_TEXTURE00;    // ÒõÓ°ÌùÍ¼

uniform sampler2D       TEXTURE00;  // »·¾³¹â£¬ÒõÓ°ÌùÍ¼£¬ÆÕÍ¨±íÃæÌùÍ¼
uniform sampler2D       TEXTURE01;  // ·¨ÏßÌùÍ¼
uniform sampler2D       TEXTURE02;  // ¸ß¹â·´ÉäÌùÍ¼
uniform sampler2D       TEXTURE03;  // alphaÍ¨µÀÌùÍ¼

uniform vec4            ADSA;       // ads¹âÕÕ+alpha ²ÎÊý

// uvÐÅÏ¢
in vec2                 frag_uv;
// ÒõÓ°uv
in vec4                 shadow_coord;
// Âþ·´ÉäÏµÊý
in float                frag_diff;
// ÇÐÏßÆ½Ì¨¾ØÕó
in mat3                 tangent_mat3;
// ÑÛ¾¦Î»ÖÃ
in vec3                 position_eye;
// ¹âÔ´Î»ÖÃ
in vec3                 position_light;
// ¶¥µãÎ»ÖÃ
in vec3                 vertex_world;
// Æ¬¶Î×ÅÉ«Æ÷Êä³öÑÕÉ«
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
    spec = pow(spec,128);

    float visible = texture(DEPTH_TEXTURE00,vec3(shadow_coord.xy,shadow_coord.z));;

    color = (textureColor * frag_diff  + highLight * spec * 0.5 * frag_diff) * visible + textureColor * 0.3;
}
);
