#pragma once
#include <GLFW/glfw3.h>
#include<vector>
#include"Icon.h"
#include<stdbool.h>

class Baseicon;
class Icon_0;

class Window
{
private:
	GLFWwindow* window;
	int width;
	int height;
	double xcur;
	double ycur;
	float * pixels;
	std::vector<Baseicon*> Icon;

public:
	Window(const int& width, const int& height);
	bool init();
	bool destory();
	bool run();
	void pushicon(Baseicon& icon);
	void drawpixels(const int& i, const int& j, const float& red, const float& green, const float& blue);
	void drawline(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
	int getheight();
	~Window();
	
};
