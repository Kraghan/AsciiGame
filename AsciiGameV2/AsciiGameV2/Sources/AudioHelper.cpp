#include "../Headers/AudioHelper.h"
AudioHelper* AudioHelper::instance = nullptr;

/*explicit*/ AudioHelper::AudioHelper()
{
	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);

	fileNames = std::map<std::string, std::string>();

	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	std::string path = std::string(buffer).substr(0, pos) +"\\..\\Ressources\\";
	
	hFind = FindFirstFile((path+"*").c_str(), &ffd);

	if (INVALID_HANDLE_VALUE == hFind)
	{
		//Debug::log("Audio.log", "Error first file\n", true);
		return;
	}

	do
	{
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			std::string txt = ffd.cFileName;
			txt += " is a dir\n";
			//Debug::log("Audio.log", txt , true);
		}
		else
		{
			std::string::size_type posDot = std::string(ffd.cFileName).find_last_of(".");

			if (std::string(ffd.cFileName).substr(posDot) == ".wav")
			{
				std::string filename = std::string(ffd.cFileName).substr(0, posDot);
				std::string fullpath = path + std::string(ffd.cFileName);

				fileNames.insert(std::pair < std::string, std::string >(filename, fullpath));
			}
		}
	} while (FindNextFile(hFind, &ffd) != 0);

}

/*static*/ AudioHelper* AudioHelper::getAudioHelper()
{
	if (instance == nullptr)
	{
		instance = new AudioHelper();
	}
	return instance;
}

/// \param  mode The reading mode : SND_SYNC, SND_ASYNC by default 
void AudioHelper::play(std::string filename, bool loop, USHORT mode /* SND_ASYNC */)
{
	std::map<std::string, std::string>::iterator it = fileNames.find(filename);
	if (it == fileNames.end())
		return;

	if (loop)
		mode |= SND_LOOP;

	PlaySound((*it).second.c_str(), nullptr, mode | SND_FILENAME);
}

void AudioHelper::stop()
{
	PlaySound(NULL, nullptr, SND_FILENAME);
}