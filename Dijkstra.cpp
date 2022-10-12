#include<iostream>
#include<vector>
#include<queue>
#include <ctime>
using namespace std;
#define INF 100000000 //1억을 설정. 무한을 의미

// 노드의 개수(n), 간선의 개수(m), 시작 노드 번호(start)
int n, m, start;

vector<pair<int, int> > graph[100001]; // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
int distanc[100001]; // 최단 거리 테이블

void dijkstra(int start)
{
	priority_queue<pair<int, int>>pq; // 거리, 노드 인덱스

	pq.push({ 0,start }); //시작 노드로 가기위한 최단 경로는 0으로 설정하고, 큐에 삽입.
	distanc[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first; // 현재 노드까지의 거리
		int now = pq.top().second; // 현재 노드
		pq.pop();

		if (distanc[now] < dist) // dist보다 짧은 경로가 이미 발견된 경우 continue
			continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = dist + graph[now][i].second; // 현재노드까지 거리 + 다음 노드 거리
			if (cost < distanc[graph[now][i].first]) // 거리가 더 짧다면 distanc[] 갱신
			{
				distanc[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main(void)
{
	cin >> n >> m >> start;
	// 노드의 개수(n), 간선의 개수(m), 시작 노드 번호(start)
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		// a번 노드에서 b번 노드로 가는 거리가 c
		graph[a].push_back({ b, c });
	}
	// 최단 거리 테이블을 모두 INF로 초기화
	fill(distanc, distanc + 100001, INF);

	clock_t startime, endtime;
	startime = clock();
	dijkstra(start);
	endtime = clock();
	float res = (float)(endtime - startime);
	// 모든 노드로 가기 위한 최단 거리를 출력
	for (int i = 1; i < n; i++)
	{
		// 도달할 수 없는 경우
		if (distanc[i] == INF) {
			cout << start << " -> " << i << " : " << "도달 불가\n";
		}
		// 도달할 수 있는 경우 거리를 출력
		else {
			cout << start << " -> " << i << " : " << distanc[i] << "\n";
		}
	}

	cout << "\n 실행 시간 : " << res << "\n";
	cout << "12151641 홍인호\n";
}