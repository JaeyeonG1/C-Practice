#include <iostream>
#include <string>
using namespace std;

class Term{
private:
	int coef;
	int exp;
	Term* pre;
	Term* next;
public:
	Term() {
		pre = NULL;
		next = NULL;
	}
	Term(int coef, int exp) {
		this->coef = coef;
		this->exp = exp;
		pre = NULL;
		next = NULL;
	}
	~Term() {
		delete pre;
		delete next;
	}
	int getCoef() { return coef; }
	int getExp() { return exp; }
	Term* getPre() { return pre; }
	Term* getNext() { return next; }
	void setCoef(int coef) { this->coef = coef; }
	void setExp(int exp) { this->exp = exp; }
	void setPre(Term* pre) { this->pre = pre; }
	void setNext(Term* next) { this->next = next; }
};

class Polynomial {
private:
	Term* first;
public:
	Polynomial() {
		first = NULL;
	}
	~Polynomial() {
		first->setNext(NULL);
		first->setPre(NULL);
		delete first;
	}
	Term* getFirst() {
		return first;
	}
	void insertPoly(int coef, int exp) {
		Term* temp = new Term(coef, exp);
		if (first == NULL) {
			first = temp;
		}
		else {
			Term* current = first;
			while (1) {
				if (current->getExp() < temp->getExp()) {
					if (current == first) {
						temp->setNext(current);
						current->setPre(temp);
						first = temp;
						return;
					}
					temp->setPre(current->getPre());
					temp->setNext(current);
					temp->getPre()->setNext(temp);
					current->setPre(temp);
					return;
				}
				else if (current->getExp() == temp->getExp()) {
					int coef = current->getCoef() + temp->getCoef();
					current->setCoef(coef);
					return;
				}
				if (current->getNext() == NULL) {
					current->setNext(temp);
					temp->setPre(current);
					break;
				}
				current = current->getNext();
			}
		}
	}
	void viewPoly() {
		Term* current = first;
		while (1) {
			if (current->getExp() == 0) {
				cout << current->getCoef() << endl;
				break;
			}
			cout << current->getCoef() << "x^" << current->getExp() << " + ";
			current = current->getNext();
		}
	}
	void sumPolys(Polynomial &p1, Polynomial &p2) {
		Term* current1 = p1.getFirst();
		Term* current2 = p2.getFirst();
		while (1) {
			insertPoly(current1->getCoef(), current1->getExp());
			if (current1->getNext() == NULL) {
				break;
			}
			current1 = current1->getNext();
		}
		while (1) {
			insertPoly(current2->getCoef(), current2->getExp());
			if (current2->getNext() == NULL) {
				break;
			}
			current2 = current2->getNext();
		}
	}
};

int main() {
	Polynomial poly1;
	Polynomial poly2;
	Polynomial sum;
	int coef;
	int exp;

	cout << "첫번째 다항식을 입력하세요." << endl;

	while (1) {

		cout << "계수 : ";
		cin >> coef;
		cout << "지수 : ";
		cin >> exp;

		poly1.insertPoly(coef, exp);

		if (coef == 0 || exp == 0)
			break;
	}

	poly1.viewPoly();

	cout << endl << "두번째 다항식을 입력하세요." << endl;

	while (1) {

		cout << "계수 : ";
		cin >> coef;
		cout << "지수 : ";
		cin >> exp;

		poly2.insertPoly(coef, exp);

		if (coef == 0 || exp == 0)
			break;
	}

	poly2.viewPoly();

	sum.sumPolys(poly1, poly2);
	cout << endl << "합 = ";
	sum.viewPoly();

	return 0;
}