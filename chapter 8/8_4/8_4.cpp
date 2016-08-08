// Power set: Write a method to return all subset of a set

#include <iostream>

void printSet(int array[],int size){
    int i;

    for (i=1;i<=size;i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    return;
}

void printPowerset (int n){
    int stack[10],k;

    stack[0]=0; /* 0 is not considered as part of the set */
    k = 0;

    while(1){
        if (stack[k]<n){
            stack[k+1] = stack[k] + 1;
            k++;
        }

        else{
            stack[k-1]++;
            k--;
        }

        if (k==0)
            break;

        printSet(stack,k);
    }

    return;
}

// void powersetRec(int s[], int k, int m, int n) {
//     if (m <= n) {
//         s[k+1] = m ;
//         printSet(s, k+1) ; 
//         powersetRec(s, k+1, m+1, n) ; /* with m */
//         powersetRec(s, k, m+1, n) ; /*  without m */
//     }
// }

/* {a, b, c}
	{a, b} , {c}
	{a}
	{a , c}
	{b}
	{b, c}

*/
void powerSet(int set[]){
	

}

int main(){

    printPowerset(4);

    int mySet[4] = { 5, 10, 11, 2};

    powerSet(mySet);

    return 0;
}