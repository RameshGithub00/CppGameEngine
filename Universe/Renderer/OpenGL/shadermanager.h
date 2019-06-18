#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

enum VertexLayoutType
{
	POSITION,
	COLOR,
	TEX_COORD,
	NORMALS,
	TANGENTS,
};

class Shader
{

	GLuint m_ProgramId;

	int nPositionComponets;
	int nColorComponets;
	int nTexCoordComponets;
	int nNormaComponets;
	int nTangentComponets;

public:
	Shader():m_ProgramId(0),
			nPositionComponets(3),
			nColorComponets(4),
			nTexCoordComponets(2),
			nNormaComponets(3),
			nTangentComponets(3)

	{}

	void Use();

	void CreateInputLayout(GLvoid* bufferoffset=0);
	void SetInputLayout();


};

class ShaderManager
{
public:
	ShaderManager();

	Shader* GetShader(char*name);
	bool LoadShader(char*name);
};