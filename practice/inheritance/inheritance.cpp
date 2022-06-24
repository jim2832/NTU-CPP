#include <iostream>
#include <string>
using namespace std;

class Person{
    public:
        void inputPerson(){
            char str[128];
            cout << "請輸入個人資料" << endl;

            cout << "姓名: ";
            fflush(stdin);
            cin.getline(str,128);
            Name = str;

            cout << "電話: ";
            cin >> Phone;

            cout << "Email: ";
            cin >> Email;
        }

        void outputPerson(){
            cout << "<印出個人資料>" << endl;
            cout << "姓名" << Name << endl;
            cout << "電話" << Phone << endl;
            cout << "Email" << Email << endl;
        }

    //private:
    protected: //受保護的成員，可以被子類別直接使用，但private不行
        string Name;
        string Phone;
        string Email;
};

//inheritance class
class Student: public Person{
    public:
        void inputStudent(){
            cout << "<輸入學生資料>" << endl;

            inputPerson();

            cout << "學號: ";
            cin >> StudentID;

            cout << "系所: ";
            cin >> Department;
        }

        void outputStudent(){
            cout << "<印出學生資料>" << endl;
            outputPerson();
            cout << "學號: " << StudentID << endl;
            cout << "系所: " << Department << endl; 
        }

    private:
        string StudentID;
        string Department;
};

class Teacher: public Person{
    public:
        void inputTeacher(){
            cout << "<輸入老師資料>" << endl;
            inputPerson();

            cout << "職稱: ";
            cin >> Title;

            cout << "系所: ";
            cin >> Department;
        }

        void outputTeacher(){
            cout << "<印出老師資料>" << endl;
            outputPerson();
            cout << "職稱: " << Title << endl;
            cout << "系所: " << Department << endl; 
        }

    private:
        string Title;
        string Department;
};

int main(void){
    Student s1;
    Teacher t1;
    //s1.inputPerson();
    s1.inputStudent();
    
    cout << endl;

   // s1.outputPerson();
    s1.outputStudent();

    cout << endl;

    //t1.inputPerson();
    t1.inputTeacher();

    cout << endl;

    //t1.outputPerson(); 
    t1.outputTeacher();

    return 0;
}