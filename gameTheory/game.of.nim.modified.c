/* Sprague-Grundy Theorem
 * Each Payer can take a maximum of 3 coins 
 * other rules are same as of Game-Of-Nim
 * 
 * output only which player will win 
 * if player 1 plays first
 *
 * https://www.geeksforgeeks.org/combinatorial-game-theory-set-4-sprague-grundy-theorem/
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maximum Number of Coins in a Pile
#define maxP 10000

int N; // Number of piles
int *piles;
int *data; // for dynamic programming

int mex( int x, int y, int z ) {
    int i=0;
    while ( 1 ) {
        if ( i!=x && i!=y && i!=z )
            return i;
        i++;
    }
}

int grundy( int x ) {
    if ( data[x] == -1 )
        data[x] = mex( grundy(x-1), grundy(x-2), grundy(x-3) );
    return data[x];
}

int xor() {
    int x = 0;
    for ( int i=0; i<N; i++ ) {
        x = x ^ grundy(piles[i]);
    }
    return x;
}

int main()
{
    scanf("%d", &N);
    piles = (int*)malloc(N * sizeof(int));
    for ( int i=0; i<N; i++ ) {
        scanf("%d", &piles[i]);
    }
    data = (int*)malloc(maxP * sizeof(int));
    data[0] = 0;
    data[1] = 1;
    data[2] = 2;
    for ( int i=2; i<maxP; i++ )
        data[i] = -1;
    if ( xor() )
        printf("Player 1 wins\n");
    else 
        printf("Player 2 wins\n");
    free(piles);
    free(data);
    return 0;
}
