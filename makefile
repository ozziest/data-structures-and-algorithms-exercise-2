hepsi: derle calistir
derle:
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/BigNumber.o -c ./src/BigNumber.cpp
	g++ -I ./include/ -o ./lib/Arithmetic.o -c ./src/Arithmetic.cpp
	g++ -I ./include/ -o ./lib/Factorial.o -c ./src/Factorial.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/*.o ./src/Test.cpp
calistir:
	./bin/Test