#include <stdio.h>
#include <md5/md5.h>

using namespace model;

int main(int argc, char **argv)
{
	glm::mat4 mat;
	printf("%f",mat[15]);
	iBuffer * pMeshBuffer = BufferFromFile( "Bob.md5mesh" );
	iBuffer * pAnimBuffer = BufferFromFile( "Bob.md5anim" );
	md5MeshModel mesh;
	md5AnimModel anim;
	InitMeshModel(&mesh,pMeshBuffer);
	InitAnimModel(&anim,pAnimBuffer);
	ClearMeshModel(&mesh);
	ClearAnimModel(&anim);
	return 0;
}
