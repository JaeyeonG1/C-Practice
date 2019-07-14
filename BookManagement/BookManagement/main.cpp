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

				cout << "도서명 : " << current->getName() << " | 상태 : " << stat << endl;
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
				if (current->getIslendable() == true)
					stat = "대출 가능";
				else
					stat = "대출중";

				cout << "도서명 : " << current->getName() << " | 상태 : " << stat << endl;
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
		cout << "[도서 관리 시스템]" << endl;
		cout << "1. 도서 등록" << endl;
		cout << "2. 도서 대출" << endl;
		cout << "3. 도서 목록 출력" << endl;
		cout << "4. 도서 목록 역순 출력" << endl;
		cout << "5. 반납" << endl;
		cout << "6. 도서 삭제" << endl;
		cout << "7. 종료" << endl;
		
		cin >> menu;

		switch(menu){
		case 1:
			cout << "등록할 도서 명 : ";
			cin >> name;
			bl.addBook(name);
			break;
		case 2:
			cout << "대출할 도서 명 : ";
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
			cout << "반납할 도서명 : ";
			cin >> name;
			bl.returnBook(name);
			break;
		case 6:
			cout << "삭제할 도서명 : ";
			cin >> name;
			bl.deleteBook(name);
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