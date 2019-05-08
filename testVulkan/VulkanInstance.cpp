#include "VulkanInstance.h"

VulkanInstance::VulkanInstance(VulkanConfiguration& vulkan_config)
{
	VkApplicationInfo application_info = Initializers::ApplicationInfo(vulkan_config);

	this->extensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
	VkInstanceCreateInfo instance_info = Initializers::InstanceCreateInfo(application_info, this->layers, this->extensions);
	

	ErrorCheck(vkCreateInstance(&instance_info, NULL, &instance));

	VkResult res = SetGpus();
}

VulkanInstance::~VulkanInstance()
{
	vkDestroyInstance(instance, NULL);
}

VkInstance& VulkanInstance::GetInstance()
{
	return instance;
}

std::vector<VkPhysicalDevice>& VulkanInstance::GetGpus()
{
	return gpus;
}

VkResult VulkanInstance::SetGpus()
{	
	uint32_t gpu_count = 1;
	VkResult res = vkEnumeratePhysicalDevices(instance, &gpu_count, NULL);
	gpus.resize(gpu_count);
	res = vkEnumeratePhysicalDevices(instance, &gpu_count, gpus.data());
	assert(!res && gpu_count >= 1);
	return res;
}
