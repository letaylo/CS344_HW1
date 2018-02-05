#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <fstream>

using namespace std;

void swap( int&, int&);
void shuffle(int[], int);
void show( int[], int);

void shuffle(int arr[], int size)
{
   srand(time(0));
   int randLoc;
   for(int i = 0; i < size; i++)
   {
      //cout << arr[i] << endl;
      randLoc = rand() % size;
      //cout << randLoc << " " << arr[randLoc] << endl;
      swap(arr[i], arr[randLoc]);
      //cout << arr[i] << endl;
   }
}

void swap(int& a, int& b)
{
   //cout << "init: " << a << " " << b << endl;
   int temp = a;
   a = b;
   b = temp;
   //cout << "swap: " << a << " " << b << endl;
}

