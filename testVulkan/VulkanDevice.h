#pragma once

#include "BUILD_ORDER.h"

extern class VulkanInstance;

class VulkanDevice
{
public:
	VulkanDevice(VulkanInstance *instance);
	VulkanDevice(VulkanInstance* instance, const char **extra_extensions, uint32_t extensions_count);
	~VulkanDevice();

	VkDevice& GetDevice();
	VkPhysicalDevice& GetPhysicalDevice();
	VkCommandBuffer& GetCommandBuffer();
	VkCommandPool& GetCommandPool();

	VkDeviceQueueCreateInfo& GetDeviceQueueCreateInfo();
	VkDeviceCreateInfo& GetDeviceCreateInfo();
	VkCommandPoolCreateInfo& GetCommandPoolCreateInfo();
	VkCommandBufferAllocateInfo& GetCommandBufferAllocateInfo();

private:

	std::vector<const char*> layers;
	std::vector<const char*> extensions;

	VkDevice device;
	VkPhysicalDevice physical_device;
	VkCommandBuffer cmd_buffer;
	VkCommandPool cmd_pool;

	VkDeviceQueueCreateInfo queue_info;
	VkDeviceCreateInfo device_info;
	VkCommandPoolCreateInfo cmd_pool_info;
	VkCommandBufferAllocateInfo cmd_buff_info;
};