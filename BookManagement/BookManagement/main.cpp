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
	Book* getPre() {
		return pre;
	}
	Book* getNext() {
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
		Book* pre = new Book();
		if (first == NULL) {
			first = temp;
		}
		else {
			Book* current = first;
			if (current->getName().compare(temp->getName()) > 0) {
				temp->setNext(current);
				first = temp;
				current->setPre(first);
				return;
			}
			else if (current->getName().compare(temp->getName()) == 0) {
				cout << "�̹� ���� �̸��� ������ �����մϴ�." << endl;
				return;
			}
			else if (current->getName().compare(temp->getName()) < 0){
				if (current->getNext() == NULL) {
					current->setNext(temp);
					temp->setPre(current);
					return;
				}
			}
			while (1) {
				pre = current;
				current = current->getNext();
				if (current->getName().compare(temp->getName()) > 0) {
					temp->setNext(current);
					current->setPre(temp);
					pre->setNext(temp);
					temp->setPre(pre);
					return;
				}
				else if (current->getName().compare(temp->getName()) == 0) {
					cout << "�̹� ���� �̸��� ������ �����մϴ�." << endl;
					return;
				}
				if (current->getNext() == NULL) {
					current->setNext(temp);
					temp->setPre(current);
					return;
				}
			}
		}
	}
	void lendBook(string name) {
		Book* current = first;
		if (current->getName() == name) {
			if (current->getIslendable()) {
				current->setIslendable(false);
				cout << current->getName() << " �뿩 �Ϸ�" << endl;
				return;
			}
			else {
				cout << "�ش� ������ �̹� �뿩 ���Դϴ�." << endl;
				return;
			}
		}
		else {
			if (current->getNext() == NULL) {
				cout << "�ش��ϴ� ������ �����ϴ�." << endl;
				return;
			}
			while (1) {
				current = current->getNext();
				if (current->getName() == name) {
					if (current->getIslendable()) {
						current->setIslendable(false);
						cout << current->getName() << " �뿩 �Ϸ�" << endl;
						return;
					}
					else {
						cout << "�ش� ������ �̹� �뿩 ���Դϴ�." << endl;
						return;
					}
				}
				if (current->getNext() == NULL) {
					cout << "�ش��ϴ� ������ �����ϴ�." << endl;
					return;
				}
			}
		}
	}
	void returnBook(string name) {
		Book* current = first;
		if (current->getName() == name) {
			if (current->getIslendable() == false) {
				current->setIslendable(true);
				cout << current->getName() << " �ݳ� �Ϸ�" << endl;
				return;
			}
			else {
				cout << "���� ������ ������ �ƴմϴ�." << endl;
				return;
			}
		}
		else {
			if (current->getNext() == NULL) {
				cout << "�ش��ϴ� ������ �����ϴ�." << endl;
				return;
			}
			while (1) {
				current = current->getNext();
				if (current->getName() == name) {
					if (current->getIslendable() == false) {
						current->setIslendable(false);
						cout << current->getName() << " �ݳ� �Ϸ�" << endl;
						return;
					}
					else {
						cout << "���� ������ ������ �ƴմϴ�." << endl;
						return;
					}
				}
				if (current->getNext() == NULL) {
					cout << "�ش��ϴ� ������ �����ϴ�." << endl;
					return;
				}
			}
		}
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

				cout << "| ������ : " << current->getName() << " | ���� : " << stat << " |" << endl;
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
				if (current->getIslendable())
					stat = "���� ����";
				else
					stat = "������";

				cout << "| ������ : " << current->getName() << " | ���� : " << stat << " |" << endl;

				if (current->getPre() == NULL)
					return;

				current = current->getPre();
			}
		}
	}
	void deleteBook(string name) {
		Book* current = first;
		if (first->getName() == name) {
			if (current->getIslendable()) {
				first = first->getNext();
				current->setNext(NULL);
				first->setPre(NULL);
				delete current;
				cout << name << "�� �����Ǿ����ϴ�." << endl;
			}
			else
				cout << "�ش� ������ �뿩���Դϴ�. �뿩���� ������ ������ �� �����ϴ�." << endl;
		}
		else {
			if (current->getNext() == NULL) {
				cout << "�ش��ϴ� ������ �����ϴ�." << endl;
				return;
			}
			while (1) {
				current = current->getNext();
				if (current->getName() == name) {
					if (current->getIslendable()) {
						if (current->getNext() == NULL) {
							current->getPre()->setNext(NULL);
							current->setPre(NULL);
							delete current;
						}
						else {
							current->getPre()->setNext(current->getNext());
							current->getNext()->setPre(current->getPre());
							current->setPre(NULL);
							current->setNext(NULL);
							delete current;
						}
						cout << name << "�� �����Ǿ����ϴ�." << endl;
						return;
					}
					else {
						cout << "�ش� ������ �뿩���Դϴ�. �뿩���� ������ ������ �� �����ϴ�." << endl;
						return;
					}
				}
				if (current->getNext() == NULL) {
					cout << "�ش��ϴ� ������ �����ϴ�." << endl;
					return;
				}
			}
		}
	}
};

int main() {
	BookList bl = BookList();
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

		switch (menu) {
		case 1:
			while (1) {
				cout << "����� ���� �� (���� exit) : ";
				cin >> name;
				if (name == "exit")
					break;
				bl.addBook(name);
			}
			break;
		case 2:
			while (1) {
				cout << "������ ���� �� (���� exit) : ";
				cin >> name;
				if (name == "exit")
					break;
				bl.lendBook(name);
			}
			break;
		case 3:
			bl.printBooks();
			break;
		case 4:
			bl.reversePrintBooks();
			break;
		case 5:
			while (1) {
				cout << "�ݳ��� ������ (���� exit) : ";
				cin >> name;
				if (name == "exit")
					break;
				bl.returnBook(name);
			}
			break;
		case 6:
			while (1) {
				cout << "������ ������ (���� exit) : ";
				cin >> name;
				if (name == "exit")
					break;
				bl.deleteBook(name);
			}
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