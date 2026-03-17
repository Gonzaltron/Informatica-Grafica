#pragma once
#include<GLFW/glfw3.h>
#include <map>

class InputManager
{
public:
	InputManager();
	void Initialise(GLFWwindow* window);
	bool isKeyPressed(int key);
	double getMouseDeltaY() { return deltaY; }
	double getMouseDeltaX() { return deltaX; }

	private:
		GLFWwindow* window;
		std::map<int, bool> keyState;
		double lastX, lastY;
		double deltaX, deltaY;

		static InputManager* instance;
		static void handleKeys(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void handleMouse(GLFWwindow* wondow, double posX, double posY);
};

