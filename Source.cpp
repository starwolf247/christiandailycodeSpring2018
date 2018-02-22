#include <iostream>
void binary();
int inputa;
int inputb;
int inputc;
int inputd;
int inpute;
using namespace std;
int main() {
	cout << "Type in 1 or 0 four times" << endl;
	cin >> inputa;
	cin >> inputb;
	cin >> inputc;
	cin >> inputd;
	cin >> inpute;
	binary();
}
void binary() {
	int a = 1;
	int b = 2;
	int c = 4;
	int d = 8;
	int e = 16;

	int v;
	int w;
	int x;
	int y;
	int z;
	int f;
	w = inputa * a;
	x = inputb * b;
	y = inputc * c;
	z = inputd * d;
	v = inpute * e;

	f = w + x + y + z + e;
	cout << f << endl;

}