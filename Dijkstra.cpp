#include<iostream>
#include<vector>
#include<queue>
#include <ctime>
using namespace std;
#define INF 100000000 //1���� ����. ������ �ǹ�

// ����� ����(n), ������ ����(m), ���� ��� ��ȣ(start)
int n, m, start;

vector<pair<int, int> > graph[100001]; // �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� �迭
int distanc[100001]; // �ִ� �Ÿ� ���̺�

void dijkstra(int start)
{
	priority_queue<pair<int, int>>pq; // �Ÿ�, ��� �ε���

	pq.push({ 0,start }); //���� ���� �������� �ִ� ��δ� 0���� �����ϰ�, ť�� ����.
	distanc[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first; // ���� �������� �Ÿ�
		int now = pq.top().second; // ���� ���
		pq.pop();

		if (distanc[now] < dist) // dist���� ª�� ��ΰ� �̹� �߰ߵ� ��� continue
			continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = dist + graph[now][i].second; // ��������� �Ÿ� + ���� ��� �Ÿ�
			if (cost < distanc[graph[now][i].first]) // �Ÿ��� �� ª�ٸ� distanc[] ����
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
	// ����� ����(n), ������ ����(m), ���� ��� ��ȣ(start)
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		// a�� ��忡�� b�� ���� ���� �Ÿ��� c
		graph[a].push_back({ b, c });
	}
	// �ִ� �Ÿ� ���̺��� ��� INF�� �ʱ�ȭ
	fill(distanc, distanc + 100001, INF);

	clock_t startime, endtime;
	startime = clock();
	dijkstra(start);
	endtime = clock();
	float res = (float)(endtime - startime);
	// ��� ���� ���� ���� �ִ� �Ÿ��� ���
	for (int i = 1; i < n; i++)
	{
		// ������ �� ���� ���
		if (distanc[i] == INF) {
			cout << start << " -> " << i << " : " << "���� �Ұ�\n";
		}
		// ������ �� �ִ� ��� �Ÿ��� ���
		else {
			cout << start << " -> " << i << " : " << distanc[i] << "\n";
		}
	}

	cout << "\n ���� �ð� : " << res << "\n";
	cout << "12151641 ȫ��ȣ\n";
}