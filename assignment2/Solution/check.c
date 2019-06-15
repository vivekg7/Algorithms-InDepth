/* check the correctness of the solution
 *
 * Input :
 *   n m k
 *   nXm problem grid
 *   nXm solution grid 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    char c, **maze;
    maze = (char**)malloc(n * sizeof(char*));
    for (int i=0; i<n; i++) {
        maze[i] = (char*)malloc(m * sizeof(char));
        for (int j=0; j<m; j++) {
            c = getchar();
            if ( c == '#' || c == '.' ) {
                maze[i][j] = c;
            }else
                j--;
        }
    }
    int t = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            c = getchar();
            if ( c == '#' ) {
                if ( maze[i][j] != '#' ) {
                    printf("Wrong Answer\n");
                    printf("Better Luck Next Time.\n");
                    return 0;
                } 
            }
            else if ( c == '.' ) {
                if ( maze[i][j] != '.' ) {
                    printf("Wrong Answer\n");
                    printf("Better Luck Next Time.\n");
                    return 0;
                }
            }
            else if ( c == 'X' ) {
                t++;
                if ( maze[i][j] != '.' ) {
                    printf("Wrong Answer\n");
                    printf("Better Luck Next Time.\n");
                    return 0;
                }
            }
            else 
                j--;
        }
    }
    if ( t != k ) {
        printf("Wrong Answer\n");
        printf("Better Luck Next Time.\n");
        return 0;
    }
    printf("Good Work Captain .!!\n");
    return 0;
}
