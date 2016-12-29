#pragma once

#ifndef JUKEBOX_HPP_
# define JUKEBOX_HPP_

# include <map>
# include <string>
# include <SFML/Audio.hpp>

class Jukebox
{
	static std::map<std::string, sf::SoundBuffer> buffers;
	static std::map<std::string, sf::Sound> sounds;
	static std::map<std::string, bool> ready;

public:
	static void add(const std::string &name, const std::string &filepath);
	static bool have(const std::string &name);
	static sf::Sound &get(const std::string &name);
};

#endif /* !JUKEBOX_HPP_ */