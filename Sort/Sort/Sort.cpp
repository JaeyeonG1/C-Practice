#include <iostream>

using namespace std;

void swap(int* a, int* b) {
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

void quickSort(int list[], int left, int right);

int main() {
	int arr1[10] = { 8,5,1,3,7,6,9,11,15,23 };
	int arr2[10] = { 4,7,2,9,15,23,88,45,21,10 };
	int arr3[10] = { 20,10,58,22,1,3,4,7,9,45 };
	int arr4[10] = { 11,1,22,5,8,7,15,2,3,6 };


	cout << "버블 정렬" << endl;
	// 버블 정렬
	for (int i = 9; i > 0; i--) {
		for (int j = 0; j < i; j++) {

			int temp1 = arr1[j];

			if (arr1[j] > arr1[j + 1]) {
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp1;
			}
		}
	}

	cout << "{";
	for (int i = 0; i < 10; i++) {

		if (i == 9) {
			cout << arr1[i] << " ";
		}
		else {
			cout << arr1[i] << ", ";
		}
	}
	cout << "}" << endl << endl;


	cout << "선택 정렬" << endl;
	// 선택 정렬
	int flag;

	for (int i = 0; i < 9; i++) {

		flag = arr2[i];
		int num = i;

		for (int j = i + 1; j < 10; j++) {
			if (arr2[j] < flag) {
				flag = arr2[j];
				num = j;
			}
		}

		if (arr2[i] != flag) {
			int temp2 = arr2[i];
			arr2[i] = arr2[num];
			arr2[num] = temp2;
		}
	}

	cout << "{";
	for (int i = 0; i < 10; i++) {

		if (i == 9) {
			cout << arr2[i] << " ";
		}
		else {
			cout << arr2[i] << ", ";
		}
	}
	cout << "}" << endl << endl;


	cout << "삽입 정렬" << endl;
	// 삽입 정렬
	int i, j, key;

	for (i = 1; i < 10; i++) {
		key = arr3[i];

		for (j = i - 1; j >= 0 && arr3[j] > key; j--) {
			arr3[j + 1] = arr3[j];
		}

		arr3[j + 1] = key;
	}

	cout << "{";
	for (int i = 0; i < 10; i++) {

		if (i == 9) {
			cout << arr3[i] << " ";
		}
		else {
			cout << arr3[i] << ", ";
		}
	}
	cout << "}" << endl << endl;


	cout << "퀵 정렬" << endl;
	// 퀵 정렬



	cout << "{";
	for (int i = 0; i < 10; i++) {

		if (i == 9) {
			cout << arr4[i] << " ";
		}
		else {
			cout << arr4[i] << ", ";
		}
	}
	cout << "}" << endl << endl;

	return 0;
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