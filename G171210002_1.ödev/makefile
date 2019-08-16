derlecalistir:program calistir

program:test Yonetim Okul Sinif Ogrenci
	g++ ./lib/test.o ./lib/Yonetim.o ./lib/Okul.o ./lib/Sinif.o ./lib/Ogrenci.o -o ./bin/program
Ogrenci:
	g++ -I "./include" -c ./src/Ogrenci.cpp -o ./lib/Ogrenci.o
Sinif:
	g++ -I "./include" -c ./src/Sinif.cpp -o ./lib/Sinif.o
Okul:
	g++ -I "./include" -c ./src/Okul.cpp -o ./lib/Okul.o
Yonetim:
	g++ -I "./include" -c ./src/Yonetim.cpp -o ./lib/Yonetim.o
test:
	g++ -I "./include" -c ./src/test.cpp -o ./lib/test.o
calistir:
	./bin/program.exe