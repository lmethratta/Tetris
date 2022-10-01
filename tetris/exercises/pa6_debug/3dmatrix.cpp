// Program to read 3-dimensional matrix and display the elements as 1x3N matrix
// TODO
// User may specify SIZE (any number of rows, columns and depth). Use those to create matrix
// initize matrix using update_3d method (see comments below)
// display method must not be able to modify array elements (update the code as needed)
// display method must use a single loop/iterator to print the entire array with addresses
// display cannot use nested loops
// 

#include <iostream>
#include <stdlib.h>
#include <time.h> 
#define SIZE 3

void update_3d(double Matrix_3d[][SIZE][SIZE],int size); 
void display_1d(double Matrix_3d[][SIZE][SIZE],int size); 

// Most important bugs:
// Syntax errors
// Using constant, not taking in user input.
// incorrect iterator in display
// no iterator logic to print 3d array

int main(void) {
	//prompt the use to enter appropriate dimensions and initializ the matrix accordingly
	double Matrix_3d[SIZE][SIZE][SIZE] = {{{0}}};
	//initialize the array to non-zero values (use scanf or random numbers generator)
	update_3d(Matrix_3d, SIZE);
	//display the values
	display_1d(Matrix_3d, SIZE);
	return 0;
}

void update_3d(double matrix[][SIZE][SIZE], int size) {
	srand (time(NULL));

	std::cout<<"Entering 3N elements of the matrix:"<<std::endl;
	int i=0;
	for (; i < size; i++)
    {
      int j = 0;
      for (; j < size; j++)
	  {
	      int k = 0;
	      for (; k < size; k++)
		  {
			matrix[i][j][k] = rand() % 10;
	      }
      }
    }
}

//update as needed. 1 'for' loop only with 1 iterator to print all values with addresses
//must not be able to update the array.
//Share any observations.
void display_1d(double matrix[][SIZE][SIZE], int size) {
	
	int i;
	for (i= 0; i < 223; i++) {
		if(i % 10 == 3) {
			i += 7;
			std::cout<< "\n";
		}
		if((i % 100 - i % 10) == 30) {
			i += 70;
			std::cout<< "\n";
		}
		std::cout<< &matrix[(i / 100)][((i % 100) / 10)][(i % 10)] << " - " << matrix[(i / 100)][((i % 100) / 10)][(i % 10)] << ", ";
       	//std::cout<</*&matrix*/<<", "<< /*matrix[i][j][k]*/<<std::endl;
    }
	std::cout<< "\n";
}
