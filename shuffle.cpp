#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

void shuffle(int arr[], int size)
{
   srand(time(0));
   int temp;
   for(int i = 0; i < size; i++)
   {
      int randLoc = rand() % size;
      temp = arr[i];
      arr[i] = arr[randLoc];
      arr[randLoc] = temp;
   }
}
