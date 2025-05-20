#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
}Node;

typedef struct Tree
{
   struct node *head; 
}Tree;

Tree *create_new_tree(int base_data);
Node* create_new_node(int data);
void add_new_node(Node *root,Node *new_node);
Node *search(Node *root,int key);
void print_order(Node *root);


int main(int argc, char const *argv[])
{
    Tree* new_tree = create_new_tree(5);
    for (size_t i = 0; i < 10; i++)
    {
        add_new_node(new_tree->head,create_new_node(i)); //!!!!!!!!!!
    }
    print_order(new_tree->head);
    return 0;
}

Tree *create_new_tree(int base_data)
{
    Tree *new_tree;
    new_tree = malloc(sizeof(Tree));
    new_tree->head = create_new_node(base_data);
    return new_tree;
}

Node* create_new_node(int data)
{
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data= data;
    temp->left= NULL;
    temp->right= NULL;
    return temp;
}

void add_new_node(Node *root,Node *new_node)
{
    if (new_node->data <= root->data)//!!!!!!!!!!
    {
        if (root->left == NULL)
        {
            root->left = new_node;
        }else{
            add_new_node(root->left,new_node);
        }
    }
    if (new_node->data > root->data)//!!!!!!!!!!
    {
        if (root->right == NULL)
        {
            root->right = new_node;
        }else{
            add_new_node(root->right,new_node);
        }   
    }
}

Node *search(Node *root,int key)
{
    Node* temp = root;//!!!!!!!!!!
    while(temp != NULL)
    {
        if (temp->data == key)
        {
            printf("\n the element %d as been found",temp->data);
            return temp;
        }
        if (temp->data < key)
        {
            printf("/\n%d",temp->data);
            temp = temp->left;
        }
        if (temp->data > key)
        {
            printf("\\n%d",temp->data);
            temp = temp->right;
        }
        
    }
}

void print_order(Node* root)
{
    if (root != NULL)
    {
        print_order(root->left);
        printf("%d ",root->data);
        print_order(root->right);
    }
    
}