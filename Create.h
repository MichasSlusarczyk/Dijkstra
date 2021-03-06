/** @file  */

#pragma once
#include "Data.h"

/**
Klasa odpowiedzialna za wczytanie lub stworzenie w oparciu o komunikacje z użytkownikiem danych na których ma operować program
*/
class Create
{
public:
	bool LoadGraph(Data*&);
	bool CreateGraph(Data*&);
	bool LoadData(Data*&);
	bool CreateData(Data*&);
};

