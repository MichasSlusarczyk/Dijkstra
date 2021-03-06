/** @file  */

#pragma once

#include "Data.h"

/**
Klasa abstrakcyjna pozwalająca po której dziedziczą kalsy zawierające metody do wyświetlania konkretnych danych na ekranie
*/
class Print : public Data
{
public:
	virtual bool PrintDijkstra() = 0;
};

