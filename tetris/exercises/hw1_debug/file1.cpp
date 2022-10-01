/* Print the sum of "products of odd" from 1 to 10 (i.e., 1*3*5*7*9) and "products of even" numbers from 1 to 10 (i.e., 2*4*6*8*10)
*  Print every second characters from 'A' to 'Z' in the reverse order starting with 'Z' (i.e., skip one in between)
*  Output of the program should look like:
*  The value of limit is 10
*   The Sum = 4785
*   Z X V T R P N L J H F D B
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and 
// provide list of most important fixes (in comments)

#include <iostream>

int main(){
    int limit = 10, even_product = 1, odd_product = 1, sum;
    char c;
    std::cout<<"The value of limit is "<< limit<<std::endl;
    int i = 1;
    while (i <= limit) {
        if(i % 2 == 0){
            even_product = even_product * i;
        }   
        if(i % 2 == 1){
           odd_product = odd_product * i;
        }
        i++;
    }
    sum = even_product + odd_product;

    std::cout<< "The Sum = " << sum << std::endl;
    for(char d = 'Z'; d >= 'A'; d--){
    	std::cout<< d <<" ";
    }
    std::cout << "\n";
    
    // Most important bugs:
    // limit was negative
    // products started as 0 not 1
    // even and odd checks made no sense
    // Sum cout line was bad format syntax
    // alphabet forlop not capitalized, and going wrong way.
    return 0;
}
