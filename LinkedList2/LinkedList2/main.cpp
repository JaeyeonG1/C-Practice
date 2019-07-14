#include <iostream>
using namespace std;

/*
	1. 연결리스트
	2. 헤더가 있는 연결리스트 : 메모리 한칸 아낄수 있다.
	3. 이중 연결리스트 : 탐색 작업에 이득
	4. 원형 연결리스트 : 연결리스트로 큐 구현
*/

class Node{
private:
	int data;
	Node* next;
public:
	Node() {
		next = NULL;
	}
	Node(int data) {
		this->data = data;
		next = NULL;
	}
	~Node() {
		delete next;
	}
	int getData() {
		return data;
	}
	Node* getNext() {
		return next;
	}
	void setData(int data) {
		this->data = data;
	}
	void setNext(Node* next) {
		this->next = next;
	}
};

class NodeList {
private:
	Node* first;
public:
	NodeList() {
		first = NULL;
	}
	~NodeList() {
		delete first;
	}
	// 노드 삽입
	void insertNode(int data) {
		Node* temp = new Node(data);
		if (first == NULL) {
			first = temp;
		}
		else {
			Node* current = first;
			if (current->getData() > temp->getData()) {
				temp->setNext(current);
				first = temp;
				return;
			}
			while (current->getNext() != NULL) {
				Node* pre = current;
				current = current->getNext();
				if (current->getData() > temp->getData()) {
					temp->setNext(current);
					pre->setNext(temp);
					return;
				}
			}
			current->setNext(temp);
		}
	}
	// 노드 삭제
	void deleteNode(int data) {
		if (first->getData() == data) {
			Node *temp = first;
			first = first->getNext();
			temp->setNext(NULL);
			delete temp;
			return;
		}

		Node *pre = first;
		Node *current = pre->getNext();

		while (current->getNext() != NULL) {
			if (current->getData() == data) {
				pre->setNext(current->getNext());
				current->setNext(NULL);
				delete current;
				return;
			}
			pre = current;
			current = current->getNext();
		}
		cout << "삭제 요청한 노드가 목록에 없음." << endl;
	}
	// 리스트 출력
	void printList() {
		if (first == NULL) {
			cout << "리스트가 비어있습니다." << endl;
		}
		else {
			Node* current = first;
			while (1) {
				cout << "Data : " << current->getData() << endl;
				current = current->getNext();
				if (current == NULL)
					return;
			}
		}
	}
};

int main() {
	NodeList nl;

	nl.insertNode(4);
	nl.insertNode(2);
	nl.insertNode(6);
	nl.insertNode(8);
	nl.insertNode(1);

	nl.printList();

	nl.deleteNode(1);
	nl.deleteNode(6);
	nl.deleteNode(10);

	nl.printList();


	return 0;
}