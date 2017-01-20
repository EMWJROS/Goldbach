all: goldbach.exe

goldbach.exe: goldbach.o SetOfPrimeNumbers.o
	g++ -o goldbach.exe -g goldbach.o SetOfPrimeNumbers.o

goldbach.o: goldbach.cpp
	gcc -c goldbach.cpp

SetOfPrimeNumbers.o: SetOfPrimeNumbers.cpp
	gcc -c SetOfPrimeNumbers.cpp

clean:
	 rm goldbach.o SetOfPrimeNumbers.o goldbach.exe
