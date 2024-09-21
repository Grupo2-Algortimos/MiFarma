#pragma once
#include"MainInterfaz.h"
class CompraInterfaz:public MainInterfaz
{
private:

public:
	CompraInterfaz():MainInterfaz(){}
	~CompraInterfaz(){}

	void compra()
	{
		encuadrar();
		dibujarCarritoCompraz(ANCHO / 2, ALTO / 2.5);
		dibujarComprado(4, 4);
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

};
