main: main.o path.o passgrid.o
	g++ -o main main.o path.o passgrid.o
main.o: main.cc path.hh passgrid.hh
	g++ -o main.o -c main.cc -Wall
path.o: path.cc path.hh
	g++ -o path.o -c path.cc -Wall
passgrid.o: passgrid.cc passgrid.hh path.hh
	g++ -o passgrid.o -c passgrid.cc -Wall
	
clean:
	rm -f *.o
