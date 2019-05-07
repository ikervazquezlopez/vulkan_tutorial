#include "BUILD_ORDER.h"


VulkanInstance* instance;

int main() 
{
	VulkanConfiguration vulkan_config;
	vulkan_config.application_name = "My vulkan app";
	vulkan_config.application_version = VK_MAKE_VERSION(1, 0, 0);

	instance = new VulkanInstance(vulkan_config);


	/* Enumerate GPUs */
	std::vector<VkPhysicalDevice> gpus;
	gpus = instance->GetGpus();
	std::cout << "Physical devices found: " << gpus.size() << std::endl;

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
	VkDeviceQueueCreateInfo queue_info = Initializers::DeviceQueueCreateInfo(family_index);

	VkDeviceCreateInfo device_info = Initializers::DeviceCreateInfo(queue_info);

	VkDevice device;
	VkResult res = vkCreateDevice(gpus[0], &device_info, NULL, &device);
	assert(res == VK_SUCCESS);



	delete instance;

	return 0;
}