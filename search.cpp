void recursive_search( int[] array, int size, int& min, int& max, int& cost ) {
	if (size == 2 || size == 1) {
		naive_search( array, size, min, max, cost );
	}else {
		int size_left = size/2;
		int size_right = size - (size/2);
		int left_array [size_left];
		int right_array [size_right];

		for (int i = 0; i < size_left; i++) {
			left_array[i] = array[i];
		}
		for (int i = 0; i < size_right; i++ {
			right_array[i] = array[i + size_left];
		}

		recursive_search(left_array, size_left, min, max, cost);
		recursive_search(right_array, size_right, min, max, cost);
	}
}
		
