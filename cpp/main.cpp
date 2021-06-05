#include "node.h"

// Functions For BFS Solve :
bool contains(std::queue<Node *> q, Node *n);
void solveBFS(Node init, std::vector<int> goalState, int noOfDepths);
// Functions For DFS Solve :
bool contains_DFS(std::stack<Node *> q, Node *n);
void solveDFS(Node init, std::vector<int> goalState, int noOfDepths);

int main()
{
    //****************************************
    //how to play game commands
    std::cout << "Start ..." << std::endl;
    int input_key{};
    int dimension{};
    std::cout << BOLDMAGENTA << "Choose the way you want to play : \033[0m" << std::endl;
    std::cout << '\n'
              << BOLDCYAN << "1)Solve a random maze\033[0m" << '\n'
              << BOLDCYAN << "2)Solve a Custom maze\033[0m" << '\n'
            //   << BOLDCYAN << "3)Solve your normal maze\033[0m" << '\n'
              << '\n'
              << BOLDMAGENTA << "Please Press a Key (1 or 2 ) : \033[0m";
    std::cin >> input_key;

    if (input_key != 1 && input_key != 2)
    {
        while (true)
        {
            std::cerr << "\033[48;5;253m" << BOLDRED << "Eror ! No matching key please try again...\033[0m" << std::endl;
            std::cout << '\n'
                      << BOLDMAGENTA << "Please Press a Key (1 or 2 or 3) : \033[0m" << '\n';
            std::cin >> input_key;
            std::cout << '\n';
            if (input_key == 1 || input_key == 2 || input_key == 3)
                break;
        }
    }

    int input_key0{};
    std::cout << BOLDCYAN << "Well we have to ways to solve your maze !" << WHITE << '\n'
              << BOLDMAGENTA << "1)Use" << RED << " BFS" << BOLDMAGENTA << " algorithm to solve your maze" << WHITE << '\n'
              << BOLDMAGENTA << "2)Use" << RED << " DFS" << BOLDMAGENTA << " algorithm to solve your maze" << WHITE << '\n'
              << BOLDCYAN << "(Please input just " << RED << "1" << BOLDCYAN << " Or" << RED << " 2" << BOLDCYAN << " !)" << '\n'
              << BOLDCYAN << "Input number : " << WHITE;
    std::cin >> input_key0;
    if (input_key0 != 1 && input_key0 != 2)
    {
        while (true)
        {
            std::cerr << BOLDCYAN << "Eror ! No matching input ! Please input" << RED << " 1" << BOLDCYAN << " Or " << RED << "2 " << BOLDCYAN << "!" << WHITE << std::endl;
            std::cout << BOLDCYAN << "Input Again : " << WHITE;
            std::cin >> input_key0;
            std::cout << std::endl;
            if (input_key0 == 1 || input_key0 == 2)
                break;
        }
    }

    //***************************************************

    // create Random maze :
    size_t attemps  = 100;
    if (input_key == 1)
    {
        std::cout << BOLDMAGENTA << "Please input the dimension of your maze : " << WHITE;
        std::cin >> dimension;
        std::cout << '\n';
        std::cout << BOLDRED << "Creating a random maze...\033[0m" << std::endl;
        std::cout << '\n';
        if(input_key0==1)
        {
            Node rand_maze(dimension);
            // auto root_rand_maze = std::vector<int>(dimension*dimension);
            // root_rand_maze = rand_maze.generate_maze();
            // auto goal_rand_maze = std::vector<int>(dimension);
            // goal_rand_maze->set_state(m.goal_state);
            std::cout << "Start:\n\n";
            
            std::cout << "End:\n\n";
            // goal_rand_maze->show();
            std::cout << BOLDMAGENTA << "Press <any key + Enter> to start solution!\n";
            char any_key;
            std::cin >> any_key;
            // auto solution = m.breadth_first_search(root_node, 100);
            

        }

    }
    //  **************************************************
    if(input_key==2)
    {
        std::cout << BOLDRED << "a custom maze...\033[0m" << std::endl;
        std::cout << '\n';
        std::vector<int> root = {-1, -1, 1, -1,
                             -1, 0, 0, -1,
                             -1, 0, -1, -1,
                             -1, 0, -1, -1};

        std::vector<int> goal = {-1, -1, 0, -1,
                                    -1, 0, 0, -1,
                                    -1, 0, -1, -1,
                                    -1, 1, -1, -1};
        Node X(root, NULL, 4);

        if(input_key0==1)
        {
            std::cout << BOLDMAGENTA << "Use" << RED << " BFS" << BOLDMAGENTA << " algorithm to solve your maze" << WHITE << '\n';
            solveBFS(X, goal, 23);  

        }
        if(input_key0==2)
        {
            std::cout << BOLDMAGENTA << "Use" << RED << " DFS" << BOLDMAGENTA << " algorithm to solve your maze" << WHITE << '\n';
            solveDFS(X, goal, 12);  
        }

    }
}

// Functions For BFS Solve :
//**************************************************
bool contains(std::queue<Node *> q, Node *n)
{
    bool exist = false;
    while (!q.empty())
    {
        if (q.front()->maze == n->maze)
            exist = true;
        q.pop();
    }
    return exist;
}

void solveBFS(Node init, std::vector<int> goalState, int noOfDepths)
{
    std::queue<Node *> openList;
    std::queue<Node *> closedList;
    openList.push(&init);
    bool goalFound = false;
    int count0 = 0;
    std::vector<Node *> solution;
    std::vector<Node *> vecForCheck;
    std::cout << BOLDRED << "Searching for BFS solution...\033[30;40m" << WHITE << std::endl;
    std::cout << '\n';
    while (!openList.empty() && !goalFound)
    {
        Node *currentNode = openList.front();
        closedList.push(currentNode);
        openList.pop();
        int x{currentNode->find_One()};
        currentNode->moveUp(x);
        currentNode->moveDown(x);
        currentNode->moveRight(x);
        currentNode->moveLeft(x);
        for (auto i : currentNode->children)
        {
            Node *currentChild = i;
            if (currentChild->maze == goalState)
            {
                std::cout << "\033[32;1;4mGoal Found :D \033[0m" << std::endl;
                std::cout << '\n';
                // Once the goal is found the path is traced by recursively iterating through the parent nodes starting from goal node till the inital node is found
                Node *curr = currentChild;
                int count{0};
                solution.push_back(currentChild);
                while (curr->parent != NULL)
                {
                    count++;
                    curr = curr->parent;
                    solution.push_back(curr);
                }
                std::reverse(solution.begin(), solution.end());
                std::cout << BOLDCYAN << "printing solutionution :\033[0m" << std::endl;
                std::cout << '\n';
                for (size_t i{0}; i < solution.size(); i++)
                {
                    std::cout << "Move " << i;
                    solution[i]->show();
                }
                std::cout << std::endl;
                std::cout << "\033[38;5;12mNo. of depths : " << count << WHITE << std::endl;
                goalFound = true;
            }
            if (currentChild->maze != goalState)
            {
                int count1{0};
                Node *curr = currentChild;
                while (curr->parent != NULL)
                {
                    count1++;
                    curr = curr->parent;
                }
                if (count1 > noOfDepths)
                {
                    std::cout << "\033[1m\033[31mFound no answer until depth you have entered :(\033[37m" << std::endl;
                    std::cout << '\n';
                    goalFound = true;
                    break;
                }
            }
            if (!contains(openList, currentChild) && !contains(closedList, currentChild))
            {
                openList.push(currentChild);
            }
        }
        count0++;
    }
    std::cout << "\033[38;5;4mNo. of nodes in closed list: " << count0 << WHITE << std::endl;
    std::cout << '\n';
}

// Functions For DFS Solve :
//*****************************************************************
bool contains_DFS(std::stack<Node *> q, Node *n)
{
    bool exist = false;
    while (!q.empty())
    {
        if (q.top()->maze == n->maze)
            exist = true;
        q.pop();
    }
    return exist;
}

void solveDFS(Node init, std::vector<int> goalState, int noOfDepths)
{
    std::stack<Node *> openList;
    std::stack<Node *> closedList;
    openList.push(&init);
    bool goalFound = false;
    int count0 = 0;
    std::vector<Node *> solution;
    std::vector<Node *> vecForCheck;
    std::cout << BOLDRED << "Searching for DFS solution...\033[30;40m" << WHITE << std::endl;
    std::cout << '\n';
    while (!openList.empty() && !goalFound)
    {
        Node *currentNode = openList.top();
        closedList.push(currentNode);
        openList.pop();
        int x{currentNode->find_One()};
        currentNode->moveUp(x);
        currentNode->moveDown(x);
        currentNode->moveRight(x);
        currentNode->moveLeft(x);
        for (auto i : currentNode->children)
        {
            Node *currentChild = i;
            if (currentChild->maze == goalState)
            {
                std::cout << "\033[32;1;4mGoal Found :D \033[0m" << std::endl;
                std::cout << '\n';
                // Once the goal is found the path is traced by recursively iterating through the parent nodes starting from goal node till the inital node is found
                Node *curr = currentChild;
                int count{0};
                solution.push_back(currentChild);
                while (curr->parent != NULL)
                {
                    count++;
                    curr = curr->parent;
                    solution.push_back(curr);
                }
                std::reverse(solution.begin(), solution.end());
                std::cout << BOLDCYAN << "printing solutionution :\033[0m" << std::endl;
                std::cout << '\n';
                for (size_t i{0}; i < solution.size(); i++)
                {
                    std::cout << BOLDCYAN <<"Move " << RED << i << WHITE;
                    solution[i]->show();
                }
                std::cout << "\033[38;5;12mNo. of depths : " << count << WHITE << std::endl;
                goalFound = true;
            }
            if (currentChild->maze != goalState)
            {
                int count1{0};
                Node *curr = currentChild;
                while (curr->parent != NULL)
                {
                    count1++;
                    curr = curr->parent;
                }
                if (count1 > noOfDepths)
                {
                    currentNode = openList.top();
                    openList.pop();
                    if (openList.empty())
                    {
                        std::cout << "\033[1m\033[31mFound no answer until depth you have entered :(\033[37m" << std::endl;
                        std::cout << '\n';
                        goalFound = true;
                        break;
                    }
                }
            }
            if (!contains_DFS(openList, currentChild) && !contains_DFS(closedList, currentChild))
            {
                openList.push(currentChild);
            }
        }
        count0++;
    }
    std::cout << "\033[38;5;4mNo. of nodes in closed list: " << count0 << WHITE << std::endl;
    std::cout << '\n';
}