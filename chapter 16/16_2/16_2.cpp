// Word Frequencies: Design a method to find the frequency of occurrences of any given word in a book. What if we were running this algorithm multiple times
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// Some sort of hash so you don't have to recompute
// key: word, value: count


//This is case sensitive (ie 'the' != 'The')
void countWordFrequencies(istream& in, map<string,int>& counts) {
	string word;
	while (in >> word) {
		counts[word]++;
	}
}

int main (int arc, char** argv) {
	ifstream in(argv[1]);
	string word = argv[2];

	map<string,int> wordcounts;
	countWordFrequencies(in, wordcounts);

	cout << "frequency of '" << word << "': " << wordcounts[word] << endl;

	return 0;
}