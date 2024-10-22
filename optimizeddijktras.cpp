#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int source, vector<vector<pair<int, int>>>& graph, vector<int>& distances) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distances[node])
            continue;

        for (auto& edge : graph[node]) {
            int nextNode = edge.first;
            int weight = edge.second;
            if (distances[node] + weight < distances[nextNode]) {
                distances[nextNode] = distances[node] + weight;
                pq.push({distances[nextNode], nextNode});
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> graph(V);
    graph[0].push_back({1, 10});
    graph[0].push_back({2, 5});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 3});
    graph[2].push_back({3, 9});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 4});
    graph[4].push_back({3, 6});

    vector<int> distances(V, INF);
    dijkstra(0, graph, distances);

    for (int i = 0; i < V; i++) {
        if (distances[i] == INF) cout << "INF ";
        else cout << distances[i] << " ";
    }

    return 0;
}
