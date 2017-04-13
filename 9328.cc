#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct door {
    int x;
    int y;
};
int n, m;
char map[103][103];
bool check[103][103];
bool keys[26];
bool door_num[26];
queue <pair<int,int>> doors[26];    //save door's position & name;
char getKeys[26];
 
int dollar = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int key_num;
void find_dollar(int x, int y)
{
    check[x][y] = true;
    queue <pair<int, int>> q;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        int px = q.front().first;
        int py = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = px + dx[i];
            int ny = py + dy[i];
            if (nx<0 || ny<0 || nx>n + 2 || ny>m + 2)
                continue;
            if (map[nx][ny] == '.' && !check[nx][ny])
            {
                check[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
            else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z' && !check[nx][ny])
            {
                int tag = map[nx][ny] - 'a';
 
                keys[tag] = true;
                q.push(make_pair(nx, ny));
                if (door_num[tag] == true)
                {
                    while (!doors[tag].empty())
                    {
                        q.push(make_pair(doors[tag].front().first, doors[tag].front().second));
                        doors[tag].pop();
                    }
                }
                map[nx][ny] = '.';
            }
            else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z' && !check[nx][ny])
            {
                int tag = map[nx][ny] - 'A';
                if (keys[tag] == true)
                {
                    map[nx][ny] = '.';
                    q.push(make_pair(nx, ny));
                }
                else {
                    doors[tag].push(make_pair(nx, ny));
                }
                door_num[tag] = true;
            }
            else if (map[nx][ny] == '$' && !check[nx][ny])
            {
                map[nx][ny] = '.';
                dollar++;
                check[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &n, &m);
        string nowKeys = "";
        dollar = 0;
        key_num = 0;
        for (int i = 0; i < 26; i++)
        {
            door_num[i] = false;
            keys[i] = false;
        }
        for (int i = 0; i < 26; i++)
        {
            if (doors[i].empty())
                continue;
            else
            {
                while (!doors[i].empty())
                {
                    doors[i].pop();
                }
            }
        }
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                check[i][j] = false;
                map[i][j] = '.';
            }
        }
        //Map input();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> map[i][j];
 
        cin >> nowKeys;
 
        for (char c : nowKeys) {
            keys[c - 'a'] = true;
        }
 
        find_dollar(0, 0);
        cout << dollar << endl;
    }
    return 0;
}
