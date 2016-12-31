#pragma once

#ifndef MOBLIB_HPP_
# define MOBLIB_HPP_

# include <map>
# include <string>

class MobLib
{
	std::map<short, std::string> assets;

	static const std::string NO_PATH;
  
public:
	MobLib(const std::string &first);
	MobLib(const MobLib &);
	~MobLib();
	MobLib &operator=(const MobLib &);

	void add(short id, const std::string &filepath);
	bool have(short id);
	const std::string &get(short id);
	const std::string &operator[](short);
};

#endif /* !MOBLIB_HPP_ */
