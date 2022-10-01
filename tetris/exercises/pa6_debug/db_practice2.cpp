// Program to read integers into a 3X3 matrix and display them
// Todo: Fix bugs and makesure program works as intended.
// for each bug fix, add a comments specifying what you fixed.
// Number of errors/bugs = 12


#include <iostream>
// not using std namespace
using namespace std;
void display(int Matrix[3][3],int size);

int main(void) {
	int size=3;
  // cant be var, also why -1
	int Matrix[3][3];
	cout<<"Enter 9 elements of the matrix:"<<endl;
  // declare i in loop, commas not ;
	for (int i = 0; i < size; i++)
    {
      // declare j in for loop
      for (int j = 0; j < size; j++){
        // : not ;
        cin>>Matrix[i][j];
      }
    }
  // already a address
	display(Matrix,3);
	return 0;
}

// should be int
void display(int Matrix[3][3], int size) {
	for (int i = 0; i < size; i++) {
    //simplified j math
		for (int j = 0; j < size; j++ /* should be ++*/) 
        {
          // right indices
          cout<<Matrix[i][j]<<", ";
        }
        cout<<endl;
	}    
}
