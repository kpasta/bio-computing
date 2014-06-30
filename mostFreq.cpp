// Find the most frequent K-mers (common strings of length K) in a string
#include <iostream> // std::cout
#include <string.h> // str::strlen
using namespace std;

//prints result
void printArr( char arr[] ) {
	int len = strlen(arr);
	// loop through array
	int i=0;
	while( arr[i] != '0' ){
		cout << arr[i];
		i++;
	}
};

//prints full string
void printer( char arr[] ) {
	int len = strlen(arr)-1;
	// loop through array
	for( int i = 0; i < len; i++ ) {
		cout << arr[i];
	}
}

void findMostFreq( int k, char strand[] ){
	int len = strlen(strand);
	char result[len];
	char test[k], comp[k];
	int mostF = 0; // highest frequency so far
	int currF = 1; // testing the fequency
	int ctr=0, t=0;
	
	// loop through the strings for k-mer
	for( int i=0; i<len-k; i++ ){
		// for loop to get the k-mer
		for( t=0; t<k; t++ ){
			test[t] = strand[i+t];
		}
		currF = 1; //restart current frequency
		
		// for loop to test the k-mer throughout the string
		for( int j=(i+1); j<(len-k); j++ ){
			// test for common strings
			t=0;
			while( (test[t] == strand[j+t])){
				t++;
			}
			// if there is a common string, increase currF
			if( t==4 ){ currF++; }			
		}
		// else if currF = mostF, add ", -string-"

		if( currF == mostF ){

			//get to end of string
			ctr=0;
			while(result[ctr] !='0'){
				ctr++;
			}
		
			//add new test string
			result[ctr] = ',';
			ctr++;
			for(int l=0;l<4;l++){
				result[ctr+l] = test[l];
				result[ctr+l+1] = '0';
			}	
		}
			
		// if currF > mostF clear, replace result
		if( currF > mostF ){
			for(ctr=0;ctr<4;ctr++){
				result[ctr] = test[ctr];
			}
			result[ctr] = '0'; //end of string;
			mostF = currF; // add 1 for test string
		}			
	}
	printArr( result );
	cout << endl;
	cout << mostF;
	cin >> ctr; //////////////////////////////////////////////	
};

int main() {
	// your code goes here
	
	int k = 4; // length k
	char strand[] = "ACGTTGCATGTCGCATGATGCATGAGAGCT"; // string
	
	// answer: CATG, GCAT
	// printer(strand);
	cout << "Enter strand: ";
	cin >> strand;
	cout << endl;
	cout << "Enter k: ";
	cin >> k;
	cout << endl;
	findMostFreq( k, strand );
	
	return 0;
}
