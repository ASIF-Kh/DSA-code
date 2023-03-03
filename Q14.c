#include<stdio.h>
#include<stdlib.h>
struct node{
 int key;
 struct node*left;
 struct node*right;
};
struct node *newNode(int item){
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 temp->key=item;
 temp->left=NULL;
 temp->right=NULL;
 return temp;
};
struct node *insert(struct node *node,int key)
{
 if (node==NULL)
 return newNode(key);
 else if (key < node->key)
 node->left=insert(node->left,key);
 else
 node->right=insert(node->right,key);
 return node;
};
int main()
{
 struct node *root=NULL;
 root=insert(root,8);
 root=insert(root,3);
 root=insert(root,1);
 root=insert(root,6);
 root=insert(root,4);
 root=insert(root,10);
 root=insert(root,5);
 root=insert(root,9);
}
