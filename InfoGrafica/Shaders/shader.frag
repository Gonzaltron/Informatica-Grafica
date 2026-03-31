#version 330
in vec4 vColor;
in vec3 normal;

struct DirectionalLight
{
    vec3 color;
    float ambientInten;
    vec3 lightDir;
    float diffuseInten; 
};

uniform DirectionalLight directionalLight;
uniform vec3 cameraPos = vec3(0, 0, 0);
out vec4 colour;
void main(){
    vec3 norm = normalize(normal);
    vec3 lDir = normalize(directionalLight.lightDir);
    vec3 ambient = directionalLight.ambientInten * directionalLight.color;

    

    float diff = max(dot(norm, lDir), 0.0f);
    vec3 diffuse = directionalLight.color * directionalLight.diffuseInten * diff;
    vec3 luzFinal = ambient + diffuse;
    vec3 tempColor = vec3(0.5f, 0.5f, 0.5f);
    colour = vec4(luzFinal, 1.0f);
}