/* Knuth-Morris-Pratt (KMP) Pattern Matching
 * Substring Search
 * 
 * outputs only the index of the main string
 * where the search string found
 *
 * no output for not match*/

#include<stdio.h>
#include<stdlib.h>

int N = 100000; // max size of main string
int M = 1000; // max size of search string

int main()
{
    char a[N]; // main string
    char b[M]; // search string
    char c;    // char for easy input
    int len_a = 0; // length of a
    int len_b = 0; // length of b

    // input main string following a 'new line char'
    c = getchar();
    while (c != '\n') {
        a[ len_a++ ] = c;
        c = getchar();
    }
    a[len_a] = '\0';

    // input search string following a 'new line char'
    c = getchar();
    while (c != '\n') {
        b[ len_b++ ] = c;
        c = getchar();
    }
    b[len_b] = '\0';

    // configure string b for efficient search
    int i = 1;
    int j = 0;
    int val[ len_b ];
    val[0] = 0;
    while (i < len_b) {
        if (b[j] != b[i]) {
            val[i++] = 0;
            if(j) i--;
            j = j==0? 0:val[j - 1];
        }
        else {
            val[i++] = j + 1;
            j++;
        }
    }

    // search algorithm
    // i runs on main string a
    // j runs on search string b
    i = 0;
    j = 0;
    while (i < len_a) {
        if (a[i] == b[j]) {
            i++;
            j++;
        }
        else if (j==0) {
            i++;
        }
        else {
            j = val[j-1];
        }
        if (j == len_b) {
            printf("%d\n", i - j);
            j = val[ j-1 ];
        }
    }

    return 0; 
}
