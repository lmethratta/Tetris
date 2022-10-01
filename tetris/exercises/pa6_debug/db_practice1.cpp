// Program to check if the user-provided number is a palindrome
// Number of errors/bugs = 15

//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.

#include<iostream>
// wasn't using namespace
using namespace std;
// useless declaration
//void func(char x);

//the return value of your func should be true / false only
// not void..
// must be above main
bool func(int n) {
        
        //int given_number, no temp initialization
        int remainder = 0, temp = 0;
                
        while (n > 0) {
		remainder = n / 10;
		n -= 10;
                temp = temp + 10 + remainder;
                        
        }

        // wrong var
        if (n == temp)
        {
                return false;
        }
        else
        {
                return true;
        }
}

// main must return int
int main() {
        // not an int
        int user_input;
        // no quotes around string        
	cout<<"enter an integer please\n";
        // Not getting an int
        cin >> user_input;
        
        // random 4 in func name
        // assigning to same variable
        bool result = func(user_input);
        if (result){
                cout<<"It is not a palindrome"<<endl;
        }
        else{
                cout<<"It is a palindrome"<<endl;
        }
		
	return 0;
}
// random 8....
//8


