#ifndef _AUDIO_SOURCE_H
#define _AUDIO_SOURCE_H

#include "component.h"

#include"AL/al.h"
#include"AL/alc.h"

#include <vector>

class audioSource : public Component
{
	ALuint bufferID;
	ALenum format;
	ALsizei freq;
	std::vector<char> bufferData;
	ALuint sourceID;
	ALint state;

public:

	~audioSource();
	void audioSourceInit(char* _audio);
	void playSound();
	void load_ogg(char* _audio);
	bool soundCheck();
};



#endif
