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