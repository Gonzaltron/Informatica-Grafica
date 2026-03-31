#include "Light.h"

Light::Light()
{
	color = glm::vec3(1.0f, 0.0f, 1.0f);
	aInstensity = 1.0f;
	direction = glm::vec3(0);
	dIntensity = 0.0f;
}

Light::Light(glm::vec3 color, GLfloat ambientIntensity, glm::vec3 dir, GLfloat diffuseIntensity)
{
	this->color = color;
	this->aInstensity = ambientIntensity;
	direction = dir;
	dIntensity = diffuseIntensity;
}

void Light::UseLight(GLfloat colorLocation, GLfloat aIntensityLocation, GLfloat directionLocation, GLfloat dIntensityLocation)
{
	glUniform1f(aIntensityLocation, aInstensity);
	glUniform1f(dIntensityLocation, dIntensity);
	glUniform3f(colorLocation, color.x, color.y, color.z);
	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
}

Light::~Light()
{
}
