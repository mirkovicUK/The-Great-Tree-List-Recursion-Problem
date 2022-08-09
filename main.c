/* 
    A huge thanks to professor Nick Parlante from Stanford University 
    for making knowledge freely available online
*/



#include "helpers.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


int main (int argc, char * argv[])
{
    //read in user input
    int node_numb = 0;
    bool condition = true;
    do
    {
        printf("Please enter number of nodes: ");
        int test = scanf("%d", &node_numb);
        //printf("test is: %d\n", test);
        
        if (test == 1)
        {
            condition = false;
        }
        
        //clear input stream 
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        
    } while (condition);
    

    //build BST of node_numb elements 
    struct node * head = NULL;
    for (int i = 1; i <= node_numb; i++)
    {
        head = insert(head, i);
    }
 
    //print tree after building 
    printf("Print BST: ");
    print(head);
    printf("\n");

    //tree to list in O(n) time
    head = tree_to_list(head);

    //print list after building
    printf("doubly linked list: ");
    print_ll(head);

    // free memory
    free_list(head);
    printf("\n");
   
}




