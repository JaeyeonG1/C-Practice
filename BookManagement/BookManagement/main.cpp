#include <iostream>
#include <string>
using namespace std;

class Book {
private:
	string name;
	bool islendable;
	Book* pre;
	Book* next;
public:
	Book() {
		name = "";
		islendable = true;
		pre = NULL;
		next = NULL;
	}
	Book(string name) {
		this->name = name;
		islendable = true;
		pre = NULL;
		next = NULL;
	}
	~Book() {
		delete pre;
		delete next;
	}
	string getName() {
		return name;
	}
	bool getIslendable() {
		return islendable;
	}
	Book* getPre(){
		return pre;
	}
	Book* getNext(){
		return next;
	}
	void setName(string name) {
		this->name = name;
	}
	void setIslendable(bool islendable) {
		this->islendable = islendable;
	}
	void setPre(Book* pre) {
		this->pre = pre;
	}
	void setNext(Book* next) {
		this->next = next;
	}
};
class BookList {
private:
	Book* first;
public:
	BookList() {
		first = NULL;
	}
	~BookList() {
		delete first;
	}
	void addBook(string name) {
		Book* temp = new Book(name);
		if (first == NULL) {
			first = temp;
		}
		else {
			Book* current = first;
			if (current->getName().compare(temp->getName()) > 0) {
				temp->setNext(current);
				first = temp;
				first->setPre(current);
				return;
			}
			while (current->getNext() != NULL) {
				Book* pre = current;
				current = current->getNext();
				if (current->getName().compare(temp->getName()) > 0) {
					temp->setNext(current);
					current->setPre(temp);
					pre->setNext(temp);
					temp->setPre(pre);
					return;
				}
			}
			current->setNext(temp);
			temp->setPre(current);
		}
	}
	void lendBook(string name) {

	}
	void printBooks() {
		if (first == NULL) {
			cout << "������ �������� �ʽ��ϴ�." << endl;
		}
		else {
			Book* current = first;
			string stat;
			while (1) {
				if (current->getIslendable() == true)
					stat = "���� ����";
				else
					stat = "������";

				cout << "������ : " << current->getName() << " | ���� : " << stat << endl;
				current = current->getNext();

				if (current == NULL)
					return;
			}
		}
	}
	void reversePrintBooks() {
		if (first == NULL) {
			cout << "������ �������� �ʽ��ϴ�." << endl;
		}
		else {
			Book* current = first;
			string stat;
			while (1) {
				current = current->getNext();

				if (current->getNext() == NULL)
					break;
			}
			while (1) {
				if (current->getIslendable() == true)
					stat = "���� ����";
				else
					stat = "������";

				cout << "������ : " << current->getName() << " | ���� : " << stat << endl;
				current = current->getPre();

				if (current == NULL)
					return;
			}
		}
	}
	void returnBook(string name) {

	}
	void deleteBook(string name) {

	}
};

int main() {
	BookList bl;
	string name = "";
	int menu;

	while (1) {
		cout << "[���� ���� �ý���]" << endl;
		cout << "1. ���� ���" << endl;
		cout << "2. ���� ����" << endl;
		cout << "3. ���� ��� ���" << endl;
		cout << "4. ���� ��� ���� ���" << endl;
		cout << "5. �ݳ�" << endl;
		cout << "6. ���� ����" << endl;
		cout << "7. ����" << endl;
		
		cin >> menu;

		switch(menu){
		case 1:
			cout << "����� ���� �� : ";
			cin >> name;
			bl.addBook(name);
			break;
		case 2:
			cout << "������ ���� �� : ";
			cin >> name;
			bl.addBook(name);
			break;
		case 3:
			bl.printBooks();
			break;
		case 4:
			bl.reversePrintBooks();
			break;
		case 5:
			cout << "�ݳ��� ������ : ";
			cin >> name;
			bl.returnBook(name);
			break;
		case 6:
			cout << "������ ������ : ";
			cin >> name;
			bl.deleteBook(name);
			break;
		case 7:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�ùٸ� �޴��� �����ϼ���!" << endl;
			break;
		}
	}
	return 0;
}