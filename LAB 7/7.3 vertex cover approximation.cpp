//7.3 vertex cover of graph using approximation algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

vector<int> vertex_cover_approx(map<int, set<int> > graph) {
    vector<int> vertex_cover;
    vector<pair<int, int> > edges;

    // Convert the input graph to a list of edges
    for (auto it = graph.begin(); it != graph.end(); ++it) {
        int u = it->first;
        for (auto v : it->second) {
            edges.push_back(make_pair(u, v));
        }
    }

    while (!edges.empty()) {
        // Select an arbitrary edge and add its endpoints to the vertex cover
        int u = edges.back().first;
        int v = edges.back().second;
        edges.pop_back();
        vertex_cover.push_back(u);
        vertex_cover.push_back(v);

        // Remove any edges that are now covered by the selected vertices
        auto it = remove_if(edges.begin(), edges.end(), [&](pair<int, int> e){
            return (e.first == u || e.first == v || e.second == u || e.second == v);
        });
        edges.erase(it, edges.end());
    }

    return vertex_cover;
}

int main() {
    // Example usage
    map<int, set<int> > graph;
    graph[0].insert(1);
    graph[0].insert(2);
    graph[1].insert(0);
    graph[1].insert(2);
    graph[1].insert(3);
    graph[2].insert(0);
    graph[2].insert(1);
    graph[2].insert(3);
    graph[3].insert(1);
    graph[3].insert(2);

    vector<int> vc = vertex_cover_approx(graph);

    cout << "Vertex Cover: ";
    for (auto v : vc) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}

