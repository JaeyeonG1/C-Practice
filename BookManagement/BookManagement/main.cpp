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
				cout << "이미 같은 이름의 도서가 존재합니다." << endl;
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
					cout << "이미 같은 이름의 도서가 존재합니다." << endl;
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
				cout << current->getName() << " 대여 완료" << endl;
				return;
			}
			else {
				cout << "해당 도서가 이미 대여 중입니다." << endl;
				return;
			}
		}
		else {
			if (current->getNext() == NULL) {
				cout << "해당하는 도서가 없습니다." << endl;
				return;
			}
			while (1) {
				current = current->getNext();
				if (current->getName() == name) {
					if (current->getIslendable()) {
						current->setIslendable(false);
						cout << current->getName() << " 대여 완료" << endl;
						return;
					}
					else {
						cout << "해당 도서가 이미 대여 중입니다." << endl;
						return;
					}
				}
				if (current->getNext() == NULL) {
					cout << "해당하는 도서가 없습니다." << endl;
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
				cout << current->getName() << " 반납 완료" << endl;
				return;
			}
			else {
				cout << "대출 상태인 도서가 아닙니다." << endl;
				return;
			}
		}
		else {
			if (current->getNext() == NULL) {
				cout << "해당하는 도서가 없습니다." << endl;
				return;
			}
			while (1) {
				current = current->getNext();
				if (current->getName() == name) {
					if (current->getIslendable() == false) {
						current->setIslendable(false);
						cout << current->getName() << " 반납 완료" << endl;
						return;
					}
					else {
						cout << "대출 상태인 도서가 아닙니다." << endl;
						return;
					}
				}
				if (current->getNext() == NULL) {
					cout << "해당하는 도서가 없습니다." << endl;
					return;
				}
			}
		}
	}
	void printBooks() {
		if (first == NULL) {
			cout << "도서가 존재하지 않습니다." << endl;
		}
		else {
			Book* current = first;
			string stat;
			while (1) {
				if (current->getIslendable() == true)
					stat = "대출 가능";
				else
					stat = "대출중";

				cout << "| 도서명 : " << current->getName() << " | 상태 : " << stat << " |" << endl;
				current = current->getNext();

				if (current == NULL)
					return;
			}
		}
	}
	void reversePrintBooks() {
		if (first == NULL) {
			cout << "도서가 존재하지 않습니다." << endl;
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
					stat = "대출 가능";
				else
					stat = "대출중";

				cout << "| 도서명 : " << current->getName() << " | 상태 : " << stat << " |" << endl;

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
				cout << name << "이 삭제되었습니다." << endl;
			}
			else
				cout << "해당 도서가 대여중입니다. 대여중인 도서는 삭제할 수 없습니다." << endl;
		}
		else {
			if (current->getNext() == NULL) {
				cout << "해당하는 도서가 없습니다." << endl;
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
						cout << name << "이 삭제되었습니다." << endl;
						return;
					}
					else {
						cout << "해당 도서가 대여중입니다. 대여중인 도서는 삭제할 수 없습니다." << endl;
						return;
					}
				}
				if (current->getNext() == NULL) {
					cout << "해당하는 도서가 없습니다." << endl;
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
		cout << "[도서 관리 시스템]" << endl;
		cout << "1. 도서 등록" << endl;
		cout << "2. 도서 대출" << endl;
		cout << "3. 도서 목록 출력" << endl;
		cout << "4. 도서 목록 역순 출력" << endl;
		cout << "5. 반납" << endl;
		cout << "6. 도서 삭제" << endl;
		cout << "7. 종료" << endl;

		cin >> menu;

		switch (menu) {
		case 1:
			while (1) {
				cout << "등록할 도서 명 (종료 exit) : ";
				cin >> name;
				if (name == "exit")
					break;
				bl.addBook(name);
			}
			break;
		case 2:
			while (1) {
				cout << "대출할 도서 명 (종료 exit) : ";
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
				cout << "반납할 도서명 (종료 exit) : ";
				cin >> name;
				if (name == "exit")
					break;
				bl.returnBook(name);
			}
			break;
		case 6:
			while (1) {
				cout << "삭제할 도서명 (종료 exit) : ";
				cin >> name;
				if (name == "exit")
					break;
				bl.deleteBook(name);
			}
			break;
		case 7:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "올바른 메뉴를 선택하세요!" << endl;
			break;
		}
	}
	return 0;
}