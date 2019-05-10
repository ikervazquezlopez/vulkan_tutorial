#pragma once

#include "BUILD_ORDER.h"

typedef class VulkanInstance
{

public:
	VulkanInstance(VulkanConfiguration& vulkan_config);
	VulkanInstance(VulkanConfiguration& vulkan_config, const char** extra_extensions, uint32_t extra_extensions_count);
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