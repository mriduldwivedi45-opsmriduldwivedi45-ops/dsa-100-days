#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int n, vector<vector<pii>>& adj, int source) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    vector<int> dist(n + 1, INT_MAX);
    
    dist[source] = 0;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (currDist > dist[node]) continue;
        
        for (auto neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            
            if (dist[node] + weight < dist[nextNode]) {
                dist[nextNode] = dist[node] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pii>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});   // remove if graph is directed
    }
    
    int source;
    cin >> source;
    
    dijkstra(n, adj, source);
    
    return 0;
}
