// Implement TRIEMATCHING to solve the Multiple Pattern Matching Problem.
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

void findPattern( char pattern[][5], char strand[] ){
	int slen = strlen(strand);
	int k = 0;
	// loop through strand
	for( int i=0; i<(slen-3); i++ ){
		// test each pattern
		for( int j=0; j<5; j++){
			k=0;
			while( pattern[j][k] == strand[i+k] && k<4){
				// if pattern is there, print original location
				k++;
				if( k == 4 ){
					cout << i << ", ";
				}
			}
		}
	}
}

int main() {
	// your code goes here
	
	char pattern[5][5]; // ATCG, GGGT
	char strand[] = "AATCGGGTTCAATCGGGGT"; // string
	char inp;
	int ctr = 0;
	// answers should be: 1 4 11 15 ---------------
		cout << "Enter strand: ";
	cin >> strand;
	//printArr(strand);
	cout << endl;
	
	cout << "Enter pattern: ";
	cin >> pattern[ctr];
	cout << endl;
	
	ctr++;
	cout << "Do you want to enter another pattern (5 max)? (Y/N): ";
	cin >> inp;
	while ( (inp == 'Y' || inp == 'y') && (ctr <= 5) ){
		cout << "Enter pattern (" << (5-ctr) << " left): ";
		cin >> pattern[ctr];
		cout << endl;
		
		ctr++;
		cout << "Do you want to enter another pattern (5 max)? (Y/N): ";
		cin >> inp;
	}
	
	findPattern( pattern, strand );
	cin >> ctr;
	
	return 0;
}
