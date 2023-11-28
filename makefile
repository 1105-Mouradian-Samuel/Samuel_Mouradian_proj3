PA3v3: driver.o
	g++ -o PA3v3 driver.o

driver.o: driver.cpp
	g++ -c driver.cpp

clean:
	rm *.o PA3v3