#include <iostream>
#include <string>
#include <typeinfo>
#include <iomanip>
#define MAX 100

using namespace std;

class person {
protected:
    unsigned int pid, age;
    string name, address;
public:
    person() {
        pid = age = 0;
        name = address = "\0";
    }
    virtual void readd();
    virtual void display()const;
    virtual void isoutstanding() = 0;
    ~person() {}
};
void person::readd() {

    cout << "Enter the Name:" << endl;
    cin.ignore(2, '\n');
    getline(cin, name);
    //cin.ignore();
    cout << "Enter ID:" << endl;
    cin >> pid;
    cout << "Enter Age:" << endl;
    cin >> age;
    cout << "Enter the Address:" << endl;
    cin.ignore(2, '\n');
    getline(cin, address);
    // cin.ignore();
}
void person::display()const {
    cout << "\n\n*** Personal Info ***" << endl;
    cout << "Name:" << name << endl;
    cout << "Id:" << pid << endl;
    cout << "Age:" << age << endl;
    cout << "Address:" << address << endl;
}
class student :virtual public person {
protected:
    string degree;
    float CGPA;
    unsigned int semester;
public:
    student() {
        degree = name = address = "\0";
        semester = pid = age = 0;
        CGPA = 0.0;
    }
    void readData();
    void display()const;
    void isOutStanding();
    ~student() {}
};
void student::readData() {
    person::readd();
    cout << "Enter name of Degree:" << endl;
    cin.ignore(1,'\n');
    getline(cin, degree);
    
    cout << "Enter the semester:" << endl;
    cin >> semester;
    cout << "Enter the CGPA:" << endl;
    cin >> CGPA;
}
void student::isOutStanding() {
    if (CGPA >= 3.5) {
        cout << "Out standing." << endl;
    }
}
void student::display()const {
    person::display();
    cout << "Address:" << address << endl;
    cout << "** Academics Info **" << endl;
    cout << "Degree:" << degree << endl;
    cout << "Semester:" << semester << endl;
    cout << "CGPA:" << CGPA << endl;
}
class teacher :public person {
protected:
    unsigned int pub;
    int salary;
    string dept;
public:
    teacher() {
        dept = name = address = "\0";
        pub = pid = age = 0;
        salary = 0.0;
    }
    void readd();
    void display()const;
    void isoutstanding();
    ~teacher();
};
void teacher::readd() {
    person::readd();
    cout << "Enter no of Publication:" << endl;
    cin >> pub;
   
    cout << "Enter the Salary:" << endl;
    cin >> salary;
    cout << "Enter the Department:" << endl;
    cin.ignore(10, '\n');
    getline(cin, dept);
}
void teacher::isoutstanding() {
    if (pub >= 5) {
        cout << "Out Standing." << endl;
    }
}
void teacher::display()const {
    person::display();
    cout << "No of Publications:" << pub << endl;
    cout << "Department:" << dept << endl;
    cout << "Salary:" << salary << endl << endl;
}

int main()
{
    person* ptr[MAX];
    char opt;
    int stNo=0;
    int tNo = 0;
    int n = 0, t = 0,s=0;
    do {
        cout << setw(50) << "** Main Menu **" << endl;
        cout << "1.Enter data for Professor." << endl;
        cout  << "2.Enter data for student." << endl;
        cout << "3. Display" << endl;
        cout << "4. exit" << endl;
       
        cout << "Enter your Choice:" << endl;
        cin >> opt;
        switch (opt) {
        case '1':
            ptr[n] = new teacher;
            cout << "how many teacher" << endl;
            cin >> tNo;
            for (int i = 0;i < tNo;i++) {
                ptr[n]->readd();
                n++;
                t++;
            }
            //cout << "sytem capabilities are full." << endl;

            break;
        case '2':

           
            ptr[n] = new student;
            cout << "how many students" << endl;
            cin >> stNo;
            for (int i = 0;i < stNo;i++) {
                ptr[n]->readd();
                n++;
                t++;
            }
            //else {
            //    cout << "sytem capabilities are full." << endl;
            //}
            break;
        case '3':
            for (int i = 0;i < n;i++)
            {
                if (typeid(*ptr[i]) == typeid(student)) {
                    cout << "Students are:" << endl;
                    ptr[i]->display();
                    ptr[i]->isoutstanding();
                    
                }
                if(typeid(*ptr[i]) == typeid(teacher)) {
                    cout << "teachers are:" << endl;
                    ptr[i]->display();
                    ptr[i]->isoutstanding();
                    t++;
                }
          }
        case '5':
            exit(0);
            break;
        }
    } while (1);
}