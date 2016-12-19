#ifndef FONTLIB_HPP_
# define FONTLIB_HPP_

# include <map>
# include <SFML/Graphics/Font.hpp>

class FontLib
{
	static std::map<std::string, sf::Font> lib;
	static std::map<std::string, bool> ready;

public:
	static void add(const std::string &name, const std::string &filepath);
	static bool have(const std::string &name);
	static sf::Font *get(const std::string &name);
};

#endif /* !FONTLIB_HPP_ */
