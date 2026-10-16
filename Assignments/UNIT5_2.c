#include <stdio.h>

#define MAX 20
#define INF 99999

int main() {
    int graph[MAX][MAX];
    int distance[MAX];
    int visited[MAX] = {0};
    int n, source;
    int i, j, count, min, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the weighted adjacency matrix:\n");
    printf("Enter 0 if there is no direct road between two vertices.\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    printf("Enter source vertex (1 to %d): ", n);
    scanf("%d", &source);
    source--;

    for (i = 0; i < n; i++) {
        distance[i] = graph[source][i];
    }

    distance[source] = 0;
    visited[source] = 1;

    for (count = 1; count < n; count++) {
        min = INF;
        next = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                next = i;
            }
        }

        if (next == -1)
            break;

        visited[next] = 1;

        for (i = 0; i < n; i++) {
            if (!visited[i] &&
                graph[next][i] != INF &&
                distance[next] + graph[next][i] < distance[i]) {

                distance[i] = distance[next] + graph[next][i];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source + 1);

    for (i = 0; i < n; i++) {
        if (distance[i] == INF)
            printf("Destination %d : Not reachable\n", i + 1);
        else
            printf("Destination %d : %d\n", i + 1, distance[i]);
    }

    return 0;
}
