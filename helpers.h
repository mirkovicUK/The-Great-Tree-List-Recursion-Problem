
struct node
{
    int data;
    struct node * left;
    struct node * right;
};


// function allocate new node 
struct node * new_node(int data);


// function that insert node in BST
struct node * insert (struct node * node, int date);


//helper function that Print BST
void print (struct node * head);


//free memory BST takes tree head/root
void free_memory_BST(struct node* head);


//helper function that join 2 nodes together so that second follow first
//sets next pointer of firs node to point to second node, and previous of second to first node
void joinNode (struct node * head1, struct node * head2);


//function that join 2 doubly linked list and return head pointer 
struct node* joinList ( struct node* head1, struct node* head2);


//function rearrange pointers of BST and create doubly linked list 
//visiting each node only once and it's done in O(n) time
struct node* tree_to_list(struct node* head);


//print linked list
void print_ll(struct node * head);

//free memory take list head
void free_list(struct node* head);