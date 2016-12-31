#include "Jukebox.hpp"

std::map<std::string, sf::SoundBuffer> Jukebox::buffers;
std::map<std::string, sf::Sound> Jukebox::sounds;
std::map<std::string, bool> Jukebox::ready;

void Jukebox::add(const std::string & name, const std::string & filepath)
{
	sf::SoundBuffer buf;
	if (!buf.loadFromFile(filepath))
	{
		ready[name] = false;
		return;
	}
	ready[name] = true;
	buffers[name] = buf;
	sounds[name].setBuffer(buffers[name]);
}

bool Jukebox::have(const std::string & name)
{
	bool haveit = false;
	try
	{
		haveit = ready.at(name);
	}
	catch (std::out_of_range e)
	{
		haveit = false;
	}
	return haveit;
}

sf::Sound & Jukebox::get(const std::string & name)
{
	return sounds.at(name);
}
