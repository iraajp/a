#include <stdio.h>
#include <limits.h>

// Time Complexity: O(n!) brute-force backtracking (factorial). Space: O(n)

// Algorithm: Backtracking - Travelling Salesman (brute-force)

int n, cost[10][10], visited[10], ans = INT_MAX;

void tsp(int pos, int count, int sum){
    if (count == n && cost[pos][0]){
        if (sum + cost[pos][0] < ans) ans = sum + cost[pos][0];
        return;
    }
    for (int i = 0; i < n; i++)
        if (!visited[i] && cost[pos][i]){
            visited[i] = 1;
            tsp(i, count + 1, sum + cost[pos][i]);
            visited[i] = 0;
        }
}

int main(){
    printf("Enter number of cities: ");
    if (scanf("%d", &n) != 1) return 0;
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &cost[i][j]);
    for (int i = 0; i < n; i++) visited[i] = 0;
    visited[0] = 1;
    tsp(0, 1, 0);
    if (ans == INT_MAX) printf("No tour\n");
    else printf("Minimum tour cost: %d\n", ans);
    return 0;
}
