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