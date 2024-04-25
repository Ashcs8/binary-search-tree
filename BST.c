#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

#define NEWNODE (struct node *)malloc(sizeof(struct node))
struct node *root=NULL;

struct node* insert(struct node* root,int num)
{
    if(root==NULL)
    {
        struct node* newnode=NEWNODE;
        newnode->data=num;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    if(num < root->data)
    {
        root->left=insert(root->left,num);
    }
    else if(num > root->data)
    {
        root->right=insert(root->right,num);
    }
    else
    {
        printf("\nduplicate entry");
        return root;
    }
    return root;
}

void createbst(int n)
{
    int i,num;
    printf("\n enter the data in the tree..");
    for(i=0;i<n;i++)
    {
        printf("\n enter the values in nodes:");
        scanf("%d",&num);
        root=insert(root,num);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}


int main()
{
    int n,choice,num;
    while(1)
    {
        printf("\n\t\t\t\tBINARY SEARCH TREE\n");
        printf("1-create\n");
        printf("2-insert\n");
        printf("3-display\n");
        printf("4-exit\n");
        printf("\nenter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nenter the number of node in tree");
            scanf("%d",&n);
            createbst(n);
            break;
            
            case 2:
            printf("\ninsert the new node in the tree..enter data\n");
            scanf("%d",&num);
            root=insert(root,num);
            break;
            
            case 3:
            printf("\n preorder traversal..");
            preorder(root);
            printf("\ninorder traversal..");
            inorder(root);
            printf("\npostorder traversal..");
            postorder(root);
            break;
            
            case 4:
            printf("exit");
            break;
            
            default:
            printf("invalid entry");
            break;
        }
    }
}
