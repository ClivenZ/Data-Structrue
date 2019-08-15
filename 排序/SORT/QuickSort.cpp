#include "Header.hpp"

/***********************
*	Hoare方法           *
***********************/
template <class T> 
void Swap(T& a, T& b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int partitionH(int* data, int left, int right)
{	
	int pivot = right;
	while (left < right) {
		while (left < right && data[left] <= data[pivot])
			++left;
		while (left < right && data[right] >= data[pivot])
			--right;
		Swap(data[left], data[right]);
	}
	Swap(data[left], data[pivot]);
	return pivot;
}
//递归
void quickSortRecusiveH(int* data, int left, int right){
	if (data == NULL || left < 0 || right <= 0 || left > right)
		return;
	int pivot = partitionH(data,left,right);
	if (pivot > left)
		quickSortRecusiveH(data, left, pivot - 1);
	if (pivot < right)
		quickSortRecusiveH(data, pivot + 1, right);
	
}
//非递归实现
void quickSortNorecusiveH(int* data, int left, int right)
{
	if (data == NULL || left < 0 || right <= 0 || left > right)
		return;
	stack<int> s;
	int l, r;
	s.push(right);
	s.push(left);
	while (!s.empty()) {
		l = s.top();
		s.pop();
		r = s.top();
		s.pop();
		if (l < r) {
			int povit = partitionH(data, l, r);
			if (povit > l) {
				s.push(povit - 1);
				s.push(l);
			}
			if (r > povit) {
				s.push(r);
				s.push(povit + 1);
			}
		}
	}

}
/***********************
*	挖坑方法             *
***********************/
int partitionW(int* arr,int left,int right) {
	int pivot = arr[left];
	int index = left;
	while (left < right) {
		while (right != index) {
			if (arr[right] < pivot) {
				arr[index] = arr[right];
				index = right;
				++left;
			}
			else
				--right;
		}
		while (left != index) {
			if (arr[left] > pivot) {
				arr[index] = arr[left];
				index = left;
				--right;
			}
			else
				++left;
		}
	}
	arr[index] = pivot;
	return index;
}
//递归
void quickSortRecusiveW(int* data,int left,int right) {
	if (data == NULL || left < 0 || right <= 0 || left >right)
		return;
	int pos = partitionW(data, left, right);
	//左右
	if(left < pos)
	quickSortRecusiveW(data, left, pos - 1);
	quickSortRecusiveW(data, pos + 1, right);
}
//非递归
void quickSortNorecusiveW(int* data, int left, int right) {
	if (data == NULL || left < 0 || right <= 0 || left > right)
		return;
	stack<int> s;
	int l, r;
	s.push(right);
	s.push(left);
	while (!s.empty()) {
		l = s.top();
		s.pop();
		r = s.top();
		s.pop();
		if (l < r) {
			int pos = partitionW(data, l, r);
			if (l < pos) {
				s.push(pos - 1);
				s.push(l);
			}
			if (r > pos) {
				s.push(r);
				s.push(pos + 1);
			}
		}
	}
}

/***********************
*	双指针方法           *
***********************/
int partitionZ(int* data, int left, int right) {
	int pivot = data[left];
	while (left < right) {
		while (left < right) {
			if (data[right] < pivot)
				break;
			--right;
		}
		while (left < right) {
			if (data[left] > pivot)
				break;
			++left;
		}
		if(left < right)
			Swap(data[left], data[right]);
	}
	Swap(data[left], pivot);
	return left;
}
//递归
void quickSortRecusiveZ(int* data, int left, int right) {
	if (data == NULL || left < 0 || right <= 0 || left > right)
		return;
	int pos = partitionZ(data, left, right);

	if(left < pos)
		quickSortRecusiveZ(data, left, pos - 1);
	if(right > pos)
		quickSortRecusiveZ(data, pos + 1, right);
}
//非递归
void quickSortNorecusiveZ(int* data, int left, int right) {

}