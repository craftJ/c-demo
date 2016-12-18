#!/bin/bash

read -p "1:(.a)build, 2:(.so)build, 3:clear :" boption

result_exe="print"

if [ $boption -eq 1 ]
then
	gcc -c *.c
	ar -r libpfunc1.a pf1.o
	ar -r libpfunc1.a print1.o
	ar -r libpfunc2.a pf2.o
	ar -r libpfunc2.a print2.o
	gcc -o $result_exe main.o -L ./ -lpfunc2 -lpfunc1
elif [ $boption -eq 2 ]
then
	gcc -c *.c
	gcc -shared -o libpfunc1.so pf1.o print1.o
	gcc -shared -o libpfunc2.so pf2.o print2.o
	gcc -o $result_exe main.o -L ./ -lpfunc2 -lpfunc1	
elif [ $boption -eq 3 ]
then
	rm -f *.o
	rm -f *.so
	rm -f *.a
	rm -f $result_exe
else
	echo "option err!!"
fi


