//This program should read any string (including spaces) from the user and print it using a character pointer
//The program is setup to use pointer offset notation to get each character of the string

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

// Biggest bugs:
// messed up imports
// pointer not declared correctly
// main must return int
// doesnt dereference pointer when comparing to string end
// doesnt print multiple spaces
int main(){
    char s[20];
    char* cPtr;
    cin>>s;
    cPtr = s;
    while(*cPtr != '\0'){
        cout<<*(cPtr++);
    }
  cout<<"\n";
  return 0;
}
