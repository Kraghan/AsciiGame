#include "../Headers/Debug.h"

/*static*/ void Debug::log(std::string filename, std::string text, bool append)
{
	std::ofstream ostream;
	if(append)
		ostream.open(filename, std::ios::out | std::ios::app);
	else
		ostream.open(filename, std::ios::out | std::ios::trunc);
	if (!ostream.is_open())
	{
		std::cerr << "Error : debug while opening the file" << std::endl;
		return;
	}
	ostream << text;
	ostream.close();
}