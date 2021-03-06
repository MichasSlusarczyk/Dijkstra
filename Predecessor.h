/** @file  */

#pragma once

#include <iostream>

#include "Borderer.h"
#include "Graph.h"

/**
Klasa bedąca odpowiedzialną za przechowywanie efektu działania algorytmu Dijkstry
*/
class Predecessor : public Borderer
{
public:
	long int predecessor; ///< Numer poprzedniego wierzchołka na trasie
	Predecessor* pNext; ///< Wskaźnik na nastepny element
	Predecessor* pPrev; ///< Wskaźnik na poprzedni element

	Predecessor();

	Predecessor& operator=(const Predecessor&);

	static bool AddPredecessorEnd(Predecessor*&, Predecessor*);
	static bool AddPredecessorByNumber(Predecessor*&, Predecessor*);
	static bool PreparePredecessor(Predecessor*&, Primal*, long int);
	static Predecessor* FindPredecessorByLowerCost(Predecessor*, Primal*);
	static Predecessor* FindPredecessorByNumber(Predecessor*, long int N);
	static bool CompletePredecessor(Predecessor*&, Primal*, long int, Graph*);
	bool DeletePredecessorList();
};
