quicksort: obj main.o introalg.o
	g++ -Wall -o introsort main.o introalg.o

obj:

quickalg.o: quickalg.cpp
	g++ -c -o introalg.o introalg.cpp

main.o: main.cpp 
	g++ -c -o main.o main.cpp

clean:
	rm -f *.o introsort
