#version 430 core

uniform mat4 modelview;
uniform mat4 projection;
uniform vec3 lightPosition;

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

//attributes in camera coordinates
out vec3 N;
out vec3 L;
out vec3 V;
out vec2 UV;

void main(void)
{
	UV = uv;

	vec4 lightCameraSpace = modelview*vec4(lightPosition, 1.0);

	lightCameraSpace.xyz /= lightCameraSpace.w;

	mat3 normalMatrix = transpose(inverse(mat3(modelview)));

	N = normalize(normalMatrix*normal);

    float scale = 4.0;    

	vec3 positionModelSpace = vertex*scale + vec3(0.0, -0.42, 0.0);

    vec4 positionCameraSpace = modelview * vec4(positionModelSpace, 1.0);

	positionCameraSpace.xyz /= positionCameraSpace.w;

	V = normalize(-positionCameraSpace.xyz);
	L = normalize(lightCameraSpace.xyz - positionCameraSpace.xyz);

    gl_Position = projection * positionCameraSpace;    
}
