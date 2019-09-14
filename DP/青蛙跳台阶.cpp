#include<iostream>


//只能跳一阶和两阶的时候，注意联想思路
size_t FrogJump(const size_t& step)
{
	if (step <= 2)
	{
		return step;
	}
	int f1 = 1;
	int f2 = 2;
	int fn = 0;
	for (size_t i = 3; i <= step; ++i)
	{
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
	}
	return fn;
}

//变态n级青蛙
size_t SuperJump(const size_t& step)
{
	if (step <= 2)
	{
		return step;
	}
	size_t ret = 2;
	for (size_t i = 3; i <= step; ++i)
	{
		ret *= 2;
	}
	return ret;
}


//上述写法都没有进行递归，递归影响性能


int main()
{
	std::cout << FrogJump(7) << std::endl;
	system("pause");
	return 0;
}