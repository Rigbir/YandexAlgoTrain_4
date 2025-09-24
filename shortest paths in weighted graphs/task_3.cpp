//
// Created by Marat on 23.09.25.
//

#include <iostream>
#include <vector>
#include <set>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<long long, long long>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        long long u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    long long s, f;
    std::cin >> s >> f;

    std::vector<long long> dist(n + 1, 1e18);
    dist[s] = 0;

    std::set<std::pair<long long, long long>> q;
    q.insert({dist[s], s });

    while (!q.empty()) {
        long long nearest = q.begin()->second;
        q.erase(q.begin());

        for (auto& [to, weight] : graph[nearest]) {
            if (dist[to] > dist[nearest] + weight) {
                q.erase({ dist[to], to });
                dist[to] = dist[nearest] + weight;
                q.insert({ dist[to], to });
            }
        }
    }

    if (dist[f] == 1e18) std::cout << -1;
    else std::cout << dist[f];
}