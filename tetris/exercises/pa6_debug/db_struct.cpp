//This program includes a struct called car that is used to store information about a given car
//The program should ask the user for information about their car and initialize a car structure with the given information
//The program should also print the information using a pointer to the initialized struct
//The information printed using the struct and the pointer should be the same

#include <iostream>
#include <string>
using namespace std;

//Biggest bugs:
// not using pointers /references correctly

struct Car{
	string car;
	int modelYear;
	float speed;
};

int main(void){
	string n;
	int a;
	float w;

	struct Car c;
    Car* cPtr = &c;


	cout<<"What is your favorite car's name: ";
	cin>>n;
	c.car = n;

	cout<<"When was it launched : ";
	cin>>a;
	c.modelYear = a;

	cout<<"How much speed does it give : ";
	cin>>w;
	c.speed = w;
        
	cout<<"Car's name is " <<c.car<<", and should be the same as" <<(*cPtr).car<<".\n";
	cout<<"Car's model year is "<<c.modelYear<<", and should be the same as "<<(*cPtr).modelYear<<".\n";
	cout<<"Car's speed is "<<c.speed<<", and should be the same as "<<(*cPtr).speed<<".\n";
}
