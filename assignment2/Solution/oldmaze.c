/* Not the best method to solve a problem
 * only work till 15X15 matrix */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// n X m maze, k boxes to eliminate
int n, m, k;
char **maze;

// take care of input
void takeinput() {
    scanf("%d %d %d", &n, &m, &k);
    char c;
    maze = (char**)malloc(n * sizeof(char*));
    for (int i=0; i<n; i++) {
        maze[i] = (char*)malloc(m * sizeof(char));
        for (int j=0; j<m; j++) {
            c = getchar();
            if (c == '.' || c == '#')
                maze[i][j] = c;
            else 
                j--;
        }
    }
}

// take care of printing the result
void printmaze() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// if the maze breaks into fragments return 0
// else return 1
// dfs algo to traverse
int youcan() {
    char *a = (char*)malloc(n*m * sizeof(char));
    int t;
    for (int i=0; i<n*m; i++) {
        if (maze[i/m][i%m] == '.') {
            t=i;
            a[i] = 0;
        }
        else
            a[i] = 1;
    }
    int *que = (int*)malloc(n*m * sizeof(int));
    int q=0;
    que[q++] = t;
    while (q) {
        t = que[0];
        a[t] = 1;
        for (int i=1; i<q; i++) {
            que[i-1] = que[i];
        }
        q--;
        if (t/m > 0) {
            if (a[t - m] == 0) {
                que[q++] = t-m;
            }
        }
        if (t%m > 0) {
            if (a[t-1] == 0) {
                que[q++] = t-1;
            }
        }
        if (t/m < n-1) {
            if (a[t + m] == 0) {
                que[q++] = t+m;
            }
        }
        if (t%m < m-1) {
            if (a[t+1] == 0) {
                que[q++] = t+1;
            }
        }
    }
    for (int i=0; i<n*m; i++) {
        if (a[i] == 0) {
            free(a);
            free(que);
            return 0;
        }
    }
    free(a);
    free(que);
    return 1;
}

// when called each time
// remove a cell from the maze
void removep() {
    int t;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maze[i][j] == '.') {
                t=0;
                if (i > 0)
                    t += maze[i-1][j]=='.'?1:0;
                if (j > 0)
                    t += maze[i][j-1]=='.'?1:0;
                if (i < n-1)
                    t += maze[i+1][j]=='.'?1:0;
                if (j < m-1)
                    t += maze[i][j+1]=='.'?1:0;
                if (t==1) {
                    maze[i][j] = 'X';
                    return ;
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maze[i][j] == '.') {
                maze[i][j] = 'C';
                if (youcan()) {
                    maze[i][j] = 'X';
                    return ;
                }else 
                    maze[i][j] = '.';
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    char c;
    maze = (char**)malloc(n * sizeof(char*));
    for (int i=0; i<n; i++) {
        maze[i] = (char*)malloc(m * sizeof(char));
        for (int j=0; j<m; j++) {
            c = getchar();
            if (c == '.' || c == '#')
                maze[i][j] = c;
            else 
                j--;
        }
    }
    while (k--) {
        removep();
    }
    printmaze();
    return 0;
}
