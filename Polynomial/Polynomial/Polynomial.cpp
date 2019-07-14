#include <iostream>
#include <string>
using namespace std;

class Term {
private:
	int coef;	// ���
	int exp;	// ����
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
	// ���׽� �Է�
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
	// �ٸ� ���׽İ��� �� ���
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
	// ���׽� 2���� ������ ����
	void sumPolys(Polynomial &p1, Polynomial &p2) {
		for (int i = 0; i < p1.getCurrent(); i++) {
			insertPoly(p1.getTerm()[i]);
		}
		for (int j = 0; j < p2.getCurrent(); j++) {
			insertPoly(p2.getTerm()[j]);
		}
	}
	// ���׽� ���
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
	// capacity �ø���
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

	cout << "ù��° ���׽��� �Է��ϼ���." << endl;

	while (1) {

		cout << "��� : ";
		cin >> coef;
		cout << "���� : ";
		cin >> exp;

		term = Term(coef, exp);

		poly1.insertPoly(term);

		if (coef == 0 || exp == 0)
			break;
	}

	poly1.viewPloy();

	cout << endl << "�ι�° ���׽��� �Է��ϼ���." << endl;

	while (1) {

		cout << "��� : ";
		cin >> coef;
		cout << "���� : ";
		cin >> exp;

		term = Term(coef, exp);

		poly2.insertPoly(term);

		if (coef == 0 || exp == 0)
			break;
	}
	
	poly2.viewPloy();

	
	sum.sumPolys(poly1, poly2);
	cout << endl << "�� = ";
	sum.viewPloy();
	
	/*
	sum = poly1.sumPoly(poly2);
	cout << endl << "�� = ";
	sum->viewPloy();

	delete sum;
	*/

	return 0;
}