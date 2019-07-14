#include <iostream>
using namespace std;

/*
	1. ���Ḯ��Ʈ
	2. ����� �ִ� ���Ḯ��Ʈ : �޸� ��ĭ �Ƴ��� �ִ�.
	3. ���� ���Ḯ��Ʈ : Ž�� �۾��� �̵�
	4. ���� ���Ḯ��Ʈ : ���Ḯ��Ʈ�� ť ����
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
	// ��� ����
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
	// ��� ����
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
		cout << "���� ��û�� ��尡 ��Ͽ� ����." << endl;
	}
	// ����Ʈ ���
	void printList() {
		if (first == NULL) {
			cout << "����Ʈ�� ����ֽ��ϴ�." << endl;
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