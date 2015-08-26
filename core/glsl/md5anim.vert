SHADER_TEXT(

\#version 410 core \n

layout(location = 0) in vec3 	bindVertices;
layout(location = 1) in vec3 	normal;
layout(location = 2) in vec2 	uv;
layout(location = 3) in int 	weight_count;
layout(location = 4) in ivec4  	weight_joint_idx;
layout(location = 5) in vec4  	weight_bias;


uniform mat4x4  MODEL;
uniform mat4x4  VIEW;
uniform mat4x4  PROJECTION;

uniform mat4x4	BONE_MATRICES[64];

out vec2  frag_uv;

void main()
{
	mat4x4 matAppend;
	float biasPlus = 0.0f;
	if(weight_count > 0)
	{
		matAppend = BONE_MATRICES[weight_joint_idx[0]] * weight_bias[0];
		for(int i = 1;i<weight_count;++i)
		{
			matAppend += BONE_MATRICES[weight_joint_idx[i]] * weight_bias[i];
			biasPlus+=weight_bias[i];
		}
	}
	vec4 vert =  matAppend * vec4(bindVertices,1.0f) ;
	gl_Position         = PROJECTION * VIEW * MODEL * vert;
    frag_uv             = uv.xy;
}
);