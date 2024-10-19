#pragma once
#include"Libreria.h"
class MainInterfaz
{
protected:
	int logo[5][5] = { {0,0,6,6,0},{0,2,2,6,6},
					   {2,10,10,10,2},{2,10,10,10,0},
					   {0,2,2,0,0} };
public:
	MainInterfaz(){}
	~MainInterfaz(){}

	void inicio()
	{
		logoSimbolo(ANCHO - 10, 2);
		logoMiFarma(ANCHO / 4, ALTO / 2.5);
		encuadrar();
		_sleep(1000);
	}

	void compra()
	{
		encuadrar();
		//dibujarCarritoCompraz(ANCHO / 2, ALTO / 2.5);
		dibujarComprado(ANCHO / 3, ALTO / 4);
	}

	void delivery()
	{
		encuadrar();
		//dibujarMoto(ANCHO / 2, ALTO / 2.5);
		dibujarCajaEntregada(ANCHO / 2, ALTO / 2.5);
	}

	void logoMiFarma(int x, int y) {
		Console::ForegroundColor = ConsoleColor(14);
		Console::SetCursorPosition(x ,y + 0);
		cout << "##     ## #### ########    ###    ########  ##     ##    ###";
		Console::SetCursorPosition(x, y + 1);
		cout << "###   ###  ##  ##         ## ##   ##     ## ###   ###   ## ##";
		Console::SetCursorPosition(x, y + 2);
		cout << "#### ####  ##  ##        ##   ##  ##     ## #### ####  ##   ##";
		Console::SetCursorPosition(x, y + 3);
		cout << "## ### ##  ##  ######   ##     ## ########  ## ### ## ##     ##";
		Console::SetCursorPosition(x, y + 4);
		cout << "##     ##  ##  ##       ######### ##   ##   ##     ## #########";
		Console::SetCursorPosition(x, y + 5);
		cout << "##     ##  ##  ##       ##     ## ##    ##  ##     ## ##     ##";
		Console::SetCursorPosition(x, y + 6);
		cout << "##     ## #### ##       ##     ## ##     ## ##     ## ##     ##";
	}

	void logoSimbolo(int x, int y)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				Console::SetCursorPosition(j + x, i + y);
				Console::ForegroundColor = ConsoleColor(logo[i][j]);
				cout << char(219);
			}
		}
	}

	void encuadrar()
	{
		Console::ForegroundColor = ConsoleColor(10);
		Console::SetCursorPosition(0, 0);
		Console::Write("+");
		for (int i = 1; i < ANCHO - 1; ++i) {
			Console::Write("-");
		}
		Console::Write("+");

		Console::ForegroundColor = ConsoleColor(6);
		for (int i = 1; i < ALTO - 1; i++) {
			Console::SetCursorPosition(0, i);
			Console::Write("|");
			Console::SetCursorPosition(ANCHO - 1, i);
			Console::Write("|");
		}
		Console::ForegroundColor = ConsoleColor(10);
		Console::SetCursorPosition(0, ALTO - 1);
		Console::Write("+");
		for (int i = 1; i < ANCHO - 1; i++) {
			Console::Write("-");
		}
		Console::Write("+");
		logoSimbolo(ANCHO - 10, 2);
		Console::ForegroundColor = ConsoleColor(15);
	}


	void dibujarCarritoCompraz(int x, int y)
	{
		Console::ForegroundColor = ConsoleColor(15);
		Console::SetCursorPosition(x, y + 0);
		cout << "%%*";
		Console::SetCursorPosition(x, y + 1);
		cout << "+++++++++++";
		Console::SetCursorPosition(x, y + 2);
		cout << " +  *  #  %";
		Console::SetCursorPosition(x, y + 3);
		cout << " *  #  * -.";
		Console::SetCursorPosition(x, y + 4);
		cout << "  *:=:-=:=";
		Console::SetCursorPosition(x, y + 5);
		cout << "  *%***##*";
		Console::SetCursorPosition(x, y + 6);
		cout << "  #*    %#";
	}

	void dibujarComprado(int x, int y)
	{
		Console::ForegroundColor = ConsoleColor(2);
		Console::SetCursorPosition(x, y + 0);
		cout << "#####";
		Console::SetCursorPosition(x, y + 1);
		cout << "#    #   ####  #    # #####  #####    ##   #####   ####";
		Console::SetCursorPosition(x, y + 2);
		cout << "#       #    # ##  ## #    # #    #  #  #  #    # #    #";
		Console::SetCursorPosition(x, y + 3);
		cout << "#       #    # # ## # #    # #    # #    # #    # #    #";
		Console::SetCursorPosition(x, y + 4);
		cout << "#       #    # #    # #####  #####  ###### #    # #    #";
		Console::SetCursorPosition(x, y + 5);
		cout << "#    #  #    # #    # #      #   #  #    # #    # #    #";
		Console::SetCursorPosition(x, y + 6);
		cout << " #####   ####  #    # #      #    # #    # #####   ####";
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
