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
	// 토큰을 원하는 기준으로 나눠 반환해 주는 함수
	string getNext(string delimiter) {
		string token = "";

		int delPos = original.find(delimiter);
		token = original.substr(0, delPos);
		original = original.substr(delPos + 1, string::npos);

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
		char opr[2];
		strcpy_s(opr, op.c_str());

		switch (opr[0]) {
		case '^':
			return 0;
		case '*':
			return 1;
		case '/':
			return 1;
		case '%':
			return 1;
		case '+':
			return 2;
		case '-':
			return 2;
		case '(':
			return 3;
		case ')':
			return 4;
		default:
			return -1;
		}
	}
	void infixToPostfix() {
		tknzr.inputString(exp);
		string token;
		int opCount = 1;
		int brktCount = 0;

		while (tknzr.next()) {
			token = tknzr.getNext();
			if (isDigit(token)) {
				postfix += (token + " ");
				opCount = 0;
			}
			else {
				if (getPriority(token) == 3){
					oprtr.push(token);
					brktCount++;
					opCount--;
				}
				else if (getPriority(token) == 4) {
					if (brktCount < 1) {
						cout << "잘못된 식 입력 (여는 괄호 없음)" << endl;
						return;
					}
					while (1) {
						string temp = oprtr.pop();
						if (getPriority(temp) == 3) {
							brktCount--;
							break;
						}
						postfix += (temp + " ");
					}
					opCount = -1;
				}
				else if (opCount != 0 && getPriority(token) != 2) {
					cout << "잘못된 식 입력 (부호 자리에 잘못된 기호)" << endl;
					return;
				}
				else if (opCount > 1) {
					cout << "잘못된 식 입력 (연산자 위치 오류)" << endl;
					return;
				}
				else if (opCount == 1 && getPriority(token) == 2) {
					postfix += token;
				}
				else{
					if (oprtr.getTop() == -1) {
						oprtr.push(token);
					}
					else {
						string tempOp = oprtr.pop();
						int comparer = 0;
						if (getPriority(tempOp) <= getPriority(token)) {
							while (getPriority(tempOp) <= getPriority(token)) {
								postfix += (tempOp + " ");
								if (oprtr.getTop() == -1) {
									comparer = 1;
									break;
								}
								tempOp = oprtr.pop();
							}
							if (comparer == 0) {
								oprtr.push(tempOp);
							}
						}
						else {
							oprtr.push(tempOp);
						}
						oprtr.push(token);
					}
				}
				opCount++;
			}
		}
		while (oprtr.getTop() > -1) {
			string temp = oprtr.pop();
			if (getPriority(temp) == 3) {
				cout << "잘못된 식 입력 (닫는 괄호 없음)" << endl;
				return;
			}
			postfix += (temp + " ");
		}
		printPostfix();
	}
	void calculate() {
		tknzr.inputString(postfix);
		string token;
		int value;
		int count;

		while (tknzr.next()) {
			token = tknzr.getNext(" ");

			if (isDigit(token)) {
				int temp = atoi(token.c_str());
				oprnd.push(temp);
			}
			else {
				int rNum = oprnd.pop();
				int lNum = oprnd.pop();
				char op[2];
				strcpy_s(op, token.c_str());

				switch (op[0]) {
				case '^':
					count = 0;
					value = 1;

					while (count < rNum) {
						value *= lNum;
						count++;
					}
					oprnd.push(value);

					break;
				case '*':
					value = lNum * rNum;
					oprnd.push(value);

					break;
				case '/':
					value = lNum / rNum;
					oprnd.push(value);

					break;
				case '%':
					value = lNum % rNum;
					oprnd.push(value);

					break;
				case '+':

					value = lNum + rNum;
					oprnd.push(value);

					break;
				case '-':

					value = lNum - rNum;
					oprnd.push(value);

					break;
				default:
					break;
				}
			}
		}
		result = oprnd.pop();

		printResult();
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

	return 0;
}