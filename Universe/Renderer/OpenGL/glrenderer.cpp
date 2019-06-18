#include "precompiled.h"
#include "glrenderer.h"

void GLRenderer::Init()
{
	GLFWmonitor* monitor;
	GLFWwindow* window;
	
	if (!glfwInit())
	{
		assert(false);
	}

	window = glfwCreateWindow(640, 480, "OpenGL", nullptr, nullptr);
	
	glfwMakeContextCurrent(window);

	glewInit();

	glClearColor(0, 0, 0, 0);

	float vertex[]={
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.0f,0.5f,0.0f,
		//2nd tri
		-0.8f,-0.8f,0.0f,
		0.5f,-0.5f,0.0f,
		-0.3f,0.85f,0.0f
	};

	
	//GLuint VertexArrayID;
	//glGenVertexArrays(1, &VertexArrayID);
	//glBindVertexArray(VertexArrayID);

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);


	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();

		glDrawArrays(GL_TRIANGLES,0,6);

		glfwSwapBuffers(window);
	}

	glfwTerminate();

}