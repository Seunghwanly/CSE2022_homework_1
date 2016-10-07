#include"Window.h"
#include<iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <stdbool.h>

Window::Window(const int& width, const int& height)
{
	this->width = width; this->height = height;
	pixels = new float[width*height * 3];
	xcur = 0; ycur = 0;
} 


bool Window::init() //make the window
{
	/* Initialize the library */
	if (!glfwInit())
		return false;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return false;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background
	return true;
}

bool Window::run() 
{
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

	glfwGetCursorPos(window, &xcur, &ycur);

	for (int i = 0; i < Icon.size() ; i++)
	{
		Icon[i]->draw(this);
		Icon[i]->mouse(xcur, ycur);
	}

	glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

	/* Swap front and back buffers */
	glfwSwapBuffers(window);

	/* Poll for and process events */
	glfwPollEvents();

	std::this_thread::sleep_for(std::chrono::milliseconds(10));

	if (glfwWindowShouldClose(window))
		return false;
	return true;
}

bool Window::destory() //destory the window
{
	glfwTerminate();

	return true;
}

Window::~Window()
{
	delete[] pixels; // or you may reuse pixels array 
}

void Window::drawpixels(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void Window::drawline(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	if ((i1 - i0) == 0)
	{
		for (int i = j0; i <= j1; i++)
		{
			this->drawpixels(i0, i, red, green, blue);
		}
	}
	else
	{
		for (int i = i0; i <= i1; i++)
		{
			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

			this->drawpixels(i, j, red, green, blue);
		}
	}
}
void Window::pushicon(Baseicon& Icon)
{
	this->Icon.push_back(&Icon);
}

int Window::getheight()
{
	return height;
}