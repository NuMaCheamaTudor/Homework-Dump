#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void addEdge(vector<set<int>>& adjList, int u, int v) {
    adjList[u].insert(v);
    adjList[v].insert(u);
}

void findThreeCycles(const vector<set<int>>& adjList) {
    int n = adjList.size();
    set<vector<int>> uniqueCycles;

    for (int u = 0; u < n; ++u) {
        for (int v = u + 1; v < n; ++v) {
            if (adjList[u].find(v) != adjList[u].end()) {
                for (int w = v + 1; w < n; ++w) {
                    if (adjList[v].find(w) != adjList[v].end() && adjList[u].find(w) != adjList[u].end()) {
                        vector<int> cycle = {u, v, w};
                        sort(cycle.begin(), cycle.end());
                        uniqueCycles.insert(cycle);
                    }
                }
            }
        }
    }

    cout << "Numarul total: " << uniqueCycles.size() << "\n";
    cout << "3-ciclurile din graf sunt:\n";
    for (const auto& cycle : uniqueCycles) {
        cout << "{" << cycle[0] << ", " << cycle[1] << ", " << cycle[2] << "}\n";
    }
}

int main() {
    int n = 6;
    vector<set<int>> adjList(n);

    for (int u = 0; u < n; ++u) {
        for (int v = u + 1; v < n; ++v) {
            addEdge(adjList, u, v);
        }
    }

    adjList[1].erase(2);
    adjList[2].erase(1);

    findThreeCycles(adjList);

    return 0;
}
