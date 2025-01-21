#include <iostream>
#include <vector>

#include "Board.h"

using namespace std;

int main()
{
    //Initialisation variables
    int SizeBoard = 10;
    int NombreBombes = 5;
    vector<vector<int>> Board;
    Board = GenerationBoard(SizeBoard, NombreBombes);

    //Affiche le board 2D
    for (int i = 0; i < Board.size(); i++) {
        for (int j = 0; j < Board[i].size(); j++)
            cout << Board[i][j] << " ";
        cout << endl;
    }
    return 0;

}