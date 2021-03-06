#ifndef _SHADER_H
#define _SHADER_H

#include <SDL_opengl.h>
#include <string>
#include <vector>
#include <memory>
#include <glm\glm.hpp>
using namespace glm;
using namespace std;

/** \brief A shader class

This class creates a shader program from string sources (GLSL code) and implements functions for submitting uniform values to the shader.
One can bind the shader by its unique ID.
*/
class Shader
{
	struct ShaderAttribute
	{
		GLuint Location;
		string Name;
	};
	GLuint Program;

	vector<shared_ptr<ShaderAttribute>> Attributes;

	shared_ptr<ShaderAttribute> FindAttribute(string aName);

	bool HasTesselation;

	bool DepthTest;
	bool AlphaBlend;
	bool FaceCulling;

public:
	Shader(string aVertex, string aFragment);
	void Bind();

	void Uniform1f(string aName, float aValue);
	void Uniform2f(string aName, vec2 aVec);
	void Uniform3f(string aName, vec3 aVec);
	void Uniform4f(string aName, vec4 aVec);
	void UniformMat4(string aName, mat4 aMat);
	void Uniform1i(string aName, int aI);
	void UniformLights(vector<vec3> aPositions, vector<vec3> aColor, vector<vec3> aDirection, vector<int> aType);
	~Shader();


	static shared_ptr<Shader> FlatTextured();
	static shared_ptr<Shader> BlinnPhongTextured();
	static shared_ptr<Shader> SkyBox();
	static shared_ptr<Shader> Terrain();
};

#else
class Shader;
#endif
