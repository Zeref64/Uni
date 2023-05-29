all: executable

executable: main.o Student.o Course.o
	g++ -o executable main.o Student.o Course.o && ./executable 

main.o: main.cpp Student.h Course.h
	g++ -c main.cpp

Student.o: Student.cpp Student.h
	g++ -c Student.cpp

Course.o: Course.cpp Course.h
	g++ -c Course.cpp

clean:
	rm -f executable *.o