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
		}

		// shuffle array
		shuffle( buffer, curr_size );

		// search for minmax while tracking cost
		int min, max, cost;
		cost = 0;

		iterative_search( buffer, curr_size, min, max, cost );
		assert( min == 0 && max == curr_size - 1 );
		outfile << curr_size << " " << cost << endl;
	}

	// closing output file 
	outfile.close();	

}

void shuffle(int arr[], int size)
{
   srand(time(0));
   int randLoc;
   for(int i = size; i > 0; i--)
   {
      randLoc = rand() % size;
      swap(arr[i], arr[randLoc]);
   }
}

void swap(int& a, int& b)
{
   int temp = a;
   a = b;
   b = temp;
}

void iterative_search(int buffer[], int size, int& min, int& max, int& cost)
{
  int start;
  if(size % 2 == 0)
  {
    start = 2;
    if(buffer[0] < buffer[1])
    {
      min = buffer[0];
      max = buffer[1];
    }
    else
    {
      min = buffer[1];
      max = buffer[0];
    }
    cost++;
  }
  else
  {
    start = 1;
    min = buffer[0];
    max = buffer[1];
  }
  for(int i = start; i < size; i = i + 2)
  {
    if(buffer[i] < buffer[i+1])
    {
      if(buffer[i] < min)
      {
        min = buffer[i];
      }
      if (buffer[i+1] > max)
      {
        max = buffer[i+1];
      }
    }
    else
    {
      if(buffer[i] > max)
      {
        max = buffer[i];
      }
      if(buffer[i+1] < min)
      {
        min = buffer[i+1];
      }
    }
    cost += 3;
  }       
}
