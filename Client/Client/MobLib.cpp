#include "MobLib.hpp"

MobLib::MobLib(const std::string & first)
{
	assets[0] = first;
}

MobLib::MobLib(const MobLib &o) : assets(o.assets)
{
}

MobLib::~MobLib()
{
}

MobLib & MobLib::operator=(const MobLib &o)
{
	assets = o.assets;
	return *this;
}

void MobLib::add(short id, const std::string & filepath)
{
	assets[id] = filepath;
}

bool MobLib::have(short id)
{
	bool haveit = false;
	try
	{
		assets.at(id);
		haveit = true;
	}
	catch (std::out_of_range e)
	{
		haveit = false;
	}
	return haveit;
}

const std::string & MobLib::get(short id)
{
	if (have(id))
		return assets[id];
	else if (have(0))
		return assets[0];
	else
		return "";
}

const std::string & MobLib::operator[](short id)
{
	return get(id);
}
