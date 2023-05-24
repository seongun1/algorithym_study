#include <iostream>
int team[100001];
using namespace std;
void union_team(int a, int b);
int find_team(int a);
void is_same_team(int a, int b);
int main() {
	int N, M; // M: 입력으로 주어지는 연산의 개수
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		team[i] = i; // 각각의 개인은 각자의 팀이 있다.
	}
	for (int i = 0; i < M; i++) {
		int x, a, b; // 팀 합치기  : x=0 , 같은 팀 여부 확인 : x= 1
		cin >> x >> a >> b;
		if (x == 0) // 팀 합치기
		{
			union_team(a, b);
		}
		else if (x == 1) // 같은 팀 여부 확인 -> YES or NO 
		{
			is_same_team(a, b);
		}
	}
}
void union_team(int a, int b) // a 와 b 가 같은 팀으로 합치기
{
	if (find_team(a) > find_team(b))
		team[a] = b;
	else if (find_team(a) < find_team(b))
		team[b] = a;
}
int find_team(int a) // 누구 팀인지 알아내기
{
	if (team[a] != a)
		team[a] = find_team(team[a]);
	return team[a];
}
void is_same_team(int a, int b)  // 같은 팀 여부 확인
{
	if (find_team(a) == find_team(b))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;	
}
