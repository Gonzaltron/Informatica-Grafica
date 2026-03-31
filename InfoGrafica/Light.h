#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
class Light
{
public:
	Light();
	Light(glm::vec3 color, GLfloat ambientIntensity, glm::vec3 dir, GLfloat diffuseIntensity);
	void UseLight(GLfloat colorLocation, GLfloat aIntensityLocation, GLfloat directionLocation, GLfloat dIntensityLocation);
	~Light();
private:
	glm::vec3 direction;
	glm::vec3 color;
	GLfloat aInstensity;
	GLfloat dIntensity;
};

