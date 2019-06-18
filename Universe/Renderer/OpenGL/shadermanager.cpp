#include "precompiled.h"
#include "shadermanager.h"

void Shader::CreateInputLayout(GLvoid* bufferoffset)
{
	if (nPositionComponets)
		glVertexAttribPointer(0, nPositionComponets, GL_FLOAT, false, 0, bufferoffset);
}