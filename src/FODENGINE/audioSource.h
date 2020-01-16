#ifndef _AUDIO_SOURCE_H_
#define _AUDIO_SOURCE_H_

#include "component.h"

#include"AL/al.h"
#include"AL/alc.h"

#include <vector>
/**
* \brief Component that stores a sounds and can play it
*/
class audioSource : public Component
{
	ALuint bufferID; ///< Audio Buffer
	ALenum format; ///< Audio Format
	ALsizei freq; ///< Frequency of Audio
	std::vector<char> bufferData;
	ALuint sourceID;
	ALint state; ///< State used for checking if the audio is playing

public:

	~audioSource();
	/**
	* \brief Sets up the component and loads in the sound
	*/
	void audioSourceInit(char* _audio);
	/**
	* \brief Plays the sound
	*/
	void playSound();
	/**
	* \brief Loads in the sound, calledd in the Init function
	*/
	void load_ogg(char* _audio);
	/**
	* \brief Checks if the sound is playing
	*/
	bool soundCheck();
	/**
	* \brief Update loop, checks for sound palying if not then plays sound
	*/
	void onUpdate();
};



#endif
