#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class user
{
private:
    string username, password, current_user;

public:
    void user_login(char status)
    {
        if (status == 'Y')
        {
            string password_confirm;
            cout << "\n\t\t\t\t\tPlease Enter Username for You   ";
            cin >> username;
        rey:
            cout << "\n\t\t\t\t\tPlease Enter Password(8 Characters) ";
            cin >> password;
            if (password.length() != 8)
            {
                cout << "\n\t\t\t\t\tPlease Enter Password with 8 Characters ";
                cin >> password;
            }
            cout << "\n\t\t\t\t\tPlease Confirm Your Password ";
            cin >> password_confirm;

            if (password == password_confirm)
            {
                ofstream reguser("usercredentials.txt", ios::app);
                reguser << "\n"
                        << username << " " << password;
                reguser.close();
            }
            else
            {
                cout << "\t\t\t\t\tPassword doesn't match" << endl;
                goto rey;
            }
            cout << "\t\t\t\t\tUsername Created Successfully" << endl;
            current_user = username;
        }
        else if (status == 'N')
        {
        ren:
            cout << "\t\t\t\t\tPlease Enter Your Username ";
            cin >> username;
            cout << "\t\t\t\t\tPlease Enter Your Password ";
            cin >> password;

            int flag = 0;
            ifstream chkuser("usercredentials.txt", ios::in);
            string s1, s2;

            while (!chkuser.eof())
            {
                chkuser >> s1 >> s2;
                if (username == s1 && password == s2)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag)
            {
                cout << "\t\t\t\t\tWelcome Back >>>>" << username << "<<<<" << endl;
            }
            else
            {
                cout << "\t\t\t\t\tInvalid Credentials" << endl;
                goto ren;
            }
        }
        else
        {
            char re;
            cout << "\t\t\t\t\tPlease Enter 'Y' for Yes and 'N' for No" << endl;
            cin >> re;
            user_login(re);
        }
    }
};

class test
{
private:
public:
};

int main()
{
    char user_status;
    user u;

    system("cls");
    cout << "\t\t\t SKILLSPARK : Igniting Interview Success through Practice and Skill Enhancement" << endl;
    cout << "\n";
    cout << "\t\tWelcome to a comprehensive practice platform designed to empower you with enhanced skills before your interviews, facilitating your professional growth & maximizing your chances of success. With a focus on skill development, this project offers you a range of practice exercises and resources to prepare for their upcoming interviews." << endl;
    cout << "___________________________________________________________________________________________________________________________" << endl;
    cout << "\n";

    cout << "\t\t\t\t\t\t Are you a new user?(Y/N)   ";
    cin >> user_status;

    u.user_login(user_status);

    cout << "___________________________________________________________________________________________________________________________" << endl;

    return 0;
}