// M.Pietras - PAMSI projekt 1
// sortowanie introspektywne

#include "introdec.hh"
#include "introalg.cpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <chrono>

using namespace std;

int main (int argc, char *argv[]) 
          
    {

    if(argc == 1) 	
    {
    cout << " M.PIETRAS \n PAMSI \n PROJEKT 1 - SORTOWANIE INTROSPEKTYWNE \n WYWOLANIE: \n ./mergesort rozmiar_tablicy procent_posortowania (-100 - odwrotnie) \n \n WYNIKIEM SA CZASY SORTOWANIA 100 TABLIC W MS" <<endl;
    exit(0);
    }

    const int rozmiar = atoi(argv[1]);     // rozmiar tablicy; atoi - konwertuje znaki do liczby
    int i, licznik; 

    // PETLA PO 100 TABLICACH

    for(licznik = 0; licznik < 100  ; licznik++)  
    {   

    int *tab = new int[rozmiar];                 // alokowanie tablicy dynamicznej               
    int *elemp, *elemo;	// wskazniki na pierwszy i ostatni element

    srand(time(NULL));     // funkcja do losowania liczb losowych, time musi być, zeby zawsze były inne       


    // TABLICA LOSOWA 

    for(i = 0; i < rozmiar  ; i++)  
    {          
    tab[i] = rand() %rozmiar;
    }

    // TABLICA CZESCIOWO POSORTOWANA

    if(atoi(argv[2]) != -100) 
    {
    for(int i = 0; i < (rozmiar*atoi(argv[2])/100); i++) 
    {
    tab[i] = i;	
    }
    }

    // TABLICA ODWROTNIE POSORTOWANA (-100)

    if(atoi(argv[2]) == -100) 	
    {
    for(int i = 0; i < rozmiar; i++) 
	{
        tab[i] = rozmiar-i;	
        }
     }
        

/*
    for(i = 0; i < rozmiar  ; i++)   // sprawdzanie tablicy wejsciowej
    {          
    cout << tab[i] << " ";      
    }
*/

    elemp = &tab[0];
    elemo = &tab[rozmiar - 1];

    auto tstart = std::chrono::system_clock::now();

    sortowanie<int>(tab, rozmiar);
    
    auto tend = std::chrono::system_clock::now();
    auto czas = std::chrono::duration_cast<std::chrono::microseconds>(tend - tstart).count();

    
    // TEST SORTOWANIA
    
    if(test<int>(tab, rozmiar)) 
    {
        cout << "Blad" <<endl;
    }
    

/*
    for(i = 0; i < rozmiar  ; i++)   // sprawdzanie tablicy wyjsciowej
    {          
    cout << tab[i] << " ";      
    }  
*/


    cout << czas << endl;

    delete[] tab;
    }
    }


