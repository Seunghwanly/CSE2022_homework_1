#pragma once
#include "Window.h"

class Window;

class Baseicon
{
	float r;
	float g;
	float b;
	double xcur;
	double ycur;
protected:
	int x;
	int y;
	int width;
	int height;
public:
	Baseicon(
		const int& x,
		const int& y,
		const int& width,
		const int& height,
		const float& r,
		const float& g,
		const float& b
		);
	virtual void draw(Window* window);
	void mouse(const double& x, const double& y);
	bool checkX(int, int,Window*);
	bool checkY(int, int,Window*);
};

class Icon_0 : public Baseicon
{
private:
public:
	Icon_0(
		const int& x,
		const int& y,
		const int& width,
		const int& height,
		const float& r,	
		const float& g,
		const float& b 
		);
	virtual void draw(Window* window);
	bool mouseOn(const double& x, const double& y);
};
class Icon_1 : public Baseicon
{
private:
public:
	Icon_1(const int& x, const int& y, const int& width, const int& height, const float& r, const float& g, const float& b);
	virtual void draw(Window* window);
};
class Icon_2 : public Baseicon
{
private:
public:
	Icon_2(const int& x, const int& y, const int& width, const int& height, const float& r, const float& g, const float& b);
	virtual void draw(Window* window);
};
class Icon_3 : public Baseicon
{
private:
public:
	Icon_3(const int& x, const int& y, const int& width, const int& height, const float& r, const float& g, const float& b);
	virtual void draw(Window* window);
};
class Icon_4 : public Baseicon
{
private:
public:
	Icon_4(const int& x, const int& y, const int& width, const int& height, const float& r, const float& g, const float& b);
	virtual void draw(Window* window);
};
class Icon_5 : public Baseicon
{
private:
public:
	Icon_5(const int& x, const int& y, const int& width, const int& height, const float& r, const float& g, const float& b);
	virtual void draw(Window* window);
};
class Icon_6 : public Baseicon
{
private:
public:
	Icon_6(const int& x, const int& y, const int& width, const int& height, const float& r, const float& g, const float& b);
	virtual void draw(Window* window);
};
class Icon_7 : public Baseicon
{
private:
public:
	Icon_7(const int& x, const int& y, const int& width, const int& height, const float& r, const float& g, const float& b);
	virtual void draw(Window* window);
};
class Icon_8 : public Baseicon
{
private:
public:
	Icon_8(const int& x, const int& y, const int& width, const int& height, const float& r, const float& g, const float& b);
	virtual void draw(Window* window);
};
class Icon_9 : public Baseicon
{
private:
public:
	Icon_9(const int& x, const int& y, const int& width, const int& height, const float& r, const float& g, const float& b);
	virtual void draw(Window* window);
};
