#include <iostream>
#include <algorithm>
using namespace std;

int n;
int map[21][21];
int ans = 0;
void solve(int step)
{
	if (step == 5)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans = max(ans, map[i][j]);
		return;
	}
	int temp[21][21];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[i][j] = map[i][j];

	for (int dir = 0; dir < 4; dir++) {
		if (dir == 0)	
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = n - 1; j > 0; j--)
				{
					for (int k = j - 1; k >= 0; k--)
					{
						if (map[i][j] == 0)
						{
							map[i][j] = map[i][k];
							map[i][k] = 0;
						}
						else if (map[i][j] > 0)
						{
							if (map[i][k] == map[i][j])
							{
								map[i][j] = map[i][k] * 2;
								map[i][k] = 0;
								break;
							}
							else if (map[i][k] != map[i][j])
							{
								if (map[i][k] == 0)
									continue;
								else
									break;
							}
						}
					}
				}
			}
		}
		if (dir == 1)	//<<
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n - 1; j++)
				{
					for (int k = j + 1; k <= n - 1; k++)
					{
						if (map[i][j] == 0)
						{
							map[i][j] = map[i][k];
							map[i][k] = 0;
						}
						else if (map[i][j] > 0)
						{
							if (map[i][k] == map[i][j])
							{
								map[i][j] = map[i][k] * 2;
								map[i][k] = 0;
								break;
							}
							else if (map[i][k] != map[i][j])
							{
								if (map[i][k] == 0)
									continue;
								else
									break;
							}
						}
					}
				}
			}
		}
		else if (dir == 2)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = n - 1; j >0; j--)
				{
					for (int k = j - 1; k >= 0; k--)
					{
						if (map[j][i] == 0)
						{
							map[j][i] = map[k][i];
							map[k][i] = 0;
						}
						else if (map[j][i] > 0)
						{
							if (map[k][i] == map[j][i])
							{
								map[j][i] = map[k][i] * 2;
								map[k][i] = 0;
								break;
							}
							else if (map[k][i] != map[j][i])
							{
								if (map[k][i] == 0)
									continue;
								else
									break;
							}
						}
					}
				}
			}

		}
		else if (dir == 3)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j <n - 1; j++)
				{
					for (int k = j + 1; k <= n - 1; k++)
					{
						if (map[j][i] == 0)
						{
							map[j][i] = map[k][i];
							map[k][i] = 0;
						}
						else if (map[j][i] > 0)
						{
							if (map[k][i] == map[j][i])
							{
								map[j][i] = map[k][i] * 2;
								map[k][i] = 0;
								break;
							}
							else if (map[k][i] != map[j][i])
							{
								if (map[k][i] == 0)
									continue;
								else
									break;
							}
						}
					}
				}
			}
		}
		
		solve(step + 1);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map[i][j] = temp[i][j];
	}
	return;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	solve(0);
	printf("%d\n", ans);
}
