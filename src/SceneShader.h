/*
 * SceneShader.h
 *
 *  Created on: Nov 17, 2015
 *      Author: acarocha
 */

#ifndef SCENESHADER_H_
#define SCENESHADER_H_

#include "Shader.h"
#include <vector>

#define GLM_FORCE_RADIANS

#include "TriMesh.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/* Assignment 2 inclusion */
#include "texture.h"

class SceneShader : public Shader
{
public:

	SceneShader();
	~SceneShader();

	void startup ();
	void shutdown ();
	void render();

	void renderPlane();
	void renderMesh();
	void renderLight();

	void setAspectRatio( float ratio );
	void setZTranslation(float z);
	void setRotationX( float x );
	void setRotationY( float y );

	void updateLightPositionX( float x );
	void updateLightPositionY( float y );
	void updateLightPositionZ( float z );

	/* Assignment 2 update methods */
	void updaterAdd();
	void updaterSubtract();
	void imagePick();
	void imagePick1();
	void imagePick2();
	void imagePick3();

private:

	/*methods*/
	void readMesh( std::string filename );
	void createVertexBuffer();

	//image
	std::vector<unsigned char> _image;
	unsigned int _imageWidth;
	unsigned int _imageHeight;

	/*variables*/
	GLuint _programLight;
	GLuint _programPlane;
	GLuint _programMesh;

	GLuint _planeVertexArray;
	GLuint _planeVertexBuffer;
	GLuint _planeTextureBuffer;

	GLuint _meshVertexArray;
	GLuint _meshVertexBuffer;

	GLuint _meshNormalBuffer;
	GLuint _meshIndicesBuffer;

	GLuint _meshTextureBuffer;

	/* Textures */
	GLuint _textureID;
	GLuint _textureImageID;
	Texture _texture;

    GLint _mvUniform, _projUniform;

	/* Matrices */
	glm::mat4 _modelview;
	glm::mat4 _projection;
	
	float _zTranslation;
	float _xRot;
	float _yRot;
	float _aspectRatio;

	
	trimesh::TriMesh* _mesh;
	std::vector<unsigned int> _triangleIndices;

	glm::vec3 lightPosition;

	/* Assignment 2 update variables */
	glm::vec2 ri;

};

#endif /* SCENESHADER_H_ */
