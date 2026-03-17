#pragma once
#include<GLFW/glfw3.h>
#include <map>

class InputManager
{
	public:
		InputManager();
		~InputManager();
		void Initialise(GLFWwindow* window);
		bool isKeyPressed(int key);

	private:
		GLFWwindow* window;
		std::map<int, bool> keyState;
		static InputManager* instance;
		static void handleKeys(GLFWwindow* window, int key, int scancode, int action, int mods);
};

