#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	/**
	 * @param m: An integer m denotes the size of a backpack
	 * @param A: Given n items with size A[i]
	 * @param V: Given n items with value V[i]
	 * @return: The maximum value
	 */
	int backPackII(int m, vector<int> &A, vector<int> &V) {
		// write your code here
		if (A.empty() || V.empty() || m < 1)//前提条件
		{
			return 0;
		}
		size_t asize = A.size();
		size_t vsize = V.size();

		vector<vector<int>> maxval(asize + 1, vector<int>(m + 1, 0));

		for (size_t i = 1; i <= asize; ++i)
		{
			for (size_t j = 1; j <= m; ++j)
			{
				if (A[i - 1] > j)//放不下
				{
					maxval[i][j] = maxval[i - 1][j];
				}
				else//放得下
				{//比较与上一个这么大位置的价值。
					maxval[i][j] = max(maxval[i - 1][j], maxval[i - 1][j - A[i - 1]] + V[i - 1]);
				}
			}
		}
		return maxval[asize][m];
	}
};

int main()
{
	int m = 10;
	vector<int> A = { 2, 3, 5, 7 };
	vector<int> V = { 1, 5, 2, 4 };
	Solution s;
	cout << s.backPackII(m, A, V) << endl;
	system("pause");
	return 0;
}

class Solution2 {
public:
	int minCut(string s) {


		if (s.empty())
		{
			return 0;
		}
		size_t size = s.size() + 1;
		vector<int> mincut(size);
		for (size_t i = 0; i < size; ++i)
		{
			mincut[i] = i - 1;
		}
		for (size_t i = 1; i < size; ++i)
		{
			for (size_t j = 0; j < i; ++j)
			{
				if (IsPalindrome(s, j, i - 1))//j+1到i是回文串
				{
					mincut[i] = min(mincut[i], 1 + mincut[j]);
				}
			}
		}
		return mincut[size - 1];
	}
	bool IsPalindrome(const string& str, int left, int right)
	{
		while (left < right)
		{
			if (str[left] != str[right])
			{
				return false;
			}
			--right;
			++left;
		}
		return true;
	}
};