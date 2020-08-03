
#include "Utils.h"
#include <iostream>

bool ensure(void* ptr)
{
	if (ptr == nullptr)
	{
		printf("ensure: There is nullptr somewhere.\n");
		return false;
	}

	return true;
}