#include <iostream>
#include <vector>

#include "Board.h"
#include "Affichage.h"

using namespace std;

int main()
{
    //Initialisation variables
    int SizeBoard = 9;
    int NombreBombes = 7;


    //Initialisation du Board
    vector<vector<int>> BoardCache = GenerationBoard(SizeBoard, NombreBombes);
    vector<vector<int>> BoardJoueur = BoardCache;
    BoardCache = PlacementBombes(BoardCache, NombreBombes, SizeBoard);
    BoardCache = CompteBombes(BoardCache, SizeBoard);

    AfficheBoard(BoardCache, BoardJoueur, SizeBoard);

    return 0;

}