all: driver.o dataFile.o drink.o item.o snack.o vending.o
	g++ -Wall driver.o dataFile.o drink.o item.o snack.o vending.o -o output.out

dataFile.o: dataFile.cpp
	g++ -Wall -c dataFile.cpp

drink.o: drink.cpp
	g++ -Wall -c drink.cpp

item.o: item.cpp
	g++ -Wall -c item.cpp

snack.o: snack.cpp
	g++ -Wall -c snack.cpp

vending.o: vending.cpp
	g++ -Wall -c vending.cpp

driver.o: driver.cpp
	g++ -Wall -c driver.cpp

run:
	./output.out

val:
	valgrind ./output.out

clean: 
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
