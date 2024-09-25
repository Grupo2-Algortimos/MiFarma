#pragma once
#include"MainInterfaz.h"
class ProductosInterfaz:public MainInterfaz
{
private:
	int cosmetico[5][5]= { {0,0,15,0,0},{0,15,15,15,0},
					       {0,6,6,6,0},{0,6,6,6,0},{0,6,6,6,0} };
	int farmaco[8][8] = { {0,4,4,15,0},{4,4,15,15,15},
						   {4,4,15,15,15},{4,4,15,15,15},{0,4,15,15,0} };
	int cruz[5][5]= { {0,0,15,0,0},{0,0,15,0,0},
					  {15,15,15,15,15},{0,0,15,0,0},{0,0,15,0,0} };
	int cuidadoPersonal[5][5]= { {0,3,3,3,0},{3,3,3,3,3},
								 {3,3,3,3,3},{3,3,3,3,3},{0,3,3,3,0} };
public:
	ProductosInterfaz():MainInterfaz(){}
	~ProductosInterfaz(){}

	void productos() {
		encuadrar();
		dibujarPersonaMayor(ANCHO / 4, ALTO / 2.5);
	}

	void dibujarCosmetico(int x, int y)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				Console::SetCursorPosition(j + x, i + y);
				Console::ForegroundColor = ConsoleColor(cosmetico[i][j]);
				cout << char(219);
			}
		}
		Console::ForegroundColor = ConsoleColor(15);
	}
	void dibujarFarmaco(int x, int y)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				Console::SetCursorPosition(j + x, i + y);
				Console::ForegroundColor = ConsoleColor(farmaco[i][j]);
				cout << char(219);
			}
		}
		Console::ForegroundColor = ConsoleColor(15);
	}
	void dibujarCruz(int x, int y)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				Console::SetCursorPosition(j + x, i + y);
				Console::ForegroundColor = ConsoleColor(cruz[i][j]);
				cout << char(219);
			}
		}
		Console::ForegroundColor = ConsoleColor(15);
	}

	void dibujarBiberon(int x, int y)
	{
		Console::ForegroundColor = ConsoleColor(3);
		Console::SetCursorPosition(x, y + 0);
		cout << "   __";
		Console::SetCursorPosition(x, y + 1);
		cout << "   ()";
		Console::SetCursorPosition(x, y + 2);
		cout << "   )(";
		Console::SetCursorPosition(x, y + 3);
		cout << ",;/ \\:.";
		Console::SetCursorPosition(x, y + 4);
		cout << "(`.__,')";
		Console::SetCursorPosition(x, y + 5);
		cout << "`-.__,-'";
		Console::SetCursorPosition(x, y + 6);
		cout << " ((__))";
		Console::SetCursorPosition(x, y + 7);
		cout << "  `--'";
		Console::ForegroundColor = ConsoleColor(15);
	}

	void dibujarCuidadoPersonal(int x, int y)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				Console::SetCursorPosition(j + x, i + y);
				Console::ForegroundColor = ConsoleColor(cuidadoPersonal[i][j]);
				cout << char(219);
			}
		}
		Console::ForegroundColor = ConsoleColor(15);
	}

	void dibujarPersonaMayor(int x, int y)
	{
		Console::ForegroundColor = ConsoleColor(15);
		Console::SetCursorPosition(x, y + 0);
		cout << ". - ''' - .";
		Console::SetCursorPosition(x, y + 1);
		cout << "#.     == \\";
		Console::SetCursorPosition(x, y + 2);
		cout << "###  _    _#";
		Console::SetCursorPosition(x, y + 3);
		cout << "(_ ''(a)=(a)";
		Console::SetCursorPosition(x, y + 4);
		cout << " \\     _\\ |";
		Console::SetCursorPosition(x, y + 5);
		cout << "  '.   = /";
		Console::SetCursorPosition(x, y + 6);
		cout << " __/`---;";
		Console::SetCursorPosition(x, y + 7);
		cout << "/`   \\___|`\\";
		Console::SetCursorPosition(x, y + 8);
		Console::ForegroundColor = ConsoleColor(15);
	}
};
