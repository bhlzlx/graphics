#include <stdio.h>
#include <audio/owAudio.h>

ow::owAEDevice* _pDevice;

int main(int argc, char **argv)
{
	ow::owBuffer * vorbisFile = ow::CreateFileBuffer("./greensleeves.ogg");
	assert(vorbisFile);
	_pDevice = ow::GetAudioDevice();
	ow::owAEVorbisSource * pVorbisSource = _pDevice->CreateVorbisSource( vorbisFile);
	_pDevice->Release();
	return 0;
}