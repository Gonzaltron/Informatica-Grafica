#include "Light.h"

Light::Light()
{
	color = glm::vec3(1.0f, 0.0f, 1.0f);
	aIntensity = 1.0f;
}

Light::Light(glm::vec3 color, float intensity)
{
	this->color = color;
	this->aIntensity = intensity;
}

void Light::UseLight(GLfloat colorLocation, GLfloat aIntensityLocation)
{
	glUniform1f(aIntensityLocation, aIntensity);
	glUniform3f(colorLocation, color.x, color.y, color.z);
}
