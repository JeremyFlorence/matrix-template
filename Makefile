output: Matrix clean

Matrix: main.o rational.o matrix.o
					g++ main.o matrix.o rational.o -o Matrix

main.o: main.cpp
				g++ -c main.cpp

rational.o: rational.cpp
						g++ -c rational.cpp
matrix.o: matrix.cpp
					g++ -c matrix.cpp

clean: 
	rm *.o 
