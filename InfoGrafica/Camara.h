#pragma once
#include "InputManager.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
class Camara
{
	public:
		Camara();
		Camara(glm::vec3 startPos, glm::vec3 fron, glm::vec3 startUp, glm::vec3 right, glm::vec3 worldUp, float startPitch, float startYaw, float moveSpeed, float  turnSpeed);
		void update(InputManager& input, float deltaTime);
		glm::mat4 getViewMatrix();


	private:
		glm::vec3 pos;
		glm::vec3 front;
		glm::vec3 up;
		glm::vec3 right;
		glm::vec3 worldUp;
		float pitch, yaw;
		float moveSpeed, turnSpeed;
		void Recalculate();

};

