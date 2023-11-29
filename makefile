PA3vF: driver.o
	g++ -o PA3vF driver.o

driver.o: driver.cpp
	g++ -c driver.cpp

clean:
	rm *.o PA3vF