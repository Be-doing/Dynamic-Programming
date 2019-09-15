#include<vector>
using namespace std;
//初始格子
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m == 1 || n == 1)
			return 1;
		vector<vector<int>> v(n);//建立一个格子保存每一个格子的走法
		for (int i = 0; i < n; ++i)
		{
			v[i].resize(m);
			v[i][0] = 1;
		}

		for (int i = 0; i < m; ++i)
		{
			v[0][i] = 1;
		}
		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j < m; ++j)
			{
				v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[n - 1][m - 1];
	}
};

//带有障碍的格子
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty())
		{
			return 0;
		}
		vector<vector<long long>> pathv(obstacleGrid.size(), vector<long long>(obstacleGrid[0].size(), 0));
		for (size_t i = 0; i < obstacleGrid.size(); ++i)
		{
			if (obstacleGrid[i][0])
			{
				break;
			}
			pathv[i][0] = 1;
		}
		for (size_t i = 0; i < obstacleGrid[0].size(); ++i)
		{
			if (obstacleGrid[0][i])
			{
				break;
			}
			pathv[0][i] = 1;
		}
		for (size_t i = 1; i < obstacleGrid.size(); ++i)
		{
			for (size_t j = 1; j < obstacleGrid[0].size(); ++j)
			{
				if (obstacleGrid[i][j])
				{
					pathv[i][j] = 0;
				}
				else
				{
					pathv[i][j] = pathv[i - 1][j] + pathv[i][j - 1];
				}
			}
		}
		return pathv[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
	}
};