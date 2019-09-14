#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution1 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if (s.size() == 0 || wordDict.empty())
		{
			return false;
		}
		unordered_map<string, bool> mp;//因为传入的是vector，为了提高效率，采用哈希
		vector<bool> res(s.size() + 1, false);
		res[0] = true;//第一个字符不知道是不是在字典里，假设一个状态

		size_t maxsize = 0;//优化
		for (const auto& str : wordDict)
		{
			if (str.size() > maxsize)
			{
				maxsize = str.size();
			}
			mp[str] = true;
		}

		for (size_t i = 1; i <= s.size(); ++i)
		{
			for (size_t j = i - 1; j != string::npos; --j)
			{
				if (i - j > maxsize)//当前长度的字串大于maxsize说明后面的单词的长度都大于最大字典单词
				{
					break;
				}
				if (res[j] && mp[s.substr(j, i - j)])//核心：如果前 j 个字符的字符串能被拆分
				{												//且后i - j个字符也能被拆分，那么当前 i 个字符的字符串是能被拆分的
					res[i] = true;
					break;
				}
			}
		}
		return res[s.size()];
	}
};

#include<algorithm>
class Solution2 {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty() || triangle[0].empty())
		{
			return 0;
		}
		for (size_t i = 1; i < triangle.size(); ++i)
		{
			for (size_t j = 0; j < triangle[i].size(); ++j)
			{
				if (j == 0)//处理边界问题
				{
					triangle[i][j] += triangle[i - 1][j];
				}
				else if (j == i)
				{
					triangle[i][j] += triangle[i - 1][j - 1];
				}
				else
				{
					triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
				}
			}
		}
		int res = triangle[triangle.size() - 1][0];
		for (auto& e : triangle[triangle.size() - 1])
		{
			if (res > e)
			{
				res = e;
			}
		}
		return res;
	}
};

//逆向思维代码
class Solution3 {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty() || triangle[0].empty())
		{
			return 0;
		}
		for (size_t i = triangle.size() - 2; i != string::npos; --i)
		{
			for (size_t j = 0; j < triangle[i].size(); ++j)
			{
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}


		return triangle[0][0];
	}
};
int main()
{
	vector<vector<int>> tmp = {
			{2},
			{3, 4},
			{6, 5, 7},
			{4, 1, 8, 3}
	};
	Solution2 s;
	s.minimumTotal(tmp);
	return 0;
}