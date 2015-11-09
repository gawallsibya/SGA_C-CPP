/*
	Polymorphism  다형성

	- FSM ( Finite State Machine )

*/
#include "Orc.h"
#include <iostream>
#include <conio.h>

void main()
{
	Orc orc;
	char ch = 0;
	while (ch != 0x1b) // esc 종료
	{
		if (_kbhit())
		{
			fflush(stdin);
			ch = _getch();	
		}

		orc.update();

		std::cout << "Loop..." << std::endl;
		_sleep(500);
	}


}