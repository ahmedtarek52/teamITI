#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "../obstacles.h" 

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;


void drawBorder(int x, int y, int xPos, int yPos, const vector<Obstacle>& obstacles) {
    system("CLS"); // Clear the console

    for (int i = 0; i <= HEIGHT; i++) {
        for (int j = 0; j <= WIDTH; j++) {
            if (i == 0 || i == HEIGHT || j == 0 || j == WIDTH) {
                cout << "*"; // Draw the border
            }
            else if (i == y && j == x) {
                cout << "X"; // Draw X
            }
            else if (i == yPos && j == xPos) {
                cout << "Y"; // Draw Y
            }
            else {
                
                bool isObstacle = false;
                for (const auto& obs : obstacles) {
                    if (obs.direction == 'H') { // Horizontal line obstacle
                        if (i == obs.startY && j >= obs.startX && j < obs.startX + obs.length) {
                            cout << "-"; // Draw horizontal dashed line
                            isObstacle = true;
                            break;
                        }
                    }
                }

                if (!isObstacle) {
                    cout << " "; // Draw empty space
                }
            }
        }
        cout << endl;
    }
}

int main() {
    int x = 1, y = 1; // Initial position of X
    int xPos = WIDTH - 2, yPos = HEIGHT - 2; // Position of Y
    bool gameOver = false;

    vector<Obstacle> obstacles = loadObstacles();

    drawBorder(x, y, xPos, yPos, obstacles);
    while (!gameOver) {
        if (_kbhit()) { 
            int newX = x, newY = y;

            switch (_getch()) {
            case 72: // Up arrow
                newY--;
                break;
            case 80: // Down arrow
                newY++;
                break;
            case 75: // Left arrow
                newX--;
                break;
            case 77: // Right arrow
                newX++;
                break;
            }

            bool isValidMove = true;
            if (newX <= 0 || newX >= WIDTH || newY <= 0 || newY >= HEIGHT) {
                isValidMove = false;
            }
            for (const auto& obs : obstacles) {    
                if (obs.direction == 'H' && newY == obs.startY && newX >= obs.startX && newX < obs.startX + obs.length) {
                    isValidMove = false;
                    break;
                }
            }
            if (isValidMove) {
                x = newX;
                y = newY; 
            }
            drawBorder(x, y, xPos, yPos, obstacles);          
            if (x == xPos && y == yPos) {
                gameOver = true;
                cout << "X has reached Y! Game over.\n";
            }
            Sleep(100); // 
        }
    }

    return 0;
}
