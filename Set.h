#include <iostream>
#include <stdlib.h>

using namespace std;

class Set
{
	private:
		const static int MaxSize = 20;
		int members[MaxSize];
		int len;

	public:
	//	Set( ) { len = 0; reset(); };
		Set() { len = 0; };
		void reset();
		Set( int n );
		int find( int n);
		bool isMember( int n);
		
		Set operator+(int n);
		Set operator-(int n);
	
		Set operator+(Set a);
		Set operator-(Set a);

		Set operator*(Set a);
		
		Set operator ~( );

		void insert( int n );
		void insert( Set a );
	
	
		void print();
};


