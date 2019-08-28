#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;


//쳲���������
int Fibonacci(int n) {
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	//����һ�����飬����������Ľ�
	int* recond = new int[n + 1];
	recond[0] = 1;
	recond[1] = 1;
	for (int i = 2; i <= n; ++i) {
		recond[i] = recond[i - 1] + recond[i - 2];
	}
	return recond[n];
	delete[] recond;
}

//��̬��̨��
int jumpFloorII(int number) {
	//F(n) = 2 * F(n - 1)
	if (number <= 0)
		return 0;
	int* recond = new int[number + 1];
	recond[0] = 0;
	recond[1] = 1;
	for (int i = 2; i <= number; ++i) {
		recond[i] = 2 * recond[i - 1];
	}
	return recond[number];
	delete[] recond;
}

//�������������֮��
int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.empty())
		return -1;
	int sum = array[0];
	int maxsum = array[0];
	for (int i = 0; i < array.size();++i) {
		sum = (sum > 0) ? sum + array[i] : array[i];
		maxsum = (sum < maxsum) ? maxsum : sum;
	}
	return maxsum;
}



int main() {

	return 0;
}