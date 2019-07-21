#include <iostream>
#include <string>
using namespace std;

bool isDigit(string s);

template <typename T>
class Stack {
private:
	int capacity;
	int top;
	T *arr;

public:
	Stack() {
		capacity = 2;
		top = -1;
		arr = new T[capacity];
	}
	~Stack() {
		delete[] arr;
		arr = NULL;
	}
	int getTop() {
		return top;
	}
	void push(T num) {
		top++;
		arr[top] = num;

		if (top == capacity - 1) {
			doubleCapacity();
		}
	}
	T pop() {
		return arr[top--];
	}
	void print() {
		for (int i = 0; i <= top; i++) {
			cout << arr[i] << endl;
		}
	}
	void doubleCapacity() {
		T *temp = new T[capacity * 2];

		for (int i = 0; i <= top; i++) {
			temp[i] = arr[i];
		}
		capacity *= 2;

		delete[] arr;
		arr = temp;
	}
};

class Tokenizer {
private:
	string original;
public:
	Tokenizer() { original = ""; }
	~Tokenizer() {}
	// 토큰화 할 문장 입력
	void inputString(string s) {
		original = s;
	}
	// 다음 토큰이 있는지 검사
	bool next() {
		if (original.substr(0, 1) == "")
			return 0;
		return 1;
	}
	// 토큰을 하나씩 반환해 주는 함수
	string getNext() {
		string token = "";

		if (isDigit(original.substr(0, 1))) {
			int i;
			for (i =  0; isDigit(original.substr(i, 1)); i++) {
				token += original.substr(i, 1);
			}
			original = original.substr(i, string::npos);
		}
		else {
			token = original.substr(0, 1);
			
			original = original.substr(1, string::npos);
		}

		return token;
	}
};

class Calculator {
private:
	Stack<string> oprtr;
	Stack<int> oprnd;
	Tokenizer tknzr;
	string exp;
	string postfix;
	int result;
public:
	Calculator() { exp = ""; postfix = ""; result = 0; }
	~Calculator() {}
	void inputExp(string exp) {
		this->exp = exp;
	}
	int getPriority(string op) {
		char opr[1];
		strcpy_s(opr, op.c_str());

		switch (opr[0]) {
		case '^':
			return 2;
		case '*':
			return 3;
		case '/':
			return 3;
		case '%':
			return 3;
		case '+':
			return 4;
		case '-':
			return 4;
		case '(':
			return 0;
		case ')':
			return 1;
		default:
			return -1;
		}
	}
	void infixToPostfix() {
		tknzr.inputString(exp);
		string token;
		string pre = "";

		while (tknzr.next()) {
			token = tknzr.getNext();
			if (isDigit(token)) {
				postfix += (token + " ");
			}
			else {
				if ((pre == "" || isDigit(pre) == false) && getPriority(token) == 4) {
					postfix += token;
				}
				else {
					if (pre == "") {
						oprtr.push(token);
						pre = token;
					}
					else {
						string tempOp = oprtr.pop();
						if (getPriority(tempOp) <= getPriority(token)) {

						}
					}
				}
			}
		}
	}
	void calculate() {

	}
	void printPostfix() {
		cout << "후위 표현 계산식 : " << postfix << endl;
	}
	void printResult() {
		cout << "계산 결과 : " << result << endl;
	}
};

bool isDigit(string s) {
	return atoi(s.c_str()) != 0 || s.compare("0") == 0;
}

int main() {
	string expression;
	Calculator cal;

	cout << "중위 표현 계산식을 입력하세요 : ";
	cin >> expression;

	cal.inputExp(expression);

	cal.infixToPostfix();
	cal.calculate();
	
	cal.printPostfix();
	cal.printResult();

	return 0;
}