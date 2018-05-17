#include <iostream>

using namespace std;

int main() {

	char grid[5][5] = { 
	    ' ','|',' ','|',' ',
	    '-','-','-','-','-',
	    ' ','|',' ','|',' ',
	    '-','-','-','-','-',
	    ' ','|',' ','|',' '};
	

	cout << " ";
	for (int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			cout << " " << grid[i][j];
		}
		cout << endl << "  ";
	}
	char input1;
	int input2;
	int input3;
	while (1) {
		cout << "enter X or O" << endl;
		cin >> input1;
		cout << "what row?" << endl;
		cin >> input2;
		cout << "what collumn is that?" << endl;
		cin >> input3;

		if (input2 == 1) input2 = 0;
		if (input2 == 2) input2 = 2;
		if (input2 == 3) input2 = 4;

		if (input3 == 1) input2 = 0;
		if (input3 == 2) input2 = 2;
		if (input3 == 3) input2 = 4;

		if (input1 == 'x' || input1 == 'x') {
			grid[input2][input3] = 'x';
		}
		// random number generator goes below this commentation
		for (int i = 0; i < 25; i++) {
			int a = rand() % 5;
			int b = rand() % 5;
			if (grid[a][b] == ' ') {
				grid[a][b] = 'o';
				break;
			}
		}

		cout << "  ";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << " " << grid[i][j];
			}
			cout << endl << "  ";
		}

	}//end of while

}// end of main 