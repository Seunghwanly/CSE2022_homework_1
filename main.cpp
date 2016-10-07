#include<iostream>
#include"Window.h"
#include"Icon.h"

double win_x, win_y;

int main()
{
	Window * main = new Window(1440,810);
	//Icon_0 _icon(200,200,100,100,1,0,0);

		//first line
		main->pushicon(Icon_0(100, 100, 100, 100, 1, 0, 0));
		main->pushicon(Icon_1(200, 100, 100, 100, 1, 0, 0));
		main->pushicon(Icon_2(300, 100, 100, 100, 1, 0, 0));
		main->pushicon(Icon_3(400, 100, 100, 100, 1, 0, 0));
		main->pushicon(Icon_4(500, 100, 100, 100, 1, 0, 0));
		main->pushicon(Icon_5(500, 200, 100, 100, 1, 0, 0));
		main->pushicon(Icon_6(100, 200, 100, 100, 1, 0, 0));
		main->pushicon(Icon_7(200, 200, 100, 100, 1, 0, 0));
		main->pushicon(Icon_8(300, 200, 100, 100, 1, 0, 0));
		main->pushicon(Icon_9(400, 200, 100, 100, 1, 0, 0));

		//second line
		main->pushicon(Icon_0(100, 300, 100, 100, 1, 0, 0));
		main->pushicon(Icon_1(200, 300, 100, 100, 1, 0, 0));
		main->pushicon(Icon_2(300, 300, 100, 100, 1, 0, 0));
		main->pushicon(Icon_3(400, 300, 100, 100, 1, 0, 0));
		main->pushicon(Icon_4(500, 300, 100, 100, 1, 0, 0));
		main->pushicon(Icon_5(500, 400, 100, 100, 1, 0, 0));
		main->pushicon(Icon_6(100, 400, 100, 100, 1, 0, 0));
		main->pushicon(Icon_7(200, 400, 100, 100, 1, 0, 0));
		main->pushicon(Icon_8(300, 400, 100, 100, 1, 0, 0));
		main->pushicon(Icon_9(400, 400, 100, 100, 1, 0, 0));

		if (!main->init())
	{
		std::cout << "init error! " << std::endl;
		exit(1);
	}

	while (main->run());

	if (!main->destory())
	{
		std::cout << "destroy erroy! " << std::endl;
		exit(1);
	}
	delete main;
	return 0;
}