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
				cout << "이름 : " << studentList[i].getName() << endl;
				cout << "나이 : " << studentList[i].getAge() << endl;
				cout << "학과 : " << studentList[i].getMajor() << endl;
				cout << "학년 : " << studentList[i].getGrade() << endl;
				cout << "등록일 : " << studentList[i].getInsertDate() << endl;
				cout << "번호 : " << studentList[i].getPhone() << endl;
				break;
			}
		}
	}
	void sortByName() { //버블 정렬 사용해서 이름 순으로 정렬 (복사해서 원본은 바꾸지 말것)
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
			cout << "(" << i << "번째) " << endl;
			cout << "이름 : " << temp[i].getName() << endl;
			cout << "나이 : " << temp[i].getAge() << endl;
			cout << "학과 : " << temp[i].getMajor() << endl;
			cout << "학년 : " << temp[i].getGrade() << endl;
			cout << "등록일 : " << temp[i].getInsertDate() << endl;
			cout << "번호 : " << temp[i].getPhone() << endl;
		}
	}
	void sortByGrade() { //선택정렬 사용해서 학년 순으로 정렬
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
			cout << "(" << i << "번째) " << endl;
			cout << "이름 : " << temp[i].getName() << endl;
			cout << "나이 : " << temp[i].getAge() << endl;
			cout << "학과 : " << temp[i].getMajor() << endl;
			cout << "학년 : " << temp[i].getGrade() << endl;
			cout << "등록일 : " << temp[i].getInsertDate() << endl;
			cout << "번호 : " << temp[i].getPhone() << endl;
		}
	}
	void sortByAge() { //삽입정렬 사용해서 나이 순으로 정렬
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
			cout << "(" << i << "번째) " << endl;
			cout << "이름 : " << temp[i].getName() << endl;
			cout << "나이 : " << temp[i].getAge() << endl;
			cout << "학과 : " << temp[i].getMajor() << endl;
			cout << "학년 : " << temp[i].getGrade() << endl;
			cout << "등록일 : " << temp[i].getInsertDate() << endl;
			cout << "번호 : " << temp[i].getPhone() << endl;
		}
	}
	void sortByInsertDate() { //퀵정렬 사용해서 삽입 날짜 순으로 정렬
		Student *temp = new Student[current];

		for (int i = 0; i < current; i++) {
			temp[i] = studentList[i];
		}



		for (int i = 0; i < current; i++) {
			cout << "(" << i << "번째) " << endl;
			cout << "이름 : " << temp[i].getName() << endl;
			cout << "나이 : " << temp[i].getAge() << endl;
			cout << "학과 : " << temp[i].getMajor() << endl;
			cout << "학년 : " << temp[i].getGrade() << endl;
			cout << "등록일 : " << temp[i].getInsertDate() << endl;
			cout << "번호 : " << temp[i].getPhone() << endl;
		}
	}
	void printList() {
		for (int i = 0; i < current; i++) {
			cout << "(" << i << "번째) " << endl;
			cout << "이름 : " << studentList[i].getName() << endl;
			cout << "나이 : " << studentList[i].getAge() << endl;
			cout << "학과 : " << studentList[i].getMajor() << endl;
			cout << "학년 : " << studentList[i].getGrade() << endl;
			cout << "등록일 : " << studentList[i].getInsertDate() << endl;
			cout << "번호 : " << studentList[i].getPhone() << endl;
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

		cout << "배열의 크기가 " << capacity << "로 변경됨" << endl;
	}
};

int main() {
	int select;
	StudentList sl;
	while (1) {
		cout << "메뉴를 선택하세요." << endl;
		cout << "1. 학생 입력 " << endl;
		cout << "2. 학생 삭제" << endl;
		cout << "3. 학생 조회" << endl;
		cout << "4. 이름순 정렬" << endl;
		cout << "5. 학년순 정렬" << endl;
		cout << "6. 나이순 정렬" << endl;
		cout << "7. 등록날짜순 정렬" << endl;
		cout << "8. 전체 출력" << endl;
		cout << "9. 종료" << endl;

		cin >> select;

		switch (select) {
		case 1: {
			string name;
			string major;
			string phone;
			string date;
			int age;
			int grade;

			cout << "이름 : ";
			cin >> name;
			cout << "전공 : ";
			cin >> major;
			cout << "전화번호 : ";
			cin >> phone;
			cout << "학년 : ";
			cin >> grade;
			cout << "등록일 : ";
			cin >> date;
			cout << "나이 : ";
			cin >> age;

			Student s = Student(name, major, phone, grade, date, age);

			sl.insertStudent(s);
			break;
		}
		case 2: {
			string phone;
			cout << "삭제할 학생의 번호를 입력하세요 : ";
			cin >> phone;
			sl.deleteStudent(phone);
			break;
		}
		case 3: {
			string phone;
			cout << "조회할 학생의 번호를 입력하세요 : ";
			cin >> phone;
			sl.searchStudent(phone);
			break;
		}
		case 4: {
			cout << "============= 버블 - 이름 순 출력 =============" << endl;
			sl.sortByName();
			break;
		}
		case 5: {
			cout << "============= 선택 - 학년 순 출력 =============" << endl;
			sl.sortByGrade();
			break;
		}
		case 6: {
			cout << "============= 삽입 - 나이 순 출력 =============" << endl;
			sl.sortByAge();
			break;
		}
		case 7: {
			cout << "============= 퀵 - 날짜 순 출력 =============" << endl;
			sl.sortByInsertDate();
			break;
		}
		case 8: {
			cout << "============= 전체 출력 =============" << endl;
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