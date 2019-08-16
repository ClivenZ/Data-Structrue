#pragma once
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//QuickSort
//Hoare
template <class T>
void Swap(T* a, T* b);
int partitionH(int* data, int left, int right);
void quickSortRecusiveH(int* data, int left, int right);
void quickSortNorecusiveH(int* data, int left, int right);
//ÍÚ¿Ó
int partitionW(int* arr, int left, int right);
void quickSortRecusiveW(int* arr, int left, int right);
void quickSortNorecusiveW(int* arr, int left, int right);
//Ë«Ö¸Õë
int partitionZ(int* data, int left, int right);
void quickSortNorecusiveZ(int* arr, int left, int right);
void quickSortRecusiveZ(int* arr, int left, int right);