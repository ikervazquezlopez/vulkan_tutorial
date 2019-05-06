#pragma once

#include "BUILD_ORDER.h"

class VulkanInstance
{

public:
	VulkanInstance(VulkanConfiguration& vulkan_config);
	~VulkanInstance();

	VkInstance& GetInstance();
	std::vector<VkPhysicalDevice> &GetGpus();

private:

	/* MEMBERS */
	VkInstance instance;

	std::vector<const char*> layers;
	std::vector<const char*> extensions;

	std::vector<VkPhysicalDevice> gpus;



	/* METHODS */
	VkResult SetGpus();



};