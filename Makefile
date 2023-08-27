projet: functions.o modifier.o existence.o main.o    
	gcc functions.o modifier.o existence.o main.o  -o projet
	
main.o: main.c arrays.h
	gcc -o main.o -c main.c -W -Wall 
existence.o: existence.c arrays.h
	gcc -o existence.o -c existence.c -W -Wall

functions.o: existence.c functions.c arrays.h
	gcc -o functions.o -c functions.c -W -Wall 

modifier.o: modifier.c functions.c arrays.h
	gcc -o modifier.o -c modifier.c -W -Wall 

clean:
	rm -rf *.o

