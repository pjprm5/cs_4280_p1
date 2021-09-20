// Paul Passiglia
// cs_4280
// Project 0
// node.h

// Source: stackoverflow.com/questions/56446359/how-to-use-a-binary-search-tree-to-store-strings
// User: Haerambhan
// Accessed: 2/8/21

#ifndef NODE_H
#define NODE_H

#include <string.h>

struct node
{
  char *str;
  struct node *left, *right;
};
struct node *root = NULL;

// Str compare function

char compareStr(char *str1, char *str2)
{
  int i;
  int identical = 0;
  //printf("Str1: %s \n", str1);
  //printf("Str2: %s \n", str2);
  //int value = strcmp(str1, str2);
  // Check if first two letters of strings are identical
  for (i = 0; i < 3; i++)
  {
    if ((str1[i] == str2[i]) && strcmp(str1, str2) != 0)
    {
      identical++;
    }
  }

  return identical;
}

// Create new node
struct node* create(char *str)
{
  struct node *new1;
  new1 = (struct node*)malloc(sizeof(struct node));
  new1->str = malloc(strlen(str)+1);
  strcpy(new1->str,str);
  new1->left = NULL;
  new1->right = NULL;
  return new1;
}

// Insert new node
struct node* insert(struct node *root, char *str)
{
  if (root == NULL)
  {
    root = create(str);
  }
  
  else if (strcmp(str, root->str) < 0)
  {
    root->left = insert(root->left, str);
  }
  else if (strcmp(str, root->str) > 0)
  {
    root->right = insert(root->right, str);
  }
  else if (strcmp(str, root->str) == 0) // strings are equal, do nothing
  {
    //printf("%s & %s are duplicates.\n", str, root->str);
  }
  return root;
}

#endif








