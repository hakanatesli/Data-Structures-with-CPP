derlecalistir:program calistir
program:main Liste CiftDugum Stack TekDugum
	g++ -g ./lib/main.o ./lib/Liste.o ./lib/CiftDugum.o ./lib/Stack.o ./lib/TekDugum.o -o ./bin/program
TekDugum:
	g++ -I  "./include" -g -c ./src/TekDugum.cpp -o ./lib/TekDugum.o
Stack:
	g++ -I  "./include" -g -c ./src/Stack.cpp -o ./lib/Stack.o
CiftDugum:
	g++ -I  "./include" -g -c ./src/CiftDugum.cpp -o ./lib/CiftDugum.o
Liste:
	g++ -I  "./include" -g -c ./src/Liste.cpp -o ./lib/Liste.o
main:
	g++ -I  "./include" -g -c ./src/main.cpp -o ./lib/main.o
calistir:
	./bin/program.exe