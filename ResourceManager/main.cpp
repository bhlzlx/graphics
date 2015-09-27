#include <stdio.h>
#include <stdint.h>
#include <owfile/owfile.h>
#include <owZip/owZip.h>
#include <algorithm/md5.h>
#include <package/package_common.h>
#include <package/owPackage.h>

using namespace ow;

int main(int argc, char **argv)
{
	owPackage package;
	owBOOL ret = package.Init("d:/include.pkg");
	owFile * file = package.Open("/gl/glew.h");
	file->Release();
	return 0;
}
