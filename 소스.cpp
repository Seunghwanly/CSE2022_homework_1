#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include <stdbool.h>


GLFWwindow* window;
double win_x, win_y;

const int width = 640;
const int height = 480;

float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

// scratched from https://courses.engr.illinois.edu/ece390/archive/archive-f2000/mp/mp4/anti.html
// see 'Rasterization' part.
void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	if ((i1 - i0) == 0)
	{
		for (int i = j0; i <= j1; i++)
		{
			drawPixel(i0, i, red, green, blue);
		}
	}
	else
	{
		for (int i = i0; i <= i1; i++)
		{
			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

			drawPixel(i, j, red, green, blue);
		}
	}
}
bool measurement(const float cx, const float cy, const float r, const float x_cur, const float y_cur)
{
	return (cx - (float)x_cur)*(cx - (float)x_cur) + (cy - (float)y_cur)*(cy - (float)y_cur) - r*r < 0.0;
}

void DrawCircle(float cx, float cy, float r, int num_segments, bool significant)
{
	float theta = 2 * 3.1415926 / float(num_segments);
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;
	float rgb_red, rgb_green, rgb_blue;
	rgb_red = 1.0f; rgb_green = 0.0f; rgb_blue = 0.0f;

	float x = r;//we start at angle = 0 
	float y = 0;

	if (measurement(cx, cy, r, win_x, height - win_y) && significant) {
		rgb_red = 0.0f; rgb_green = 0.0f; rgb_blue = 1.0f;
	}

	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		//glVertex2f(x + cx, y + cy);//output vertex 
		drawPixel(x + cx, y + cy, rgb_red, rgb_green, rgb_blue);

		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}
void drawOnPixelBuffer()
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

													//for (int i = 0; i<width*height; i++) {
													//	pixels[i * 3 + 0] = 1.0f; // red 
													//	pixels[i * 3 + 1] = 1.0f; // green
													//	pixels[i * 3 + 2] = 1.0f; // blue
													//}

	const int i = rand() % width, j = rand() % height;
	drawPixel(i, j, 0.0f, 0.0f, 0.0f);

	// drawing a line
	//TODO: anti-aliasing
	const int i0 = 100, i1 = 200;
	const int j0 = 50, j1 = 80;
}

int main(void)
{
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background


							  /* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer();

		glfwGetCursorPos(window, &win_x, &win_y);

		//Making 10 circles
		for (int i = 1; i <= 10; i++) {
			for (int j = 50; j <= 250; j += 50) {
				DrawCircle(50 + j, 100, 20, 10000, true);
				DrawCircle(50 + j, 150, 20, 10000, true);
			}
		}
		//Make a line drawing function
		//first line
		{
			drawLine(90, 140, 110, 160, 1.0f, 0.0f, 0.0f);
		}
		//second line
		{
			for (int i = 1; i < 5; i++) {
				DrawCircle(150, 150, 10 - i, 10000, false);
			}
		}
		//third line
		{
			drawLine(190, 140, 210, 140, 1.0f, 0.0f, 0.0f);//under
			drawLine(190, 140, 190, 160, 1.0f, 0.0f, 0.0f);//left
			drawLine(190, 160, 210, 160, 1.0f, 0.0f, 0.0f);//up
			drawLine(210, 140, 210, 160, 1.0f, 0.0f, 0.0f);//right
		}
		//fourth line
		{
			drawLine(240, 140, 260, 160, 1.0f, 0.0f, 0.0f);//l to r
			drawLine(240, 160, 260, 140, 1.0f, 0.0f, 0.0f);//other
		}
		//fifth line
		{
			drawLine(300, 140, 300, 160, 1.0f, 0.0f, 0.0f); //stick
			drawLine(290, 150, 300, 140, 1.0f, 0.0f, 0.0f); //left arrow
			drawLine(300, 140, 310, 150, 1.0f, 0.0f, 0.0f); //right arrow

															//tenth line
			drawLine(300, 90, 300, 110, 1.0f, 0.0f, 0.0f); //stick
			drawLine(290, 100, 300, 110, 1.0f, 0.0f, 0.0f); //left arrow
			drawLine(300, 110, 310, 100, 1.0f, 0.0f, 0.0f); //right arrow
		}
		//sixth line
		{
			drawLine(90, 100, 110, 100, 1.0f, 0.0f, 0.0f); //stick
			drawLine(100, 110, 110, 100, 1.0f, 0.0f, 0.0f); //up arrow
			drawLine(100, 90, 110, 100, 1.0f, 0.0f, 0.0f); //down arrow
		}
		//seventh line
		{
			drawLine(140, 90, 150, 110, 1.0f, 0.0f, 0.0f); //left A
			drawLine(150, 110, 160, 90, 1.0f, 0.0f, 0.0f);//right A
			drawLine(145, 100, 155, 100, 1.0f, 0.0f, 0.0f); //middle A
		}
		//eighth line
		{
			drawLine(200, 90, 200, 110, 1.0f, 0.0f, 0.0f); //stick
		}
		//ninth line
		{
			drawLine(240, 100, 260, 100, 1.0f, 0.0f, 0.0f); //stick
			drawLine(250, 90, 260, 100, 1.0f, 0.0f, 0.0f); //under arrow
			drawLine(250, 110, 260, 100, 1.0f, 0.0f, 0.0f); //up arrow
		}



		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}