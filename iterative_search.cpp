#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <fstream>

void iterative_search(int buffer[], int size, int& min, int& max, int& cost)
{
   for(int i = 0; i < size; i++)
   {
      if(buffer[i] < min)
      {
         min = buffer[i];
      }
      cost++;
      if(buffer[i] > max)
      {
         max = buffer[i];
      }
      cost++;
   }
}
