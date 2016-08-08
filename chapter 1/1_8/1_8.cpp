#include <iostream>

// void zeroRowsAndColumns (int ** matrix) {
// 	// find all the zeros first
// 	int numRows = sizeof(matrix) / sizeof(matrix[0]);
// 	int numCols = sizeof(matrix[0]) / sizeof(int);

// 	printf("size of matrix: %lu\n", sizeof(matrix));
// 	printf("size of matrix[0]: %lu\n", sizeof(matrix[0]));

// 	printf("Num of rows: %d\n", numRows);
// 	printf("Num of cols: %d\n", numCols);
// 	//int rows[ sizeof(matrix / sizeof(matrix[0])) ] = {0};
// 	//int columns[ sizeof(matrix[0]) / sizeof(int) ] = {0};
// 	// for(int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++){

// 	// 	for(int j = 0; j < sizeof(matrix[0] / sizeof(int); j++){
// 	// 		if (matrix[i][j] == 0){
// 	// 			//add to hash of rows with zero and hash of columns with zeros
// 	// 		}
// 	// 	}

// 	// }

// 	//then zero rows

// 	//then zero columns
// }

void printMatrix(int ** matrix){
	int numRows = sizeof(matrix) / sizeof(matrix[0]);
	int numCols = sizeof(matrix[0]) / sizeof(int);
	printf("size of matrix: %lu\n", sizeof(matrix));
	printf("size of matrix[0]: %lu\n", sizeof(matrix[0]));

}
int main () {
	int matrix[3][3] = {{1,0,3},{0,1,5},{{1,1,1}}};
	int *m[2] = {matrix[0],matrix[1]};
	zeroRowsAndColumns(matrix);
	return 0;
}