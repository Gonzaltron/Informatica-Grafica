#include "Material.h"

Material::Material()
{
	specularIntensity = 0.0f;
	shininess = 1.0f;
}

Material::Material(GLuint specularIntensity, GLuint hsininessLocation)
{
	this->specularIntensity = specularIntensity;
	this->shininess = shininess;
}

void Material::UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation)
{
	glUniform1f(specularIntensityLocation, specularIntensity)
	glUniform1f(shininessLocation, specularIntensity)
}

Material::~Material()
{
}
