/** @file  */

#pragma once

#include"Print.h"

/**
Klasa odpowiedzialna za wyświetlanie danych na ekranie
*/
class PrintData : public Print
{
public:
	PrintData();
	PrintData(Data*);

	bool PrintDijkstra();
};

