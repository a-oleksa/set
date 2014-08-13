#include "Set.h"

int main( )
{
	Set a;
	Set b;
	Set c;
	Set d;
	Set e;
	Set f;
	Set g;
	Set h;
	Set i;

	a.insert( 1 );
	a.insert( 4 );
	a.insert( 5 );
	a.insert( 3 );
	
	cout << "A: "; 
	a.print();	

	b.insert( 2 );
	b.insert( 4 );
	b.insert( 10 );
	b.insert( 12 );

	//0 1 3 5 6 7 8 9 11 13 14 15 16 17 18 19

	cout << "B: ";
	b.print();

	c = a + b;
	cout << "C=A+B(union) " << endl;
	cout << "C: ";
	c.print();

	d = a - b;
	cout << "D=A-B(difference) " << endl;
	cout << "D: ";
	d.print();

	e = a * b;
	cout << "E=A*B(intersect)" << endl;
	cout << "E: ";
	e.print();

	f = ~a;
	cout << "F=~A(complement)" << endl;
	cout << "F: ";
	f.print();

	g = ~b;
	cout << "G=~B(complement)" << endl;
	cout << "G: ";
	g.print();

	h = b - a;
	cout << "H=B-A(difference)" << endl;
	cout << "H: ";
	h.print();

	//g = 0 1 3 5 6 7 8 9 11 13 14 15 16 17 18 19
	cout << "added 2 to g" << endl;
	g.insert( 2 );
	cout << "G: ";
	g.print();
	//does nothing since 1 is in set
	cout << "added 1 to g" << endl;
	g.insert( 1 );	
	cout << "G: ";
	g.print();

	// added number out of range
	g.insert(21);
	cout << "added 21 to g" << endl;
	cout << "G: ";
	g.print();


	//fill the set
	cout << "added 4, 10, 12 to g" << endl;
	g.insert(4);
	g.insert(10);
	g.insert(12);
	cout << "G: " << endl;
	g.print();

	//g is now full try adding a number to full set
	cout << "added 5 to g" << endl;
	g.insert(5);
	cout << "G: ";
	g.print();


	cout << "A=A+(~A) union of set and complement" << endl;
	// make union of set and its complement should be full set
	a = a + ~a;
	cout << "A: ";
	a.print();

	//create empty set
	cout << "I=A-A (difference)" <<endl;
	i = a - a;
	cout << "I: ";
	i.print();
			
}
