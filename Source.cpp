#include<iostream>
#include<string>
//#include<Windows.h>
//#include <ctime>
using namespace std;

//class definition
class smash
{
private:
	//int health;
	int lives;
	int damage;
	string name;

public:
	//void eat(char c);
	void initPlayer(int x, int y, string z);
	void printinfo();
	void takedamage(int x);
};

//function declaration
//char foodDrop(char location);

int knockback(int D, int w, int p, double s, int b, double r);

int main() {

	//srand(time(NULL));
	//while (1) {
	smash ness;
	//ness.initPoke(5);
	ness.initPlayer(4, 0, "ness");
	ness.printinfo();
	//charizard.eat('b'); //testing without food dropper
	ness.takedamage(knockback(30, 75, 20, 1.5, 20, 1.2)); //testing with food dropper
	ness.printinfo();


	system("pause");
}


//}//end main

//function declarations
//char foodDrop(char location) {
//
//	int num = rand() % 100 + 1;
//
//	if (location == 'f') {
//		if (num <= 50) {
//			cout << "you got a berry!" << endl;
//			return 'b';
//		}
//		else {
//			cout << "you got a mushroom!" << endl;
//			return 'm';
//
//		}
//	}
//	else if (location == 'd') {
//		if (num <= 20) {
//			cout << "You got a berry!" << endl;
//			return 'b';
//		}
//		else if (num <= 40) {
//			cout << "You got a fruit!" << endl;
//			return 'f';
//		}
//		else if (num < 40) {
//			cout << "You found some cheese?" << endl;
//			return 'c';
//		}
//	}
//
//
//	else
//		cout << "invalid location" << endl;
//
//}


void smash::initPlayer(int x, int y, string z) {
	lives = x;
	damage = y;
	name = z;

}
void smash::printinfo() {
	cout << name << "'s persentage is " << damage << endl;
	cout << "you have this many lives:" << lives << endl;


}
void smash::takedamage(int x) {
	damage += x;
}//declare

 //define
int knockback(int D, int w, int p, double s, int b, double r) {

	int num;
	num = ((((7 * (D + 2) * (D + p)) / (w + 100) + 9) * 2 * s) + b) * r;
	cout << "damage calculated is " << num << endl;

	return num;
}

//void smash::eat(char food) {

/*if (food == 'b')
health += 3;
else if (food == 'c')
health += 4;
else if (food == 'm')
health += 5;
else if (food == 'p')
health += 6;
else if (food == 'f')
health += 7;
*/
//}