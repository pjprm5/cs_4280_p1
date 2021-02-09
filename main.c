// Paul Passiglia
// cs_4280
// Project 0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"
#include "tree.h"

#define ROWS 30
#define COLS 30

// Function to concoctenate two strings if they have same first two letters
void concoctStr(char str1[ROWS][COLS], char *str2)
{
  int i;
  for (i = 0; i < 30; i ++)
  {

    if (compareStr(str1[i], str2) == 2 && strcmp(str1[i], str2) != 0)
    {
      char *combined = malloc(strlen(str1[i]) + strlen(str2) + 1);
      printf("%s & %s have the same first two letters! \n", str1[i], str2);
      strcpy(combined, str1[i]);
      strcat(combined, str2);
      strcpy(str1[i], combined);
      printf("Combined: %s \n", str1[i]);
    }
  }
}


int main(int argc, char* argv[])
{
  char input_buffer[300] = { 0 };
  int i = 0;
  char *token;
  char str1[ROWS][COLS] = { 0 };
  char *combined;
  char *combined2;
  char *combined3;
  int flag1 = 0;
  int flag2 = 0;


  //fprintf(stderr, "main.c begins..\n");
  //printf("argc = %d \n", argc);

  // Parse invocations below --------------------------------------

  // ./main --- Check if there was a file redirection using isatty
  if (argc < 2 && (isatty(0)))
  {
    printf("Enter a list of strings to be inserted into a BST.\n");
    printf("Each string should be separated by whitespace characters. \n");
    fgets(input_buffer, 300, stdin);
    //printf("Here is the user input: %s \n", input_buffer);
    flag1 = 1; 
    // Tokenize input_buffer
    token = strtok(input_buffer, " \n");
    while (token != NULL)
    { 
      
      printf("%s \n", token); 
      strcpy(str1[i], token);    
      concoctStr(str1, token);
      //root = insert(root, str1[i]);
      token = strtok(NULL, " \n");
      i++;
    }
    for (i = 0; i < ROWS; i++)
    {
      root = insert(root, str1[i]); // insert a node using str1[i]      
    }
  }
  
  // ./main < list.sp2020 --- File redirection was used. ------------------
  if (argc < 2 && !(isatty(0)))
  {
    flag1 = 1;
    printf("File was redirected to stdin. \n");
    while (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL)
    {
      // Tokenize input buffer
      token = strtok(input_buffer, " \n");
      while (token != NULL)
      {
        printf("%s \n", token);
        strcpy(str1[i], token);
        concoctStr(str1, token);
        //root = insert(root, str1[i]);
        token = strtok(NULL, " \n");
        i++;
        //printf("%s \n", input_buffer);
      }
    }
    for (i = 0; i < ROWS; i++)
    {
      root = insert(root, str1[i]); // insert a node using str1[i]
    }
  }
  
  // ./main list.sp2020 --- File will be read. -----------------------------
  if (argc == 2)
  {
    printf("File specified to read: %s \n", argv[1]);
    FILE *fptr;
    if ((fptr = fopen(argv[1], "r")) == NULL)
    {
      fprintf(stderr, "Error! File will not open. \n");
      return -1;
    }
    flag2 = 1;

    while (fgets(input_buffer, sizeof(input_buffer), fptr) != NULL)
    {
      token = strtok(input_buffer, " \n");
      while (token != NULL)
      {
        printf("%s \n", token);
        strcpy(str1[i], token);
        concoctStr(str1, token);
        //root = insert(root, str1[i]);
        token = strtok(NULL, " \n");
        i++;
      }
      //printf("%s \n", input_buffer);
    }
    for (i = 0; i < ROWS; i++)
    {
      root = insert(root, str1[i]); // insert a node unsing str1[i]
    }
    fclose(fptr);

    // Create necessary output files
    char period[30] = "...................";
    char argument[30];
    char winner[30];
    strcpy(argument, argv[1]);
    for (i = 0; i < strlen(argv[1]); i++)
    {
      if (argument[i] != period[i])
      {
        winner[i] = argument[i];
      }
      if (argument[i] == period[i])
      {
        break;
      }
    }
    printf("winner: %s \n", winner);
    strcpy(argv[1], winner);

    char tail[20] = ".inorder";
    combined = malloc(strlen(argv[1]) + strlen(tail) + 1);
    strcpy(combined, argv[1]);
    strcat(combined, tail);
    printf("FILENAME1: %s \n", combined);
    
    char tail2[20] = ".preorder";
    combined2 = malloc(strlen(argv[1]) + strlen(tail2) + 1);
    strcpy(combined2, argv[1]);
    strcat(combined2, tail2);
    printf("FILENAME2: %s \n", combined2); 
 
    char tail3[20] = ".postorder";
    combined3 = malloc(strlen(argv[1]) + strlen(tail3) + 1);
    strcpy(combined3, argv[1]);
    strcat(combined3, tail3);
    printf("FILENAME3: %s \n", combined3);

    FILE *fptr1 = fopen(combined, "w");
    FILE *fptr2 = fopen(combined2, "w");
    FILE *fptr3 = fopen(combined3, "w");
  }

  // Print traversals

  if (flag1 == 1)
  {
    FILE *fptr1 = fopen("output.inorder", "w");
    FILE *fptr2 = fopen("output.preorder", "w");
    FILE *fptr3 = fopen("output.postorder", "w");
    printf("Preorder traversal:\n");
    preOrder(root, "output.preorder");
    printf("Inorder traversal:\n");
    inOrder(root, "output.inorder");
    printf("Postorder traversal:\n");
    postOrder(root, "output.postorder");
  }

  if (flag2 == 1)
  {
    printf("Preorder traversal:\n");
    preOrder(root, combined2);
    printf("Inorder traversal:\n");
    inOrder(root, combined);
    printf("Postorder traversal:\n");
    postOrder(root, combined3);
  }
  
  /*int value;
  char string1[15];
  char string2[15];
  strcpy(string1, "car");
  strcpy(string2, "ca");
  value = compareStr(string1, string2);
  printf("Value: %d \n", value);
  */
  return 0;
}
