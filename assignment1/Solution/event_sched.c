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

// work-in-progress
// using bubblesort instead
void mergesort(event**, int);

// simple bubble sort algorithm on linked list
// arrange in increasing order according to importance
void bubblesort(event**, int);

int main(){
    event **head; // it's head of all heads (array of heads of linked-list)
    head = (event**)malloc(N * sizeof(event*)); // array of heads of size N
    for(int i=0; i<N; i++)
        head[i] = NULL; // initialize the pointers to null
    int n; // company-ID in input
    while(1){
        if(scanf("%d", &n) != 1) break;
        takeinput(head, n); // only take company-ID , leave others to the function
    }
    for(int i=0; i<N; i++){
        if(head[i] == NULL)
            continue;
        //mergesort(head, i);
        bubblesort(head, i); // sort all events ac to importance
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
    while(head != NULL){
        printf(" %.3f", head->imp);
        head = head->next;
    }
    printf("\n");
}

/* void mergesort(event **head, int n){

}*/

void bubblesort(event **head, int n){
    event *last = NULL;
    event *p0, *p1, *p2, *tmp;
    while(1){
        p0 = NULL;
        p1 = head[n];
        p2 = head[n]->next;
        if(last == p2)
            break;
        while(1){
            if(p2 == last){
                last = p1;
                break;
            }
            if(p1->imp > p2->imp){
                if(p0 == NULL){
                    head[n] = p2;
                    tmp = p2->next;
                    p2->next = p1;
                    p1->next = tmp;
                    p0 = head[n];
                }else{
                    p0->next = p2;
                    tmp = p2->next;
                    p2->next = p1;
                    p1->next = tmp;
                    p0 = p2;
                }
                p2 = p1->next;
            }else{
                p0 = p1;
                p1 = p2;
                p2 = p2->next;
            }
        } 
    }
}
