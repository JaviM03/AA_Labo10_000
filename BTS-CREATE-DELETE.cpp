



#include<stdio.h>
#include<stdlib.h>

 using namespace std;

 
struct node
{
  
int key;
   
struct node *left, *right;
 
};

 
struct node *
newNode (int item)
{
  
struct node *temp = new node;
  
temp->key = item;
  
temp->left = temp->right = NULL;
  
return temp;

}


 
void
inorder (struct node *root)
{
  
if (root != NULL)
    {
      
inorder (root->left);
      
printf ("%d ", root->key);
      
inorder (root->right);
    
}

}


 
struct node *
insert (struct node *node, int key)
{
  
if (node == NULL)
    return newNode (key);
  
if (key < node->key)
    
node->left = insert (node->left, key);
  
  else
    
node->right = insert (node->right, key);
  
return node;

}


 
 
struct node *
minValueNode (struct node *node)
{
  
struct node *current = node;
  
while (current && current->left != NULL)
    
current = current->left;
  
return current;

}


 
struct node *
maxValueNode (struct node *node)
{
  
struct node *current = node;
  
while (current && current->right != NULL)
    
current = current->right;
  
return current;

}


 
struct node *
deleteNode (struct node *root, int key) 
{
  
// base case
    if (root == NULL)
    return root;
  
// If the key to be deleted is smaller than the root's key,
// then it lies in left subtree
    if (key < root->key)
    
root->left = deleteNode (root->left, key);
  
// If the key to be deleted is greater than the root's key,
// then it lies in right subtree
    else if (key > root->key)
    
root->right = deleteNode (root->right, key);
  
// if key is same as root's key, then This is the node
// to be deleted
    else
    
    {
      
// node with only one child or no child
	if (root->left == NULL)
	
	{
	  
struct node *temp = root->right;
	  
free (root);
	  
return temp;
	
}
      
      else if (root->right == NULL)
	
	{
	  
struct node *temp = root->left;
	  
free (root);
	  
return temp;
	
}
      
// node with two children: Get the inorder successor (smallest
// in the right subtree)
      struct node *temp = minValueNode (root->right);
      
// Copy the inorder successor's content to this node
	root->key = temp->key;
      
// Delete the inorder successor
	root->right = deleteNode (root->right, temp->key);
    
} 
return root;

}


 
int
main ()
{
  
 
/* Let us create following BST
            8
        /       \
    3              10
 /      \             \
1       6             14 
    /       \        /
   4         7      13
*/ 
  
struct node *root = NULL;
  
root = insert (root, 8);
  
root = insert (root, 3);
  
root = insert (root, 10);
  
root = insert (root, 1);
  
root = insert (root, 6);
  
root = insert (root, 4);
  
root = insert (root, 7);
  
root = insert (root, 14);
  
root = insert (root, 13);
  
 
printf ("Inorder traversal of the given tree \n");
  


deleteNode(root,6);
deleteNode(root,10);

inorder(root);
  
return 0;

}