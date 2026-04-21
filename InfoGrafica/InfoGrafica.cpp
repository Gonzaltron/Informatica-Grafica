// InfoGrafica.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#define _USE_MATH_DEFINES


#include <iostream>
#include <cmath>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Mesh.h"
#include "Shader.h"
#include "Window.h"
#include "InputManager.h"
#include "Camera.h"
#include "Light.h"
#include "DirectionalLight.h"
#include "Material.h"

const GLint WIDTH = 800, HEIGHT = 600;
const float TORADIANS = M_PI / 180.0f;

float posX = 0, speed = 2, posMax = 0.8;

float currentRot = 0, rotSpeed = 20, maxRot = 300;
std::vector<Mesh*> meshList;
std::vector<Shader*> shaderList;


InputManager input;
Camera mainCamera;
DirectionalLight luzDireccional;
Material mat;
//Vertex shader
static const char* vShader = "Shaders/shader.vs";
//Fragment shader
static const char* fShader = "Shaders/shader.fs";


void CreateTriangle() {
    GLfloat vertices[] = {
//       x        y    z    nx     ny     nz      u     v
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,   0.0f , 1.0f,
        0.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,   0.5f , 1.0f,
        1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,    1.0f , 1.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,     0.5f , 0.0f
    };
    GLuint indices[] = {
        0, 1, 3,
        1, 2, 3,
        2, 0, 3,
        0, 2 ,1
    };
    Mesh* newMesh = new Mesh();
    newMesh->RecalculateNormals(vertices, indices, 32, 12, 8, 3);
    newMesh->CreateMesh(vertices, indices, 32, 12);
    meshList.push_back(newMesh);
}


void CreateShader() {
    Shader* shader = new Shader();
    shader->CreateShadersFromFile(vShader, fShader);
    shaderList.push_back(shader);
}

int main()
{
    Window mainWindow = Window(WIDTH, HEIGHT);
    mainWindow.Initialize();
    input = InputManager();
    input.Initialise(mainWindow.getWindow());
    mainCamera = Camera(
        glm::vec3(0, 0, 5.0f),
        -90.0f, 0.0f,
        5.0f,
        1.0f,
        glm::vec3(0.0f, 1.0f, 0.0f)
    );
    luzDireccional = DirectionalLight(glm::vec3(1.0f, 1.0f, 1.0f), 0.1f, 1, glm::vec3(-0.4f, -1.0f, 0.0f));
    mat = Material(2, 20);

    CreateShader();
    CreateTriangle();

    glm::mat4 projeccion = glm::perspective(glm::radians(45.0f), mainWindow.getBufferWidth() / (GLfloat)mainWindow.getBufferHeight(), 0.1f, 100.0f);


    float lastTime = (float)glfwGetTime();
    float deltaTime;


    while (!mainWindow.getWindowShouldClose()) {

        glfwPollEvents();

        float currentTime = (float)glfwGetTime();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        mainCamera.update(input, deltaTime);


        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderList[0]->useShader();

        luzDireccional.UseLight(shaderList[0]->GetIdDirectionalLight());

        glm::mat4 model(1.0f);
        model = glm::translate(model, glm::vec3(0, 0.0f, 0.0f));
        glUniformMatrix4fv(shaderList[0]->GetIdModel(), 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(shaderList[0]->GetIdProjection(), 1, GL_FALSE, glm::value_ptr(projeccion));
        glUniformMatrix4fv(shaderList[0]->GetIdView(), 1, GL_FALSE, glm::value_ptr(mainCamera.getViewMatrix()));
        glUniform3fv(shaderList[0]->GetIdCameraPos(), 1, glm::value_ptr(mainCamera.getCameraPos()));
        glUniform1f(shaderList[0]->GetIdTime(), currentTime);
        mat.UseMaterial(shaderList[0]->GetIdSpecularInten(), shaderList[0]->GetIdShininess());

        meshList[0]->RenderMesh();
        glUseProgram(0);

        mainWindow.swapBuffers();
    }

}