#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define INF INT_MAX

void printPath(vector<int>& path) {
    for (int i = 0; i < path.size(); i++) {
        cout << (char)('A' + path[i]);
        if (i != path.size() - 1) {
            cout << " -> ";
        }
    }
}

void dijkstra(vector<vector<int>>& graph, int start, int n) {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    
    dist[start] = 0;
    
    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        
        if (dist[u] == INF) break;
        visited[u] = true;
        
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    // Reconstruct path for TSP (simplified approach)
    vector<int> path;
    int current = start;
    vector<bool> visitedNodes(n, false);
    path.push_back(current);
    visitedNodes[current] = true;
    
    while (path.size() < n) {
        int next = -1;
        int minDist = INF;
        
        for (int v = 0; v < n; v++) {
            if (!visitedNodes[v] && graph[current][v] > 0 && graph[current][v] < minDist) {
                minDist = graph[current][v];
                next = v;
            }
        }
        
        if (next == -1) break;
        
        path.push_back(next);
        visitedNodes[next] = true;
        current = next;
    }
    
    // Return to start if possible
    if (graph[current][start] > 0) {
        path.push_back(start);
    }
    
    // Calculate total distance
    int totalDistance = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        totalDistance += graph[path[i]][path[i+1]];
    }
    
    cout << "\nHasil TSP (Dijkstra):\n";
    cout << "Rute terpendek: ";
    printPath(path);
    cout << "\nTotal jarak: " << totalDistance << endl;
}

int main() {
    cout << "Nama: [Heru Dwi Setiawan]\n";
    cout << "NIM: 23533823\n";
    cout << "=== Traveling Salesman Problem (Dijkstra) ===\n";
    
    // Berdasarkan NIM 23533823
    // A(0), B(1), C(2), D(3), E(4), F(5), G(6)
    int n = 7;
    vector<vector<int>> graph = {
        {0, 3, 5, 0, 0, 0, 0},  // A (digit 2,3,5)
        {3, 0, 3, 0, 0, 0, 0},   // B (digit 3,3)
        {5, 3, 0, 8, 0, 0, 0},   // C (digit 5,3,8)
        {0, 0, 8, 0, 2, 0, 0},   // D (digit 8,2)
        {0, 0, 0, 2, 0, 3, 0},   // E (digit 2,3)
        {0, 0, 0, 0, 3, 0, 2},   // F (digit 3,2)
        {0, 0, 0, 0, 0, 2, 0}    // G (digit 2)
    };
    
    // Tampilkan graf
    cout << "Matriks Graf:\n";
    cout << "  A B C D E F G\n";
    char labels[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    for (int i = 0; i < n; i++) {
        cout << labels[i] << " ";
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 0) {
                cout << "- ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    dijkstra(graph, 0, n);
    
    return 0;
}