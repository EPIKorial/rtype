#pragma once

#ifndef CLIENTERRORS_HPP_
# define CLIENTERRORS_HPP_

#include <exception>

class NotLockedError : public std::exception
{
public:
	NotLockedError() {}
	virtual ~NotLockedError() throw() {}

	virtual const char *what() const throw()
	{
		return "Could not lock mutex";
	}
};

#endif /* !CLIENTERRORS_HPP_ */