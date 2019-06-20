/* Find optimal move 
 * in a Tic-Tac-Toe game state
 *
 * https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-3-tic-tac-toe-ai-finding-optimal-move/ 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// board dimesions N x N
#define N 3

// #define false 0
// #define true 1

#define max(x, y) x>y?x:y
#define min(x, y) x<y?x:y

char **board;

int checkwin() {
    // check row & column
    int ro, co;
    for ( int i=0; i<N; i++ ) {
        ro = 0;
        co = 0;
        for ( int j=0; j<N; j++ ) {
            if ( board[i][j] == 'x' )
                ro++;
            else if ( board[i][j] == 'o' )
                ro--;
            if ( board[j][i] == 'x' )
                co++;
            else if ( board[j][i] == 'o' )
                co--;
        }
        if ( ro == N || co == N )
            return 10;
        if ( ro == -(N) || co == -(N) )
            return -10;
    }
    // check diagonal
    ro = 0;
    co = 0;
    for ( int i=0; i<N; i++ ) {
        if ( board[i][i] == 'x' )
            ro++;
        else if ( board[i][i] == 'o' )
            ro--;
        if ( board[i][N-i-1] == 'x' )
            co++;
        else if ( board[i][N-i-1] == 'o' )
            co--;
    }
    if ( ro == N || co == N )
        return 10;
    if ( ro == -(N) || co == -(N) )
        return -10;
    // check for incompleteness
    for ( int i=0; i<N*N; i++ ) {
        if ( board[i/N][i%N] == '_' )
            return 1;
    }
    // else it's a draw
    return 0;
}

int minimax( int depth, _Bool isMax ) {
    int chk = checkwin();
    if ( chk == 10 ) {
        return chk - depth;
    } else if ( chk == 0 || chk == -10 ) {
        return chk + depth;
    }
    int val;
    int bestVal;
    if ( isMax ) {
        bestVal = -20;
        for ( int i=0; i<N*N; i++ ) {
            if ( board[i/N][i%N] == '_' ) {
                board[i/N][i%N] = 'x';
                val = minimax( depth+1, false );
                board[i/N][i%N] = '_';
                bestVal = max( bestVal, val );
            }
        }
    }
    else {
        bestVal = 20;
        for ( int i=0; i<N*N; i++ ) {
            if ( board[i/N][i%N] == '_' ) {
                board[i/N][i%N] = 'o';
                val = minimax( depth+1, true );
                board[i/N][i%N] = '_';
                bestVal = min( bestVal, val );
            }
        }
    }
    return bestVal;
}

int findBestMove() {
    int bestMove = -1;
    int bestVal;
    int val;
    for ( int i=0; i<N*N; i++ ) {
        if ( board[i/N][i%N] == '_' ) {
            bestMove = i;
            board[i/N][i%N] = 'x';
            bestVal = minimax(0, false);
            board[i/N][i%N] = '_';
        }
    }
    if ( bestMove == -1 )
        return -1;
    for ( int i=0; i<N*N; i++ ) {
        if ( board[i/N][i%N] == '_' ) {
            board[i/N][i%N] = 'x';
            val = minimax(0, false);
            board[i/N][i%N] = '_';
            if ( val > bestVal ) {
                bestVal = val;
                bestMove = i;
            }
        }
    }
    return bestMove;
}

int main()
{
    board = (char**)malloc(N * sizeof(char*));
    char c;
    for ( int i=0; i<N; i++ ) {
        board[i] = (char*)malloc(N * sizeof(char));
        for ( int j=0; j<N; j++ ) {
            c = getchar();
            if ( c=='_' || c=='o' || c=='x' )
                board[i][j] = c;
            else
                j--;
        }
    }
    int res = findBestMove();
    if ( res == -1 )
        printf("\nNo Move Left\n");
    else {
        printf("\nThe Optimal Move is :\n");
        printf("ROW: %d and COL: %d\n", res/3, res%3);
    }
    for (int i=0; i<N; i++)
        free(board[i]);
    free(board);
    return 0;
}
