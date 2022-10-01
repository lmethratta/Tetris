/*  This program should determine if a number is a prime or composite number 
    The program should ask user for a number 'num'
    If 'num' is 0 or 1, print "num is not prime or composite"
    For any value > 1, print "num is a prime number" or "num is a composite number" depending on the number */

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and 
// provide list of most important fixes (in comments)

#include <iostream>
using namespace std;

int main(){
    int number;
    bool factor_found = false;
    cout<<"Enter Number:\n";
    cin>>number;
    if(number == 0 || number == 1) {
        cout<<number<<" is not prime or composite\n";
        return 0;
    }
    for (int i = 2; i < number; i++) {
        if (number % i == 0){
            factor_found = true;
        }
        break;
    }

    
    if (factor_found) {
        cout<<number<<" is a composite number\n";
    }
    else {
        cout<<number<<" is a prime number\n";
    }

    // Most important bugs
    // include statement spelled wrong
    // no return statement
    // if/for blocks not set correctly
    // using divide instead of mod for factor check
    // && instead of || for 0 and 1 check
    
    return 0;
}
