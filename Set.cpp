#include "Set.h"

Set::Set( int n )
{
	len = 0;
	reset();
	*this = *this + n;	
	
}

void Set::reset( )
{
	for( int i = 0; i < MaxSize; i++ )
		members[i] = 0;	
}

int Set::find( int n )
{
	for( int i = 0; i < len; i++ )
		if( members[i] == n ) return i;

	return -1;
}

bool Set::isMember( int n )
{
	if( find( n ) !=-1) return true;
	else false;
}

// union with integer
Set Set::operator +( int n )
{
	Set tmp;
	
	if( len == MaxSize )
	{
		cout << "Set is full" << endl;
		return *this;
	}

	if( n > MaxSize - 1 || n < 0 )
	{
		cout << "number out of range" << endl;
		return *this;
	}

	tmp = *this;
	if( find(n) == -1 )
		tmp.members[tmp.len++] = n;
	
	return tmp;
}

// difference with integer.
Set Set::operator -( int n )
{
	Set tmp;
	int i = find( n );
	
	for( int j = 0; j < len; j++ )
		if( j != i ) tmp = tmp + members[j];

	return tmp;
}

// union of a pair of Sets
Set Set::operator +( Set a )
{
	Set tmp = *this;
	
	for( int i = 0; i < a.len; i++ )
		tmp = tmp + a.members[i];

	return tmp;
}


// complement of Set
Set Set::operator ~( )
{
	Set tmp;

	for( int  i = 0; i < MaxSize; i++ )
	{
		
		if( !isMember(i) )
			tmp = tmp +i;
	}

	return tmp;
}

// intersection of a pair of Sets.
Set Set::operator *( Set a )
{
	Set tmp;

	for( int i = 0; i < len; i++ )
	{
		for( int j = 0; j < a.len; j++ )
		{
			if( members[i] == a.members[j] )
				tmp = tmp + members[j];
			
		}
	}

	return tmp;
}

// difference of a pair of Sets
Set Set::operator -( Set a )
{
	Set tmp = *this;
	for( int i = 0; i < a.len;i++ )
		tmp = tmp - a.members[i];

	return tmp;
}

void Set::print()
{
	if( len == 0 )
	{
		cout << "empty" << endl;
		return;
	}
	else {
	cout << "{";
	for( int i = 0; i < len; i++ )
		cout << members[i] << ", ";
	cout << "}" << endl;
	}
}

void Set::insert( int n )
{
	*this = *this + n;
}

void Set::insert( Set a )
{
	*this = *this + a;
}


