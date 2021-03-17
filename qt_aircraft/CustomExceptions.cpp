#include "CustomExceptions.h"

const char* BaseRepoException::what() const
{
	return "Generic repository exception";
}
