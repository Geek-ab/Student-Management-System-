//student management system project
#include<iostream>
#include<fstream>
using namespace std;
class student
{
    private:
    string fname,lname,course,address,email_id;
    int roll_no, contact_no;
    public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void Remov();
};
// menu 
void student::menu()
{
    int choice;
    char x;
do
{
    cout<<"------------------------------------------------"<<endl;
    cout<<"|-----------STUDENT MANAGEMENT SYSTEM-----------|"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"1.ENTER THE RECORD."<<endl;
    cout<<"2.DISPLAY THE RECORD."<<endl;
    cout<<"3.MODIFY THE RECORD."<<endl;
    cout<<"4.SEARCH THE RECORD."<<endl;
    cout<<"5.DELETE THE RECORD."<<endl;
    cout<<"6.EXIT."<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"|--------ENTER YOUR CHOICE[1/2/3/4/5/6]---------|"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cin>>choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout<<"------ENTER ANOTHER STUDENT RECORD(y/n)------"<<endl;
            cin>>x;
        } while (x =='y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        Remov();
        break;
    case 6:
        exit(0);
    
    default:
        cout<<"----INVALID CHOICE---PLEASE TRY AGAIN....";
    }
}while(choice!=6);
}
//inserting values in record
void student::insert()
{
    fstream file;
    
    cout << "-------------------------------------------------" << endl;
    cout << "--------------ADD STUDENT DETAILS----------------" << endl;
    cout << "-------------------------------------------------" << endl;
    
    cout << "ENTER FIRST NAME: ";
    cin >> fname;
    cout << "ENTER LAST NAME: ";
    cin >> lname;
    cout << "ENTER ROLL_NO: ";
    cin >> roll_no;
    cout << "ENTER COURSE: ";
    cin >> course;
    cout << "ENTER ADDRESS: ";
    cin >> address;
    cout << "ENTER EMAIL_ID: ";
    cin >> email_id;
    cout << "ENTER CONTACT_NO: ";
    cin >> contact_no;
    
    file.open("studentrecord.txt", ios::out | ios::app); // Open in append mode
    
    if (!file)
    {
        cout << "Error opening the file for appending." << endl;
    }
    else
    {
        file << fname << " " << lname << " " << roll_no << " " << course << " " << address << " " << email_id << " " << contact_no << endl;
        file.close();
        cout << "Student record added successfully." << endl;
    }
}

//display the record
void student::display()
{
    fstream file;
    string fname, lname ,roll_no, course, email_id, address, contact_no;

    cout << "-------------------------------------------------" << endl;
    cout << "|--------------STUDENT TABLE RECORD-------------|" << endl;
    cout << "-------------------------------------------------" << endl;
    
    file.open("studentrecord.txt", ios::in);
    
    if (!file)
    {
        cout << "NO DATA IS PRESENT....";
    }
    else
    {
        int total = 0; // Initialize the counter outside the loop
        
        while (file >> fname >> lname >> roll_no >> course >> email_id >> address >> contact_no)
        {
            cout << "STUDENT_NO: " << total++ << endl;
            cout << "STUDENT NAME: " << fname <<" "<<lname<< endl;
            cout << "STUDENT ROLL_NO: " << roll_no << endl;
            cout << "COURSE: " << course << endl;
            cout << "EMAIL_ID: " << email_id << endl;
            cout << "ADDRESS: " << address << endl;
            cout << "CONTACT_NO: " << contact_no << endl;
            cout << "-----------------------------------------" << endl;
        }
        
        if (total == 0)
        {
            cout << "NO DATA IS PRESENT IN FILE....";
        }
    }
    
    file.close();
}
//modify the record
void student::modify()
{
    fstream file;
    fstream file1;
    int found = 0;
    int rollno;
    
    cout << "------------------------------------------------" << endl;
    cout << "|------------STUDENT MODIFY DETAILS------------|" << endl;
    cout << "------------------------------------------------" << endl;
    
    file.open("studentrecord.txt", ios::in);
    
    if (!file)
    {
        cout << "NO DATA IS PRESENT....";
    }
    else
    {
        cout << "Enter roll_no of student which you want to modify: ";
        cin >> rollno;
        
        file1.open("record.txt", ios::out);
        
        while (file >> fname >> lname >> roll_no >> course >> address >> email_id >> contact_no)
        {
            if (rollno == roll_no)
            {
                cout << "ENTER FISRT NAME: ";
                cin >> fname;
                cout << "ENTER LAST NAME: ";
                cin >> lname;
                cout << "ENTER ROLL_NO: ";
                cin >> roll_no;
                cout << "ENTER COURSE: ";
                cin >> course;
                cout << "ENTER ADDRESS: ";
                cin >> address;
                cout << "ENTER EMAIL_ID: ";
                cin >> email_id;
                cout << "ENTER CONTACT_NO: ";
                cin >> contact_no;
                file1 << fname <<" "<<lname<< " " << roll_no << " " << course << " " << address << " " << email_id << " " << contact_no << endl;
                found++;
            }
            else
            {
                file1 << fname <<" "<<lname<< " " << roll_no << " " << course << " " << address << " " << email_id << " " << contact_no << endl;
            }
        }
        
        if (found == 0)
        {
            cout << "STUDENT ROLL NO NOT FOUND.....";
        }
        
        file1.close();
        file.close();
        
        remove("studentrecord.txt");
        rename("record.txt", "studentrecord.txt");
    }
}

//search the record
void student::search()
{
    fstream file;
    int found = 0;
    int rollno;

    cout << "------------SEARCH THE DATA--------------" << endl;
    cout << "ENTER THE ROLL NO OF STUDENT YOU WANT TO SEARCH: ";
    cin >> rollno;

    file.open("studentrecord.txt", ios::in);

    if (!file)
    {
        cout << "--------STUDENT DATA IS NOT FOUND--------" << endl;
    }
    else
    {
        while (file >> fname >>lname>> roll_no >> course >> address >> email_id >> contact_no)
        {
            if (rollno == roll_no)
            {
                cout << "STUDENT NAME: " << fname <<" "<<lname<< endl;
                cout << "STUDENT ROLL_NO: " << roll_no << endl;
                cout << "COURSE: " << course << endl;
                cout << "EMAIL_ID: " << email_id << endl;
                cout << "ADDRESS: " << address << endl;
                cout << "CONTACT_NO: " << contact_no << endl;
                found++;
                break; // Exit the loop since the record is found
            }
        }

        if (found == 0)
        {
            cout << "ROLL NO NOT FOUND" << endl;
        }

        file.close();
    }
}

//deletion of a record
void student::Remov()
{
    fstream file, file1;
    int rollno = 0;
    int found = 0;

    cout << "------------------DELETE STUDENT DETAILS----------------" << endl;
    file.open("studentrecord.txt", ios::in);

    if (!file)
    {
        cout << "-----NO DATA PRESENT...-----" << endl;
    }
    else
    {
        cout << "Enter roll no of student whose details you want to delete: ";
        cin >> rollno;

        file1.open("record.txt", ios::out);

        while (file >> fname >>lname>> roll_no >> course >> address >> email_id >> contact_no)
        {
            if (rollno != roll_no)
            {
                file1 << fname <<" "<<lname<< " " << roll_no << " " << course << " " << address << " " << email_id << " " << contact_no << endl;
            }
            else
            {
                found++;
                cout << "------SUCCESSFULLY DELETED THE DATA------" << endl;
            }
        }

        if (found == 0)
        {
            cout << "ROLL_NO NOT FOUND...." << endl;
        }

        file1.close();
        file.close();
        remove("studentrecord.txt");
        rename("record.txt", "studentrecord.txt");
    }
}

int main()
{
    student project;
    project.menu();
    return 0;
}