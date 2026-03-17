#include "Camara.h"


Camara::Camara(){}

Camara::Camara(glm::vec3 startPos, glm::vec3 fron, glm::vec3 startUp, glm::vec3 right, glm::vec3 startWorldUp, float startPitch, float startYaw, float startMoveSpeed, float  startTurnSpeed)
{
	pos = startPos;
	up = startUp;
	worldUp = startWorldUp;
	pitch = startPitch;
	yaw = startYaw;
	turnSpeed = startTurnSpeed;
	moveSpeed = startMoveSpeed;
	front = glm::vec3(0.0f, 0.0f, -1.0f);

}

void Camara::update(InputManager& input, float deltaTime)
{
	if (input.isKeyPressed(GLFW_KEY_W)) pos += front * moveSpeed * deltaTime;
	if (input.isKeyPressed(GLFW_KEY_A)) pos -= right * moveSpeed * deltaTime;
	if (input.isKeyPressed(GLFW_KEY_S)) pos -= front * moveSpeed * deltaTime;
	if (input.isKeyPressed(GLFW_KEY_D)) pos += right * moveSpeed * deltaTime;
	if (input.isKeyPressed(GLFW_KEY_Q)) pos += up * moveSpeed * deltaTime;
	if (input.isKeyPressed(GLFW_KEY_E)) pos -= up * moveSpeed * deltaTime;

	yaw += input.getMouseDeltaX() * turnSpeed * deltaTime;
	pitch += input.getMouseDeltaY() * turnSpeed * deltaTime;

	if (pitch > 89.9f) pitch = 89.9f;
	if (pitch < -89.9f) pitch = -89.9f;
}

glm::mat4 Camara::getViewMatrix()
{
	return glm::lookAt(pos, pos+front, up);
}

void Camara::Recalculate()
{
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(yaw));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);
	right = glm::normalize(glm::cross(right, front));
}