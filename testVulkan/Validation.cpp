#include "Validation.h"

void ErrorCheck(VkResult result)
{
	if (result != VK_SUCCESS)
	{
		std::cout << "Error" << std::endl;
		assert(0 && "There was an error");
	}
}
