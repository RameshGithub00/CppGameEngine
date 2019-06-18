#pragma once

#include <iostream>
class GLRenderer
{
public:
	GLRenderer()
	{
		std::cout << "Renderer Constructed";
	}

	void Init();
};