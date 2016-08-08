#include <iostream>
#include <stdbool.h>
using namespace std;

void printArray(int a[], int size){
	for (int i = 0; i < size; i++){
		printf("%d ", a[i]);
	}
	cout << "\n";
}

class node{
public:
	int data;
	node * left;
	node * right;
	node (int data){
		cout << data << "\n";
		this->data = data;
	}
};

void sortArray(int * a, int size){
	for (int i = 0; i < size ; i++){
		int temp;
		for (int j = 0; j < size - i - 1; j++){
			if (a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	return;
}

node * createBST(int a[], int length, int start, int end){
	if (start > end){
		return NULL;
	}
	int mid = (start + end)/2;
	node * n = new node(a[mid]);
	n->left = createBST(a, length, start, mid - 1);
	n->right = createBST(a, length, mid + 1, end);
	return n;
}

int findHeight(node * node){
	if (node == NULL){
		return 0;
	}
	if (node->left == NULL && node->right == NULL){
		return 1;
	}
	int heightLeft = findHeight(node->left) + 1;
	int heightRight = findHeight(node->right) + 1;
	return max(heightRight,heightLeft);
}

int isBalanced(node * root){
	// find height of left
	int heightLeft = findHeight(root->left);
	cout << "Left height: " << heightLeft << endl;
	// find height of right
	int heightRight = findHeight(root->right);
	cout << "Right height: " << heightRight << endl;
	if (abs(heightRight - heightLeft) > 1){
		return 0;
	}
	return 1;
};

int main (){
	int unsortedArray[10] = {435, 12, 432, 98, 302, 343, 29, 8, 70, 67};
	int length = sizeof(unsortedArray)/sizeof(int);
	sortArray(unsortedArray, length);
	printArray(unsortedArray, length);
	//int sortedArray[10] = {0,1,2,3,4,5,6,7,8,9};
	node * root = createBST(unsortedArray, length, 0, length - 1);
	cout << "Is created BST balanced? " << isBalanced(root) << endl;
	return 0;
}