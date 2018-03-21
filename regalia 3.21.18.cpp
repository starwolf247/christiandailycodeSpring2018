#include<vector>
#include<string>
#include<iostream>

using namespace std;
class regalia {
private:
	int  fuel;
	string brand;
	string color;
	bool drive;

public:

	void initcars(int f, string b, string c, bool d);
	void printinfo();

};



int main()

{
	vector <regalia> garage;
	vector <regalia>::iterator iter;

	regalia dodge;
	regalia audi;
	regalia bugati;
	regalia harley;
	regalia ford;

	audi.initcars(100, "audi", "blue", true);

	ford.initcars(120, "ford", "yellow", false);

	harley.initcars(140, "regallia", "black", true);

	dodge.initcars(160, "dodge", "red", false);

	bugati.initcars(180, "bugati", "orange", false);

	garage.push_back(bugati);

	garage.push_back(audi);

	garage.push_back(harley);

	garage.push_back(ford);

	garage.push_back(dodge);

	for (iter = garage.begin(); iter != garage.end(); iter++)
		iter->printinfo();
	system("pause");
}




void regalia::initcars(int f, string b, string c, bool d) {
	fuel = f;
	brand = b;
	color = c;
	drive = d;
}
void regalia::printinfo() {
	cout << "your car brand is " << brand << endl;
	cout << "your fuel is at " << fuel << endl;
	cout << "your color is  " << color << endl;
	if (drive != true)
		cout << "your car is not four wheel drive" << endl;
	else;
	cout << "your car is four wheel drive" << endl;
}