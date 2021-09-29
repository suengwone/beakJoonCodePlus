// 트리의 부모 찾기

#include <cstdio>
#include <vector>

using namespace std;

vector<bool> visited;
vector<int> parent;
vector<vector<int>> tree;

void findParent(int nodeNum) {
	visited[nodeNum] = true;

	// DFS
	for (int i = 0; i < tree[nodeNum].size(); i++) {
		int next = tree[nodeNum][i];
		
		if (!visited[next]) {
			parent[next] = nodeNum;
			findParent(next);
		}
	}
}

int main(void) {
	int N, node1, node2;
	scanf("%d", &N);

	tree = vector<vector<int>>(N + 1);
	visited = vector<bool>(N + 1);
	parent = vector<int>(N + 1);

	for (int i = 1; i < N; i++) {
		scanf("%d%d", &node1, &node2);

		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
	
	findParent(1);

	for (int i = 2; i <= N; i++) {
		printf("%d\n", parent[i]);
	}
}
