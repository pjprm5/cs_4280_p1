// Paul Passiglia
// cs_4280
// Project 0
// tree.h

// Source: stackoverflow.com/questions/56446359/how-to-use-a-binary-search-tree-to-store-strings
// User: Haerambhan
// Accessed 2/8/21


#ifndef TREE_H
#define TREE_H

void preOrder(struct node *temp, char *str1)
{
  if (temp == NULL)
    return;
  //printf("Preorder traversal: ");
  printf("%s\n ", temp->str);
  FILE * fptr1 = fopen(str1, "a");
  fprintf(fptr1, "%s \n", temp->str);
  fclose(fptr1);
  preOrder(temp->left, str1);
  preOrder(temp->right,str1);
  
}

void inOrder(struct node *temp, char *str1)
{
  if (temp == NULL)
    return;
  //printf("Inorder traversal: ");
  inOrder(temp->left, str1);
  printf("%s\n ", temp->str);
  FILE * fptr2 = fopen(str1, "a");
  fprintf(fptr2, "%s \n", temp->str);
  fclose(fptr2);
  inOrder(temp->right, str1);
}

void postOrder(struct node *temp, char *str1)
{
  if (temp == NULL)
    return;
  //printf("Postorder traversal: ");
  postOrder(temp->left, str1);
  postOrder(temp->right, str1);
  printf("%s\n ", temp->str);
  FILE * fptr3 = fopen(str1, "a");
  fprintf(fptr3, "%s \n", temp->str);
  fclose(fptr3);
  
}


#endif
