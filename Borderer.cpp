/** @file  */

#include "Borderer.h"

/**
Konstruktor domyślny klasy Borderer
*/
Borderer::Borderer()
{
	number = 0;
	metrics = 0;
	pNext = nullptr;
	pPrev = nullptr;
}

/**
Przeciążony operator przypisania
@param S Referencja do stałego obiektu typu Borderer
@return Referencja do elementu typu Borderer pozwalająca na kaskadowe wywołanie
*/
Borderer& Borderer::operator=(const Borderer& B) 
{
	if (&B == this)
	{
		return *this;
	}
	else
	{
		number = B.number;
		metrics = B.metrics;
		pNext = B.pNext;
		pPrev = B.pPrev;

		return *this;
	}
}

/**
Publiczna metoda dodająca element typu Borderer na koniec listy
@param LB Wskaźnik na referencje typu Solution
@param B Wskaźnik na obiekt typu Solution
@return Zwraca informację o poprawności wykonania metody i wystąpieniu ewentualnego błędu
*/
bool Borderer::AddBordererEnd(Borderer*& LB, Borderer* B)
{
	if (B == nullptr)
	{
		return false;
	}
	else
	{
		if (LB == nullptr)
		{
			LB = new Borderer;
			LB = B;
			B = nullptr;
		}
		else
		{
			Borderer* t_LB = LB;
			Borderer* p_LB = t_LB;
			while (t_LB->pNext != nullptr)
			{
				t_LB = t_LB->pNext;
			}
			t_LB->pNext = B;
			t_LB->pPrev->pNext = t_LB;
			LB = p_LB;
		}

		return true;
	}
}

/**
Publiczna metoda dodająca element typu Borderer z uwzględnieniem numeru sasiedniego wierzchołka
@param LS Wskaźnik na referencje typu Borderer
@param S Wskaźnik na obiekt typu Borderer
@return Zwraca informację o poprawności wykonania metody i wystąpieniu ewentualnego błędu
*/
bool Borderer::AddBordererByNumber(Borderer*& LB, Borderer* B)
{
	if (B == nullptr)
	{
		return false;
	}
	else
	{
		if (LB == nullptr)
		{
			LB = new Borderer;
			LB = B;
		}
		else
		{
			Borderer* t_LB = LB;
			Borderer* p_LB = t_LB;
			Borderer* h_LB1 = t_LB;

			if (t_LB->pNext == nullptr)
			{
				if (B->number > t_LB->number)
				{
					t_LB->pNext = B;
					t_LB->pNext->pPrev = t_LB;
					LB = t_LB;
				}
				else
				{
					t_LB->pPrev = B;
					t_LB->pPrev->pNext = t_LB;
					LB = t_LB->pPrev;
				}
			}
			else
			{
				while (t_LB->pNext != nullptr)
				{
					if (B->number > t_LB->number)
					{
						t_LB = t_LB->pNext;
					}
					else
					{
						if (t_LB->pPrev == nullptr)
						{
							t_LB->pPrev = B;
							t_LB->pPrev->pNext = t_LB;
							LB = t_LB->pPrev;
						}
						else
						{
							h_LB1 = t_LB;
							t_LB->pPrev->pNext = B;
							t_LB->pPrev = h_LB1->pNext;
							LB = p_LB;
						}

						return true;
					}
				}

				t_LB->pNext = B;
				t_LB->pNext->pPrev = t_LB;
				LB = p_LB;
			}
		}

		return true;
	}
}

/**
Publiczna metoda dodająca szuakjąca element w liście typu Borderer o zadanym numerze
@param B Wskaźnik na listę typu Borderer
@param N Numer szukanego wierzchołka
@return Zwraca wskaźnik na szukany element lub nullptr
*/
Borderer* Borderer::FindBordererByNumber(Borderer* B, long int N)
{
	if (B == nullptr)
	{
		return nullptr;
	}
	else
	{
		while (B != nullptr)
		{
			if (B->number == N)
			{
				return B;
			}

			B = B->pNext;
		}

		return nullptr;
	}
}

/**
Publiczna metoda do usuwania listy typu Borderer
@return Zwraca informację o poprawności wykonania metody i wystąpieniu ewentualnego błędu
*/
bool Borderer::DeleteBordererList()
{
	Primal* t_B = this;

	if (t_B != nullptr)
	{
		while (t_B->pNext != nullptr)
		{
			t_B = t_B->pNext;
		}

		while (t_B->pPrev != nullptr)
		{
			t_B->pNext = nullptr;
			t_B = t_B->pPrev;
			delete t_B->pNext;
		}

		t_B->pNext = nullptr;
		delete t_B;

		t_B = nullptr;
	}

	return true;
}