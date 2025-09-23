//
// Created by Marat on 23.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n, s, f;
    std::cin >> n >> s >> f;

    std::vector<std::vector<int>> matrix(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<bool> visited(n + 1, false);
    std::vector<int> dist(n + 1, 1e9);
    dist[s] = 0;

    for (int i = 1; i <= n; ++i) {
        int nearest = -1;
        for (int v = 1; v <= n; ++v) {
            if (!visited[v] && (nearest == -1 || dist[nearest] > dist[v])) {
                nearest = v;
            }
        }

        if (dist[nearest] == 1e9) break;
        visited[nearest] = true;

        for (int to = 1; to <= n; ++to) {
            if (matrix[nearest][to] != -1) {
                dist[to] = std::min(dist[to], dist[nearest] + matrix[nearest][to]);
            }
        }
    }

    if (dist[f] == 1e9) std::cout << -1;
    else std::cout << dist[f];
}