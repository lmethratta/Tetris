/* Print the multiplication of the two numbers without using multiplication operator. This approach 
   uses add & shift operations to calculate the product of two numbers (as discussed in class).  
   The program will ask you to enter 2 numbers, then it will print the product of the two number
*  The multiplation of 20 and 30 is 600
*/ 

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and 
// provide list of most important fixes (in comments)

#include<bits/stdc++.h>

int main()
{
    int number1 , number2;
    std::cout<<"Enter 1st number:\n";
    std::cin >> number1;
    std::cout <<"Enter 2nd number:\n";
    std::cin >> number2;

    int res = 0, count = 0;

    // 20 30    
    for (int i = number2; i>0; i /= 2) {

        if (i % 2 == 1) {
            res += number1 << count;
        }
        
        count++;
    }

    std::cout << "The product is " <<res<<std::endl;

    // Most important bugs:
    // cin carrots the wrong way (<<)
    // i wasnt set to an int
    // i wasnt being divided
    // res wasn't being incremented, just reset
    // SEMICOLON AFTER IF STATEMENT.

    return 0;
}
