#include "mathexception.h"

mathexception::mathexception()
{

}

mathexception::~mathexception()
{

}

const char* mathexception::what() const throw ()
{
	return "divide by zero";
}
