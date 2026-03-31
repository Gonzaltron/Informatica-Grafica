#pragma once
#include <GL/glew.h>

class Material
{
	public:
		Material();
		Material(GLuint specularIntensity, GLuint hsininessLocation);
		void UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);
		~Material();

	private:
		GLfloat specularIntensity;
		GLfloat shininess;
};

