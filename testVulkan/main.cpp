#include "BUILD_ORDER.h"


VulkanInstance* instance;

int main() 
{
	VulkanConfiguration vulkan_config;
	vulkan_config.application_name = "My vulkan app";
	vulkan_config.application_version = VK_MAKE_VERSION(1, 0, 0);

	instance = new VulkanInstance(vulkan_config);


	VulkanDevice* device = new VulkanDevice(instance);



	delete device;
	delete instance;

	return 0;
}