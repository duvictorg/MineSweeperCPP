#include <iostream>
#include <vector>

#include "Board.h"

using namespace std;

int main()
{
    //Initialisation variables
    int SizeBoard = 20;
    int NombreBombes = 5;
    vector<vector<int>> BoardCache = GenerationBoard(SizeBoard, NombreBombes);
    vector<vector<int>> BoardJoueur = BoardCache;

    //Affiche le board 2D
    for (int i = 0; i < SizeBoard; i++) {
        for (int j = 0; j < SizeBoard; j++)
            cout << "[" << static_cast<char>(BoardCache[i][j]) << "]";
        cout << " < " << i << endl;
    }
    for (int j = 0; j < SizeBoard; j++)
        cout << " ^ ";
    cout << endl;


    return 0;

}