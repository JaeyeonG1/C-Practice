#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int age;
	Person* next;
public:
		Person(){
			next = NULL;
		}
		Person(string name, int age) {
			this->name = name;
			this->age = age;
			next = NULL;
		}
		~Person() {
			delete next;
		}
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	Person* getNext() {
		return next;
	}
	void setName(string name) {
		this->name = name;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setNext(Person* next) {
		this->next = next;
	}
};

class PersonList {
private:
	Person* person;
public:
	PersonList() {
		person = NULL;
	}
	~PersonList() {
		delete person;
	}
	void insertPerson(string name, int age) {
		Person* p = new Person(name, age);
		if (person == NULL) {
			person = p;
			return;
		}
		else {
			Person* current = person;
			while (1) {
				if (current->getNext() == NULL) {
					current->setNext(p);
					return;
				}
				current = current->getNext();
			}
		}
	}
	void printList() {
		if (person == NULL) {
			cout << "사람이 없네유" << endl;
		}
		else {
			Person* current = person;
			while (1) {
				cout << "이름 : " << current->getName() << endl;
				cout << "나이 : " << current->getAge() << endl;
				current = current->getNext();
				if (current == NULL)
					return;
			}
		}
	}
};

int main() {
	PersonList pl;

	pl.insertPerson("최현진", 26);
	pl.insertPerson("최재영", 24);
	pl.insertPerson("임준범", 24);

	pl.printList();

	return 0;
}