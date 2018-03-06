#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <fstream>

using namespace std;

// prototypes
void show( int[], int );
void shuffle( int[], int );
void swap( int&, int& );
void naive_search( int[], int, int&, int&, int& );
void recursive_search( int[], int, int&, int&, int& );
void iterative_search( int[], int, int&, int&, int& );

// main driver
int main( int argc, char *argv[] )
{
	// check number of inputs
	if ( argc < 3 ) {
		cerr << "Usage: ./test_me <size> <filename>" << endl;
		exit(1);
	}

	// read inputs: size and filename
	int max_size;
	ofstream outfile;

	max_size = atoi( argv[1] );
	cerr << "Size = " << max_size << endl;
	cerr << "Filename = " << argv[2] << endl;

	// open output file
	outfile.open( argv[2] );

	// run experiment on all sizes
	for (int curr_size = 2; curr_size <= max_size; curr_size++) {
		// create an array of integers
		int buffer[curr_size];
		for (int i = 0; i < curr_size; i++) {
			buffer[i] = i;
		}

		// shuffle array
		shuffle( buffer, curr_size );

		// search for minimum and maximum
		int min, max;
		int cost;

		outfile << curr_size << " ";

		// naive
		cost = 0;
		naive_search( buffer, curr_size, min, max, cost );
		assert( min == 0 && max == curr_size-1 );
		outfile << cost << " ";

		// recursive
		cost = 0;
		recursive_search( buffer, curr_size, min, max, cost );
		assert( min == 0 && max == curr_size-1 );
		outfile << cost << " ";

		// iterative
		cost = 0;
		iterative_search( buffer, curr_size, min, max, cost );
		assert( min == 0 && max == curr_size-1 );
		outfile << cost << endl;
	}

	// close output file
	outfile.close();	
}

