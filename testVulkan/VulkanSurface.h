#pragma once

#include "BUILD_ORDER.h"

class VulkanSurface
{
public:

	VulkanSurface();
	~VulkanSurface();

	VkSurfaceKHR GetSurface();
	VkWin32SurfaceCreateInfoKHR GetSurfaceInfo();

private:

	VkSurfaceKHR surface;
	VkWin32SurfaceCreateInfoKHR surface_info;
};