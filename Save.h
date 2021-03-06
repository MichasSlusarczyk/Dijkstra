/** @file  */

#pragma once

#include <iostream>
#include <fstream>

#include "Data.h"

/**
Klasa zapisująca określone dane do pliku wynikowego
*/
class Save
{
public:
	bool ClearFile(Data*);
	bool SaveGraph(Data*);
	bool SaveData(Data*);
	bool SaveSolution(Data*);
};

