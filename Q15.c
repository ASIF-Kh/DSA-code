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
 if (key < node->key)
 node->left=insert(node->left,key);
 else
 node->right=insert(node->right,key);
 return node;
};
void inorderTraversal(struct node *root)
{
 if(root!=NULL)
 {
 inorderTraversal(root->left);
 printf("%d->",root->key);
 inorderTraversal(root->right);
 }
}
void preorder(struct node* root)
{
    if (root != NULL)
    {
        printf("%d->", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root)
{
    if (root != NULL)
    {
        preorder(root->left);
        preorder(root->right);
        printf("%d->", root->key);
    }
}
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
 printf("Inorder Traversal of BST is\n");
 inorderTraversal(root);
 printf("\nPreorder Traversal of BST is\n");
 preorder(root);
 printf("\nPostorder Traversal of BST is\n");
 postorder(root);

}
