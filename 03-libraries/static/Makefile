
app: main.cpp libgreet.a
	g++ -I. -o app main.cpp libgreet.a

libgreet.a: greet.o
	ar r libgreet.a greet.o

greet.o: greet.cpp
	g++ -c greet.cpp -o greet.o

.PHONY: clean
clean:
	rm libgreet.a greet.o app