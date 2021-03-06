#pragma once

#include "BUILD_ORDER.h"

namespace Initializers {

	

	VkApplicationInfo ApplicationInfo(VulkanConfiguration& config);

	VkInstanceCreateInfo InstanceCreateInfo(VkApplicationInfo &app_info);
	VkInstanceCreateInfo InstanceCreateInfo(VkApplicationInfo &app_info, std::vector<const char*> &layers, std::vector<const char*> &extensions);

	VkDeviceQueueCreateInfo DeviceQueueCreateInfo(uint32_t family_index);

	VkDeviceCreateInfo DeviceCreateInfo(VkDeviceQueueCreateInfo& queue_info, std::vector<const char*>& layers, std::vector<const char*>& extensions);

	VkCommandPoolCreateInfo CommandPoolCreateInfo(uint32_t family_index);
	VkCommandBufferAllocateInfo CommandBufferAllocateInfo(VkCommandPool cmd_pool);

	VkWin32SurfaceCreateInfoKHR SurfaceCreateInfoKHR();


}