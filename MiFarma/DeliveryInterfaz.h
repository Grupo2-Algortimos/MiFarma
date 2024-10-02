#pragma once
#include"MainInterfaz.h"
class DeliveryInterfaz:public MainInterfaz
{
public:
	DeliveryInterfaz():MainInterfaz(){}
	~DeliveryInterfaz(){}

	void delivery()
	{
		encuadrar();
		//dibujarMoto(ANCHO / 2, ALTO / 2.5);
		dibujarCajaEntregada(ANCHO / 2, ALTO / 2.5);
	}

	void dibujarMoto(int x, int y)
	{
		Console::ForegroundColor = ConsoleColor(5);
		Console::SetCursorPosition(x, y + 0);
		cout << "	_";
		Console::SetCursorPosition(x, y + 1);
		cout << "  D/_";
		Console::SetCursorPosition(x, y + 2);
		cout << "  /(_`._,-.";
		Console::SetCursorPosition(x, y + 3);
		cout << "(o) `--'(o)";
		Console::ForegroundColor = ConsoleColor(15);
	}

	void dibujarCajaEntregada(int x, int y)
	{
		Console::ForegroundColor = ConsoleColor(7);
		Console::SetCursorPosition(x, y + 0);
		cout << "   +--------------+";
		Console::SetCursorPosition(x, y + 1);
		cout << "  /|             /|";
		Console::SetCursorPosition(x, y + 2);
		cout << " / |            / |";
		Console::SetCursorPosition(x, y + 3);
		cout << "*--+-----------*  |";
		Console::SetCursorPosition(x, y + 4);
		cout << "|  |           |  |";
		Console::SetCursorPosition(x, y + 5);
		cout << "|  | En espera |  |";
		Console::SetCursorPosition(x, y + 6);
		cout << "|  |           |  |";
		Console::SetCursorPosition(x, y + 7);
		cout << "|  +-----------+--+";
		Console::SetCursorPosition(x, y + 8);
		cout << "| /            | /";
		Console::SetCursorPosition(x, y + 9);
		cout << "|/             |/";
		Console::SetCursorPosition(x, y + 10);
		cout << "*--------------*";
		Console::ForegroundColor = ConsoleColor(15);
	}

};
