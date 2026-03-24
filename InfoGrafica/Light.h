#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
class Light
{
	public:
		Light();
		Light(glm::vec3 color, float intensity);
		void UseLight(GLfloat colorLocation, GLfloat aIntensityLocation);
	private:
		glm::vec3 color;
		GLfloat aIntensity;
};

