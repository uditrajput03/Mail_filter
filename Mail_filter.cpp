#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string st;
    string notallowed="remaining.txt";
    char sourcefile[50];
    cout << "Enter Source File with Extension: ";
    ifstream in;
    ofstream out;
    gets(sourcefile);
    in.open(sourcefile);
    string mail;
    if (!in || sourcefile==notallowed)
    {
        cout << "Error in Opening Source File,Try again or Select another...!!!";
        exit(1);
    }
    cout<<"Enter Domain (eg. @gmail.com,.edu):\n";
    cin>>mail;
    string extension=mail+".txt";

    cout << "Wait...!!!"<<endl;
    while (in.eof() == 0)
    {
        getline(in, st);
        if (st.find(mail) > 0 && st.find(mail) < 50)
        {
            // cout << st << endl;
            ofstream out(extension, ios::app);
            out << st << endl;
        }
        else
        {
            ofstream out("remaining.txt", ios::app);
            out << st << endl;
            // cout << "null" << endl;
        }
    }

    cout << "Done";
    return 0;
}