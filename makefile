PA3v1: driver.o
	g++ -o PA3v1 driver.o

driver.o: driver.cpp
	g++ -c driver.cpp

clean:
	rm *.o PA3v1