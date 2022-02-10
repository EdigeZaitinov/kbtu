
#include <stdio.h>
#include <string.h>

char *words(int count) {
  char words[5] = "words";
  if(count==1) 
    words[strlen(words)-1] = '\0';
  char *ptr = words; 
  return ptr;
}

int print_word_count(char **argv) {
  int count = 0;
  char **a = argv;
  while(*(a++))
    ++count;
  char *ptr = words(count);
  char w[5];
  strcpy(w,ptr);
  printf("The sentence contains %d %s.\n", count, w);
  return count;
}

int main(int argc, char **argv) {
  return print_word_count(argv+1);
}

   
