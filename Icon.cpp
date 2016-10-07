#include "Icon.h"
#include<iostream>
#define BMPY(y) height-y

Baseicon::Baseicon(
	const int& x,
	const int& y,
	const int& width,
	const int& height,
	const float& r,
	const float& g,
	const float& b
	)
{
	this->x = x; this->y = y; this->width = width; this->height = height; this->r = r; this->g = g; this->b = b;
}
//CURSOR IS ON?

void Baseicon::mouse(const double& x, const double& y)
{
	this->xcur = x; this->ycur = y;
}

//initialize
Icon_0::Icon_0(
	const int& x,
	const int& y,
	const int& width,
	const int& height,
	const float& r,
	const float& g,
	const float& b
)
	:Baseicon(x, y, width, height, r, g, b)
{}

Icon_1::Icon_1(
	const int& x,
	const int& y,
	const int& width,
	const int& height,
	const float& r,
	const float& g,
	const float& b
)
	: Baseicon(x, y, width, height, r, g, b)
{}

Icon_2::Icon_2(
	const int& x,
	const int& y,
	const int& width,
	const int& height,
	const float& r,
	const float& g,
	const float& b
)
	: Baseicon(x, y, width, height, r, g, b)
{}

Icon_3::Icon_3(
	const int& x,
	const int& y,
	const int& width,
	const int& height,
	const float& r,
	const float& g,
	const float& b
)
	: Baseicon(x, y, width, height, r, g, b)
{}

Icon_4::Icon_4(
	const int& x,
	const int& y,
	const int& width,
	const int& height,
	const float& r,
	const float& g,
	const float& b
)
	: Baseicon(x, y, width, height, r, g, b)
{}

Icon_5::Icon_5(
	const int& x,
	const int& y,
	const int& width,
	const int& height,
	const float& r,
	const float& g,
	const float& b
)
	: Baseicon(x, y, width, height, r, g, b)
{}

Icon_6::Icon_6(
	const int& x,
	const int& y,
	const int& width,
	const int& height,
	const float& r,
	const float& g,
	const float& b
)
	: Baseicon(x, y, width, height, r, g, b)
{}

Icon_7::Icon_7(
	const int& x,
	const int& y,
	const int& width,
	const int& height,
	const float& r,
	const float& g,
	const float& b
)
	: Baseicon(x, y, width, height, r, g, b)
{}

Icon_8::Icon_8(
	const int& x,
	const int& y,
	const int& width,
	const int& height,
	const float& r,
	const float& g,
	const float& b
)
	: Baseicon(x, y, width, height, r, g, b)
{}

Icon_9::Icon_9(
	const int& x,
	const int& y,
	const int& width,
	const int& height,
	const float& r,
	const float& g,
	const float& b
	)
	: Baseicon(x, y, width, height, r, g, b)
{}

//draw method
void Baseicon::draw(Window* window)
{
//change to square
	window->drawline(x - width / 3, y - height / 3, x + width / 3, y - height / 3, this->r, this->g, this->b);
	window->drawline(x - width / 3, y + height / 3, x + width / 3, y + height / 3, this->r, this->g, this->b);
	window->drawline(x - width / 3, y - height / 3, x - width / 3, y + height / 3, this->r, this->g, this->b);
	window->drawline(x + width / 3, y - height / 3, x + width / 3, y + height / 3, this->r, this->g, this->b);

	int p_x= x - width / 3;
	int p_y = y - height / 3;
	int q_x = x + width / 3;
	int q_y = y + height / 3;

	if (checkX(p_x,q_x, window) && checkY(p_y,q_y, window)) {
		this->r = 0.0f;
		this->g = 1.0f;
		this->b = 0.0f;
		window->drawline(x - width / 3, y - height / 3, x + width / 3, y - height / 3, this->r, this->g, this->b);
		window->drawline(x - width / 3, y + height / 3, x + width / 3, y + height / 3, this->r, this->g, this->b);
		window->drawline(x - width / 3, y - height / 3, x - width / 3, y + height / 3, this->r, this->g, this->b);
		window->drawline(x + width / 3, y - height / 3, x + width / 3, y + height / 3, this->r, this->g, this->b);
	}
	else {
		this->r = 0.0f;
		this->g = 0.0f;
		this->b = 1.0f;
	}

	//int x = this->width / 2;
	//int y = 0;
	//int err = 0;
	//if ( (xcur- this->x) * (xcur- this->x) + ((window->getheight() - ycur )- this->y)* ((window->getheight() - ycur) - this->y) - x*x < 0 )// 100, 100 -> 100,710
	//{
	//	this->r = 0.0;
	//	this->g = 0.0;
	//	this->b = 1.0;
	//}
	//else
	//{
	//	this->r = 1.0;
	//	this->g = 0.0;
	//	this->b = 0.0;
	//}
	//while (x >= y)
	//{
	//	window->drawpixels(this->x + x, this->y + y, this->r, this->g, this->b);
	//	window->drawpixels(this->x + y, this->y + x, this->r, this->g, this->b);
	//	window->drawpixels(this->x - y, this->y + x, this->r, this->g, this->b);
	//	window->drawpixels(this->x - x, this->y + y, this->r, this->g, this->b);
	//	window->drawpixels(this->x - x, this->y - y, this->r, this->g, this->b);
	//	window->drawpixels(this->x - y, this->y - x, this->r, this->g, this->b);
	//	window->drawpixels(this->x + y, this->y - x, this->r, this->g, this->b);
	//	window->drawpixels(this->x + x, this->y - y, this->r, this->g, this->b);
	//	y += 1;
	//	err += 1 + 2 * y;
	//	if (2 * (err - x) + 1 > 0)
	//	{
	//		x -= 1;
	//		err += 1 - 2 * x;
	//	}
//	}
}

bool Baseicon::checkX(int p_x, int q_x, Window *window)
{
	if ((p_x) < (xcur) && (xcur) < (q_x))
		return true;
	else
		return false;
}

bool Baseicon::checkY(int p_y, int q_y, Window *window)
{
	if ((p_y) < ((window->getheight() - ycur)) && ((window->getheight() - ycur)) < (q_y)) return true;
	else return false;
}

void Icon_0::draw(Window* window)
{
	//one line in circle
	Baseicon::draw(window);
	window->drawline( x - width/4 , y - height/4 , x + width / 4, y + width / 4, 1.0f, 0.0f, 0.0f);
}


void Icon_1::draw(Window* window)
{
	//circle in circle
	Baseicon::draw(window);
	{
		//drawing circle
		for (float i = 4; i <= 7; i+=0.005)
		{
		float x = this->width / i;
		int y = 0;
		int err = 0;
			while (x >= y)
			{
				//red circle
				window->drawpixels(this->x + x, this->y + y, 1.0f, 0.0f, 0.0f);
				window->drawpixels(this->x + y, this->y + x, 1.0f, 0.0f, 0.0f);
				window->drawpixels(this->x - y, this->y + x, 1.0f, 0.0f, 0.0f);
				window->drawpixels(this->x - x, this->y + y, 1.0f, 0.0f, 0.0f);
				window->drawpixels(this->x - x, this->y - y, 1.0f, 0.0f, 0.0f);
				window->drawpixels(this->x - y, this->y - x, 1.0f, 0.0f, 0.0f);
				window->drawpixels(this->x + y, this->y - x, 1.0f, 0.0f, 0.0f);
				window->drawpixels(this->x + x, this->y - y, 1.0f, 0.0f, 0.0f);
				y += 1;
				err += 1 + 2 * y;
					if (2 * (err - x) + 1 > 0)
					{
					x -= 1;
					err += 1 - 2 * x;
					}
			}
		//	x = this->width / 8;
		}
	}
}

void Icon_2::draw(Window* window)
{
	Baseicon::draw(window);
	window->drawline(x - width / 4, y - height / 4, x + width / 4, y + width / 4, 1.0f, 0.0f, 0.0f);
	window->drawline(x - width / 4, y + height / 4, x + width / 4, y - width / 4, 1.0f, 0.0f, 0.0f);
}

void Icon_3::draw(Window* window)
{
	//right arrow
	Baseicon::draw(window);
	window->drawline(x - width / 4, y, x + width / 4, y, 1.0f, 0.0f, 0.0f);
	window->drawline(x , y + height / 4, x + width / 4, y, 1.0f, 0.0f, 0.0f);
	window->drawline(x, y - height / 4, x + width / 4, y, 1.0f, 0.0f, 0.0f);
}

void Icon_4::draw(Window* window)
{
	//left arrow
	Baseicon::draw(window);
	window->drawline(x - width / 4, y, x + width / 4, y, 1.0f, 0.0f, 0.0f);
	window->drawline(x-width/4, y, x, y+height/4, 1.0f, 0.0f, 0.0f);
	window->drawline(x-width/4, y, x, y-height/4, 1.0f, 0.0f, 0.0f);

}

void Icon_5::draw(Window* window)
{
	//down arrow
	Baseicon::draw(window);
	window->drawline(x, y - height / 4, x, y + height / 4, 1.0f, 0.0f, 0.0f);
	window->drawline(x - width / 4, y, x, y - height / 4, 1.0f, 0.0f, 0.0f);
	window->drawline(x, y - height / 4, x + width / 4, y, 1.0f, 0.0f, 0.0f);
}

void Icon_6::draw(Window* window)
{
	//up arrow
	Baseicon::draw(window);
	window->drawline(x, y - height / 4, x, y + height / 4, 1.0f, 0.0f, 0.0f);
	window->drawline(x - width / 4, y, x, y + height / 4, 1.0f, 0.0f, 0.0f);
	window->drawline(x, y + height / 4, x + width / 4, y, 1.0f, 0.0f, 0.0f);
}

void Icon_7::draw(Window* window)
{
	//square
	Baseicon::draw(window);
	window->drawline(x - width / 4, y - height / 4, x + width / 4, y - height / 4, 1.0f, 0.0f, 0.0f);
	window->drawline(x - width / 4, y - height / 4, x - width / 4, y + height / 4, 1.0f, 0.0f, 0.0f);
	window->drawline(x - width / 4, y + height / 4, x + width / 4, y + height / 4, 1.0f, 0.0f, 0.0f);
	window->drawline(x + width / 4, y - height / 4, x + width / 4, y + height / 4, 1.0f, 0.0f, 0.0f);
}

void Icon_8::draw(Window* window)
{
	//large A
	Baseicon::draw(window);
	window->drawline(x-width/4, y-height/4, x, y+height/4, 1.0f, 0.0f, 0.0f); //left A
	window->drawline(x, y+height/4, x + width / 4, y-height/4, 1.0f, 0.0f, 0.0f);//right A
	window->drawline(x-width/8, y, x+width/8, y, 1.0f, 0.0f, 0.0f); //middle A
}

void Icon_9::draw(Window* window)
{
	//reverse slash
	Baseicon::draw(window);
	window->drawline(x - width / 4, y + height / 4, x + width / 4, y - height / 4, 1.0f, 0.0f, 0.0f);
}

