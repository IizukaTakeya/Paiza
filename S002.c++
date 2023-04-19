#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <numeric>
#pragma warning(disable:4996)
using namespace std;
vector<int> directX = { 1,-1,0,0 }, directY = { 0,0,-1,1 };
struct Node
{
	int x, y, dis;
	Node(int x, int y, int dis) :x(x), y(y), dis(dis) {};
};
bool legal(vector<vector<int>>& road, vector<vector<int>>& visit, int x, int y)
{
	if (x < 0 || x >= road.size() || y < 0 || y >= road[0].size() || road[x][y] == 1 || visit[x][y] != 99999999)
	{
		return false;
	}
	return true;
}
int main()
{
	int n = 0, m = 0, beginX = 0, beginY = 0, endX = 0, endY = 0, ans = -1;
	cin >> n >> m;
	vector<vector<int>> road(m, vector<int>(n, 0)), flag(m, vector<int>(n, -1));
	vector<vector<vector<int>>> visit(2, vector<vector<int>>(m, vector<int>(n, 99999999)));
	for (int i = 0; i < road.size(); i++)
	{
		for (int j = 0; j < road[0].size(); j++)
		{
			string s;
			s.resize(1);
			scanf("%s", &s[0]);
			if (s == "s")
			{
				beginX = i;
				beginY = j;
			}
			else if (s == "g")
			{
				endX = i;
				endY = j;
			}
			else
			{
				road[i][j] = stoi(s);
			}
		}
	}
	queue<Node> qBegin, qEnd;
	qBegin.push(Node(beginX, beginY, 0));
	while (!qBegin.empty())
	{
		visit[0][qBegin.front().x][qBegin.front().y] = min(visit[0][qBegin.front().x][qBegin.front().y], qBegin.front().dis);
		if (visit[0][endX][endY] < 99999998)
		{
			cout << visit[0][endX][endY];
			return 0;
		}
		for (int i = 0; i < 4; i++)
		{
			if (legal(road, visit[0], qBegin.front().x + directX[i], qBegin.front().y + directY[i]))
			{
				visit[0][qBegin.front().x + directX[i]][qBegin.front().y + directY[i]] = 99999998;
				qBegin.push(Node(qBegin.front().x + directX[i], qBegin.front().y + directY[i], qBegin.front().dis + 1));
			}
		}
		qBegin.pop();
	}
	cout << "Fail";
	return 0;
}
