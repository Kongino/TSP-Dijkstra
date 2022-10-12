#include<iostream>
#include<cstring>
#include <ctime>
#define MAX 24 // 24보다 클 경우 에러 발생
#define INF 987654321
using namespace std;

/* 전역변수 선언 */
int N, Answer_Bit;
int MAP[MAX][MAX];
int Cost[MAX][1 << MAX];

int Min(int A, int B) { if (A < B) return A; return B; }
/* Bit Masking DP 방식을 이용*/

int TSP(int Node, int Bit)
{
	if (Bit == Answer_Bit)
	{
		if (MAP[Node][0] == 0) return INF; 
		// Bit가 Answer_Bit에 도달했는데 MAP[Node][0] ==0인 경우. MAP[0][0]인 경우이므로 INF 리턴
		else return MAP[Node][0]; // 아닌 경우 MAP[Node][0]을 리턴
	}

	if (Cost[Node][Bit] != -1) return Cost[Node][Bit];
	Cost[Node][Bit] = INF;

	for (int i = 0; i < N; i++)
	{
		if (MAP[Node][i] == 0) continue; // MAP[][] ==0 즉, Node==i인 경우 continue
		if ((Bit & (1 << i)) == (1 << i)) continue;

		Cost[Node][Bit] = Min(Cost[Node][Bit], MAP[Node][i] + TSP(i, Bit | 1 << i));
	}
	return Cost[Node][Bit];
}

int main(void)
{
	cin >> N;
	/* 지점들의 수(N)를 입력받은 후 NxN의 표 형태로 그래프 입력 */
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
	int outt = TSP(0, 1); // 0번 점 기준, 시작 시 Bit=1
	end = clock();
	res = (float)(end - start);
	cout << "TSP 결과 : "<<outt << "\n";
	cout << "수행 시간 : " << res << "ms\n";
	cout << "\n12151641 홍인호\n";
}
