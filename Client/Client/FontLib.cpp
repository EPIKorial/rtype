#include "FontLib.hpp"

std::map<std::string, sf::Font> FontLib::lib;
std::map<std::string, bool> FontLib::ready;


void FontLib::add(const std::string & name, const std::string & filepath)
{
	sf::Font font;
	if (font.loadFromFile(filepath))
	{
		lib[name] = font;
		ready[name] = true;
	}
	else
	{
		ready[name] = false;
	}
}

bool FontLib::have(const std::string & name)
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

sf::Font *FontLib::get(const std::string & name)
{
	if (have(name))
	{
		return &(lib.at(name));
	}
	return nullptr;
}
