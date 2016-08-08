// Magic index: A[i] = i
// Given a sorted array of integers

// Naive: Linearly check each element, takes O(n) time

// Optimized: use a binary search some how?

/* Say a[i] != i
	if (a[i] > i) then magic element cannot exist in right half because all elements will be greater than their indices. Thus search left half

	1, 1, 3, 5, 6 

	if (a[i]) < i) then magic element cannot exist in left half since all of the elements will be less than their indices, so search right

	0, 0, 1, 3, 6

	if (a[i] == i) return i
*/
#include <iostream>
using namespace std;

// This BST only works for distinct integer arrays
int findMagicIndex(int array[], int start, int end){
	if (start > end){
		return -1;
	}

	int mid = (start + end) / 2;
	if (array[mid] == mid){
		return mid;
	}

	if (array[mid] > mid){
		cout << "searching left half" << endl;
		return findMagicIndex(array, start, mid - 1);
	}
	if (array[mid] < mid){
		cout << "searching right half" << endl;
		return findMagicIndex(array, mid + 1, end);
	}

	return -1;
}

int main (){
	int array[5] = {-1,1,3,5,6};

	cout << "Magic Index: " << findMagicIndex(array, 0, 4) << endl;

	int arr[5] = {1,2,3,5,6};
	cout << "Magic Index: " << findMagicIndex(arr, 0, 4) << endl;
	return 0;
}