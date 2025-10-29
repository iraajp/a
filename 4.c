#include <stdio.h>
#include <string.h>

// Time Complexity: O(n*m) in the worst case (n=text length, m=pattern length). Space: O(1)

// Algorithm: Naive String Matching

int main(){
    char t[100], p[50];
    printf("Text: ");
    if (scanf("%99s", t) != 1) return 0;
    printf("Pattern: ");
    if (scanf("%49s", p) != 1) return 0;
    int n = strlen(t), m = strlen(p);
    int found = 0;
    for (int i = 0; i <= n - m; i++){
        int j;
        for (j = 0; j < m; j++) if (t[i + j] != p[j]) break;
        if (j == m) { printf("%d ", i); found = 1; }
    }
    if(found) printf("\n");
    return 0;
}
