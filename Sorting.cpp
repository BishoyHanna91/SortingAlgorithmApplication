# include "Sorting.h" 

ofstream time_Data;
static double B[fixed_size];
Sorting::Sorting()
{
	int m = fixed_size-1;
	for (int i = 0; i<fixed_size; i++)
	{
		
		Array[i] = rand()%fixed_size;



		//m--;
		
		Array2[i] = rand();
		//m--;
	}
	
	
	Array_size = fixed_size;
}



void Sorting::displayArray(double Arr[], int size)
{
	for (int i = 0; i <size; i++)
	{
		cout << Arr[i] << "  ";
	//	time_Data << Arr[i] << "  ";



	}
	cout << endl;
	time_Data << endl;
}
void Sorting::displayArray_bucket_sorting(int Arr[], int size)
{
	for (int i = 0; i <size; i++)
	{
		cout << Arr[i] << "  ";
		//	time_Data << Arr[i] << "  ";



	}
	cout << endl;
	time_Data << endl;
}
void Sorting::callingSorting()
{
	time_Data.open("RunningTime.txt");
	clock_t merge_time, Bucket_time, quick_time, heap_time, sort_time;
	long Bucket_timeMS;
	
	cout << "List: ";
	//displayArray(Array, Array_size);


	//displayArray(B, Array_size);
	//displayArray_bucket_sorting(Array2,Array_size);
	cout << "==========================================" << endl;

	
	merge_time = clock();
    MergeSort(Array, 0, Array_size - 1);
	merge_time = clock() - merge_time;

	cout << "Merge Sort=  ";
	cout << (float)merge_time  << endl;
	time_Data << "Merge Sort=  ";
	time_Data << (float)merge_time  << endl;
    //displayArray(Array, Array_size);
	cout << "==============================================" << endl;
	time_Data << "==============================================" << endl;



	quick_time = clock();
	QuickSorting(Array, 0, Array_size - 1);
	quick_time = clock() - quick_time;


	cout << "Quick Sort=  ";
	cout << (float)quick_time <<endl;

	time_Data << "Quick Sort=  ";
	time_Data << (float)quick_time << endl;


	//displayArray(Array, Array_size);
	cout << "==============================================" << endl;
	time_Data << "================================================" << endl;



	

	heap_time = clock();
	HeapSort(Array, Array_size);
	heap_time = clock() - heap_time;

	cout << "Heap Sort=  ";
	cout << (float)heap_time  << endl;
	time_Data << "Heap Sort=  ";
	time_Data << (float)heap_time << endl;

	//displayArray(Array, Array_size);
	cout << "==============================================" << endl;
	time_Data << "==============================================" << endl;





	




	 sort_time = clock();
	 SortedLibrary(Array, Array_size);
	 sort_time = clock() - sort_time;

	 cout << "SortedLibrary=  ";
	 cout << (float)sort_time  << endl;

	 time_Data << "SortedLibrary=  ";
	 time_Data << (float)sort_time << endl;


	 //displayArray(Array, Array_size);
	 cout << "==============================================" << endl;
	 time_Data << "==============================================" << endl;




	 


	 Bucket_time = clock();
	 //bucketSorting(B, Array_size);
	 //bucket_sorting(Array2, Array_size);
	 radixsort(Array2, fixed_size);

	 Bucket_time = clock() - Bucket_time;
	 
	 cout << "Bucket_Sort= ";
	 cout << (float)Bucket_time  << endl;
	 
	 time_Data << "Bucket_Sort= ";
	 time_Data << (float)Bucket_time  << endl;

	 //displayArray_bucket_sorting(Array2, Array_size);
	
	 cout << "==============================================" << endl;
	 time_Data << "==============================================" << endl;


	 //displayArray(Array, Array_size);
	 //insertSorting(Array, Array_size);
	 //displayArray(Array, Array_size);



	time_Data.close();
}
void Sorting::Merge(double Arr[], int left_index, int middle_index, int right_index)
{


	 int Arr1_size = middle_index - left_index + 1;
	 int Arr2_size = right_index - middle_index;


	
	 

	static double *Arr1;
	Arr1 = new double[Arr1_size];

	

	static double *Arr2 ;
	Arr2 = new double[Arr2_size];

	

	for (int i = 0; i < Arr1_size; i++)

	{
		Arr1[i] = Arr[left_index + i];
	}
	for (int j = 0; j < Arr2_size; j++)
	{
		Arr2[j] = Arr[middle_index + 1 + j];
	}
	int i = 0;
	int j = 0;
	int k = left_index;
	while (i < Arr1_size && j < Arr2_size)
	{
		if (Arr1[i] <= Arr2[j])
		{

			Arr[k] = Arr1[i];

			i++;
		}
		else
		{
			Arr[k] = Arr2[j];
			j++;
		}
		k++;
	}

	if (i == Arr1_size)
	{

		for (int c = j; c < Arr2_size; c++)

		{
			Arr[k] = Arr2[c];
			k++;

		}


	}
	else
	{
		for (int c = i; c < Arr1_size; c++)

		{
			Arr[k] = Arr1[c];
			k++;
		}

	}
	
	delete[]Arr1;
	Arr1 = NULL;

	delete[]Arr2;
	Arr2 = NULL;
	

}
void Sorting::MergeSort(double Arr[], int left_index, int right_index)
{

	
	if (left_index<right_index)
	{
		// indicating the middle position of the array
		int middle = left_index + (right_index - left_index) / 2;

		// sorting the first part of the array
		MergeSort(Arr, left_index, middle);

		// sorting the second part of the array
		MergeSort(Arr, middle + 1, right_index);

		// merging the two array together 
		Merge(Arr, left_index, middle, right_index);
	}

}
void Sorting::bucketSorting(double B[], int size2)
{

	static vector<double> b[fixed_size];
	
	for (int i = 0; i < size2; i++)
	{
		int indexOfBucket = size2*B[i];
		b[indexOfBucket].push_back(B[i]);
	}
	for (int k = 0; k < size2; k++)
	{
		sort(b[k].begin(), b[k].end());

	}
	int index = 0;
	for (int i = 0; i < size2; i++)
	{
		for (int j = 0; j < b[i].size(); j++)
		{
			B[index] = b[i][j];
			cout << B[index] << "  ";
		}
	}
	cout << endl;


}
int Sorting::partition(double Arr[], int left_index, int right_index)
{
	int i = left_index;
	int j = right_index;

	
	
	int pivot_index =  left_index + rand() % (right_index - left_index + 1);
	//int pivot_index = (left_index + right_index) / 2;

    int pivot = Arr[pivot_index];
	
	
	//cout << pivot << endl;
	while (i <= j)
	{
		while (Arr[i] < pivot)

			i++;
		while (Arr[j] > pivot)
			j--;
		if (i <= j)
		{
			double temp = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = temp;
			i++;
			j--;
		}

	};
	return i;
}
void Sorting::QuickSorting(double Arr[], int left_index, int right_index)
{
	// calling this function to get the position where the array can be divided 
	int position = partition(Arr, left_index, right_index);


	if (left_index < position - 1)
	{
		// calling the function  recursively on the left part of the array 
		QuickSorting(Arr, left_index, position - 1);

	}
	if (position < right_index)
	{
		// calling the function  recursively on the right part of the array 
		QuickSorting(Arr, position, right_index);
	}
}
void Sorting::heapify(double Arr[], int n, int i)
{
	// the index of the parent
	int largest = i;

	// the index of the left child
	int left_node = 2 * i+1;

	// the index of the right child
	int right_node = 2 * i + 2;

	// change the index of the largest node if the left_child is greater than its parent
	if (left_node < n &&Arr[left_node]>Arr[largest])
	{
		largest = left_node;
	}
	else
	{
		largest = i;
	}

	// change the index of the largest node if the right_child is greater than its parent
	if (right_node < n &&Arr[right_node]>Arr[largest])
	{
		largest = right_node;
	}

	// swap the element of left or right child with his parent
	if (largest != i)
	{
		swap(Arr[i], Arr[largest]);
		heapify(Arr, n, largest);
	}


}
int Sorting::BuildHeap(double Arr[], int n)
{
	
	for (int i = n / 2 -1 ; i >= 0; i--)
	{
		heapify(Arr, n, i);
	}
	return n / 2;
}
void Sorting::HeapSort(double Arr[], int n)
{
	int size_of_Arr = BuildHeap(Arr, n);
	
	for (int i = n-1 ; i >= 0; i--)
	{
		
		swap(Arr[0], Arr[i]);

		
		heapify(Arr, i, 0);

	}

}
void Sorting::SortedLibrary(double Arr[], int n)
{
	// creating an array of size n
	Arr[n];

	// using this sort library
	sort(Arr, Arr + n);

}

void Sorting::bucket_sorting(int Arr[], int n)
{
	

	int smallest_element = Arr[0];
	int largest_element = Arr[n - 1];

	for (int i = 0; i < n; i++)
	{
		if (Arr[i] < smallest_element)
		{
			smallest_element = Arr[i];
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (Arr[j] > largest_element)
		{
			largest_element = Arr[j];
		}
	}
	cout << "samllest = " << smallest_element << endl;
	cout << "largest = " << largest_element << endl;

	//Here range is [smallest_element,largest_element]
	//const int m = largest_element - smallest_element+1;
	const int m = n;
	//Create m empty buckets
	int * buckets = new int[m];

	//Intialize all buckets to 0
	for (int i = 0; i <m; i++)
		buckets[i] = 0;

    //Increment the number of times each element is present in the input
	//array. Insert them in the buckets
	for (int i = 0; i < Arr[i]; i++)

		buckets[Arr[i]]++;

	//Sorting them and concatenate 
	for (int i = 0, j = 0; j < m; j++)
		for (int k = buckets[j]; k > 0; k--)
			Arr[i++] = j;
}

int Sorting::getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void Sorting::countSort(int arr[], int n, int exp)
{
	//int output[n]; // output array

	int *output = new int[n];
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];


	delete[]output;
	output = NULL;
}

// The main function to that sorts arr[] of size n using 
// Radix Sort
void Sorting::radixsort(int arr[], int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}
int Sorting::getMax2(double Arr[], int n)
{
	int mx = Arr[0];
	for (int i = 1; i < n; i++)
		if (Arr[i] > mx)
			mx = Arr[i];
	return mx;
}
void Sorting::insertSorting(double arr[], int n)
{
	for (int i = 1; i < n;i++)
	{
		int j = i;
		while (j>0 && arr[j - 1] > arr[j])
		{
			swap(arr[j - 1], arr[j]);
			j = j - 1;
		}
	}
}

