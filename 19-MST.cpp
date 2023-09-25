//Undirected Weighted 
//Spanning Tree -> n nodes and n-1 edhges and all nodes are reachable from each other

//Prims Algo
//start from any node -> mst[], vis[], pq (wt,node,parent) => (0,0,-1)
//make vis[0]=1, check its adjNodes, push the adjNodes if !vis into Q **(take the element, mark it vis, push its adj into pq)
//get the min weight value from queue, mark that node as vis, add the wt to sum, push the parent->node into MST[]
//if node from Q is vis, do nothing, because we have already added it to mst

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
	}
};


int main() {
	int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}
