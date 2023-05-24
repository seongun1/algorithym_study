// 백준 1647 도시 분할 계획
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, pair<int, int>>> edges;
int parents[100001];
int result = 0;

// 부모 노드 찾기
int find_parents(int a) {
	if (parents[a] != a) {
		parents[a] = find_parents(parents[a]);
	}
	return parents[a];
}
void unionparents(int a, int b) // 두 개의 길 합치기
{
	a = find_parents(a);
	b = find_parents(b);
	if (a > b)
		parents[a] = b;
	else if (a < b)
		parents[b] = a;
}
int main() {
	int N, M; // 집의 개수 N , 길의 개수 M
	int a, b, c; // a번 집과 b번 집을 연결하는 길의 유지비가 c
	cin >> N >> M;
	// 부모 노드의 초기값 설정.
	for (int i = 0; i < N; i++)
		parents[i] = i;
	for (int i = 0; i < M; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		edges.push_back({ cost, { x, y }});
	}
	sort(edges.begin(), edges.end()); // 비용 순으로 정렬하기
	int last = 0; // 가장 비용이 큰 간선
	// 제일 큰 비용을 제거하고 2개로 만들기
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		if (find_parents(a) != find_parents(b)) {
			unionparents(a, b);
			result += cost;
			last = cost;
		}
	}
	cout << result - last << endl;
}	
