// Paul Passiglia
// cs_4280
// Project 0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tree.h"


int main(int argc, char* argv[])
{
  char input_buffer[300];
   
  fprintf(stderr, "main.c begins..\n");
  printf("argc = %d \n", argc);

  // Check if there was a file redirection using isatty
  if (argc < 2 && (isatty(0)))
  {
    //FILE *fp = stdin;
    printf("Enter a list of strings to be inserted into a BST.\n");
    printf("Each string should be separated by whitespace characters. \n");
    fgets(input_buffer, 300, stdin);
    /*while (fgets(input_buffer, sizeof(input_buffer), fp) != NULL)
    {
      printf("%s \n", input_buffer);
    }*/

    printf("Here is the user input: %s \n", input_buffer);
  }
  
  // File redirection was used so we can check entire file
  if (argc < 2 && !(isatty(0)))
  {
    FILE *fp = stdin;
    while (fgets(input_buffer, sizeof(input_buffer), fp) != NULL)
    {
      printf("%s \n", input_buffer);
    }
  }


  


  return 0;
}
