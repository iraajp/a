#include <stdio.h>
#define INF 999

// Time Complexity: O(n^3). Space: O(n^2) for distance matrix

// Algorithm: Floyd–Warshall (All-pairs shortest paths)

int main(){
    int n;
    printf("Vertices: ");
    if (scanf("%d", &n) != 1) return 0;
    int g[n][n], i, j, k;
    printf("Adjacency matrix (%d for no edge):\n", INF);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%d", &g[i][j]);
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (g[i][k] + g[k][j] < g[i][j]) g[i][j] = g[i][k] + g[k][j];
    printf("Shortest distances:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++) printf("%s%d ", g[i][j] == INF ? "INF " : "", g[i][j]);
        printf("\n");
    }
    return 0;
}
