#include <stdio.h>

#include "helpers.h"
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

// function allocate new node
struct node * new_node(int data)
{
    //allocate new node and check for return pointer
    struct node * head = malloc(sizeof(struct node));
    assert (head && "Null pointer");

    //set data field and null pointers
    head -> data = data;
    head -> left = NULL;
    head -> right = NULL;

    return head;
}


// function that insert node in BST
struct node * insert (struct node * node, int data)
{
    if ( node == NULL) // base case 
    {
        return new_node(data);
    }
    // Otherwise recur down the tree
    else 
    {
        if (data <= node->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }

        return node;
    }
}


//Print BST
void print (struct node * head)
{
   
    if (head == NULL) 
    {
        return;
    }
    
    print(head->left);
    printf("%d ", head->data);
    print(head->right);
    
}


//free memory takes root pointer of BST
void free_memory_BST(struct node* head)
{
    if (head == NULL) { return; }

    free_memory_BST(head->left);
    free_memory_BST(head->right);
    free(head);
}

//helper function that join 2 nodes together so that second follow first
//sets next pointer of firs node to point to second and previous of second to first
void joinNode (struct node * head1, struct node * head2)
{
    head1->right = head2;
    head2->left  = head1;
}


//function that join 2 doubly linked list and return head pointer 
struct node* joinList ( struct node* head1, struct node* head2)
{
    if (head1 == NULL) { return head2; }
    if (head2 == NULL) { return head1; }

    //2 ptr to hold last node on each list
    struct node *last1, *last2;
    last1 = head1->left;
    last2 = head2->left;

    //join last node of first list and first of second list
    joinNode(last1, head2);

    //then last of second and first node of first list
    joinNode(last2, head1);

    return head1;
}


//function rearrange pointers of BST and create doubly linked list 
//visiting each node only once and it's done in O(n) time
struct node* tree_to_list(struct node* head)
{
    struct node *list1, *list2;

    //base case
    if (head == NULL) { return NULL; };

    //go down the tree and start building list up
    list1 = tree_to_list(head->left);
    list2 = tree_to_list(head->right);

    //disconnect head pointer
    head->left  = head;
    head->right = head;

    //join new lists together 
    list1 = joinList(list1, head);
    list1 = joinList(list1, list2);

    return list1;
}


//print linked list
void print_ll(struct node * head)
{
    if (head == NULL) 
    {
        printf("Empty list");
        return;
    }

    struct node * temp = head->right;
    printf("%d->", head->data);
    while (head != temp)
    {
        printf("%d->", temp->data);
        temp = temp->right;
    }
    printf("\n");
}


//free memory take list head
void free_list(struct node* head)
{
    //empty list case and 1 node list case
    if (head == NULL) { return; } 
    if (head->right == head || head->right == NULL) 
    {
        free(head);
        return;
    }

    struct node* temp = head->right;
    head->left->right = NULL;

    while(temp != NULL)
    {
        free(head);
        head = temp;
        temp = temp->right;
    }
    free(head);
}