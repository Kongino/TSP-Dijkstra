#include<iostream>
#include<cstring>
#include <ctime>
#define MAX 24 // 24���� Ŭ ��� ���� �߻�
#define INF 987654321
using namespace std;

/* �������� ���� */
int N, Answer_Bit;
int MAP[MAX][MAX];
int Cost[MAX][1 << MAX];

int Min(int A, int B) { if (A < B) return A; return B; }
/* Bit Masking DP ����� �̿�*/

int TSP(int Node, int Bit)
{
	if (Bit == Answer_Bit)
	{
		if (MAP[Node][0] == 0) return INF; 
		// Bit�� Answer_Bit�� �����ߴµ� MAP[Node][0] ==0�� ���. MAP[0][0]�� ����̹Ƿ� INF ����
		else return MAP[Node][0]; // �ƴ� ��� MAP[Node][0]�� ����
	}

	if (Cost[Node][Bit] != -1) return Cost[Node][Bit];
	Cost[Node][Bit] = INF;

	for (int i = 0; i < N; i++)
	{
		if (MAP[Node][i] == 0) continue; // MAP[][] ==0 ��, Node==i�� ��� continue
		if ((Bit & (1 << i)) == (1 << i)) continue;

		Cost[Node][Bit] = Min(Cost[Node][Bit], MAP[Node][i] + TSP(i, Bit | 1 << i));
	}
	return Cost[Node][Bit];
}

int main(void)
{
	cin >> N;
	/* �������� ��(N)�� �Է¹��� �� NxN�� ǥ ���·� �׷��� �Է� */
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}
	Answer_Bit = (1 << N) - 1;

	memset(Cost, -1, sizeof(Cost));
	clock_t start, end;
	float res;
	start = clock();
	int outt = TSP(0, 1); // 0�� �� ����, ���� �� Bit=1
	end = clock();
	res = (float)(end - start);
	cout << "TSP ��� : "<<outt << "\n";
	cout << "���� �ð� : " << res << "ms\n";
	cout << "\n12151641 ȫ��ȣ\n";
}
