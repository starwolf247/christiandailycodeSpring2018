#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main() {
	vector<string>inventory;

	int integers;
	int fox;
	vector<int> numbers;
	cout << "Please enter in integers (0 to stop): ";

	//gets user input and puts into vector
	while (cin >> integers) {
		if (integers == 0) {
			break;
		}
		numbers.push_back(integers);  //Moved after the check to not inclue 0

	}

	sort(numbers.begin(), numbers.end());

	int y = numbers.size();
	for (int i = 0; i < y; i++) {
		cout << numbers[i] << " ";
	}
	system("pause");
	return 0;
}