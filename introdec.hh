#ifndef INTROALG_HH
#define INTROALG_HH

template <typename type> void zamiana(type & firstElem, type & secondElem);
template <typename type> void naprawa(type tab[], type i, type rozmiaar);
template <typename type> void kopcowanie(type array[], type size);
template <typename type> void wstawianie(type tab[], type rozmiar);
template <typename type> bool test(type array[], type size);
template <typename type> void sortowanie(type tab[], type rozmiar);
template <typename type> void intro(type tab[], type rozmiar, type M);
template <class Item> long Partition (Item *Array, long L, long R);
template <class Item> void MedianOfThree (Item *tab, long &L, long &R);
template <typename type>void wymiana(type tab[], long i, long j);

#endif
