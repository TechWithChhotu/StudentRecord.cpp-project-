#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include<conio.h>
#include<direct.h>
#include<unistd.h>
#include<winable.h>
using namespace std;

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

class student
{
private:
    char Name[30];
    int Roll;
    char Course[20];
    char Gender[7];
    char Addresss[30];
    char Qualification[20];
    int QualifiedMarks;
    char MobileNO[11];
    char EmailID[35];

public:
    student()
    {
        strcpy(Name, "No");
        Roll = 0;
        strcpy(Course, "No");
        strcpy(Gender, "No");
        strcpy(Addresss, "No");
        strcpy(Qualification, "No");
        QualifiedMarks = 0;
        strcpy(MobileNO, "No");
        strcpy(EmailID, "No");
    }
    void SetData();          // COMPLETED
    void UpdateRec();        // COMPLETED
    void SearchRec();        //  COMPLETED
    void DeleteRec();        // COMPLETED
    void DisplayAllRec();    //  COMPLETED
    void DisplaySingleRec(); //  COMPLETED
    void ResetRec();         // COMPLETED
    void ChangePassword();   // COMPLETED
};

int CheckEmail(string str);    // COMPLETED
int CheckMobileNo(string mob); // COMPLETED
void Developer_into(){
    cout<<ANSI_COLOR_CYAN"\t\t\t-:Student Record:-\n\n";
    cout<<"\t\they my name is chhotu"<<endl;
    cout<<"\t\tI`m doing BCA form Munger University, Munger"<<endl;
    cout<<"\t\tMy Intrest for Coding\n\n\n";
    unsigned int ms=100;
    for (int i = 0; i < 30; i++)
    {
        cout<<(char)254;
    usleep(ms);
    }
    getch();
}
int main()
{
    int n;
    Developer_into();
    student s1;
    while (1)
    {
        system("cls");
        cout << ANSI_COLOR_MAGENTA __DATE__ << " " << __TIME__;
        cout << ANSI_COLOR_GREEN "\n-------------:HOME PAGE:-------------\n\n";
        cout << ANSI_COLOR_CYAN "1. Add new Record" << endl;
        cout << "2. Update Record" << endl;
        cout << "3. Search Record" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Display all Record(only office)" << endl;
        cout << "6. Reset Record(only office)" << endl;
        cout << "7. Change password(only office here)" << endl;
        cout << "8. Exit" << endl;
        cout << ANSI_COLOR_YELLOW "\n\n\tEnter your choice ?    " << ANSI_COLOR_RESET;
        cin >> n;

        char Mob[11];
        int ROLL;

        int i;

        switch (n)
        {
        case 1:
            s1.SetData();
            break;
        case 2:
            s1.UpdateRec();
            break;
        case 3:
            s1.SearchRec();
            break;

        case 4:
            s1.DeleteRec();
            break;
        case 5:
            s1.DisplayAllRec();
            break;
        case 6:
            s1.ResetRec();
            break;
        case 7:
            s1.ChangePassword();
            break;
        case 8:
            exit(0);
        default:
            cout << ANSI_COLOR_RED "Invalid choice! press any key to try again" << ANSI_COLOR_RESET << endl;
        }
        fflush(stdin);
        getch();
    }

    return 0;
}
void student::ChangePassword()
{
    system("cls");
    cout << ANSI_COLOR_MAGENTA __DATE__ << " " << __TIME__;
    cout << ANSI_COLOR_GREEN "\n-------------:RESET RECORD:-------------\n\n";
    fflush(stdin);
    string pass, pass2;
    ifstream fin;
    ofstream fout;
    fin.open("password.dat", ios::binary | ios::in | ios::out);
    getline(fin, pass);
    cout << ANSI_COLOR_YELLOW "Enter password: " << ANSI_COLOR_RESET;
    getline(cin, pass2);
    if (pass.compare(pass2) == 0)
    {
        cout << ANSI_COLOR_YELLOW "Enter  New password: " << ANSI_COLOR_RESET;
        getline(cin, pass2);
        fin.close();
        remove("passwords.dat");
        fout.open("password.dat");
        fout << pass2;
        cout << ANSI_COLOR_BLUE "\n\tPress any key to continue.....";
    }
    else
        cout << ANSI_COLOR_RED "\n\tWrong password" << ANSI_COLOR_BLUE << "\n\tPress any key to continue......" << ANSI_COLOR_RESET;
    fin.close();
    fout.close();
}

void student::ResetRec()
{
    system("cls");
    cout << ANSI_COLOR_MAGENTA __DATE__ << " " << __TIME__;
    cout << ANSI_COLOR_GREEN "\n-------------:RESET RECORD:-------------\n\n";
    fflush(stdin);
    string pass, pass2;
    ifstream fin;
    ofstream fout;
    fin.open("password.dat", ios::binary | ios::in);
    getline(fin, pass);
    cout << ANSI_COLOR_YELLOW "Enter password: " << ANSI_COLOR_RESET;
    getline(cin, pass2);

    if (pass.compare(pass2) == 0)
    {
        char check = 0;
        cout << ANSI_COLOR_RED "\n\tyou are sure all record delete:  ";
        cin >> check;
        if (check == 'Y' || check == 'y')
        {
            fout.open("Student.dat"); //***********yeha par delete function ka use karna hai after completin project*************
            fout.close();
            cout << ANSI_COLOR_RED << "\n\tsuccessfully deleted"
                 << "\n\tPress any key to continue....." << ANSI_COLOR_RESET;
        }
    }
    else
        cout << ANSI_COLOR_RED "\n\tWrong password" << ANSI_COLOR_BLUE << "\n\tPress any key to continue......" << ANSI_COLOR_RESET;
}

void student::DeleteRec()
{

    system("cls");
    cout << ANSI_COLOR_MAGENTA __DATE__ << " " << __TIME__;
    cout << ANSI_COLOR_GREEN "\n-------------:DELETE RECORD:-------------\n\n";
    fflush(stdin);
    int roll;
    char mob[11], j;
    fflush(stdin);
    cout << ANSI_COLOR_YELLOW "Enter Mobile Number:  " << ANSI_COLOR_RESET;
    cin.getline(mob, 11);
    cout << ANSI_COLOR_YELLOW "Enter Roll Number  :  " << ANSI_COLOR_RESET;
    cin >> roll;
    fflush(stdin);

    ifstream fin;
    ofstream fout;

    fin.open("Student.dat", ios::in | ios::binary);
    if (!fin)
        cout << ANSI_COLOR_RED "\nFile Not Found!\n";
    else
    {
        fout.open("temp.dat", ios::out | ios::binary);
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            if (roll != Roll && mob != MobileNO)
            {
            store:
                fout.write((char *)this, sizeof(*this));
            }
            else
            {
                char check = 0;
                DisplaySingleRec();
                cout << ANSI_COLOR_RED "\n\tyou are confom your record deleted: (y/N):  ";
                cin >> check;
                if (check == 'N' || check == 'n')
                    goto store;
            }
            fin.read((char *)this, sizeof(*this));
        }
    }
    fin.close();
    fout.close();
    remove("Student.dat");
    rename("temp.dat", "Student.dat");
    cout << ANSI_COLOR_BLUE "\npress any key to continue....\n"
         << ANSI_COLOR_RESET;
}
void student::SearchRec()
{
    system("cls");
    cout << ANSI_COLOR_MAGENTA __DATE__ << " " << __TIME__;
    cout << ANSI_COLOR_GREEN "\n-------------:SEARCH RECORD:-------------\n\n";
    fflush(stdin);
    int roll;
    char mob[11];
    fflush(stdin);
    cout << ANSI_COLOR_YELLOW "Enter Mobile Number:  " << ANSI_COLOR_RESET;
    cin.getline(mob, 11);
    cout << ANSI_COLOR_YELLOW "Enter Roll Number  :  " << ANSI_COLOR_RESET;
    cin >> roll;
    fflush(stdin);
    ifstream FRead;
    int k = 0;
    FRead.open("Student.dat", ios::binary);
    while (!FRead.eof())
    {
        FRead.read((char *)this, sizeof(*this));
        if (roll == Roll && strcmp(mob, MobileNO) == 0)
        {
            cout << endl;
            DisplaySingleRec();
            k = 1;
        }
    }
    if (!k)
        cout << ANSI_COLOR_RED << "\n\tRecord is not found!" << ANSI_COLOR_RESET;
    cout << ANSI_COLOR_BLUE "\n\tplease any key to continue..." << ANSI_COLOR_RESET;

    FRead.close();
}

void student::SetData()
{
    int j;
    system("cls");
    fflush(stdin);
    cout << ANSI_COLOR_MAGENTA __DATE__ << " " << __TIME__;
    cout << ANSI_COLOR_GREEN "\n-------:ENTER STUDENT DETAILS:-------\n\n";
    cout << ANSI_COLOR_YELLOW "Name               :   " << ANSI_COLOR_RESET;
    fflush(stdin);
    cin.getline(Name, 30);
    cout << ANSI_COLOR_YELLOW "\nRoll No            :   " << ANSI_COLOR_RESET;
    cin >> Roll;
    fflush(stdin);
    cout << ANSI_COLOR_YELLOW "\nCourse Name        :   " << ANSI_COLOR_RESET;
    cin.getline(Course, 30);
    cout << ANSI_COLOR_YELLOW "\nGender             :   " << ANSI_COLOR_RESET;
    cin.getline(Gender, 7);
    cout << ANSI_COLOR_YELLOW "\nAddress            :   " << ANSI_COLOR_RESET;
    cin.getline(Addresss, 30);
    cout << ANSI_COLOR_YELLOW "\nQualification      :   " << ANSI_COLOR_RESET;
    cin.getline(Qualification, 20);
    cout << ANSI_COLOR_YELLOW "\nQualification Marks:   " << ANSI_COLOR_RESET;
    cin >> QualifiedMarks;
    fflush(stdin);
    cout << ANSI_COLOR_YELLOW "\nMobile Number      :   " << ANSI_COLOR_RESET;
Mob:
    cin.getline(MobileNO, 11);
    j = CheckMobileNo(MobileNO);
    if (j != 10)
    {
        cout << ANSI_COLOR_RED "\n\tinvalid Mobile Number\n"
             << ANSI_COLOR_YELLOW "please Enter valid Mobile Number: " << ANSI_COLOR_RESET;
        goto Mob;
    }
    cout << ANSI_COLOR_YELLOW "\nEmail Address      :   " << ANSI_COLOR_RESET;
Email:
    cin.getline(EmailID, 35);
    j = CheckEmail(EmailID);
    if (j != 9)
    {
        cout << ANSI_COLOR_RED "\n\tinvalid Email\n"
             << ANSI_COLOR_YELLOW "please Enter valid Email: " << ANSI_COLOR_RESET;
        goto Email;
    }
    fflush(stdin);
    ofstream FWrite;
    FWrite.open("Student.dat", ios::app | ios::binary);
    if (FWrite.write((char *)this, sizeof(*this)))
    {
        cout << ANSI_COLOR_RED "\n\tRecord Saved successfully" << endl;
    }
    else
        cout << ANSI_COLOR_RED "Record Saved failed" << endl;
    FWrite.close();
    cout << ANSI_COLOR_BLUE "\tpress any key to continue.....   ";
}

void student::DisplaySingleRec()
{
    cout << ANSI_COLOR_GREEN "Name :   " << ANSI_COLOR_CYAN << Name;
    cout << ANSI_COLOR_YELLOW "\n       Roll No            :   " << ANSI_COLOR_RESET << Roll;
    cout << ANSI_COLOR_YELLOW "\n       Course Name        :   " << ANSI_COLOR_RESET << Course;
    cout << ANSI_COLOR_YELLOW "\n       Gender             :   " << ANSI_COLOR_RESET << Gender;
    cout << ANSI_COLOR_YELLOW "\n       Address            :   " << ANSI_COLOR_RESET << Addresss;
    cout << ANSI_COLOR_YELLOW "\n       Qualification      :   " << ANSI_COLOR_RESET << Qualification;
    cout << ANSI_COLOR_YELLOW "\n       Qualification Marks:   " << ANSI_COLOR_RESET << QualifiedMarks;
    cout << ANSI_COLOR_YELLOW "\n       Mobile Number      :   " << ANSI_COLOR_RESET << MobileNO;
    cout << ANSI_COLOR_YELLOW "\n       Email Address      :   " << ANSI_COLOR_RESET << EmailID << endl;
    cout << ANSI_COLOR_RED << "\t\t______________" << ANSI_COLOR_RESET << " ";
}
void student::DisplayAllRec()
{
    system("cls");
    cout << ANSI_COLOR_MAGENTA __DATE__ << " " << __TIME__;
    cout << ANSI_COLOR_GREEN "\n--------:ALL RECORDS:--------\n\n";
    fflush(stdin);
    string pass, pass2;
    ifstream fin;
    fin.open("password.dat", ios::binary | ios::in);
    fin.seekg(0);
    getline(fin, pass);
    fin.close();
    cout << ANSI_COLOR_YELLOW "Enter password: " << ANSI_COLOR_RESET;
    getline(cin, pass2);
    if (pass.compare(pass2) == 0)
    {
        ifstream FRead;
        int i = 1;
        FRead.open("Student.dat", ios::binary);
        FRead.seekg(0);
        // cout<<"k = "<<k;
        while (!FRead.eof())
        {
            FRead.read((char *)this, sizeof(*this));
            cout << endl;
            cout << ANSI_COLOR_RED << i << " ";
            DisplaySingleRec();
            i++;
        }
        FRead.close();
    }
    else
        cout << ANSI_COLOR_RED "\n\tWrong password" << ANSI_COLOR_BLUE << "\n\tPress any key to continue......" << ANSI_COLOR_RESET;
}

void student::UpdateRec() // this blok problem....!
{
    system("cls");
    cout << ANSI_COLOR_MAGENTA __DATE__ << " " << __TIME__;
    cout << ANSI_COLOR_GREEN "\n--------:UPDATE RECORDS:--------\n\n";
    fflush(stdin);
    fstream fin;
    fin.open("Student.dat", ios::in | ios::binary | ios::out);
    fin.seekg(0);

    int roll, k = 0;
    char mob[11];
    cout << "Enter Mobile Number:  ";
    cin.getline(mob, 11);
    cout << "Enter Roll Number  :  ";
    cin >> roll;
    fflush(stdin);
    fin.read((char *)this, sizeof(*this));
    while (!(fin.eof()))
    {
        if ((roll == Roll) && strcmp(mob, MobileNO) == 0)
        {
            int n;
            k = 1;
            cout << ANSI_COLOR_CYAN << "\nWhat do you want to update\n"
                 << endl;
            cout << ANSI_COLOR_YELLOW "1. Name\n2. Address\n3. Mobile Number\n4. Email\n"
                 << ANSI_COLOR_RED "\n\tEnter your choice  ?   " << ANSI_COLOR_RESET;
            cin >> n;
            switch (n)
            {
            case 1:
                cout << ANSI_COLOR_YELLOW "Name               :   " << ANSI_COLOR_RESET;
                fflush(stdin);
                cin.getline(Name, 30);
                break;
            case 2:
                fflush(stdin);
                cout << ANSI_COLOR_YELLOW "\nAddress            :   " << ANSI_COLOR_RESET;
                cin.getline(Addresss, 30);
                break;
            case 3:
                fflush(stdin);
                cout << ANSI_COLOR_YELLOW "\nMobile Number      :   " << ANSI_COLOR_RESET;
                cin.getline(MobileNO, 11);
                break;
            case 4:
                cout << ANSI_COLOR_YELLOW "\nEmail Address      :   " << ANSI_COLOR_RESET;
                fflush(stdin);
                cin.getline(EmailID, 35);
                break;

            default:
                cout << "\n\tinvalid choice!";
                break;
            }
            fflush(stdin);
            fin.seekg((fin.tellg()) - sizeof(*this));
            fin.write((char *)this, sizeof(*this));
        }
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
    if (k == 0)
        cout << ANSI_COLOR_RED "\n\tThis record is not found !" << ANSI_COLOR_RESET;
    else
        cout << ANSI_COLOR_RED "\n\tRecord update successfully" << endl;
    cout << ANSI_COLOR_BLUE "\n\tpress any key to continue...";
}
int CheckEmail(string str)
{
    int i, j = 0;
    string str2 = "@gmail.com";
    for (i = 0; str[i]; i++)
    {
        if (str[i] == str2[j])
        {
            j++;
            if (j == 9)
                break;
        }
        else
            j = 0;
    }
    return j;
}
int CheckMobileNo(string mob)
{
    int r = mob.size();
    return r;
}
