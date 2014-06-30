// Find substrings of a genome encoding a given amino acid sequence.
#include <iostream> // std::cout
#include <string.h> // str::strlen
#include <vector>
using namespace std;

//prints full string
void printArr( char arr[] ) {
	int len = strlen(arr);
	// loop through array
	for( int i = 0; i <len; i++ ) {
		cout << arr[i];
	}
}

int getInd( char inp, char table[][7][4] ){
	for(int i=0; i<27; i++){
		if(table[i][0][0] == inp){
			return i;
		}
	}
	return 27; // aka *;
}

void findGenome( char pattern[], char strand[], char table[][7][4] ){
	int slen = strlen(strand);
	int k = 0, s = 0;;
	// loop through strand	// get indexes
	int a = getInd( pattern[0], table );
	int b = getInd( pattern[1], table );
	int ctr=0;

	// scan through strand
	for( int i=0; i<(slen-3); i++ ){
		for( int j=1; j<7; j++){
			k=0;
			while( table[a][j][k] == strand[i+k] && k<3){
//				cout << table[a][j][k] << "--" << strand[i+k] << endl;
				k++;
				// if the first pattern is there test the second pattern
				if( k == 3 ){
					for( int m=1; m<7; m++){
						s=0;
						
						while( table[b][m][s] == strand[i+s+3] && s<3){
//							cout << table[b][m][s] << "--" << strand[i+s+3] << endl;
							s++;
							
							if( s == 3 ){
//								cin >> ctr;
								cout << table[a][j];
								cout << table[b][m] << endl;
							}
						}			
					}
				} 
			}
		}				
	}
}

int main() {
	// your code goes here
	char strand[] = "ATGGCCATGGCCCCCAGAACTGAGATCAATAGTACCCGTATTAACGGGTGA"; // string
	char inp[] = { 'M', 'A' };
	
	char anArray[][7][4] =
	{
		{"A", "GCA", "GCC", "GCG", "GCT", "XXX", "XXX"},
		{"B", "AAC", "AAT", "GAC", "GAT", "XXX", "XXX"},
		{"C", "TGC", "TGT", "XXX", "XXX", "XXX", "XXX"},
		{"D", "GAC", "GAT", "XXX", "XXX", "XXX", "XXX"},
		{"E", "GAA", "GAG", "XXX", "XXX", "XXX", "XXX"},
		{"F", "TTC", "TTT", "XXX", "XXX", "XXX", "XXX"},
		{"G", "GGA", "GGC", "GGG", "GGT", "XXX", "XXX"},
		{"H", "CAC", "CAT", "XXX", "XXX", "XXX", "XXX"},
		{"I", "ATA", "ATC", "ATT", "XXX", "XXX", "XXX"},
		{"K", "AAA", "AAG", "XXX", "XXX", "XXX", "XXX"},
		{"L", "CTA", "CTC", "CTG", "CTT", "TTA", "TTG"},
		{"M", "ATG", "GGC", "XXX", "XXX", "XXX", "XXX"},
		{"N", "AAC", "AAT", "XXX", "XXX", "XXX", "XXX"},
		{"P", "CCA", "CCC", "CCG", "CCT", "XXX", "XXX"},
		{"Q", "CAA", "CAG", "XXX", "XXX", "XXX", "XXX"},
		{"R", "AGA", "AGG", "CGA", "CGC", "CGG", "CGT"},
		{"S", "AGC", "AGT", "TCA", "TCC", "TCG", "TCT"},
		{"T", "ACA", "ACC", "ACG", "ACT", "XXX", "XXX"},
		{"V", "GTA", "GTC", "GTG", "GTT", "XXX", "XXX"},
		{"Q", "TGG", "XXX", "XXX", "XXX", "XXX", "XXX"},
		{"X", "NNN", "XXX", "XXX", "XXX", "XXX", "XXX"},
		{"Y", "TAC", "TAT", "XXX", "XXX", "XXX", "XXX"},
		{"Z", "CAA", "CAG", "GAA", "GAG", "XXX", "XXX"},
		{"*", "TAA", "TAG", "GTA", "XXX", "XXX", "XXX"}
	};

	
	
	// answer: ATGGCC

	cout << "Enter strand: ";
	//cin >> strand;
	printArr(strand);
	cout << endl;
	
	cout << "Enter Amino Acid Sequence (2 Max): ";
	//cin >> inp[0] >> inp[1];
	cout << inp[0] << inp[1];
	cout << endl;
	
	findGenome( inp, strand, anArray );
	
	int ctr= 0;
	cin >> ctr;
	
	return 0;
}
