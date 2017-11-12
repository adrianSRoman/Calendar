calendar.out: main.o calendar.o day.o appt.o time.o 
	g++ -Wall -ansi -g -o calendar.out main.o calendar.o day.o appt.o time.o
main.o: main.cpp calendar.h
	g++ -Wall -ansi -g -c main.cpp
calendar.o: calendar.cpp calendar.h day.h appt.h time.h
	g++ -Wall -ansi -g -c calendar.cpp
day.o: day.cpp day.h
	g++ -Wall -ansi -g -c day.cpp
appt.o: appt.cpp appt.h time.h
	g++ -Wall -ansi -g -c appt.cpp
time.o: time.cpp time.h
	g++ -Wall -ansi -g -c time.cpp
clean:
	rm -f main.o day.o calendar.o appt.o time.o calendar.out
