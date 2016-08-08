// Group Anagrams: Sort an array of strings so that anagrams are next to each other. 
// Assume groups of anagrams can be in any order

// { "hello", "bzz", "abc", "elohl", "dkjl","zbz"}
#include <iostream>
#include <string>
using namespace std;

void groupAnagrams(string strarray[]){
	// Make a copy of the list of strings
	//char * copy = strcpy;

	// sort each string individually. Use bubble sort for simplicity, or mergesort for efficieny
	

	// keep track of which indices need to be grouped together


	// in original list of strings, rearrage
}

int main (){
	// vector<string> strings= { "hello", "bzz", "abc", "elohl", "dkjl","zbz"};
	string strings[] = { "hello", "bzz", "abc", "elohl", "dkjl","zbz"};
	cout << "Input list:" << endl;
	for (int i=0; i < 6; i++){
		cout << strings[i] << " ";
	}
	cout << endl;

	cout << "Output list:" << endl;
	for (int i=0; i < 6; i++){
		cout << strings[i] << " ";
	}
	cout << endl;
	return 0;
}