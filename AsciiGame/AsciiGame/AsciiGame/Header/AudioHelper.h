#pragma once
#include <windows.h>
#include <map>
#include <string>
#include <iostream>
#include "Debug.h"

// /!\ Singleton /!\
// It's impossible with this class to play many sounds simultaneously
class AudioHelper
{
private : 
	// Key : filename without extension, Value : filename with extension
	std::map < std::string, std::string > fileNames;

	// Constructor
	explicit AudioHelper();

	// Singleton
	static AudioHelper* instance;

public :
	// Get the instance of audio helper
	static AudioHelper* getAudioHelper();

	// Play a sound if present in the ressource folder
	void play(std::string filename, bool loop = false, USHORT mode = SND_ASYNC);

	// Stop all sounds
	void stop(void);
};