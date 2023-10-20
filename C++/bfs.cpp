#include<bits/stdc++.h>

using namespace std;

#define ll long long int

const ll INF = LLONG_MAX;

void bfs(vector<vector<int> >& graph, int source, vector<ll>& distances) {
    int n = graph.size();
    distances.assign(n, INF);

    queue<int> q;
    distances[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v: graph[u]) {
            if (distances[v] == INF) {
                distances[v] = distances[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m; // Number of nodes and edges
    cin >> n >> m;

    vector<vector<int> > graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Assuming an undirected graph
    }

    int source; // Source node
    cin >> source;

    vector<ll> distances;
    bfs(graph, source, distances);

    // Output the distances from the source node to all other nodes
    for (int i = 0; i < n; i++) {
        if (distances[i] == INF) {
            cout << "INF ";
        } else {
            cout << distances[i] << " ";
        }
    }

    return 0;
}
