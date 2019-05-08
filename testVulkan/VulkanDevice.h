#pragma once

#include "BUILD_ORDER.h"

extern class VulkanInstance;

class VulkanDevice
{
public:
	VulkanDevice(VulkanInstance *instance);
	~VulkanDevice();

	VkDevice& GetDevice();
	VkCommandBuffer& GetCommandBuffer();
	VkCommandPool& GetCommandPool();

	VkDeviceQueueCreateInfo& GetDeviceQueueCreateInfo();
	VkDeviceCreateInfo& GetDeviceCreateInfo();
	VkCommandPoolCreateInfo& GetCommandPoolCreateInfo();
	VkCommandBufferAllocateInfo& GetCommandBufferAllocateInfo();

private:

	VkDevice device;
	VkCommandBuffer cmd_buffer;
	VkCommandPool cmd_pool;

	VkDeviceQueueCreateInfo queue_info;
	VkDeviceCreateInfo device_info;
	VkCommandPoolCreateInfo cmd_pool_info;
	VkCommandBufferAllocateInfo cmd_buff_info;
};