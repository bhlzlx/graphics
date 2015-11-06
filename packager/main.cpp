#include <stdio.h>
#include <stdint.h>
#include <owfile/owfile.h>
#include <owZip/owZip.h>
#include <algorithm/md5.h>
#include <archive/owArchive.h>
#include <owfile/owfile.h>

using namespace ow;

int main(int argc, char **argv)
{
	owArchive archive;
	archive.Init("E:/projects/builds/core","E:/projects/builds/core/package.pkg");
	ow::owFile * file = archive.Open("config.txt");
	printf("%p",file);
	system("pause");
}
