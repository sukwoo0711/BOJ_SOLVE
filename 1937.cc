#include <stdio.h>
int n,ans;
int dp[501][501];
int map[501][501];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y)
{
	//재귀 종료조건 : 1.x와y가 범위내가 아닐 경우 2.대나무가 많은 땅이 없을경우
	int depth = 0;
	for (int i = 0; i < 4; i++)
	{
		//4방향으로 퍼져보자.
		int nx = x + dx[i];
		int ny = y + dy[i];
		//재귀 종료조건 1을 충족시키기 위해 진행을 하지않음
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
		//대나무가 더 많은땅이 있을 시
		if (map[nx][ny] > map[x][y])
		{
			//방문을 한 적이 없어서 dp[다음지역] 이 0 일때
			if (dp[nx][ny] == 0)
			{
				//해당 지역으로 방문한다.
				dfs(nx, ny);
			}
			/*
				주변에 있는 모든 대나무를 다 먹고
				맨 마지막 지점에서 재귀가 풀려 아래코드를 실행한다.
			*/
			if (depth < dp[nx][ny])
				depth = dp[nx][ny];
		}
	}//map[x][y]에서 배열의 값을 갱신한다.
	dp[x][y] = depth + 1;	//가장 마지막 위치에서 갱신하므로 
	if (dp[x][y] > ans)
		ans = dp[x][y];
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dfs(i, j);
	printf("%d\n", ans);
	return 0;
}
