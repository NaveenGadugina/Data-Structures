#include <stdio.h>
#include <stdlib.h>

// Structure definition for a linked list node
struct node
{
    int data;
    struct node *next;
};

struct node *head;   // Global pointer to the first node of the list

void printll();      // Function prototype to print the linked list

// Insert a node at the beginning
void ins_beg()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node)); // Allocate memory
    printf("Enter the data of the new node: \n");
    scanf("%d", &new_node->data);

    new_node->next = head; // Link new node to current head
    head = new_node;       // Update head

    printll();
}

// Insert a node after a specified node value
void ins_aft()
{
    struct node *ptr, *preptr;
    int pos;

    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data of the node after which the new node is to be inserted: \n");
    scanf("%d", &pos);

    printf("Enter the data of the new node");
    scanf("%d", &new_node->data);

    preptr = head;
    ptr = preptr->next;

    // Traverse until required node is found
    while (preptr->data != pos)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }

    new_node->next = ptr;  // Link new node
    preptr->next = new_node;

    printll();
}

// Insert a node before a specified node value
void ins_bef()
{
    struct node *ptr, *preptr;
    int pos;

    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data of the node before which the new node is to be inserted: \n");
    scanf("%d", &pos);

    printf("Enter the data of the newnode \n");
    scanf("%d", &new_node->data);

    preptr = head;
    ptr = preptr->next;

    // Traverse until the required position is found
    while (ptr->data != pos)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }

    new_node->next = preptr->next;
    preptr->next = new_node;

    printll();
}

// Insert a node at the end of the list
void ins_end()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;

    printf("Enter the data of the new node: \n");
    scanf("%d", &new_node->data);

    new_node->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ptr = head;

        // Traverse to last node
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = new_node; // Attach new node
    }

    printll();
}

// Delete node from beginning
void del_beg()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr;

    ptr = head;
    head = ptr->next; // Move head to next node
    free(ptr);        // Free memory

    printll();
}

// Delete a specific node by value
void del_mid()
{
    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
    struct node *ptr, *preptr;
    int data;

    printf("Enter the data of the node to be deleted \n");
    scanf("%d", &data);

    preptr = head;
    ptr = preptr->next;

    // Traverse to find the node
    while (preptr->next->data != data)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }

    preptr->next = ptr->next; // Remove node
    free(ptr);

    printll();
    }
}

// Delete node at the end
void del_end()
{
    if(head==NULL){
        printf("The list is empty");
    }
    else{
    struct node *ptr, *preptr;

    preptr = head;
    ptr = preptr->next;

    // Traverse to last node
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }

    preptr->next = NULL;
    free(ptr);

    printll();
    }
}

// Function to print the linked list
void printll()
{
    struct node *ptr = head;

    if(head == NULL){
        printf("The list is empty");
    }
    else{
        printf("The list is:\n");

        // Traverse and print each node
        while (ptr != NULL)
        {
            printf("%d\n ", ptr->data);
            ptr = ptr->next;
        }
    }
}

// Main menu driven program
int main()
{
    int opt;

    while (1)
    {
        printf("---------Operations on Linked list---------\n");
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after the specified node\n");
        printf("4. Insertion before the specified node\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of specific node\n");
        printf("7. Deletion at the End\n");
        printf("8. Print the linked list\n");
        printf("9. Exit\n");

        printf("Select the operation to be performed\n");
        scanf("%d", &opt);

        // Menu switch for operations
        switch (opt)
        {
        case 1:
            ins_beg();
            break;
        case 2:
            ins_end();
            break;
        case 3:
            ins_aft();
            break;
        case 4:
            ins_bef();
            break;
        case 5:
            del_beg();
            break;
        case 6:
            del_mid();
            break;
        case 7:
            del_end();
            break;
        case 8:
            printll();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid option\n");
        }
    }

    return 0;
}