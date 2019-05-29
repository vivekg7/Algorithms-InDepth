#include<stdio.h>
#include<stdlib.h>

int N = 100000; // sizeof linkedlist array

// contains start-time, end-time, importance, and pointer to next box
// of a meeting in the company
typedef struct event {
    int s_h; // hours of start-time
    int s_m; // minutes of start-time
    int e_h; // hours of end-time
    int e_m; // minutes of end-time
    float imp; // importance of the event
    struct event *next; // pointer for linked-list
} event;

// take data about events and meetings 
// put them in a linked list 
void takeinput(event**, int);

// print the company-ID and importance of the events
// in increasing order
void print(event*, int);

// used by mergesort
/* Split the nodes of the given list into front and back halves, 
    and return the two lists using the reference parameters. 
    If the length is odd, the extra node should go in the front list. 
    Uses the fast/slow pointer strategy. */
void frontbacksplit(event*, event**, event**);

// used by mergesort
/* recursively merge 2 linkedlists sorted in increasing order */
event* sortedmerge(event*, event*);

/* Merge-Sort Algorithm to sort linked-list in 
   increasing order .
   Takes pointer to head of the linked-list */
void mergesort(event**);

// simple bubble sort algorithm on linked list
// arrange in increasing order according to importance
void bubblesort(event**, int);

int main(){
    event **head; // it's head of all heads (array of heads of linked-list)
    head = (event**)malloc(N * sizeof(event*)); // array of heads of size N
    for (int i=0; i<N; i++)
        head[i] = NULL; // initialize the pointers to null
    int n; // company-ID in input
    while (1) {
        if (scanf("%d", &n) != 1) break;
        takeinput(head, n); // only take company-ID , leave others to the function
    }
    for (int i=0; i<N; i++) {
        if (head[i] == NULL)
            continue;
        mergesort(&head[i]); 
        // bubblesort(head, i); // we have mergesort now
        print(head[i], i); // print importance and ID
    }
    return 0;
}

void takeinput(event **head, int n){
    event *ptr = (event*)malloc(sizeof(event));
    scanf("%d:%d-%d:%d %f", &ptr->s_h, &ptr->s_m, &ptr->e_h, &ptr->e_m, &ptr->imp);
    ptr->next = head[n];
    head[n] = ptr;
}

void print(event *head, int n){
    printf("%d", n);
    while (head != NULL) {
        printf(" %.3f", head->imp);
        head = head->next;
    }
    printf("\n");
}

void frontbacksplit(event* source, event** front, event** back){
    event *fast;
    event *slow;
    slow = source;
    fast = source->next;
    
    /* Advanced 'fast' two nodes, and advanced "slow" one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    /* 'slow' is before the midpoint in the list, 
      so split in two at that point. */
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

event* sortedmerge(event* a, event* b){
    event* result = NULL;
    
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    
    /* Pick either a or b, and recur */
    if (a->imp <= b->imp) {
        result = a;
        result->next = sortedmerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedmerge(a, b->next);
    }
    return (result);
}

void mergesort(event **headref){
    event *head = *headref;
    event *a;
    event *b;
    
    /* Base Cases -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL))
        return ;
    
    /* Split head into 'a' and 'b' sublists */
    frontbacksplit(head, &a, &b);
    
    /* Recursively sort the sublists */
    mergesort(&a);
    mergesort(&b);
    
    /* answer = merge the two sorted lists together */
    *headref = sortedmerge(a, b);
}

void bubblesort(event **head, int n){
    event *last = NULL;
    event *p0, *p1, *p2, *tmp;
    while (1) {
        p0 = NULL;
        p1 = head[n];
        p2 = head[n]->next;
        if (last == p2)
            break;
        while (1) {
            if (p2 == last) {
                last = p1;
                break;
            }
            if (p1->imp > p2->imp) {
                if (p0 == NULL) {
                    head[n] = p2;
                    tmp = p2->next;
                    p2->next = p1;
                    p1->next = tmp;
                    p0 = head[n];
                }
                else {
                    p0->next = p2;
                    tmp = p2->next;
                    p2->next = p1;
                    p1->next = tmp;
                    p0 = p2;
                }
                p2 = p1->next;
            }
            else {
                p0 = p1;
                p1 = p2;
                p2 = p2->next;
            }
        } 
    }
}
