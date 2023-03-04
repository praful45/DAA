//prims algorithm
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<pair<int, int> > adj[], int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(vector<pair<int, int> > adj[], int V) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> key(V, INT_MAX);
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    int src = 0;
    pq.push(make_pair(0, src));
    key[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for (auto i : adj[u]) {
            int v = i.first;
            int weight = i.second;
            if (visited[v] == false && weight < key[v]) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    cout << "Minimum Spanning Tree: " << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    int V = 5;
    vector<pair<int, int> > adj[V];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 4, 7);
    addEdge(adj, 3, 4, 9);
    primMST(adj, V);
    return 0;
}

