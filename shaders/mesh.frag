#version 430 core

out vec4 color;

in vec3 N;
in vec3 L;
in vec3 V;
in vec2 UV;

// Assingment 2 implementation

uniform sampler2D image;
uniform vec2 ri;

// Assignment 2 implementation of x-toon shading following the formula provided in class

void main(void)
{
	vec3 white = vec3(1.0, 1.0, 1.0);
	vec3 R = normalize(reflect(-L, N));
	float diffuse = max(0.01, dot(N, L));
	float D = max(0.01, pow(abs(dot(N, V)), ri.x));
	vec2 vecs = vec2(diffuse, D);
	vec4 colorImage = texture(image, vecs);
	color = colorImage;
}
