// Design a leaderboard that supports the following functionalities: 
// 1. addUser() – the ability to add new Users with the attribute name, email, and score. The initial score should be zero.  
// 2. updateScore() – the ability to update the score of a user with the given value.  
// 3. getRank() – the ability to get the rank of the given user. 
// If two users have the same score, then the user who was added before will have a better rank(i.e. lower value). 
// 4. getFirstK() – the ability to get the list of users with rank less than equal to K. 
// I created two classes and gave the brute-force approach for all the functions.
// Then, the interviewers told me the expected time complexity for each of the functions. 
// After some time and hints, I told them an approach that uses BST and also modified the classes that I created.
// We discussed the approach in detail and the time complexity for each function. 
// After this, we were short on time, so the interviewers told me to assume certain functions and complete my code.


//https://www.geeksforgeeks.org/uber-interview-experience-for-sde-1-off-campus-2021/

#include <bits/stdc++.h>
using namespace std;

class User
{
public:
    string name;
    string email;
    int score;
    User()
    {
    }
    User(string name, string email, int score)
    {
        this->name = name;
        this->email = email;
        this->score = score;
    }
};

struct comparator
{
    bool operator()(const pair<int, int> o, const pair<int, int> p) const
    {
        if(o.first == p.first){
            return p.second > o.second;
        }
        return o.first > p.first;
    }
};

class Leaderboard
{
    map<pair<int, int>, User, comparator> scoresheet;

public:
    void addUser(string name, string email, int score)
    {
        User user(name, email, score);
        int entryId = scoresheet.size() + 1;
        pair p = {score, entryId};
        scoresheet[p] = user;
        cout << "Uer Added :) " << endl;
    }

    void showLeaderBoard()
    {
        cout << "The leaderboard is as follows: " << endl;
        for (auto score : scoresheet)
        {
            cout << score.first.first << " " << score.first.second << " " << score.second.name << endl;
        }
    }

    void upDateUser(string email, int newScore)
    {
        for (auto score : scoresheet)
        {
            if (score.second.email == email)
            {
                int oldScore = score.first.first;
                int entryrank = score.first.second;
                User user = score.second;
                scoresheet.erase({oldScore, entryrank});
                scoresheet[{newScore, entryrank}] = user;
                cout << "Updated User score " << endl;
                return;
            }
        }
        cout << "Could not find user " << endl;
    }

    void getRank(string email)
    {
        int rank = 1;
        for (auto score : scoresheet)
        {
            if (score.second.email == email)
            {
                int oldScore = score.first.first;
                int entryrank = score.first.second;
                User user = score.second;
                cout << "Rank of user is " << rank << endl;
                return;
            }
            rank++;
        }
        cout << "Could not find user " << endl;
    }

    void getFirstK(int k)
    {
        int count = 1;
        for (auto score : scoresheet)
        {
            if (k == 0)
                return;
            int Score = score.first.first;
            int entryrank = score.first.second;
            User user = score.second;
            cout << "Rank of " << user.name << " is " << count<<endl;
            k--;
            count++;
        }
    }
};

int main()
{
    Leaderboard lb;
    lb.addUser("Ankit", "an@pa1", 110);
    lb.addUser("Nanni", "an@pa", 100);
    lb.addUser("Papa", "an@pa", 100);
    lb.addUser("mummy", "an@pa", 120);
    lb.addUser("Surabhi", "an@pa", 100);
    lb.showLeaderBoard();
    lb.upDateUser("an@pa1", 400);
    lb.showLeaderBoard();
    lb.getRank("an@pa1");
    lb.getFirstK(3);
}