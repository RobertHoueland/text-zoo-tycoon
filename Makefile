CC = g++ -Wall
exe_file = zoo_tycoon
$(exe_file): *.o
	$(CC) *.o -o $(exe_file)
*.o: *.cpp
	$(CC) -c *.cpp

clean:
	rm -f *.out *.o $(exe_file)