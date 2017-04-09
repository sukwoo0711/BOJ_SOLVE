#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int n, k;
struct p {
	int num;
	int age;
	string name;
};
vector<p> table;
bool cmp(const p &u, const p &v)
{
	if (u.age < v.age)
		return true;
	else if (u.age == v.age)
	{
		if (u.num < v.num)
			return true;
		else
			return false;
	}
	else
		return false;
}
int main()
{
	scanf("%d", &n);
	table.resize(n);
	for (int i = 0; i < n; i++)
	{
		int _age;
		string _name = "";
		cin >> _age >> _name;
		table[i].age = _age;
		table[i].name = _name;
		table[i].num = i;
	}
	sort(table.begin(), table.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		cout << table[i].age << " " << table[i].name <<'\n';
	}
}
