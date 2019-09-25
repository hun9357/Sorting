




#include <iostream>
#include <string>
#include <ctime>
#include <queue> 
using namespace std;


void displayArray(double * items, int start, int end)
{
	for (int i = start; i <= end; i++)
	cout << items[i] << " ";
	cout << endl;
}

int filter(double *items, int start, int end)
{
	double p;
	p = items[start];
	double temp;
	while(start != end)
	{
		if (items[start] > items[end])
		{
			temp = items[start];
			items[start] = items[end];
			items[end] = temp;
		}
		if (p == items[start])
		{
			end--;
		}
		else
		{
			start++;
		}
	}
	return start;
}


void quickSort(double * items, int start, int end)
{
	//Base case:  when is sorting super easy?
	if (start > end)
	{
		cout;
	}
	//Recursive case:
	//step 1: call filter and get your pivot index.
	//step 2: recursively sort the items before the pivot
	//step 3: recursively sort the items after the pivot
	else
	{
		int p = filter(items, start, end);
		quickSort(items, start, p-1);
		quickSort(items, p+1, end);
	}
}


void heapSort(double * items, int start, int end)
{
	priority_queue<double> heap;

	//step 1:  put all the items into the heap one by one
	for (int i = start; i <= end; i++)
	{
		heap.push(items[i]);
	}
	int i = 0;
	
	//step 2: remove the largest item from the heap until it is empty,
	//putting the items into the array in the order you remove them.
	while (!heap.empty())
	{
		items[i++] = heap.top();
		heap.pop();
	}
}

int main()
{

	double testNumsA[] = { 13, 34.1, 43, 189, 4, 4.5, 18.35, 85, 3, 37.2, 5 };

	//The filter will place all items <= 13 to the left of value 13, and all items large than 13 to the right of 13 in the array.
	int p = filter(testNumsA, 0, 10);
	cout << p << endl; //should be 4, the new index of 13.
	displayArray(testNumsA, 0, 10);  //should display something like this:  5 3 4.5 4 13 18.35 85 189 37.2 43 34.1

	double testNumsB[] = { 13, 34.1, 43, 189, 4, 4.5, 18.35, 85, 3, 37.2, 5 };
	p = filter(testNumsB, 2, 6);  //Here we are only interested in items from indices 2-6, ie, 43, 189, 4, 4.5, 18.35
	cout << p << endl; //should be 5
	displayArray(testNumsB, 0, 10); //Notice only indices 2-6 have been partioned:  13 34.1 18.35 4 4.5 43 189 85 3 37.2 5

	
	//Testing Quick Sort
	double testNums[] = { 13, 34.1, 43, 189, 4, 4.5, 18.35, 85, 3, 37.2, 5 };
	double Nums[] = { 4,6,1,3,7,10 };

	quickSort(testNums, 0, 10);

	displayArray(testNums, 0, 10);
	
	quickSort(Nums, 0, 5);

	displayArray(Nums, 0, 5);
	
	
	//Quick sort speed test

	//Stress test:
	int size = 100000; //test with: 1000, 10000, 100000,1000000, 10000000
	double * numbers = new double[size];

	for (int i = 0; i < size; i++)
	{
		numbers[i] = rand();
	}

	clock_t startTime, endTime;

	startTime = clock();
	quickSort(numbers, 0, size - 1);
	endTime = clock();

	cout << "Blaze sort took: " << endTime - startTime << " milliseconds to sort " << size << " doubles." << endl;

	
	//Heap sort speed test

	size = 10000; //test with: 1000, 10000, 100000,1000000, 10000000
	double * numbers2 = new double[size];

	for (int i = 0; i < size; i++)
	{
		numbers2[i] = rand();
	}

	startTime = clock();
	heapSort(numbers2, 0, size - 1);
	endTime = clock();

	//displayArray(numbers2, 0, size - 1);
	cout << "Heap sort took: " << endTime - startTime << " milliseconds to sort " << size << " doubles." << endl;
	


	return 0;
}