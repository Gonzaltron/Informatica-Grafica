#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL/glew.h>
#include <glm/glm.hpp>

struct UniformBaseLight {
	GLuint uniformColor;
	GLuint uniformAmbientInten;
	GLuint uniformDiffuseInten;
	
};
struct UniformDirectionalLigh {
	
	UniformBaseLight base;
	GLuint uniformDir;
};
class Shader
{
public:
	Shader();
	void CreateShadersFromString(const char* vertexCode, const char* fragmentCode);
	void CreateShadersFromFile(const char* vertexPath, const char* fragmentPath);

	GLuint GetIdModel() { return uniformModel; }
	GLuint GetIdProjection() { return uniformProjection; }
	GLuint GetIdView() { return uniformView; }
	GLuint GetIdCameraPos() { return uniformCameraPos; }
	const UniformDirectionalLigh GetIdDirectionalLight() { return uniformDirLight; }
	GLuint GetIdShininess() { return uniformShininess; }
	GLuint GetIdSpecularInten() { return uniformSpecularInten; }
	GLuint GetIdTime() { return uniformTime; }



	void useShader();
	void deleteShader();
	~Shader();


private:
	GLuint idShader = 0, uniformModel = 0, uniformProjection = 0, uniformView = 0, uniformCameraPos = 0;
	GLuint uniformShininess, uniformSpecularInten;
	GLuint uniformTime = 0;
	UniformDirectionalLigh uniformDirLight;

	std::string ReadFile(const char* path);
	void AddShader(const char* shaderCode, GLenum shaderType);
	void CompileShader(const char* vertexCode, const char* fragmentCode);


};

