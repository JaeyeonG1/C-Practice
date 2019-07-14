#include <iostream>
using namespace std;

class Stack {
private:
	int capacity;
	int top;
	int *arr;

public:
	Stack() {
		capacity = 2;
		top = -1;
		arr = new int[capacity];
	}
	~Stack() {
		delete[] arr;
		arr = NULL;
	}
	void push(int num) {
		top++;
		arr[top] = num;

		if (top == capacity - 1) {
			doubleCapacity();
		}
	}
	int pop() {
		return arr[top--];
	}
	void print() {
		for (int i = 0; i <= top; i++) {
			cout << arr[i] << endl;
		}
	}
	void doubleCapacity() {
		int *temp = new int[capacity * 2];
		
		for (int i = 0; i <= top; i++) {
			temp[i] = arr[i];
		}
		capacity *= 2;

		delete[] arr;
		arr = temp;
	}
};

int main() {
	Stack s;

	s.push(3);
	s.push(2);
	s.push(4);
	s.push(5);
	cout <<"pop" << s.pop() << endl;
	s.push(7);
	s.push(3);
	s.print();

	cout << "=================" << endl;
	s.push(2);
	s.push(4);
	s.push(9);
	cout << "pop" << s.pop() << endl;
	s.print();


	return 0;
}