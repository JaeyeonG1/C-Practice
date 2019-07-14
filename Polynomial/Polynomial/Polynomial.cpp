#include <iostream>
#include <string>
using namespace std;

class Term {
private:
	int coef;	// 계수
	int exp;	// 지수
public:
	Term() {}
	Term(int coef, int exp) {
		this->coef = coef;
		this->exp = exp;
	}
	int getCoef() { return coef; }
	int getExp() { return exp; }
	void setCoef(int coef) { this->coef = coef; }
	void setExp(int exp) { this->exp = exp; }
};

class Polynomial {
private:
	Term *terms;
	int capacity;
	int current;
public:
	Polynomial() {
		capacity = 2;
		current = 0;
		terms = new Term[capacity];
	}
	~Polynomial() {
		delete[] terms;
		terms = NULL;
	}
	Term* getTerm() {
		return terms;
	}
	int getCurrent() {
		return current;
	}
	// 다항식 입력
	void insertPoly(Term t) {
		if (current + 1 == capacity) {
			doubleCapacity();
		}

		if (current == 0) {
			terms[current] = t;
			current++;
		}
		else {
			for (int i = 0; i < current; i++) {
				if (terms[i].getExp() <= t.getExp()) {
					if (terms[i].getExp() < t.getExp()) {
						for (int j = current; j > i; j--) {
							terms[j] = terms[j - 1];
						}
						terms[i] = t;
						current++;
					}
					else if (terms[i].getExp() == t.getExp()) {
						terms[i].setCoef(terms[i].getCoef() + t.getCoef());
					}
					return;
				}
			}
			terms[current] = t;
			current++;
		}
	}
	// 다른 다항식과의 합 출력
	Polynomial* sumPoly(Polynomial &s) {
		Polynomial *sum = new Polynomial();
		Term* sub = s.getTerm();
		Term temp;

		for (int i = 0; i < current; i++) {
			temp = terms[i];
			sum->insertPoly(temp);
		}
		
		for (int j = 0; j < s.getCurrent(); j++) {
			temp = sub[j];
			sum->insertPoly(temp);
		}

		return sum;
	}
	// 다항식 2개의 합으로 생성
	void sumPolys(Polynomial &p1, Polynomial &p2) {
		for (int i = 0; i < p1.getCurrent(); i++) {
			insertPoly(p1.getTerm()[i]);
		}
		for (int j = 0; j < p2.getCurrent(); j++) {
			insertPoly(p2.getTerm()[j]);
		}
	}
	// 다항식 출력
	void viewPloy() {
		for (int i = 0; i < current; i++) {
			if (terms[i].getExp() == 0) {
				cout << terms[i].getCoef() << endl;
				break;
			}

			cout << terms[i].getCoef() << "x^" << terms[i].getExp();
			cout << " + ";
		}
	}
	// capacity 늘리기
	void doubleCapacity() {
		Term *temp = new Term[capacity * 2];

		for (int i = 0; i < capacity; i++) {
			temp[i] = terms[i];
		}
		capacity *= 2;

		delete[] terms;

		terms = temp;
	}
};

int main() {
	Polynomial poly1;
	Polynomial poly2;
	Polynomial sum;
	//Polynomial* sum;
	Term term;
	int coef;
	int exp;

	cout << "첫번째 다항식을 입력하세요." << endl;

	while (1) {

		cout << "계수 : ";
		cin >> coef;
		cout << "지수 : ";
		cin >> exp;

		term = Term(coef, exp);

		poly1.insertPoly(term);

		if (coef == 0 || exp == 0)
			break;
	}

	poly1.viewPloy();

	cout << endl << "두번째 다항식을 입력하세요." << endl;

	while (1) {

		cout << "계수 : ";
		cin >> coef;
		cout << "지수 : ";
		cin >> exp;

		term = Term(coef, exp);

		poly2.insertPoly(term);

		if (coef == 0 || exp == 0)
			break;
	}
	
	poly2.viewPloy();

	
	sum.sumPolys(poly1, poly2);
	cout << endl << "합 = ";
	sum.viewPloy();
	
	/*
	sum = poly1.sumPoly(poly2);
	cout << endl << "합 = ";
	sum->viewPloy();

	delete sum;
	*/

	return 0;
}