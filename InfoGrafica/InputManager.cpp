#include "InputManager.h"

InputManager::InputManager()
{
	window = nullptr;
}

void InputManager::Initialise(GLFWwindow* newwindow)
{
	window = newwindow;
	instance = this;
	glfwSetKeyCallback(window, handleKeys);
}

void InputManager::handleKeys(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (!instance) return;

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, true);

	if (action == GLFW_PRESS) instance->keyState[key] = true;
	else if (action == GLFW_RELEASE) instance->keyState[key] = false;

}