//Validate a binary search tree

#include <iostream>
#include <stdbool.h>
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
	n->child1 = createBST(array, size, start, mid-1);
	n->child2 = createBST(array, size, mid+1, end);

	//find which element should be the root
	return n;
}

// Checks to make sure the tree starting at node head is a binary search tree
bool validateBST(node * head, int min, int max){
	if (head == NULL) {
		return true;
	}

	// If leaf, true
	if (head->child1 == NULL && head->child2 == NULL) {
		return true;
	}

	if (head->child1 != NULL && head->child1->data > head->data){
		return false;
	}

	if (head->child2 != NULL && head->child2->data < head->data){
		return false;
	}

	// if (head->child1 != NULL && head->child1->data > max) {
	// 	return false;
	// }

	// if (head->child2 != NULL && head->child2->data < min){
	// 	return false;
	// }

	if (max != NULL && head->data > max){
		return false;
	}
	if (min != NULL && head->data < min){
		return false;
	}


	return validateBST(head->child1, min, head->data) && validateBST(head->child2, head->data, max);

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
	cout << root->child2->child2->child2->data << endl;
	cout << root->child2->child1->child2->data << endl;

	cout << "Is created BST valid? " << validateBST(root, NULL, NULL) << endl;
	cout << "modifying tree to be invalid..." << endl;
	root -> child2 -> child1 -> data = 66 ;
	cout << "Is modified BST valid? " << validateBST(root, NULL, NULL) << endl;

	return 0;
}