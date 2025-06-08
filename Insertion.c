#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

// linked list traversal
void linkedlist_traversal(struct node *head);

// linkedlist insert at start
struct node *insertion_at_start(struct node *head, int data);

// size of linkedlist
int *linkedlist_size(struct node *ptr);

// insert at end
struct node *insert_at_end(struct node *head, int data);

// insert after the node
struct node *insert_after_node(struct node *head, struct node *Node, int data);
//free allocated memory
void freelinkedlist_function(struct node *head);

//insertion at index
struct node *insertion_at_index(struct node *head, int index, int data);

int main()
{
    int input, success, data, index, *size;
    struct node *head, *second, *third, *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    (*head).data = 12;
    head->next = second;
    second->data = 34;
    second->next = third;
    third->data = 22;
    third->next = fourth;
    fourth->data = 78;
    fourth->next = NULL;
    size = linkedlist_size(head);
    printf("%d\n",*size);
    printf("**welcome to Insertion**\nThis is your existing linkedlist: ");
    linkedlist_traversal(head);
    printf("\nEnter the data which you want to insert: \n");
    scanf(" %d", &data);
    do
    {
        printf("\nEnter :\n1->Insert at start\n2->Insert at index\n3->Insert at end\n4->Insert after the node\nyour input:");
        success = scanf("%d", &input);
        if (success != 1)
        {
            while (getchar() != '\n')
                ; // flush input buffer
            printf("Invalid input. Please enter a number (1 ,2 ,3 or 4).\n");
            continue;
        }

        if (input > 4 || input < 1)
        {
            printf("Invalid Input!!\n");
        }
    } while (input > 4 || input < 1);
    switch (input)
    {
    case 1:
        head = insertion_at_start(head, data);
        *size++;
        linkedlist_traversal(head);
        printf("\n");
        break;
    case 2:
        do
        {
            printf("Enter index number where you want to insert:\n");
            success = scanf(" %d", &index);
            if (success != 1)
            {
                while (getchar() != '\n')
                    ; // flush input buffer
                printf("Invalid input. Please enter a valid number.\n");
                continue;
            }
            if (index > *size - 1 || index < 0)
            {
                printf("Invalid Input!! linkedlist out of bound.\n");
            }
        } while (index < 0 || index > *size - 1);
        head = insertion_at_index(head, index, data);
        linkedlist_traversal(head);
        *size ++;
        printf("\n");
        break;
    case 3:
        head = insert_at_end(head, data);
        linkedlist_traversal(head);
        *size ++;
        printf("\n");
        break;
    case 4:
        head = insert_after_node(head, second, data);
        *size ++;
        linkedlist_traversal(head);
        printf("\n");
        break;
    }

    freelinkedlist_function(head);

    return 0;
}

// linkedlist traversal function defination...
void linkedlist_traversal(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// linkedlist insertion at index defination
struct node *insertion_at_index(struct node *head, int index, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    for (int i = 0; i < index - 1 && p->next != NULL; i++)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// size of linkedlist
int *linkedlist_size(struct node *ptr)
{
    
    int i ,*size = &i;
    for (i = 1; ptr->next != NULL; i++)
    {
        ptr = ptr->next;
    }
    return size;
}

// insert at start function defination
struct node *insertion_at_start(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// insert at end defination
struct node *insert_at_end(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// insert after node defination
struct node *insert_after_node(struct node *head, struct node *Node, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    if (Node == NULL)
    {
        printf("Given node is null, cannot insert the node.\n");
        return head;
    }
    ptr->next = Node->next;
    Node->next = ptr;
    return head;
}

// free linkedlist function defination
void freelinkedlist_function(struct node *head)
{
    struct node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}