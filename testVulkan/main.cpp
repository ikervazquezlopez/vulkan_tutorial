#include "BUILD_ORDER.h"


VulkanInstance* instance;
VulkanDevice* device;

int main() 
{
	if (!glfwInit()) {
		return -1;
	}

	uint32_t extensions_count;
	auto extensions = glfwGetRequiredInstanceExtensions(&extensions_count);

	VulkanConfiguration vulkan_config;
	vulkan_config.application_name = "My vulkan app";
	vulkan_config.application_version = VK_MAKE_VERSION(1, 0, 0);

	instance = new VulkanInstance(vulkan_config, extensions, extensions_count);
	device = new VulkanDevice(instance);

	
	/* Iterate over each queue to check if it supports presenting */
	GLFWwindow* window;
	VkSurfaceKHR surface;
	VkBool32* pSupportsPresent = (VkBool32*)malloc(device->GetDeviceQueueCreateInfo().queueCount * sizeof(VkBool32));
	for (uint32_t i = 0; i < device->GetDeviceQueueCreateInfo().queueCount; i++)
	{
		int result = glfwGetPhysicalDevicePresentationSupport(instance->GetInstance(), device->GetPhysicalDevice(), i);
		assert(result != GLFW_FALSE);
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		window = glfwCreateWindow(640, 480, "testVulkan", NULL, NULL);
		//vkGetPhysicalDeviceSurfaceSupportKHR(device->GetDevice(), i, );

		VkResult res = glfwCreateWindowSurface(instance->GetInstance(), window, NULL, &surface);
		assert(res == VK_SUCCESS);
	}


	delete device;
	delete instance;

	return 0;
}