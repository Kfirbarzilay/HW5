#include "mathexception.h"

mathexception::mathexception()
{

}

const char* mathexception::what() const throw ()
{
	return "divide by zero";
}
