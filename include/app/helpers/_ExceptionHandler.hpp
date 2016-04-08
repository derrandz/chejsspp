#ifndef _EXCEPTIONHANDLER_VIEW_H_INCLUDED_
#define _EXCEPTIONHANDLER_VIEW_H_INCLUDED_

#include <stdexcept>
#include <string>
#include <exception>

/**
 * Since Ibrahim hates to use classes all over the place,
 * he thought that this shouldn't be a class, and instead namespace a simple function into something like this:
 *
 * namespace _ExceptionHandling { throw_exception() const throw() { }; }
 * but I think it is only a matter of design.
 *
 * This class would be my first step into rewriting this codebase into my new design ideas.
 */
class _ExceptionHandler : public std::exception
{
	private: std::string message;
	private: std::string name;

	_ExceptionHandler(std::string xname, std::string xmessage)
	{
		this->message = xmessage;
		this->name    = xname;
	};

	public: virtual const char* what() const throw()
	{
		std::string concat        = this->name + " : " + this->message;
		const char* _return_value = concat.c_str();
		return _return_value;
	}

	public: static inline void throw_exception(std::string name, std::string message) throw()
	{
		_ExceptionHandler exception(name, message);
		// throw _ExceptionHandler( name + ": " + message);
		throw exception;
	};
};
#endif // _EXCEPTIONHANDLER_VIEW_H_INCLUDED_