/* Given a sorted array of n integers that has been rotated an unknown number 
of times, write code to find an element in the array. You may assume that the 
array was originally sorted in increasing order.
*/
#include <iostream>
using namespace std;


//Linear solution: scan for number

// O(logn solution): use a binary search

// int num is the number to find
// returns the index of num
int findNumberIndex(int a[], int num, int start, int end)
{
	if (start > end) {
		return -1;  // negative index means not found
	}

	int mid = (start + end) / 2;
	if (a[mid] == num) {
		return mid;
	}

	// mid is a pivot point
	if (a[mid] < a[mid - 1] || a[mid] > a[mid + 1]){
		cout << "found pivot!!!!\n";
		// Determine which half to look at

		// look at left
		if (a[start] <= num && num <= a[mid - 1]){
			cout << "pivot left \n";
			return findNumberIndex(a, num, start, mid - 1);
		}

		// look at right
		if (a[mid + 1] <= num && num <= a[end]){
			cout << "pivot right\n";
			return findNumberIndex(a, num, mid + 1 , end);
		}
	}

	/* Normal Binary Search */

	// search left
	if (a[mid] > num) {
		cout << "Searching left \n";
		return findNumberIndex(a, num, start, mid - 1);
	}

	// search right
	if (a[mid] < num) {
		return findNumberIndex(a, num, mid + 1, end);
	}

	return -1;
}

int main ()
{
	int array[12] = {15,16,19,20,25,1,3,4,5,7,10,14};
	// cout << "Index of 1 is: " << findNumberIndex(array, 1, 0, 11) << endl;
	// cout << "Index of 3 is: " << findNumberIndex(array, 3, 0, 11) << endl;
	// cout << "Index of 15 is: " << findNumberIndex(array, 15, 0, 11) << endl;
	// cout << "Index of 19 is: " << findNumberIndex(array, 19, 0, 11) << endl;
	// cout << "Index of 14 is: " << findNumberIndex(array, 14, 0, 11) << endl;


	int array1[5] = {10, 15, 20, 0 ,5};
	int array2[5] = {50, 5, 20, 30, 40};

	//cout << "Index of 10 is: " << findNumberIndex(array1, 10, 0, 4) << endl;
	cout << "Index of 15 is: " << findNumberIndex(array1, 15, 0, 4) << endl;
	//cout << "Index of 20 is: " << findNumberIndex(array1, 20, 0, 4) << endl;
	//cout << "Index of 0 is: " << findNumberIndex(array1, 0, 0, 4) << endl;
	//cout << "Index of 5 is: " << findNumberIndex(array1, 5, 0, 4) << endl;


	// cout << "Index of 50 is: " << findNumberIndex(array2, 50, 0, 4) << endl;
	// cout << "Index of 5 is: " << findNumberIndex(array2, 5, 0, 4) << endl;
	// cout << "Index of 20 is: " << findNumberIndex(array2, 20, 0, 4) << endl;
	// cout << "Index of 30 is: " << findNumberIndex(array2, 30, 0, 4) << endl;
	// cout << "Index of 40 is: " << findNumberIndex(array2, 40, 0, 4) << endl;



}