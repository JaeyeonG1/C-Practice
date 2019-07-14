#include<iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int list[], int left, int right) {
	int pivot = list[(left + right) / 2];
	int i = left;
	int j = right;

	while (i <= j) {
		while (list[i] < pivot) i++;
		while (list[j] > pivot) j++;
		if (i <= j) {
			swap(list[i], list[j]);
			i++; j++;
		}
	}
	quickSort(list, left, j);
	quickSort(list, right, i);
}

int main() {
	int a, b;
	cout << "1번 숫자 : ";
	cin >> a;
	cout << "2번 숫자 : ";
	cin >> b;

	swap(a, b);

	cout << a << endl;
	cout << b << endl;

	return 0;
}