#include <iostream>
using namespace std;

void printArray(int array[], int size){
	for (int i = 0 ; i < size; i++){
		printf("%d ", array[i]);
	}
	cout << "\n";
}

class node{
public:
	int data;
	node * child1;
	node * child2;
	node (int data){
		cout << data << "\n";
		this->data = data;
	}
};

void sortArray(int * array, int size){
	//use bubble sort;
	for (int i = 0; i < size; i++){
		int temp;
		for (int j = 0; j < size - i - 1; j++){
			if (array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	return;
}


// Create binary search tree with minimal height
node* createBST(int array[], int size, int start, int end){
	if (start > end){
		return NULL;
	}

	int mid = (start + end) / 2;
	node * n = new node(array[mid]);
	n->child1 = createBST(array, 10, start, mid-1);
	n->child2 = createBST(array, 10, mid+1, end);

	//find which element should be the root
	return n;
}

int main () {
	int unsortedArray[10] = {435, 12, 432, 98, 302, 343, 29, 8, 70, 67};
	int length = sizeof(unsortedArray)/sizeof(int);
	sortArray(unsortedArray, length);
	printArray(unsortedArray, length);
	//int sortedArray[10] = {0,1,2,3,4,5,6,7,8,9};
	node * root = createBST(unsortedArray, length, 0, length - 1);
	// cout << root->data << "\n";
	// cout << root->child1->data << "\n";
	// cout << root->child1->child1->data << "\n";
	// cout << root->child1->child2->data << "\n";
	// cout << root->child1->child2->child2->data << "\n";
	// node * n = new node(5);
	// cout << n->data;
	return 0;
}