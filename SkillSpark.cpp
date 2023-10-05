#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <chrono>
#include <ctime>
#include <vector>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

class user
{
private:
    string username, password;
    char user_status;

public:
    string get_time()
    {
        auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string timeString = std::ctime(&currentTime);
        return timeString;
    }

    void user_welcome()
    {
        system("cls");
        cout << "\t\t\t SKILLSPARK : Igniting Interview Success through Practice and Skill Enhancement" << endl;
        cout << "\n";
        cout << "\t\tWelcome to a comprehensive practice platform designed to empower you with enhanced skills before your interviews, facilitating your professional growth & maximizing your chances of success. With a focus on skill development, this project offers you a range of practice exercises and resources to prepare for their upcoming interviews." << endl;
        cout << "__________________________________________________________________________________________________________________________" << endl;
        cout << "\n";
    }

    void user_login()
    {
        cout << "\t\t\t\t\t\t Are you a new user?(Y/N)   ";
        cin >> user_status;

        if (user_status == 'Y')
        {
            string password_confirm;
            int flag1 = 0, flag2 = 0;
            cout << "\n\t\t\t\t\tPlease Enter Username for You : ";
            cin >> username;
            while (true)
            {
                if (flag1 == 0)
                {
                    cout << "\n\t\t\t\t\tPlease Enter Password(8 Characters) ";
                    cin >> password;
                    if (password.length() != 8)
                    {
                        cout << "\n\t\t\t\t\tPlease Enter Password with 8 Characters ";
                        cin >> password;
                    }
                    else
                    {
                        flag1 = 1;
                    }
                }
                else if (flag2 == 0)
                {
                    cout << "\n\t\t\t\t\tPlease Confirm Your Password ";
                    cin >> password_confirm;
                    if (password != password_confirm)
                    {
                        cout << "Password doesn't match" << endl;
                        flag1 = 0;
                    }
                    else
                    {
                        flag2 = 1;
                    }
                }
                if (flag1 && flag2)
                {
                    break;
                }
            }
            ofstream reguser("usercredentials.txt", ios::app);
            reguser << "\n"
                    << username << " " << password;
            reguser.close();
            cout << "\t\t\t\t\tUsername Created Successfully" << endl;
        }
        else if (user_status == 'N')
        {
            int flag1 = 0;
            while (true)
            {
                cout << "\t\t\t\t\tPlease Enter Your Username ";
                cin >> username;
                cout << "\t\t\t\t\tPlease Enter Your Password ";
                cin >> password;
                if (user_check(username, password))
                {
                    flag1 = 1;
                }
                else
                {
                    cout << "\t\t\t\t\tInvalid Credentials" << endl;
                }
                if (flag1 == 1)
                {
                    cout << "\t\t\t\t\tWelcome Back >>>>" << username << "<<<<" << endl;
                    break;
                }
            }
        }
    }

    int user_check(string user, string pass)
    {
        int flag = 0;
        ifstream chkuser("usercredentials.txt", ios::in);
        string s1, s2;

        while (!chkuser.eof())
        {
            chkuser >> s1 >> s2;
            if (user == s1 && pass == s2)
            {
                flag = 1;
                break;
            }
        }
        chkuser.close();

        return flag;
    }

    void user_contribution()
    {
        string time = get_time();
        ofstream qstore("usercontri.txt", ios::app);
        qstore << username << " " << time;
        string que;
        while (true)
        {
            if (que == ".")
            {
                qstore << "\n";
                cout << "Thank You for Your Contribution !" << endl;
                break;
            }
            else
            {
                getline(cin, que);
                qstore << que << "\n";
            }
        }
        qstore.close();
        cout << "__________________________________________________________________________________________________________________________" << endl;
        cout << "\n";
    }

    void user_compete_login()
    {

        string password_confirm;
        int flag1 = 0, flag2 = 0;
        cout << "\n\t\t\t\t\tPlease Enter Username for You : ";
        cin >> username;
        while (true)
        {
            if (flag1 == 0)
            {
                cout << "\n\t\t\t\t\tPlease Enter Password(8 Characters) ";
                cin >> password;
                if (password.length() != 8)
                {
                    cout << "\n\t\t\t\t\tPlease Enter Password with 8 Characters ";
                    cin >> password;
                }
                else
                {
                    flag1 = 1;
                }
            }
            else if (flag2 == 0)
            {
                cout << "\n\t\t\t\t\tPlease Confirm Your Password ";
                cin >> password_confirm;
                if (password != password_confirm)
                {
                    cout << "Password doesn't match" << endl;
                    flag1 = 0;
                }
                else
                {
                    flag2 = 1;
                }
            }
            if (flag1 && flag2)
            {
                break;
            }
        }
        ofstream reguser("usercredentials.txt", ios::app);
        reguser << "\n"
                << username << " " << password;
        reguser.close();
        cout << "\t\t\t\t\tUsername Created Successfully" << endl;
    }

    void user_statistics()
    {
    }
};

class practice : public user
{
private:
    string skill, difficulty;
    vector<string> ans;
    int score = 0;

public:
    void practise_choice()
    {
        int s, d;
        cout << "Enter Number of Skill which you want to Practice on : " << endl;
        cout << "1.Skill1 2.Skill2 3.Skill3 4.Skill4 5.Skill5 " << endl;
        cin >> s;
        cout << "Enter Difficulty Level : " << endl;
        cout << "1.Easy 2.Medium 3.Hard " << endl;
        cin >> d;
        switch (s)
        {
        case 1:
            skill = "skill1";
            break;
        case 2:
            skill = "skill2";
            break;
        case 3:
            skill = "skill3";
            break;
        case 4:
            skill = "skill4";
            break;
        case 5:
            skill = "skill5";
            break;
        }
        switch (d)
        {
        case 1:
            difficulty = "Easy";
            break;
        case 2:
            difficulty = "Medium";
            break;
        case 3:
            difficulty = "Hard";
            break;
        }
    }

    void practice_display()
    {
        ifstream pracread("format.json");
        json que_data = json::parse(pracread);
        json data = que_data["Easy"]["set0"]["questions"];
        string que, temp;
        int cnt = 0;
        cout << "Let's start with your test" << endl;
        for (auto it = data.begin(); it != data.end(); it++)
        {
            que = it.value();
            cout << que << endl;
            cout << "Please Enter Your Answer : " << endl;
            cin >> temp;
            ans.push_back(temp);
        }
    }

    void practise_result()
    {
        ifstream ansread("format.json");
        json ans_data = json::parse(ansread);
        json data = ans_data["Easy"]["set0"]["answers"];
        string real_ans;
        int cnt = 0;
        for (auto it = data.begin(); it != data.end(); it++)
        {
            real_ans = it.value();
            if (real_ans == ans.at(cnt))
            {
                score++;
            }
            cnt++;
        }
        if (score >= 0 && score <= 4)
        {
            cout << "Your score is " << score << endl;
            cout << "Please Go through solutions to check where you went wrong ... " << endl;
        }
        else if (score == 5)
        {
            cout << "Congratulations ! You were able to solve all questions correctly " << endl;
        }
        // practice_result_store();
    }

    void practice_result_store()
    {
    }
};

class compete : public user
{
private:
    string user1, user2, pass1, pass2;
    int flag = 0;
    char status;
    vector<string> ans;

public:
    void compete_info()
    {
        cout << "\t\t\tPlease Enter Information of Player 1 : " << endl;
        cout << "\t\t\tAre You a New User ?(Y/N) ";
        cin >> status;
        if (status == 'Y')
        {
            user_compete_login();
            cout << "Please Enter Username of Player 1 : ";
            cin >> user1;
        }
        else if (status == 'N')
        {
            cout << "Please Enter Username of Player 1 : ";
            cin >> user1;
            cout << "Please Enter Password of Player 1 : ";
            cin >> pass1;
            if (user_check(user1, pass1))
            {
                cout << "Please Enter Information of Player 2 : " << endl;
                cout << "Are You a New User ?(Y/N) ";
                cin >> status;
                if (status == 'Y')
                {
                    user_compete_login();
                    cout << "Please Enter Username of Player 2 : ";
                    cin >> user2;
                }
                else if (status == 'N')
                {
                    cout << "Please Enter Username of Player 2 : ";
                    cin >> user2;
                    cout << "Please Enter Password of Player 2 : ";
                    cin >> pass2;
                }
                if (user_check(user2, pass2))
                {
                    compete_display();
                }
                else
                {
                    cout << "Invalid Credentials" << endl;
                    compete_info();
                }
            }
            else
            {
                cout << "Invalid Credentials" << endl;
                compete_info();
            }
        }
    }

    void compete_display()
    {
        ifstream competedis("compete.json");
        json que_read = json::parse(competedis);
        json data = que_read["set0"]["questions"];
        int cnt = 1;
        string temp, que;
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            if (cnt % 2 != 0)
            {
                cout << "Question for Player 1 : ";
                que = it.value();
                cout << que << endl;
                cin >> temp;
                ans.push_back(temp);
                cnt++;
            }
            else if (cnt % 2 == 0)
            {
                cout << "Question for Player 2 : ";
                que = it.value();
                cout << que << endl;
                cin >> temp;
                ans.push_back(temp);
                cnt++;
            }
            else if (cnt == 10)
            {
                break;
            }
        }
    }

    void compete_result()
    {
        string temp;
        int score1 = 0, score2 = 0, cnt = 0;
        ifstream competeans("compete.json");
        json ans_read = json::parse(competeans);
        json data = ans_read["set0"]["answers"];
        string real_ans;
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            real_ans = it.value();
            if (cnt % 2 == 0)
            {
                if (real_ans == ans.at(cnt))
                {
                    score1++;
                }
            }
            else
            {
                if (real_ans == ans.at(cnt))
                {
                    score2++;
                }
            }
            cnt++;
        }

        if (score1 > score2)
            cout << user1 << " takes the Win ! Congratulations !" << endl;
        else if (score2 > score1)
            cout << user2 << " takes the Win ! Congratulations !" << endl;
        else
            cout << "Oh! It's a Tie...Well Played Both of You" << endl;
    }

    void compete_result_store(int s1, int s2)
    {
    }
};

int main()
{
    user u;
    practice p;
    compete c;

    u.user_welcome();
    u.user_login();
    cout << "__________________________________________________________________________________________________________________________" << endl;
    cout << "\n";

    int choice;
    while (true)
    {
        cout << "\t\t\t\t\t\tWhat do you want to do??" << endl;
        cout << "\n\t\t\t   1.Practice 2.Compete 3.Contribute 4.Display Statistic 5.Create Test 6.Exit" << endl;

        cout << "\t\t\t\t\t    Please Enter Number of Your Choice   ";
        cin >> choice;
        cout << "\n";

        if (choice == 1)
        {
            p.practise_choice();
            p.practice_display();
            p.practise_result();
        }
        else if (choice == 2)
        {
            c.compete_info();
            c.compete_result();
        }
        else if (choice == 3)
        {
            cout << "Enter . to getting back to main menu" << endl;
            u.user_contribution();
        }
        else if (choice == 4)
        {
            u.user_statistics();
        }
        else if (choice == 5)
        {
        }
        else if (choice == 6)
        {
            cout << "\t\t\t\tThank You! Visit Again..." << endl;
            break;
        }
        else
        {
            cout << "Please Enter Correct Choice" << endl;
            cin >> choice;
        }
    }
    return 0;
}
