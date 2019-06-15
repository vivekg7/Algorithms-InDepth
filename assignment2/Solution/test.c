/* Create test cases for the problem*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int n, m, k;
char **maze;

int main()
{
    srand(time(0));
    n = 10+rand()%80; // n rows assigned                 you can
    m = 10+rand()%80; // m columns assigned              change
    k = rand()%(n*m/3)+n*m/4; // no. of dots assigned    these
    maze = (char**)malloc(n * sizeof(char*));
    for (int i=0; i<n; i++) {
        maze[i] = (char*)malloc(m * sizeof(char));
        for (int j=0; j<m; j++) {
            maze[i][j] = '#';
        }
    }
    int t = rand()%(n*m), ch;
    maze[t/m][t%m] = '.';
    for (int i=0; i<k; i++) {
        ch = rand()%4;
        if (ch == 0) {
            if (t/m > 0) {
                t = t - m;
                if (maze[t/m][t%m] == '.')
                    i--;
                maze[t/m][t%m] = '.';
            }
            else i--;
        }
        else if (ch == 1) {
            if (t%m < m-1) {
                t = t + 1;
                if (maze[t/m][t%m] == '.')
                    i--;
                maze[t/m][t%m] = '.';
            }
            else i--;
        }else if (ch == 2) {
            if (t/m < n-1) {
                t = t + m;
                if (maze[t/m][t%m] == '.')
                    i--;
                maze[t/m][t%m] = '.';
            }
            else i--;
        }else if (ch == 3) {
            if (t%m > 0) {
                t = t - 1;
                if (maze[t/m][t%m] == '.')
                    i--;
                maze[t/m][t%m] = '.';
            }
            else i--;
        }
    }
    printf("%d %d %d\n", n, m, rand()%(k/2)+k/5);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}
