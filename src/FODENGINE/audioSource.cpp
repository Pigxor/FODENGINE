#include "audioSource.h"
#include <stb_vorbis.h>

audioSource::~audioSource()
{
	alDeleteSources(1, &sourceID);
	alDeleteBuffers(1, &bufferID);
}

void audioSource::audioSourceInit(char * _audio)
{
	bufferID = 0;
	format = 0;
	freq = 0;
	alGenBuffers(1, &bufferID);
	load_ogg(_audio);
	alBufferData(bufferID,format,&bufferData.at(0),static_cast<ALsizei>(bufferData.size()),freq);
}

void audioSource::playSound()
{
	sourceID = 0;
	alGenSources(1, &sourceID);
	alSource3f(sourceID, AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSourcei(sourceID, AL_BUFFER, bufferID);
	alSourcePlay(sourceID);
}

void audioSource::load_ogg(char* _audio) //Karsten's Basic Load OGG Function
{
	int channels = 0;
	int sampleRate = 0;
	short* output = NULL;
	size_t samples = stb_vorbis_decode_filename(
		_audio, &channels, &sampleRate, &output);

	if (samples == -1)
	{
		throw std::exception();
	}

	// Record the sample rate required by OpenAL
	freq = sampleRate;

	// Record the format required by OpenAL
	if (channels == 1)
	{
		format = AL_FORMAT_MONO16;
	}
	else
	{
		format = AL_FORMAT_STEREO16;

		// Force format to be mono (Useful for positional audio)
		// format = AL_FORMAT_MONO16;
		// freq *= 2;
	}

	// Allocate enough space based on short (two chars) multipled by the number of
	// channels and length of clip
	bufferData.resize(sizeof(*output) * channels * samples);
	memcpy(&bufferData.at(0), output, bufferData.size());

	// Clean up the read data
	free(output);
}

bool audioSource::soundCheck()
{
	alGetSourcei(sourceID, AL_SOURCE_STATE, &state);
	return (state == AL_PLAYING);
}

