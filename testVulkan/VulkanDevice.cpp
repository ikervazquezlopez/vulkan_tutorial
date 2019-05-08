#include "VulkanDevice.h"

VulkanDevice::VulkanDevice(VulkanInstance *instance)
{
	/* Enumerate GPUs */
	std::vector<VkPhysicalDevice> gpus = instance->GetGpus();

	/* Init device family queue */
	uint32_t queue_family_count;
	std::vector<VkQueueFamilyProperties> queue_props;

	vkGetPhysicalDeviceQueueFamilyProperties(gpus[0], &queue_family_count, NULL);
	assert(queue_family_count >= 0);

	queue_props.resize(queue_family_count);
	vkGetPhysicalDeviceQueueFamilyProperties(gpus[0], &queue_family_count, queue_props.data());
	assert(queue_family_count >= 1);

	bool found = false;
	uint32_t family_index;
	for (unsigned int i = 0; i < queue_family_count; i++) {
		if (queue_props[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
			family_index = i;
			found = true;
			break;
		}
	}

	assert(found);
	assert(queue_family_count >= 1);


	/* Init graphical device */
	this->queue_info = Initializers::DeviceQueueCreateInfo(family_index);

	this->device_info = Initializers::DeviceCreateInfo(this->queue_info);

	VkResult res = vkCreateDevice(gpus[0], &this->device_info, NULL, &this->device);
	assert(res == VK_SUCCESS);


	/* Command pool */
	this->cmd_pool_info = Initializers::CommandPoolCreateInfo(this->queue_info.queueFamilyIndex);

	res = vkCreateCommandPool(this->device, &this->cmd_pool_info, NULL, &this->cmd_pool);
	assert(res == VK_SUCCESS);

	/* Command buffer for command pool */
	this->cmd_buff_info = Initializers::CommandBufferAllocateInfo(this->cmd_pool);
	res = vkAllocateCommandBuffers(this->device, &this->cmd_buff_info, &this->cmd_buffer);
	assert(res == VK_SUCCESS);
}

VulkanDevice::~VulkanDevice()
{
	VkCommandBuffer cmd_bufs[1] = {this->cmd_buffer};
	vkFreeCommandBuffers(this->device, this->cmd_pool, 1, cmd_bufs);
	vkDestroyCommandPool(this->device, this->cmd_pool, NULL);
	vkDeviceWaitIdle(this->device);
	vkDestroyDevice(this->device, NULL);
}

VkDevice& VulkanDevice::GetDevice()
{
	return this->device;
}

VkCommandBuffer& VulkanDevice::GetCommandBuffer()
{
	return this->cmd_buffer;
}

VkCommandPool& VulkanDevice::GetCommandPool()
{
	return this->cmd_pool;
}

VkDeviceQueueCreateInfo& VulkanDevice::GetDeviceQueueCreateInfo()
{
	return this->queue_info;
}

VkDeviceCreateInfo& VulkanDevice::GetDeviceCreateInfo()
{
	return this->device_info;
}

VkCommandPoolCreateInfo& VulkanDevice::GetCommandPoolCreateInfo()
{
	return this->cmd_pool_info;
}

VkCommandBufferAllocateInfo& VulkanDevice::GetCommandBufferAllocateInfo()
{
	return this->cmd_buff_info;
}
