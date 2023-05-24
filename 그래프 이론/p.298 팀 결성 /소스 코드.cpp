//학교에서 학생들에게 0번부터 N번까지의 번호를 부여했다.처음에는 모든 학생이 서로 다른 팀으로 구분되어, 총 N + 1 개의 팀이 존재한다.이때 선생님은 '팀 합치기'연산과 '같은 팀 여부 확인'연산을 사용할 수 있다.
//
//'팀 합치기' 연산은 두 팀을 합치는 연산이다.
//'같은 팀 여부 확인' 연산은 특정한 두 학생이 같은 팀에 속하는지를 확인하는 연산이다.
//선생님이 M개의 연산을 수행할 수 있을 때, '같은 팀 여부 확인'연산에 대한 연산 결과를 출력하는 프로그램을 작성하시오.
//
//첫째 줄에 N, M이 주어진다.M은 입력으로 주어지는 연산의 개수이다. (1 <= N, M <= 100, 000)
//다음 M개의 줄에는 각각의 연산이 주어진다.
//'팀 합치기' 연산은 0 a b 형태로 주어진다.이는 a번 학생이 속한 팀과 b번 학생이 속한 팀을 합친다는 의미이다.
//'같은 팀 여부 확인' 연산은 1 a b 형태로 주어진다.이는 a번 학생과 b번 학생이 같은 팀에 속해 있는지를 확인하는 연산이다.
//a와 b는 N 이하의 양의 정수이다.
//'같은 팀 여부 확인'연산에 대하여 한 줄에 하나씩 YES 혹은 NO로 결과를 출력한다.
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
