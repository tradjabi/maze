#include "node.h"

Node::Node(int dimension)
{
    this->dimension = dimension;
}
Node::Node(std::vector<int> maze, Node *parent, int dimension)
{
    this->maze = maze;
    this->parent = parent;
    this->dimension = dimension;
}

int Node::find_One() const
{
    for (size_t i{}; i < maze.size(); i++)
    {
        for (size_t j{}; j < maze.size(); j++)
        {
            if (maze[maze.size() * i + j] == 1)
            {
                return maze.size() * i + j;
            }
        }
    }
    return -1;
}

void Node::moveUp(int input_one)
{
    std::vector<int> temp{maze};
    if (input_one > dimension - 1)
    {
        if (maze[input_one - dimension] == 0)
        {
            std::swap(temp[input_one], temp[input_one - dimension]);
        }
    }
    Node *child = new Node(temp, this, dimension);
    children.push_back(child);
}

void Node::moveDown(int input_one)
{
    std::vector<int> temp{maze};
    if (input_one < (dimension) * (dimension - 1))
    {
        if (maze[input_one + dimension] == 0)
        {
            std::swap(temp[input_one], temp[input_one + dimension]);
        }
    }
    Node *child = new Node(temp, this, dimension);
    children.push_back(child);
}

void Node::moveRight(int input_one)
{
    std::vector<int> temp{maze};
    if (input_one % dimension < dimension - 1)
    {
        if (maze[input_one + 1] == 0)
        {
            std::swap(temp[input_one], temp[input_one + 1]);
        }
    }
    Node *child = new Node(temp, this, dimension);
    children.push_back(child);
}

void Node::moveLeft(int input_one)
{
    std::vector<int> temp{maze};
    if (input_one % dimension > 0)
    {
        if (maze[input_one - 1] == 0)
        {
            std::swap(temp[input_one], temp[input_one - 1]);
        }
    }
    Node *child = new Node(temp, this, dimension);
    children.push_back(child);
}

void Node::show()
{
    for (size_t i{}; i < maze.size(); i++)
    {
        size_t j{i};
        if (j % dimension != 0)
        {
            std::cout << std::setw(3) ;
            // << maze[i];
            if(maze[i]==-1){
                std::cout <<"#";
            }
            else if (maze[i]==1)
            {
                std::cout << RED <<"  o"<< WHITE;
            }
            else if(maze[i]==0)
            {
                std::cout <<" ";
            }
            
        }
        else
        {
            std::cout << '\n';
            std::cout << std::setw(3) ;
            // << maze[i];
            if(maze[i]==-1){
                std::cout <<"#";
            }
            else if (maze[i]==1)
            {
                std::cout << RED <<"o"<< WHITE;
            }
            else if(maze[i]==0)
            {
                std::cout <<" ";
            }
        }
    }
    std::cout << std::endl;
}

// void Node::generateMaze(){
//     std::vector<int> temp;
//     for(size_t i{}; i < dimension * dimension; i++)
//     {
//         // temp[temp.size() * i + j] = 0; //creat a maze filled with zero
//         temp.push_back(0);
//     }
//     Node m(dimension);
//     // node.set_state(state);
//     srand(time(0));
//     for (int i{}; i < dimension * dimension; i++)
//     {
//         if (temp[i] != 1 && temp[i] != 2)
//         {
//             temp[i] = -(rand() % 2);
//         }
//     }
//     // Set ending element
//     int cnt{};
//     for (int i{}; i < dimension; i++)
//     {
//         if (temp[i + dimension * (dimension - 1)] == 0)
//         {
//             cnt++;
//         }
//     }
//     if (cnt == 0)
//     {
//         temp[rand() % dimension + dimension * (dimension - 1)] = 1;
//     }
//     else
//     {
//         cnt = rand() % cnt;
//         for (int i{}; i < dimension; i++)
//         {
//             if (temp[i + dimension * (dimension - 1)] == 0)
//             {
//                 if (cnt == 0)
//                 {
//                     temp[i + dimension * (dimension - 1)] = 1;
//                     break;
//                 }
//                 cnt--;
//             }
//         }
//     }

// }

std::vector<int> generate_maze(int dimension)
{
    std::vector<int> random_root;
    srand(time(0));
    while (true)
    {
        int cnt{};
        for (int i{}; i < (dimension * dimension); i++)
        {
            random_root.push_back((rand() % 3) - 1);
            if (random_root[i] == 1)
            {
                cnt++;
            }
            if (cnt > 1)
            {
                random_root[i] = (rand() % 2) - 1;
            }
        }
        if (random_root.size() == dimension * dimension)
        {
            if (cnt != 0)
                break;
            else
            {
                random_root[rand() % (dimension * dimension)] = 1;
                break;
            }
        }
    }
    return random_root;
}
// void setGoal(){
//     for(size_t i{} ; i<maze.size ; i++)
//     std::vector<int> temp{maze};
//     pos_one = maze.find
//     if (maze[input_one - dimension] == 0)
//         {
//             std::swap(temp[input_one], temp[input_one - dimension]);
//         }

// }



    // Set goal_state
//     set_goal(state);
//     node.set_state(state);
//     state[node.find_one()] = 0;
//     // Set starting element
//     cnt = 0;
//     for (int i{}; i < n; i++)
//     {
//         if (state[i] == 0)
//         {
//             cnt++;
//         }
//     }
//     if (cnt == 0)
//     {
//         state[rand() % n] = 1;
//     }
//     else
//     {
//         cnt = rand() % cnt;
//         for (int i{}; i < n; i++)
//         {
//             if (state[i] == 0)
//             {
//                 if (cnt == 0)
//                 {
//                     state[i] = 1;
//                     break;
//                 }
//                 cnt--;
//             }
//         }
//     }
//     node.set_state(state);
//     return std::make_shared<Maze::Node>(node);
// }

// std::shared_ptr<Maze::Node> Maze::make_random_maze(int attemps){
//     auto root_node = std::make_shared<Maze::Node>(n);
//     std::deque<std::shared_ptr<Maze::Node>> sol;
//     root_node = make_random_maze();
//     sol = breadth_first_search(root_node, 100, false);
//     for (int i{}; i < attemps; i++){
//         std::cout << "Attemp >> " << i << std::endl;
//         if (sol.size() > 0){
//             std::cout << BOLDMAGENTA << ">> A solvable maze found! <<\n";
//             break;
//         }
//         else{
//             std::cout << BOLDRED << "Not solvable!\n";
//             root_node->show();
//             root_node = make_random_maze();
//             sol = breadth_first_search(root_node, 100, false);
//         }
//     }
//     return root_node;
// }
