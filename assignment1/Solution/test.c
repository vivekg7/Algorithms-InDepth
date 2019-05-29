/* I create a test case of size N = 1 million (can be changed)
 * better  to direct it in a file
 * use linux terminal
 * created to check for time complexity
 * */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int N = 100000;

int main(){
    float imp;
    int a[100];
    srand((unsigned int)time(0));
    for(int i=0; i<100; i++){
        a[i] = rand()%N;
    }
    for(int i=0; i<N; i++){
        printf("%d 12:30-14:45 %.3f", rand()%100, ((float)rand()/(float)(RAND_MAX)) * 1000.0 + 100);
        if(i<N-1) printf("\n");
    }
    return 0;
}
