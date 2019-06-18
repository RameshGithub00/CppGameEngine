#include <iostream>

#include <Renderer/OpenGL/glrenderer.h>

int main()
{
	GLRenderer renderer;
	renderer.Init();
	std::cout << "Hello Again"<<std::endl;
	return 0;
}