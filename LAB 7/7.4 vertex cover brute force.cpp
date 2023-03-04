//7.4 Write a program to find Vertex Cover of a Graph using brute force exhaustive search method (trying out all combinations). 
//Perform comparative analysis of approximation algorithm and exhaustive search method.

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

void vertex_cover_bruteforce(set<int> vertices, set<pair<int, int> > edges) {
    int n = vertices.size();
    int min_size = n+1;
    vector<int> min_cover;

    // Try all possible subsets of vertices as the vertex cover
    for (int mask = 0; mask < pow(2, n); mask++) {
        vector<int> cover;
        for (int i = 0; i < n; i++) {
            if (mask & (1<<i)) {
                cover.push_back(i);
            }
        }

        // Check if the current subset is a valid vertex cover
        bool is_cover = true;
        for (auto e : edges) {
            if (find(cover.begin(), cover.end(), e.first) == cover.end() &&
                find(cover.begin(), cover.end(), e.second) == cover.end()) {
                is_cover = false;
                break;
            }
        }

        // Update the minimum vertex cover found so far
        if (is_cover && cover.size() < min_size) {
            min_size = cover.size();
            min_cover = cover;
        }
    }

    cout << "Minimum Vertex Cover: ";
    for (auto v : min_cover) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    // Example usage
    set<int> vertices = {0, 1, 2, 3};
    set<pair<int, int> > edges = {{0,1}, {0,2}, {1,2}, {1,3}, {2,3}};

    vertex_cover_bruteforce(vertices, edges);

    return 0;
}



