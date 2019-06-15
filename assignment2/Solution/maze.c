/* Works really good till 90X90 maze matrix*/

/* It's a reverse method
 * fill all '.' to 'X'
 * then get a continuous '.' from that
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// n, m dimensions of maze; k= no. of dots to fill
int n, m, k;
char **maze; // pointer to maze matrix

// take your input matrix
// convert every '.' to 'X'
// return no. of '.'
int takeinput() {
    scanf("%d %d %d", &n, &m, &k);
    char c;
    int dots = 0;
    maze = (char**)malloc(n * sizeof(char*));
    for (int i=0; i<n; i++) {
        maze[i] = (char*)malloc(m * sizeof(char));
        for (int j=0; j<m; j++) {
            c = getchar();
            if ( c == '.' ) {
                maze[i][j] = 'X';
                dots++;
            }
            else if ( c == '#' )
                maze[i][j] = c;
            else 
                j--;
        }
    }
    return dots;
}

// print the result maze
void printmaze() {
    printf("\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// check if further movement is possible
// return total directions available
int ava(int p) {
    int t=0;
    if ( p/m > 0 )
        t += maze[p/m -1][p%m]=='X'?1:0;
    if ( p%m > 0 )
        t += maze[p/m][p%m -1]=='X'?1:0;
    if ( p/m < n-1 )
        t += maze[p/m +1][p%m]=='X'?1:0;
    if ( p%m < m-1 )
        t += maze[p/m][p%m +1]=='X'?1:0;
    return t;
}

// Assumes further movement is possible
// return the next block to go
int move(int p) {
    if ( p/m > 0 ) {
        if ( maze[p/m -1][p%m] == 'X' )
            return p - m;
    }
    if ( p%m > 0 ) {
        if ( maze[p/m][p%m -1] == 'X' )
            return p - 1;
    }
    if ( p/m < n-1 ) {
        if ( maze[p/m +1][p%m] == 'X' )
            return p + m;
    }
    if ( p%m < m-1 ) {
        if ( maze[p/m][p%m +1] == 'X' )
            return p + 1;
    }
    printf("Help Me!\n");
    return -1;
}

// add all needed dots
void addDots(int dots) {
    int t;
    int checkpoint[dots], ptrcp = 0;
    for (int i=0; i<n*m; i++) {
        if (maze[i/m][i%m] == 'X') {
            t = i;
            break;
        }
    }
    while ( dots-- ) {
        maze[t/m][t%m] = '.';
        if ( ava(t) > 1 ) {
            checkpoint[ptrcp++] = t;
            t = move(t);
        }else if ( ava(t) == 1 ) {
            t = move(t);
        }else {
            for (int i=ptrcp-1; i>=0; i--) {
                if ( ava(checkpoint[i]) ) {
                    t = move(checkpoint[i]);
                    ptrcp = i;
                    break;
                }
            }
        }
    }
}

int main()
{
    int dots = takeinput();
    addDots(dots-k);
    printmaze();
    return 0;
}
