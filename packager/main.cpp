#include <stdio.h>
#include <stdint.h>
#include <file/owfile.h>
#include <zip/owZip.h>
#include <crypto/md5.h>
#include <archive/owArchive.h>

using namespace ow;

int main(int argc, char **argv)
{
	owArchive archive;
	archive.Init("E:/projects/builds/core","E:/projects/builds/core/package.pkg");
	ow::owFile * file = archive.Open("config.txt");
	printf("%p",file);
	system("pause");
}
