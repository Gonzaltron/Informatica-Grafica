#version 330
in vec4 vColor;
in vec3 normal;

struct LuzDireccional
{
    vec3 color;
    float ambientInten;
};
uniform LuzDireccional luzDir;
out vec4 colour;
void main(){
    vec3 ambient = luzDir.ambientInten * luzDir.color;

    vec3 luzFinal = ambient;
    colour = vColor * luzFinal;
}