void recursive_search( int array[], int size, int& min, int& max, int& cost ) {
	if (size == 1) {
		min = array[0];
		max = array[0];
	}else if (size == 2) {
		if (array[0] < array[1]) {
			min = array[0];
			max = array[1];
		}else {
			min = array[1];
			max = array[0];
		}
	}else {
		int size_left = size/2;
		int size_right = size - (size/2);
		int left_array [size_left];
		int right_array [size_right];
		int left_min, left_max, right_min, right_max = 0;

		for (int i = 0; i < size_left; i++) {
			left_array[i] = array[i];
		}
		for (int i = 0; i < size_right; i++) {
			right_array[i] = array[i + size_left];
		}

		recursive_search(left_array, size_left, left_min, left_max, cost);
		recursive_search(right_array, size_right, right_min, right_max, cost);

		if (left_min < right_min) {
			min = left_min;
		} else {
			min = right_min;
		}
		cost++;

		if (left_max > right_max) {
			max = left_max;
		} else {
			max = right_max;
		}
		cost++;
	}
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
    max = buffer[0];
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

