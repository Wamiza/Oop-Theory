#include <iostream>
#include <string>
using namespace std;

 // 24K-0010 WAMIZA NOMAN

struct Position {
    int x, y;
    Position(int x, int y) : x(x), y(y) {}
};

class Ball {
private:
    int ballX, ballY;
public:
    Ball(int x = 0, int y = 0) : ballX(x), ballY(y) {}
    int getX() {
	    return ballX; 
	    }
    int getY() { 
	    return ballY; 
		}
    void move(int dx, int dy) { 
	    ballX += dx; ballY += dy; 
		}
    void reset() { 
	    ballX = 0; ballY = 0; 
		}
	Position getPosition() {
        return Position(ballX, ballY);
    }
};

class Goal {
public:
    int goalX, goalY;
    Goal(int x, int y) : goalX(x), goalY(y) {}
    bool isGoalReached(int ballX, int ballY) { 
	    return (ballX == goalX && ballY == goalY); 
    	}
};

class Robot {
public:
    string name;
    int hits;
    Robot(string n) : name(n), hits(0) {}
    void hitBall(Ball &ball, const string &direction) {
        int dx = 0, dy = 0;
        if (direction == "up") dy = 1;
        else if (direction == "down") dy = -1;
        else if (direction == "left") dx = -1;
        else if (direction == "right") dx = 1;
        ball.move(dx, dy);
        hits++;
    }
};

class Team {
public:
    string name;
    Robot *robot;
    
    Team(string n, string robo) : name(n) { 
	    robot = new Robot(robo); 
		}
    ~Team() { 
	    delete robot; 
		}
};

class Game {
public:
    Team teamOne;
    Team teamTwo;
    Ball ball;
    Goal goal;
    Game(string team1, string robot1, string team2, string robot2) : teamOne(team1, robot1), teamTwo(team2, robot2), ball(0, 0), goal(3, 3) {}
    void startGame() {
        int hitsTeamOne = play(teamOne);
        ball.reset();
        int hitsTeamTwo = play(teamTwo);
        declareWinner(hitsTeamOne, hitsTeamTwo);
    }
    int play(Team &team) {
        int hits = 0;
        while (!goal.isGoalReached(ball.getX(), ball.getY())) {
            string direction;
            if (ball.getX() < goal.goalX) direction = "right";
            else if (ball.getX() > goal.goalX) direction = "left";
            else if (ball.getY() < goal.goalY) direction = "up";
            else direction = "down";
            team.robot->hitBall(ball, direction);
            hits++;
        }
        return hits;
    }
    void declareWinner(int hitsOne, int hitsTwo) {
        if (hitsOne < hitsTwo) cout << "Team " << teamOne.name << " won with " << hitsOne << " hits!" << endl;
        else if (hitsTwo < hitsOne) cout << "Team " << teamTwo.name << " won with " << hitsTwo << " hits!" << endl;
        else cout << "It's a tie! Both teams took " << hitsOne << " hits." << endl;
    }
};

int main() {
	cout<<"WAMIZA NOMAN 24K-0010\n"<<endl;
    Game g1("Team1", "Robot1", "Team2", "Robot2");
    g1.startGame();
    return 0;
}
