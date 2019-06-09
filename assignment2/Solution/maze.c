#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    char maze[n][m], c;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            c = getchar();
            if (c == '.' || c == '#')
                maze[i][j] = c;
            else 
                j--;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}
