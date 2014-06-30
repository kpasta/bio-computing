// Find all occurrences of a pattern in a string
#include <iostream> // std::cout
#include <string.h> // str::strlen
using namespace std;

//prints full string
void printArr( char arr[] ) {
	int len = strlen(arr);
	// loop through array
	for( int i = 0; i < len; i++ ) {
		cout << arr[i];
	}
}

void findPattern( char pattern[], char strand[] ){
	int slen = strlen(strand);
	int plen = strlen(pattern);
	int k = 0;
	// loop through strand
	for( int i=0; i<(slen-4); i++ ){
		// find the same strand
		k=0;
		while( pattern[k] == strand[i+k] && k<4){
			// if pattern is there, print original location
			k++;
			if( k == 4 ){
				cout << i << ", ";
			}
		}
	}
}

int main() {
	// your code goes here
	
	char pattern[] = "ATAT"; // length k
	char strand[] = "GATATATGCATATACTT"; // string
	
	// answer: CATG, GCAT
	printArr(strand);
	cout << endl;
	printArr(pattern);
	cout << endl;
	findPattern( pattern, strand );
	
	int ctr= 0;
	cin >> ctr;
	
	return 0;
}
