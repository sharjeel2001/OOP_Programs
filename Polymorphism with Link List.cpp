// Program for Read And display data of Teachers and Students using Polymorphism and Singly Linked List
//Programmer Name :Muhammad Sharjeel
//Compilation Date: 11/12/2022
//Compiler Used: Microsoft Visual Studio (Community Edition)
//Smeaster # 3, OOP,International Islamic University
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class person {
    unsigned int id, age;
    string name, address;

public:
    person* next;
    person() {
        next = NULL;
        id = age = 0;
        name = address = "\0";
    }
    virtual void readData();
    virtual void displayData();
    virtual void isOutStanding() = 0;

};
void person::readData() {

    cout << "Enter Name:" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Enter ID(only Numaric):" << endl;
    cin >> id;
    cout << "Enter Age:" << endl;
    cin >> age;
    cout << "Enter Address:" << endl;
    cin.ignore();
    getline(cin, address);

}
void person::displayData() {
    cout << "*** Personal Info ***" << endl;
    cout << "Name:" << name << endl;
    cout << "Id:" << id << endl;
    cout << "Age:" << age << endl;
    cout << "Address:" << address << endl;
}
class student :virtual public person {
    string degree;
    float CGPA;
    unsigned int semester;
public:
    student() {
        degree = "\0";
        semester = 0;
        CGPA = 0.0;
    }
    void readData();
    void displayData();
    void isOutStanding();

};
void student::readData() {
    person::readData();
    cout << "Enter name of Degree:" << endl;
    cin.ignore();
    getline(cin, degree);

    cout << "Enter the semester:" << endl;
    cin >> semester;
    cout << "Enter the CGPA:" << endl;
    cin >> CGPA;
}
void student::isOutStanding() {
    if (CGPA >= 3.5) {
        cout << "Student is Out standing." << endl;
    }
}
void student::displayData() {
    person::displayData();
    cout << "***Academic Information***" << endl;
    cout << "Degree:" << degree << endl;
    cout << "Semester:" << semester << endl;
    cout << "CGPA:" << CGPA << endl;
}
class teacher :public person {
    unsigned int pub;
    int salary;
    string dept;
public:
    teacher() {
        dept =  "\0";
        pub =  0;
        salary = 0.0;
    }
    void readData();
    void displayData();
    void isOutStanding();

};
void teacher::readData() {
    person::readData();
    cout << "Enter no of Publication:" << endl;
    cin >> pub;

    cout << "Enter the Salary:" << endl;
    cin >> salary;
    cout << "Enter the Department:" << endl;
    cin.ignore();
    getline(cin, dept);
}
void teacher::isOutStanding() {
    if (pub >= 3) {
        cout << "Teacher Performance is Out Standing." << endl;
    }
}
void teacher::displayData() {
    person::displayData();
    cout << "***Academic Information***" << endl;
    cout << "No of Publications:" << pub << endl;
    cout << "Department:" << dept << endl;
    cout << "Salary:" << salary << endl << endl;
}

int main()
{
    person* pre = NULL,
        * first = NULL,
        * temp = NULL;
    char opt;
    int stNo = 0;

    int n = 0, t = 1, s = 1;
    do {
        cout << "** Main Menu **\n"
            << "1.Enter data for Teacher.\n"
            << "2.Enter data for student.\n"
            << "3. Display\n"
            << "4. exit" << endl;

        cout << "Enter your Choice:" << endl;
        cin >> opt;
        switch (opt) {
        case '1':
            cout << "how many teachers are of which you want to enter data?" << endl;
            cin >> stNo;
            for (int i = 0; i < stNo; i++)
            {


                temp = new teacher;
                temp->next = NULL;
                temp->readData();

                if (first == NULL)
                    first = pre = temp;
                else
                {
                    pre->next = temp;
                    pre = temp;

                }
                n++;
                system("cls");
            }


            break;
        case '2':

            cout << "how many Students are of which you want to enter data?" << endl;
            cin >> stNo;
            for (int i = 0; i < stNo; i++) {


                temp = new student;
                temp->next = NULL;
                temp->readData();

                if (first == NULL)
                    first = pre = temp;
                else
                {
                    pre->next = temp;
                    pre = temp;

                }
                n++;
                system("cls");
            }
            break;
        case '3':
            cout << "Total Number of Students and Teachers are " << n << endl;;
            temp = first;
            if (temp != NULL)
                cout << "Students are:\n" << endl;
           
            while (temp != NULL)
            {
                ;
                if (typeid(*temp) == typeid(student)) {
                    cout << "Student NO " << s++ << endl;;
                    temp->displayData();
                    temp->isOutStanding();
                    cout << "\n\n";
                }

                temp = temp->next;
            }
            temp = first;
            if (temp != NULL)
                cout << "Teachers are:\n" << endl;
           
            while (temp != NULL)
            {
                if (typeid(*temp) == typeid(teacher))
                {
                    cout << "Teacher NO " << t++ << endl;;
                    temp->displayData();
                    temp->isOutStanding();
                    cout << "\n\n";
                }
                temp = temp->next;
            }


            break;
        case '4':
            exit(0);
            break;
        }
        system("pause");
        system("cls");
    } while (1);
    return 0;
}