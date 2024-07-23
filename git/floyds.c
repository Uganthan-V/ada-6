#include <stdio.h>
#define INF 999
int min(int a, int b) {
    return (a < b) ? a : b;
}

void floyd(int p[][10], int n) {
    int i, j, k;
    // Applying Floyd-Warshall algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (p[i][k] != INF && p[k][j] != INF) {
                    // Check for integer overflow
                    if (p[i][j] > p[i][k] + p[k][j]) {
                        p[i][j] = p[i][k] + p[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int a[10][10], n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for infinity/absence of edge):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (i != j && a[i][j] == 0) {
                a[i][j] = INF; // Initialize non-diagonal zeros as infinity
            }
        }
    }
    floyd(a, n);
    printf("\nShortest distance matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
