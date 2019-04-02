#include "introdec.hh"
#include <cmath>
#include <iostream>

using namespace std;


// POMOCNICZA FUNKCJA ZAMIENIAJACA ELEMENTY

template <typename type>
void zamiana(type & elem1, type & elem2) 
{
    type elempom = elem1;              // elempom - element pomocniczy
    elem1 = elem2;                
    elem2 = elempom;             
}   

// POMOCNICZA FUNKCJA ZAMIENIAJACA ELEMENTY MAJAC TABLICE


template <typename type>
void wymiana(type tab[], long i, long j)
{
  type temp;
  temp=tab[i];
  tab[i]=tab[j];
  tab[j]=temp;
}


// FUNKCJA SORTOWANIA PRZEZ WSTAWIANIE

template <typename type>
void wstawianie(type tab[], type rozmiar) 
{
   for (type i = 1; i < rozmiar; ++i)                
   {
     type j = i;
     while (j > 0)
	{
	  if (tab[j - 1] > tab[j])             
	  {
	  zamiana(tab[j-1], tab[j]);      
	  --j;                                
	  }
	  else
	  {
	  break;
	  }
	 }
     }
}


// FUNKCJA SORTOWANIE INTROSPEKTYWNE
// M - maksymalna dozwolona glebokosc wywolan rekurancji
// i -klucz lelementu rozdzielajacego (klucz pivota)

template <typename type>
void intro (type tab[], type rozmiar, type M)
{
  type i;
  if (M<=0)		// sortowanie przez kopcowanie wywolywane jest, gdy poczatkowe przedzialy sa zdegenerowane
  {
   kopcowanie(tab,rozmiar);
    return;
  }
  i=Partition(tab,0,rozmiar);	// dzieli tablice na dwie osobne
  // bedzie wywolane rekurencyjne, ale juz M-1, wiec mniejsza dozwolona liczba rekurencji
  if (i>9)			// rozmiar 9 zostal wyznaczony eksperymentalnie
    intro(tab,i, M-1);
  if (rozmiar-1-i>9)
    intro(tab+i+1,rozmiar-1-i, M-1);
}


template <typename type>
void sortowanie(type tab[], type rozmiar)
{
  type M;
  M = 2*log(rozmiar);		// taka jest definicja
  intro(tab, rozmiar, M);		// pracuje na duzych zbiorach
  wstawianie(tab,rozmiar);		// porzadkuje zbior do konca
}
 


// FUNKCJA DO NAPRAWIANIA KOPCA


template <typename type>
void naprawa(type tab[], type i, type rozmiar) 
{
    
  type j;                
  while (i<=rozmiar/2)
  {
    j=2*i;
    if (j+1<rozmiar && tab[j+1]>tab[j])		// sprawdzanie czy element jest wikeszy
      j=j+1;
    if (tab[i]<tab[j])
      wymiana(tab,i,j);				// wymiana jezeli element jest mniejszy
    else break;
    i=j;
  }
}



// FUNKCJA SORTOWANIE PRZEZ KOPCOWANIE

template <typename type>
void kopcowanie(type tab[], type rozmiar) 
{
   type i;
	for (i = rozmiar / 2; i > 0; i--)		// pierwsze polowa
	naprawa(tab-1, i, rozmiar);            // trzeba naprawiac strukture kopca 

	for (i = rozmiar - 1; i > 0; i--)		// druga polowa
	{
	zamiana(tab[0], tab[i]);                // zamiana
	naprawa(tab-1, 1, i);            // naprawienie kopca
	}
}



// POMOCNICZE FUNKCJE, KTORE DZIELA TABLICE W ODPOIWEDNI SPOSOB

template <class Item>
long Partition (Item *tab, long L, long R)  // l- element z lewej, r - element z prawej
{
  long i, j;
  if (R>=3)
    MedianOfThree(tab,L,R);
  for (i=L, j=R-2; ; )
  {
    for ( ; tab[i]<tab[R-1]; ++i);
    for ( ; j>=L && tab[j]>tab[R-1]; --j);
    if (i<j)
      wymiana(tab,i++,j--);
    else break;
  }
  wymiana(tab,i,R-1);
  return i;
}
 
template <class Item>
void MedianOfThree (Item *Array, long &L, long &R)	// to robi wymiany miedzy elementami
{
  if (Array[++L-1]>Array[--R])
    wymiana(Array,L-1,R);
  if (Array[L-1]>Array[R/2])
    wymiana(Array,L-1,R/2);
  if (Array[R/2]>Array[R])
    wymiana(Array,R/2,R);
  wymiana(Array,R/2,R-1);
}
 


// FUNKCJA SPRAWDZAJACA

template <typename type>
bool test (type tab[], type rozmiar) 
    {
    bool blad = false;
    for(type i = 0; i < rozmiar - 1; i++) 
	{
        if (tab[i] > tab[i+1]) 
	    {       
            blad = true;              
            }
	}
    return blad;
}
 
 
 
