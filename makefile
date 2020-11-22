all: ketson

ketson: main.o conj.o
	gcc -o ketson main.o conj.o

main.o: main.c conj.h
	gcc -c main.c -Wall

conj.o: conj.c conj.h
	gcc -c conj.c -Wall

clean:
	rm main.o conj.o ketson
