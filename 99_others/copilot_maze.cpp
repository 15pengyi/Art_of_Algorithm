#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

// constants for the four walls
const int LEFT = 1;
const int UP = 2;
const int RIGHT = 4;
const int DOWN = 8;

// constants for the grid size
const int ROWS = 10;
const int COLS = 10;

// symbols for printing the maze
const char WALL = '#';
const char PASS = ' ';
const char PATH = '.';

// a struct to represent a cell position
struct Cell {
    int row;
    int col;
};

// a function to check if a cell is valid and unvisited
bool isValid(int grid[ROWS][COLS], int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && grid[row][col] == 0;
}

// a function to print the maze
void printMaze(int grid[ROWS][COLS]) {
    // print the top border
    for (int i = 0; i < COLS * 2 + 1; i++) {
        cout << WALL;
    }
    cout << endl;

    for (int i = 0; i < ROWS; i++) {
        // print the left border
        cout << WALL;

        for (int j = 0; j < COLS; j++) {
            // print the cell
            if (grid[i][j] == 0) {
                cout << WALL;
            } else if (grid[i][j] > 0) {
                cout << PASS;
            } else {
                cout << PATH;
            }

            // print the right wall if needed
            if (grid[i][j] & RIGHT) {
                cout << PASS;
            } else {
                cout << WALL;
            }
        }
        cout << endl;

        // print the bottom wall if needed
        for (int j = 0; j < COLS; j++) {
            cout << WALL;
            if (grid[i][j] & DOWN) {
                cout << PASS;
            } else {
                cout << WALL;
            }
        }
        cout << endl;
    }
}

// a function to generate a maze using DFS
void generateMaze(int grid[ROWS][COLS]) {
    // initialize the random seed
    srand(time(NULL));

    // create a stack for DFS
    stack<Cell> s;

    // choose a random cell as the start point
    int startRow = rand() % ROWS;
    int startCol = rand() % COLS;

    // mark the start cell as visited and push it to the stack
    grid[startRow][startCol] = 15;
    s.push({startRow, startCol});

    // loop until the stack is empty
    while (!s.empty()) {
        // get the current cell from the stack
        Cell cur = s.top();
        s.pop();

        // get the valid neighbors of the current cell
        vector<Cell> neighbors;
        if (isValid(grid, cur.row - 1, cur.col)) {
            neighbors.push_back({cur.row - 1, cur.col});
        }
        if (isValid(grid, cur.row + 1, cur.col)) {
            neighbors.push_back({cur.row + 1, cur.col});
        }
        if (isValid(grid, cur.row, cur.col - 1)) {
            neighbors.push_back({cur.row, cur.col - 1});
        }
        if (isValid(grid, cur.row, cur.col + 1)) {
            neighbors.push_back({cur.row, cur.col + 1});
        }

        // if there are any valid neighbors
        if (!neighbors.empty()) {
            // push the current cell to the stack
            s.push(cur);

            // choose a random neighbor
            int index = rand() % neighbors.size();
            Cell next = neighbors[index];

            // remove the wall between the current cell and the chosen neighbor
            if (next.row == cur.row - 1) {
                grid[cur.row][cur.col] -= UP;
                grid[next.row][next.col] += DOWN;
            } else if (next.row == cur.row + 1) {
                grid[cur.row][cur.col] -= DOWN;
                grid[next.row][next.col] += UP;
            } else if (next.col == cur.col - 1) {
                grid[cur.row][cur.col] -= LEFT;
                grid[next.row][next.col] += RIGHT;
            } else if (next.col == cur.col + 1) {
                grid[cur.row][cur.col] -= RIGHT;
                grid[next.row][next.col] += LEFT;
            }

            // mark the chosen neighbor as visited and push it to the stack
            s.push(next);
        }
    }

    // choose two cells on the edge as entrance and exit
    int entrance = rand() % ROWS;
    int exit = rand() % ROWS;

    // remove the wall of the entrance and exit
    grid[entrance][0] -= LEFT;
    grid[exit][COLS - 1] -= RIGHT;

}

// a function to solve a maze using DFS
void solveMaze(int grid[ROWS][COLS]) {
    // create a stack for DFS
    stack<Cell> s;

    // find the entrance of the maze and push it to the stack
    for (int i = 0; i < ROWS; i++) {
        if (grid[i][0] & LEFT) {
            s.push({i, 0});
            break;
        }
    }

    // loop until the stack is empty or the exit is found
    bool found = false;
    while (!s.empty() && !found) {
        // get the current cell from the stack
        Cell cur = s.top();
        s.pop();

        // mark the current cell as part of the path
        grid[cur.row][cur.col] = -1;

        // check if the current cell is the exit
        if (cur.col == COLS - 1 && !(grid[cur.row][cur.col] & RIGHT)) {
            found = true;
            break;
        }

        // get the neighbors of the current cell that are not walls
        vector<Cell> neighbors;
        if (!(grid[cur.row][cur.col] & UP) && grid[cur.row - 1][cur.col] > 0) {
            neighbors.push_back({cur.row - 1, cur.col});
        }
        if (!(grid[cur.row][cur.col] & DOWN) && grid[cur.row + 1][cur.col] > 0) {
            neighbors.push_back({cur.row + 1, cur.col});
        }
        if (!(grid[cur.row][cur.col] & LEFT) && grid[cur.row][cur.col - 1] > 0) {
            neighbors.push_back({cur.row, cur.col - 1});
        }
        if (!(grid[cur.row][cur.col] & RIGHT) && grid[cur.row][cur.col + 1] > 0) {
            neighbors.push_back({cur.row, cur.col + 1});
        }

        // push the neighbors to the stack
        for (Cell next : neighbors) {
            s.push(next);
        }
    }

    // if the exit is found, print the path
    if (found) {
        cout << "The maze is solved!" << endl;
        printMaze(grid);
    } else {
        cout << "The maze is unsolvable!" << endl;
    }
}

// the main function
int main() {
    // create a grid for the maze
    int grid[ROWS][COLS] = {0};

    // generate a maze
    cout << "Generating a maze..." << endl;
    generateMaze(grid);
    printMaze(grid);

    // solve the maze
    cout << "Solving the maze..." << endl;
    solveMaze(grid);

    return 0;
}
