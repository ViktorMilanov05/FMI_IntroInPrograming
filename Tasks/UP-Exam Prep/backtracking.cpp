#include <iostream>
using namespace std;
const size_t rows = 6;
const size_t colls = 5;
bool areValid(unsigned a, unsigned b) {
    return a < rows && b < colls;
}
void printPath(const char field[rows][colls], const bool visited[rows][colls])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colls; j++)
        {
            if (visited[i][j])
                cout << "| 1 |";
            else
                cout << "| " << field[i][j] << " |";
        }
        cout << endl;
    }
}
bool findPathRec(char matrix[rows][colls], bool visited[rows][colls], unsigned startX, unsigned startY, unsigned destX, unsigned destY) {
    if (!areValid(startX, startY) || matrix[rows][colls] != ' ' || visited[rows][colls])
        return false;
    visited[startX][startY] = true;
    if (startX == destX && startY == destY)
        return true;
    bool found = findPathRec(matrix, visited, startX + 1, startY, destX, destY) ||
        findPathRec(matrix, visited, startX - 1, startY, destX, destY) ||
        findPathRec(matrix, visited, startX, startY + 1, destX, destY) ||
        findPathRec(matrix, visited, startX, startY - 1, destX, destY);
    if(!found)
        visited[startX][startY] = false;
    return visited;
}
bool findPath(char matrix[rows][colls], unsigned startX, unsigned startY, unsigned destX, unsigned destY) {
    bool visited[rows][colls]{ true };
    bool containsPath = findPathRec(matrix, visited, startX, startY, destX, destY);

    if (containsPath)
        printPath(matrix, visited);
    else
        cout << "No path!" << endl;
    return containsPath;
}
//int main()
//{
//    char field[rows][colls]
//    {
//        {' ', ' ', ' ', ' ', ' '},
//        {' ', ' ', ' ', ' ', ' '},
//        {' ', 'X', ' ', ' ', ' '},
//        {' ', 'X', ' ', 'X', 'X'},
//        {'X', 'X', ' ', ' ', ' '},
//        {' ', ' ', ' ', 'X', ' '}
//
//    };
//
//    findPath(field, 3, 0, 5, 4);
//
//    return 0;
//}