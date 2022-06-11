#include <bits/stdc++.h>
using namespace std;

// 1. Define models - Snake , Ladder , GameBoard, Player
// 2. Define Services ( controllers that contact with models and store) - DiceService, SnakeLadderService
// 3. Define Driver

class Snake
{
private:
    int mouth;
    int tail;

public:
    Snake(int mouth, int tail)
    {
        this->mouth = mouth;
        this->tail = tail;
    }
    int getMouth()
    {
        return this->mouth;
    }
    int getTail()
    {
        return this->tail;
    }
    // TODO: setters to be declared
};

class Ladder
{
private:
    int start;
    int end;

public:
    Ladder(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
    int getStart()
    {
        return this->start;
    }
    int getEnd()
    {
        return this->end;
    }
    // TODO: setters to be declared
};

class Player
{
private:
    string name;
    string email;

public:
    Player(string name, string email)
    {
        this->name = name;
        this->email = email;
    }
    string getName()
    {
        return this->name;
    }
    string getEmail()
    {
        return this->email;
    }
};

class Board
{
private:
    vector<Snake> snakes;
    vector<Ladder> ladders;
    queue<Player> players;
    int size;

public:
    unordered_map<string, int> position_of_player;
    Board(vector<Snake> snakes, vector<Ladder> ladders, vector<Player> playersArray, int size)
    {
        this->ladders = ladders;
        this->snakes = snakes;
        this->size = size;
        for (auto player : playersArray)
        {
            this->players.push(player);
            position_of_player[player.getName()] = 0;
        }
        // while (!this->players.empty())
        // {
        //     Player curr = this->players.front();
        //     this->players.pop();
        //     cout<<curr.getName()<<endl;
        // }
        
    }
    vector<Snake> getSnakes()
    {
        return this->snakes;
    }
    vector<Ladder> getLadders()
    {
        return this->ladders;
    }
    queue<Player> getPlayers()
    {
        return this->players;
    }
    int getSize()
    {
        return this->size;
    }
};

// Time to create some services to interact with these models

class DiceService
{
public:
    int roll()
    {
        vector<int> possibilty = {1, 2, 3, 4, 5, 6};
        return possibilty[rand() % 6];
    }
};

class SnakeLadderService
{
private:
    const int DEFAULT_BOARD_SIZE = 100;
    Board *board;
    DiceService dice;
    bool isGameComplete;
    int getNewPositionAfterSnakeAndLadders(int newPosition)
    {
        for (auto snake : this->board->getSnakes())
        {
            if (snake.getMouth() == newPosition)
            {
                return getNewPositionAfterSnakeAndLadders(snake.getTail());
            }
        }
        for (auto ladder : this->board->getLadders())
        {
            if (ladder.getStart() == newPosition)
            {
                return getNewPositionAfterSnakeAndLadders(ladder.getEnd());
            }
        }
        return newPosition;
    }
    int getNewPosition(int position, int diceRoll)
    {
        if ((position + diceRoll) <= this->board->getSize())
        {
            return position + diceRoll;
        }
        else
            return position;
    }

public:
    SnakeLadderService(vector<Snake> snakes, vector<Ladder> ladders, vector<Player> players)
    {
        this->board = new Board(snakes, ladders, players, DEFAULT_BOARD_SIZE);
        this->isGameComplete = false;
    }
    void startGame()
    {
        queue<Player> q = this->board->getPlayers();
        do
        {   
            Player curr = q.front();
            q.pop();
            int currentPosition = this->board->position_of_player[curr.getName()];
            int diceRoll = dice.roll();
            int newPosition = getNewPosition(currentPosition, diceRoll);
            newPosition = getNewPositionAfterSnakeAndLadders(newPosition);
            if (newPosition == this->board->getSize())
            {
                cout << curr.getName() << " has won the Game !!!!!!" << endl;
                return;
            }
            else
            {
                cout << curr.getName() << " got a " << diceRoll << " and reached " << newPosition << endl;
                this->board->position_of_player[curr.getName()] = newPosition;
                q.push(curr);
            }
        } while (!this->isGameComplete);
        return;
    }
};

int main()
{
    int noOfSnakes;
    int noOfLadders;
    cout<<"Enter no of Snakes and Ladders  "<<endl;
    cin >> noOfSnakes >> noOfLadders;
    vector<Snake> snakes;
    vector<Ladder> ladders;
    vector<Player> players;
    cout<<"Enter snakes - mouth and tail "<<endl;
    for (int i = 0; i < noOfSnakes; i++)
    {
        int mouth, tail;
        cin >> mouth >> tail;
        Snake s(mouth, tail);
        snakes.push_back(s);
    }
    cout<<"Enter ladders - start and end "<<endl;
    for (int i = 0; i < noOfLadders; i++)
    {
        int start, end;
        cin >> start >> end;
        Ladder l(start, end);
        ladders.push_back(l);
    }
    int noOfPlayers;
    cout<<"ENter no of players "<<endl;
    cin >> noOfPlayers;
    cout<<"Enter players - name and email "<<endl;
    for (int i = 0; i < noOfPlayers; i++)
    {
        string name, email;
        cin >> name >> email;
        Player p(name, email);
        players.push_back(p);
    }
    SnakeLadderService game(snakes, ladders, players);
    game.startGame();
    return 0;
}
