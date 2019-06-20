/* Sprague-Grundy Theorem
 *
 * Guess the winner if Player A plays first 
 *
 * N integers 
 * easy time a player divide a number by 2, 3 or 6
 * and takes the floor
 * till all numbers become zero
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define maxA 1000

int N;
int *a;
int *data;

int mex(int x, int y, int z) {
    for ( int i=0; i<=3; i++ ) {
        if ( i!=x && i!=y && i!=z )
            return i;
    }
    printf("Something is Wrong\n");
    return -1;
}

int grundy( int x ) {
    if ( data[x] == -1 )
        data[x] = mex( grundy(x/2), grundy(x/3), grundy(x/6) );
    return data[x];
}

int xor() {
    int x = 0;
    for ( int i=0; i<N; i++ ) {
        x = x ^ grundy(a[i]);
    }
    return x;
}

int main()
{
    scanf("%d", &N);
    a = (int*)malloc(N * sizeof(int));
    for ( int i=0; i<N; i++ ) {
        scanf("%d", &a[i]);
    }
    data = (int*)malloc(maxA * sizeof(int));
    data[0] = 0;
    data[1] = 1;
    for ( int i=2; i<maxA; i++ )
        data[i] = -1;
    if ( xor() )
        printf("Player A\n");
    else 
        printf("Player B\n");
    free(a);
    free(data);
    return 0;
}
