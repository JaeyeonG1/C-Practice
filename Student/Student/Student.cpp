#include <iostream>
#include <string>
using namespace std;


class Student {
private:
	string name;
	string major;
	string phone;
	string insertDate;
	int age;
	int grade;
public:
	Student() {}
	Student(string name, string major, string phone, int grade, string insertDate, int age) {
		this->name = name;
		this->major = major;
		this->phone = phone;
		this->grade = grade;
		this->insertDate = insertDate;
		this->age = age;
	}
	string getInsertDate() { return insertDate; }
	int getAge() { return age; }
	string getName() { return name; }
	string getMajor() { return major; }
	string getPhone() { return phone; }
	int getGrade() { return grade; }
	void setName(string name) { this->name = name; }
	void setMajor(string major) { this->major = major; }
	void setPhone(string phone) { this->phone = phone; }
	void setGrade(int grade) { this->grade = grade; };
	void setInsertDate(string insertDate) { this->insertDate = insertDate; }
	void setAge(int age) { this->age = age; }
};





class StudentList {
private:
	Student *studentList;
	int capacity;
	int current;
public:
	StudentList() {
		capacity = 2;
		current = 0;
		studentList = new Student[capacity];
	}
	~StudentList() {
		delete[] studentList;
		studentList = NULL;
	}
	void insertStudent(Student s) {
		if (current == capacity) {
			doubleCapacity();
		}

		studentList[current] = s;
		current++;
	}
	void deleteStudent(string phone) {
		for (int i = 0; i < current; i++) {
			if (studentList[i].getPhone() == phone) {
				for (int j = i + 1; j < current; j++) {
					studentList[i] = studentList[j];
				}
				current--;
				break;
			}
		}
	}
	void searchStudent(string phone) {
		for (int i = 0; i < current; i++) {
			if (studentList[i].getPhone() == phone) {
				cout << "�̸� : " << studentList[i].getName() << endl;
				cout << "���� : " << studentList[i].getAge() << endl;
				cout << "�а� : " << studentList[i].getMajor() << endl;
				cout << "�г� : " << studentList[i].getGrade() << endl;
				cout << "����� : " << studentList[i].getInsertDate() << endl;
				cout << "��ȣ : " << studentList[i].getPhone() << endl;
				break;
			}
		}
	}
	void sortByName() { //���� ���� ����ؼ� �̸� ������ ���� (�����ؼ� ������ �ٲ��� ����)
		Student *temp = new Student[current];

		for (int i = 0; i < current; i++) {
			temp[i] = studentList[i];
		}

		for (int i = current - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {

				Student temp1 = temp[j];

				if (temp[j].getName().compare(temp[j + 1].getName()) > 0) {
					temp[j] = temp[j + 1];
					temp[j + 1] = temp1;
				}
			}
		}

		for (int i = 0; i < current; i++) {
			cout << "(" << i << "��°) " << endl;
			cout << "�̸� : " << temp[i].getName() << endl;
			cout << "���� : " << temp[i].getAge() << endl;
			cout << "�а� : " << temp[i].getMajor() << endl;
			cout << "�г� : " << temp[i].getGrade() << endl;
			cout << "����� : " << temp[i].getInsertDate() << endl;
			cout << "��ȣ : " << temp[i].getPhone() << endl;
		}
	}
	void sortByGrade() { //�������� ����ؼ� �г� ������ ����
		Student *temp = new Student[current];

		for (int i = 0; i < current; i++) {
			temp[i] = studentList[i];
		}

		for (int i = 0; i < current - 1; i++) {

			Student flag = temp[i];
			int num = i;

			for (int j = i + 1; j < current; j++) {
				if (temp[j].getGrade() < flag.getGrade()) {
					flag = temp[j];
					num = j;
				}
			}

			if (temp[i].getGrade() != flag.getGrade()) {
				Student temp2 = temp[i];
				temp[i] = temp[num];
				temp[num] = temp2;
			}
		}

		for (int i = 0; i < current; i++) {
			cout << "(" << i << "��°) " << endl;
			cout << "�̸� : " << temp[i].getName() << endl;
			cout << "���� : " << temp[i].getAge() << endl;
			cout << "�а� : " << temp[i].getMajor() << endl;
			cout << "�г� : " << temp[i].getGrade() << endl;
			cout << "����� : " << temp[i].getInsertDate() << endl;
			cout << "��ȣ : " << temp[i].getPhone() << endl;
		}
	}
	void sortByAge() { //�������� ����ؼ� ���� ������ ����
		Student *temp = new Student[current];

		for (int i = 0; i < current; i++) {
			temp[i] = studentList[i];
		}

		int j; Student key;

		for (int i = 0; i < current - 1; i++) {
			key = temp[i + 1];

			for (j = i; j >= 0 && temp[j].getAge() > key.getAge(); j--) {
				temp[j + 1] = temp[j];
			}

			temp[j + 1] = key;
		}

		for (int i = 0; i < current; i++) {
			cout << "(" << i << "��°) " << endl;
			cout << "�̸� : " << temp[i].getName() << endl;
			cout << "���� : " << temp[i].getAge() << endl;
			cout << "�а� : " << temp[i].getMajor() << endl;
			cout << "�г� : " << temp[i].getGrade() << endl;
			cout << "����� : " << temp[i].getInsertDate() << endl;
			cout << "��ȣ : " << temp[i].getPhone() << endl;
		}
	}
	void sortByInsertDate() { //������ ����ؼ� ���� ��¥ ������ ����
		Student *temp = new Student[current];

		for (int i = 0; i < current; i++) {
			temp[i] = studentList[i];
		}



		for (int i = 0; i < current; i++) {
			cout << "(" << i << "��°) " << endl;
			cout << "�̸� : " << temp[i].getName() << endl;
			cout << "���� : " << temp[i].getAge() << endl;
			cout << "�а� : " << temp[i].getMajor() << endl;
			cout << "�г� : " << temp[i].getGrade() << endl;
			cout << "����� : " << temp[i].getInsertDate() << endl;
			cout << "��ȣ : " << temp[i].getPhone() << endl;
		}
	}
	void printList() {
		for (int i = 0; i < current; i++) {
			cout << "(" << i << "��°) " << endl;
			cout << "�̸� : " << studentList[i].getName() << endl;
			cout << "���� : " << studentList[i].getAge() << endl;
			cout << "�а� : " << studentList[i].getMajor() << endl;
			cout << "�г� : " << studentList[i].getGrade() << endl;
			cout << "����� : " << studentList[i].getInsertDate() << endl;
			cout << "��ȣ : " << studentList[i].getPhone() << endl;
		}
	}
	void doubleCapacity() {
		Student *temp = new Student[capacity * 2];

		for (int i = 0; i < capacity; i++) {
			temp[i] = studentList[i];
		}
		capacity *= 2;

		delete[] studentList;
		studentList = temp;

		cout << "�迭�� ũ�Ⱑ " << capacity << "�� �����" << endl;
	}
};

int main() {
	int select;
	StudentList sl;
	while (1) {
		cout << "�޴��� �����ϼ���." << endl;
		cout << "1. �л� �Է� " << endl;
		cout << "2. �л� ����" << endl;
		cout << "3. �л� ��ȸ" << endl;
		cout << "4. �̸��� ����" << endl;
		cout << "5. �г�� ����" << endl;
		cout << "6. ���̼� ����" << endl;
		cout << "7. ��ϳ�¥�� ����" << endl;
		cout << "8. ��ü ���" << endl;
		cout << "9. ����" << endl;

		cin >> select;

		switch (select) {
		case 1: {
			string name;
			string major;
			string phone;
			string date;
			int age;
			int grade;

			cout << "�̸� : ";
			cin >> name;
			cout << "���� : ";
			cin >> major;
			cout << "��ȭ��ȣ : ";
			cin >> phone;
			cout << "�г� : ";
			cin >> grade;
			cout << "����� : ";
			cin >> date;
			cout << "���� : ";
			cin >> age;

			Student s = Student(name, major, phone, grade, date, age);

			sl.insertStudent(s);
			break;
		}
		case 2: {
			string phone;
			cout << "������ �л��� ��ȣ�� �Է��ϼ��� : ";
			cin >> phone;
			sl.deleteStudent(phone);
			break;
		}
		case 3: {
			string phone;
			cout << "��ȸ�� �л��� ��ȣ�� �Է��ϼ��� : ";
			cin >> phone;
			sl.searchStudent(phone);
			break;
		}
		case 4: {
			cout << "============= ���� - �̸� �� ��� =============" << endl;
			sl.sortByName();
			break;
		}
		case 5: {
			cout << "============= ���� - �г� �� ��� =============" << endl;
			sl.sortByGrade();
			break;
		}
		case 6: {
			cout << "============= ���� - ���� �� ��� =============" << endl;
			sl.sortByAge();
			break;
		}
		case 7: {
			cout << "============= �� - ��¥ �� ��� =============" << endl;
			sl.sortByInsertDate();
			break;
		}
		case 8: {
			cout << "============= ��ü ��� =============" << endl;
			sl.printList();
			break;
		}
		case 9: {
			exit(0);
		}
		}
	}
	return 0;
}