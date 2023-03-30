#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    string name;
    int roll_no;
    int marks[3];

    Student(string n, int r) {
        name = n;
        roll_no = r;
        for(int i=0; i<3; i++) {
            marks[i] = -1;
        }
    }

    void set_marks(int m[]) {
        for(int i=0; i<3; i++) {
            marks[i] = m[i];
        }
    }

    float calculate_average() {
        float sum = 0;
        for(int i=0; i<3; i++) {
            sum += marks[i];
        }
        return sum / 3;
    }

    void print_details() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll_no << endl;
        cout << "Marks: ";
        for(int i=0; i<3; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Average: " << calculate_average() << endl;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void add_student(string name, int roll_no) {
        Student s(name, roll_no);
        students.push_back(s);
    }

    void add_marks(int roll_no, int m[]) {
        for(int i=0; i<students.size(); i++) {
            if(students[i].roll_no == roll_no) {
                students[i].set_marks(m);
                return;
            }
        }
        cout << "Student not found with Roll No " << roll_no << endl;
    }

    void display_student_details(int roll_no) {
        for(int i=0; i<students.size(); i++) {
            if(students[i].roll_no == roll_no) {
                students[i].print_details();
                return;
            }
        }
        cout << "Student not found with Roll No " << roll_no << endl;
    }

    void display_all_students() {
        for(int i=0; i<students.size(); i++) {
            students[i].print_details();
            cout << endl;
        }
    }
};

int main() {
    StudentManagementSystem sms;

    // add students
    sms.add_student("John", 101);
    sms.add_student("Jane", 102);

    // add marks
    int m1[] = {70, 80, 90};
    sms.add_marks(101, m1);

    int m2[] = {60, 75, 85};
    sms.add_marks(102, m2);

    // display student details
    sms.display_student_details(101);
    sms.display_student_details(102);

    // display all students
    sms.display_all_students();

    return 0;
}
