#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
	int id;
	string name;
	string course;
	int age;
};

class StudentRecordSystem {
	private:
		vector<Student> students;

	public:
		void addStudent() {
			Student student;
			cout << "Enter student ID: ";
			cin >> student.id;
			cin.ignore();
			cout << "Enter student name: ";
			getline(cin, student.name);
			cout << "Enter student age: ";
			cin >> student.age;
			cin.ignore();
			cout << "Enter student course: ";
			getline(cin, student.course);

			students.push_back(student);
			cout << "Student was successfully added!" << endl;
		}
		void displayStudent() {
			if (students.empty()) {
				cout << "No student found in record" << endl;
				return;
			}
			cout << "Student Record:" << endl;
			for (const auto& student : students) {
				cout << "ID: " << student.id << endl;
				cout << "Name: " << student.name << endl;
				cout << "Age: " << student.age << endl;
				cout << "Course: " << student.course << endl;
			}
		}
		void searchStudent() {
			int searchId;
			cout << "Enter ID student to search for: ";
			cin >> searchId;
			for (const auto& student : students) {
				if (student.id == searchId) {
					cout << "Student Found: "
						<< "ID: " << student.id
						<< ", Name: " << student.name
						<< ", Age: " << student.age
						<< ", Course: " << student.course << endl;
					return;
				}
			}
			cout << "Student with ID " << searchId << " not found" << endl;
		}
		void updateStudent() {
			int updateId;
			cout << "Enter Student ID to update: ";
			cin >> updateId;

			for (auto& student : students) {
				if (student.id == updateId) {
					cout << "Enter New Name: ";
					cin.ignore();
					getline(cin, student.name);
					cout << "Enter New Age: ";
					cin >> student.age;
					cin.ignore();
					cout << "Enter New Course: ";
					getline(cin, student.course);

					cout << "Student record updated successfully!\n";
					return;
				}
			}
			cout << "Student with ID " << updateId << " not found." << endl;
		}
		void deleteStudent() {
			int deleteId;
			cout << "Enter Student ID to delete: ";
			cin >> deleteId;

			for (auto it = students.begin(); it != students.end(); ++it) {
				if (it->id == deleteId) {
					students.erase(it);
					cout << "Student record deleted successfully!\n";
					return;
				}
			}

			cout << "Student with ID " << deleteId << " not found.\n";
		}
};

int main() {
	StudentRecordSystem system;
	int choice;

	do {
		cout << "Student Record System Menu:" << endl;
		cout << "1. Add Student" << endl;
		cout << "2. Display All Students" << endl;
		cout << "3. Search Student by ID" << endl;
		cout << "4. Update Student" << endl;
		cout << "5. Delete Student" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			system.addStudent();
			break;
		case 2:
			system.displayStudent();
			break;
		case 3:
			system.searchStudent();
			break;
		case 4:
			system.updateStudent();
			break;
		case 5:
			system.deleteStudent();
			break;
		case 0:
			cout << "Exiting the program." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 0);

	return 0;
}