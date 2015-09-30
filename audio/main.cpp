#include <stdio.h>
#include <audio/owAudio.h>

ow::owAEDevice*			_pDevice;

int main(int argc, char **argv)
{
	_pDevice->Init();
	
	
	
	_pDevice->Release();
	return 0;
}