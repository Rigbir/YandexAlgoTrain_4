//
// Created by Marat on 23.09.25.
//

#include <iostream>
#include <vector>
#include <set>

struct Bus {
    int from;
    int departure;
    int to;
    int arrival;
};

int main() {
    int n, d, v, r;
    std::cin >> n >> d >> v >> r;

    std::vector<std::vector<Bus>> graph(n + 1);
    for (int i = 0; i < r; ++i) {
        Bus b;
        std::cin >> b.from >> b.departure >> b.to >> b.arrival;
        graph[b.from].push_back(b);
    }

    std::vector<int> dist(n + 1, 1e9);
    dist[d] = 0;

    std::set<std::pair<int, int>> q;
    q.insert({0, d});

    while (!q.empty()) {
        auto [currentTime, nearest] = *q.begin();
        q.erase(q.begin());

        for (auto& bus : graph[nearest]) {
            if (bus.departure >= currentTime && dist[bus.to] > bus.arrival) {
                q.erase({dist[bus.to], bus.to });
                dist[bus.to] = bus.arrival;
                q.insert({dist[bus.to], bus.to });
            }
        }
    }

    if (dist[v] == 1e9) std::cout << -1;
    else std::cout << dist[v];
}