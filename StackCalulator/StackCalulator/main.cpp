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
	/*
	void tokenizer(string exp) {
		string num = "";
		string op = "";
		for (int i = 0; i < exp.length(); i++) {
			if (isDigit(exp.substr(i, 1))) {
				num += exp.substr(i, 1);
			}
			else {
				op = exp.substr(i, 1);

				oprnd.push(atoi(num.c_str()));
				oprtr.push(op);

				exp = exp.substr(i + 1, string::npos);

				break;
			}
		}
		while (1) {
			int operand;
			num = "";
			for (int i = 0; i < exp.length(); i++) {
				if (isDigit(exp.substr(i, 1))) {
					num += exp.substr(i, 1);
				}
				else {
					op = exp.substr(i, 1);

					oprnd.push(atoi(num.c_str()));

					string preOp = oprtr.pop();
					if (getPriority(op) <= getPriority(preOp)) {
						oprtr.push(preOp);

						operand = oprnd.pop();
						output.insert(pos, to_string(operand) + " ");

						output += oprtr.pop() + " ";

						operand = oprnd.pop();
						output.insert(pos, to_string(operand) + " ");

						pos = output.length();
						oprtr.push(op);
					}
					else {
						oprtr.push(preOp);
						oprtr.push(op);
					}

					exp = exp.substr(i + 1, string::npos);

					break;
				}
			}
			if (num.length() == exp.length() && num.compare(exp) == 0) {
				oprnd.push(atoi(num.c_str()));
				operand = oprnd.pop();
				output.insert(pos, to_string(operand) + " ");
				output += op;
				operand = oprnd.pop();
				output.insert(pos, to_string(operand) + " ");
				break;
			}
		}
	}
	*/
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
		calculate();
	}
	int getPriority(string op) {
		char opr[1];
		strcpy_s(opr, op.c_str());

		switch (opr[0]) {
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
		default:
			return -1;
		}
	}
	void covertToPostfix() {
		tknzr.inputString(exp);
		string token = tknzr.getNext();
		while (tknzr.next()) {
			token = tknzr.getNext();
			if (isDigit(token)) {
				oprnd.push(atoi(token.c_str()));
			}
			else {
				oprtr.push(token);
			}
		}
	}
	void getResult() {

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

	Stack<int> a;
	a.pop();

	cout << "중위 표현 계산식을 입력하세요 : ";
	cin >> expression;


	/*
	cal.inputExp(expression);
	cal.printPostfix();
	cal.printResult();
	*/
	return 0;
}