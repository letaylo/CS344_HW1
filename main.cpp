#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <fstream>


using namespace std;

// prototypes
void show( int[], int );
void shuffle( int[], int );
void swap( int&, int& );
void min_search( int[], int, int&, int& );
void naive_search( int[], int, int&, int&, int& );
void recursive_search( int[], int, int&, int&, int& );
void iterative_search( int[], int, int&, int&, int& );

// main driver
int main( int argc, char *argv[] )
{
	// check inputs
	if ( argc < 3 ) {
		cerr << "Usage: ./test_me <size> <filename>" << endl;
		exit(1);
	}

	// read size
	int size;
	size = atoi( argv[1] );
	cerr << "Size = " << size << endl;

	// open outputfile
	ofstream outfile;
	cerr << "Output file = " << argv[2] << endl;
	outfile.open( argv[2] );

	for (int curr_size = 2; curr_size < size; curr_size++) {

		// create an array of integers 
		int buffer[curr_size];
		for (int i = 0; i < curr_size; i++) {
			buffer[i] = i;
			//cout << buffer[i] << endl;
		}

		// shuffle array
		shuffle( buffer, curr_size );

		// search for minmax while tracking cost
		int min, max, cost;
		cost = 0;
		
		recursive_search( buffer, curr_size, min, max, cost );
		//iterative_search( buffer, curr_size, min, max, cost );
		//cout << min << " " << max << endl;
		assert( min == 0 && max == curr_size - 1 );
		outfile << curr_size << " " << cost << endl;
	}

	// closing output file 
	outfile.close();	

}


