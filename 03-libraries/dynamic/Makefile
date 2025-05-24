
app: main.cpp libgreet.so
	g++ -I. -o app main.cpp -L. -l greet

libgreet.so: greet.o
	g++ -shared greet.o -o libgreet.so

greet.o: greet.cpp
	g++ -c greet.cpp -o greet.o

.PHONY: clean
clean:
	rm libgreet.so greet.o app
