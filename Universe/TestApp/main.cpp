#include <iostream>

#include <Renderer/OpenGL/glrenderer.h>

int main()
{
	GLRenderer renderer;
	renderer.Init();
	std::cout << "Hello Again"<<std::endl;
	int k;
	std::cin >> k;
	return 0;
}