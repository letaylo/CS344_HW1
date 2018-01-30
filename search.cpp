void recursive_search( int[] array, int size, int& min, int& max, int& cost ) {
	if (size == 2 || size == 1) {
		min_max( array, size, min, max, cost );
	}else {
		int size_left = size/2;
		int size_right = size - (size/2);
		int left_array [size_left];
		int right_array [size_right];
		int left_min, left_max, right_min, right_max = 0;

		for (int i = 0; i < size_left; i++) {
			left_array[i] = array[i];
		}
		for (int i = 0; i < size_right; i++ {
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
		
