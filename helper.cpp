#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <fstream>

void swap( int&, int&);
void shuffle(int[], int);
void show( int[], int);

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

