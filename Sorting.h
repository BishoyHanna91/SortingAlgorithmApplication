# include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
# include<cstdlib>
# include<ctime>
# include<Windows.h>
using namespace std;
static int  const fixed_size = 1000000;
class Sorting

{
private:
	int Array_size;
	double Array[fixed_size];
	int Array2[fixed_size];

public:
	Sorting();

	void displayArray(double Arr[], int size);
	
	void callingSorting();
	void MergeSort(double Arr[], int left_index, int right_index);
	void Merge(double Arr[], int left_index, int middle_index, int right_index);
	void bucketSorting(double B[], int size2);
	int partition(double Arr[], int left_index, int right_index);
	void QuickSorting(double Arr[], int left_index, int right_index);
	void heapify(double Arr[], int n, int i);
	int BuildHeap(double Arr[], int n);
	void HeapSort(double Arr[], int n);
	void SortedLibrary(double Arr[], int n);
	void bucket_sorting(int Arr[], int n);
	void displayArray_bucket_sorting(int Arr[], int size);
	int getMax(int arr[], int n);
	void countSort(int arr[], int n, int exp);
	void radixsort(int arr[], int n);
	int getMax2(double arr[], int n);
	void insertSorting(double arr[], int n);
	
};