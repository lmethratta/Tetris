#include <stdio.h>

#define MAX_LETTERS 26

char alphabet[MAX_LETTERS];

void initialize_alphabet(char *a) {
  char *p;
  char current_letter = 'a';
  for (p=a;p<(a+MAX_LETTERS);p++){
    *p = current_letter++;
  }
}  

void reverse_print_alpha(char *b) {
  char *p;

  printf("\nReverse alpha...\n");
  initialize_alphabet(b);
  for (p=(b+MAX_LETTERS);p>b;p--){
    printf("%c ",p);
  }
  printf("\n");
  return ;
}

int main(void) {
  int i;
  while (i++ < 10) {
    reverse_print_alpha(alphabet);
  }
}

  

  
