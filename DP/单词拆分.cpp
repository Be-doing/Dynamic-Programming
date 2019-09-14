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
		unordered_map<string, bool> mp;//��Ϊ�������vector��Ϊ�����Ч�ʣ����ù�ϣ
		vector<bool> res(s.size() + 1, false);
		res[0] = true;//��һ���ַ���֪���ǲ������ֵ������һ��״̬

		size_t maxsize = 0;//�Ż�
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
				if (i - j > maxsize)//��ǰ���ȵ��ִ�����maxsize˵������ĵ��ʵĳ��ȶ���������ֵ䵥��
				{
					break;
				}
				if (res[j] && mp[s.substr(j, i - j)])//���ģ����ǰ j ���ַ����ַ����ܱ����
				{												//�Һ�i - j���ַ�Ҳ�ܱ���֣���ô��ǰ i ���ַ����ַ������ܱ���ֵ�
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
				if (j == 0)//����߽�����
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

//����˼ά����
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