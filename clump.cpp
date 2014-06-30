// Find the k-mers that form (L,t) clumps
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

void findClump( int k, int L, int t, char strand[] ){
	int len = strlen(strand);
	char test[]="00000";
	int i = 0, j = 0, ctr = 0, ind = 0, te=0;
	// ind is start of window
	// i is index for the compare window
	// j is the index for the tester
	// ctr is the freq counter

	// scan through window for testers
	for( int m=0; m<L-k+1; m++ ){
		// get tester

		for( j=0; j<k; j++ ){ // tester
			test[j] = strand[ind+m+j];
		}
		// scan through window
		ctr = 0;
		for( i=0; i<(L-k); i++ ){
			j=0;
			// scan a possible match
			while( test[j] == strand[(ind+i+1)+j] ){
				//cout << test[j] << "==" << strand[(ind+i+1)+j] << endl;
				j++;
				// increment if matches
				if(j == k){ctr++;}
			}
		}
		// at the end of the window test if matches = t
		if(ctr == t){ 
			printArr(test);
			cout << ", ";
		}	
		// if the end of the window matches
		if( ind+L <= len && m<L){
			ind++;
			m=0;
		}
	}
}

int main() {
	// your code goes here
	
	int k = 5; // length k
	int l = 50;
	int t = 4;
	char strand[] = "CGGACTCGACAGATGTGAAGAACGACAATGTGAAGACTCGACACGACAGAGTGAAGAGAAGAGGAAACATTGTAA"; // string
	
	// answer: CGACA, GAAGA
	printArr(strand);
	cout << endl;
	findClump( k, l, t, strand );
	
	int ctr= 0;
	cin >> ctr;
	
	return 0;
}
