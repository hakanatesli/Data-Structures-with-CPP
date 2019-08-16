derle:program calistir

program:AgacDugum BinaryST BinaryDugum Test
	g++ ./lib/AgacDugum.o ./lib/BinaryST.o ./lib/BinaryDugum.o ./lib/Test.o -o ./bin/program
BinaryDugum:
	g++ -I "./include" -c ./src/BinaryDugum.cpp -o ./lib/BinaryDugum.o
BinaryST:
	g++ -I "./include" -c ./src/BinaryST.cpp -o ./lib/BinaryST.o
AgacDugum:
	g++ -I "./include" -c ./src/AgacDugum.cpp -o ./lib/AgacDugum.o
Test:
	g++ -I "./include" -c ./src/Test.cpp -o ./lib/Test.o
calistir:
	./bin/program.exe