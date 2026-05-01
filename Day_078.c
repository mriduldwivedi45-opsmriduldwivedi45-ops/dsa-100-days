#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int primMST(int n, vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    vector<bool> visited(n + 1, false);
    
    pq.push({0, 1});  // {weight, node}
    
    int totalWeight = 0;
    
    while (!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (visited[node]) continue;
        
        visited[node] = true;
        totalWeight += wt;
        
        for (auto neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int edgeWt = neighbor.second;
            
            if (!visited[nextNode]) {
                pq.push({edgeWt, nextNode});
            }
        }
    }
    
    return totalWeight;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pii>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    cout << primMST(n, adj) << endl;
    
    return 0;
}
