#include<iostream>


//ֻ����һ�׺����׵�ʱ��ע������˼·
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

//��̬n������
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


//����д����û�н��еݹ飬�ݹ�Ӱ������


int main()
{
	std::cout << FrogJump(7) << std::endl;
	system("pause");
	return 0;
}