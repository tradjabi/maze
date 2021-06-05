#ifndef NODE_H
#define NODE_H

#include <memory>
#include <random>
#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <stack>
#include <string>
#include <cstdlib>
#include <iomanip>
#define BOLDBLACK "\033[38;5;0m"      /* Bold Black */
#define BLUE "\033[34m"               /* Blue */
#define WHITE "\033[37m"              /* White */
#define RED "\033[31m"                /* Red */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */

class Node
{
public:
    int dimension{};
    std::vector<Node *> children;
    std::vector<int> maze;
    Node *parent;
    Node(std::vector<int> maze, Node *parent, int dimension);
    Node(int dimension);
    ~Node() = default;

    

    void show();
    int find_One() const;
    void moveUp(int);
    void moveDown(int);
    void moveRight(int);
    void moveLeft(int);
    // void generateMaze();
    std::vector<int> generate_maze(int dimension);
    // void setGoal();     //........
};

#endif