all:
	g++ driver.cpp Set.cpp  -o set_program

clean:
	rm -f set_program
