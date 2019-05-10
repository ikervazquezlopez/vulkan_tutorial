#include "Initializers.h"

VkApplicationInfo Initializers::ApplicationInfo(VulkanConfiguration &config)
{
	VkApplicationInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	info.pApplicationName = config.application_name;
	info.pEngineName = config.engine_name;
	info.applicationVersion = config.application_version;
	info.engineVersion = config.engine_version;
	info.apiVersion = config.api_version;

	return info;
}

VkInstanceCreateInfo Initializers::InstanceCreateInfo(VkApplicationInfo& app_info)
{
	VkInstanceCreateInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	info.pApplicationInfo = &app_info;
	info.enabledExtensionCount = 0;
	info.enabledLayerCount = 0;
	info.ppEnabledExtensionNames = NULL;
	info.ppEnabledLayerNames = NULL;

	return info;
}

VkInstanceCreateInfo Initializers::InstanceCreateInfo(VkApplicationInfo& app_info, std::vector<const char*>& layers, std::vector<const char*>& extensions)
{
	VkInstanceCreateInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	info.pApplicationInfo = &app_info;
	info.enabledLayerCount = layers.size();
	info.ppEnabledLayerNames = layers.data();
	info.enabledExtensionCount = extensions.size();
	info.ppEnabledExtensionNames = extensions.data();

	return info;
}

VkDeviceQueueCreateInfo Initializers::DeviceQueueCreateInfo(uint32_t family_index)
{
	VkDeviceQueueCreateInfo info;
	float queue_priorities[1] = { 0.0 };

	info.queueFamilyIndex = family_index;
	info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	info.pNext = NULL;
	info.queueCount = 1;
	info.pQueuePriorities = queue_priorities;

	return info;
}

VkDeviceCreateInfo Initializers::DeviceCreateInfo(VkDeviceQueueCreateInfo& queue_info, std::vector<const char*>& layers, std::vector<const char*>& extensions)
{
	VkDeviceCreateInfo info;
	info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	info.pNext = NULL;
	info.queueCreateInfoCount = 1;
	info.pQueueCreateInfos = &queue_info;
	info.enabledLayerCount = layers.size();
	info.ppEnabledLayerNames = layers.data();
	info.enabledExtensionCount = extensions.size();
	info.ppEnabledExtensionNames = extensions.data();
	info.pEnabledFeatures = NULL;

	return info;
}

VkCommandPoolCreateInfo Initializers::CommandPoolCreateInfo(uint32_t family_index)
{
	VkCommandPoolCreateInfo info;
	info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	info.pNext = NULL;
	info.queueFamilyIndex = family_index;
	info.flags = 0;

	return info;
}

VkCommandBufferAllocateInfo Initializers::CommandBufferAllocateInfo(VkCommandPool cmd_pool)
{
	VkCommandBufferAllocateInfo info;
	info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	info.pNext = NULL;
	info.commandPool = cmd_pool;
	info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	info.commandBufferCount = 1;

	return info;
}

VkWin32SurfaceCreateInfoKHR Initializers::SurfaceCreateInfoKHR()
{
	VkWin32SurfaceCreateInfoKHR info;
	info.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
	info.pNext = NULL;
	//info.hinstance
	return info;
}
