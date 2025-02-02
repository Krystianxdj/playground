/*********************************************************************************************/ /**
* Peer-graded Assignment: 
* Week 3 Assignment: Working with lists
**************************************************************************************************/

/*********************************************************************************************/ /**
* Includes 
**************************************************************************************************/
#include<stdio.h>  // Standard I/O Interface
#include<stdlib.h> // Standard Library
#include <ctype.h>
/*********************************************************************************************/ /**
* Defines 
**************************************************************************************************/
#define SIZE 100         // size of 100 elements in list
/*********************************************************************************************/ /**
* Private typedef 
**************************************************************************************************/
typedef struct list
{
    int data; 
    struct list *next;
} list;
/*********************************************************************************************/ /**
* Function and vaiables declaration
**************************************************************************************************/
int is_empty(const list *l);
list *create_list(int d);
list *add_to_front(int d, list *h);
list *array_to_list(int d[], int size);
void print_list(list *h, char *title);
void swap(list *p1, list *p2);
void sort_list(list *h);
/*********************************************************************************************/ /**
* The main method
**************************************************************************************************/
int main ()
{
    int i;
    //srand(time(0));                            //seed the rand() and seed is set to system time

    list *L = create_list(rand() % 100);       //first element
    
    for(i = 1; i < SIZE; i++)
    {
        L = add_to_front (rand() % 1000, L);    //taking a random number and adding it to the list
    }
    print_list(L, "\n\nList Before sorting : \n");

    sort_list(L);

    print_list(L, "\n\nList After Sorting : \n");

    return 0;    
}





/*********************************************************************************************/ /**
* Function definition:
* show_day
* show_next_day
**************************************************************************************************/
int is_empty(const list *l)
{
    return (l == NULL);
}

list *create_list(int d)
{
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    
    return head;
}

list *add_to_front(int d, list *h)
{
    list *head = create_list(d);
    head -> next = h;
    
    return head;
}

list *array_to_list(int d[], int size)
{
    list *head = create_list(d[0]);
    
    for(int i=1; i<size; i++)
    {
        head = add_to_front(d[i], head);
    }
    
    return head;
}

void print_list(list *h, char *title)
{
    int i = 0;
    printf("%s\n", title);
    while(h != NULL)
    {
        if(i != SIZE-1)
        {
            printf("%d\t", h -> data);
        }
        else
        {
            printf("%d", h->data);
        }

        //new line every 20 elements
        if ((i+1) % 20 == 0)
        {
            printf("\n");
        }

        h = h -> next;

        i++;
    }
}

void swap(list *p1, list *p2)
{
    int temp = p1->data;
    p1->data = p2->data;
    p2->data = temp;
}

//bubble sort to sort the list
void sort_list(list *h)
{
    int i, j;
    list *p1, *p2;

    for(i = SIZE-2; i >= 0; i--)
    {
        p1 = h;
        p2 = p1->next;

        for (j = 0; j <= i; j++)
        {
            if(p1->data > p2->data)
                swap(p1, p2);

            p1 = p2;
            p2 = p2->next;
        }
    }

}


/*********************************************************************************************/ /**
* Compile:      $ gcc -o day_month_struct.out day_month_struct.c
* Run:          $ ./day_month_struct.out
*
* Peer-graded Assignment: Week 2 Assignment: Using struct
* Test Output for "day_month_struct.txt"
* ************************************************************************************************
* Date is January 1 and the next day is January 2
* 
* Date is February 28 and the next day is March 1
* 
* Date is March 14 and the next day is March 15
*
* Date is October 31 and the next day is November 1
*
* Date is December 31 and the next day is January 1
**************************************************************************************************/