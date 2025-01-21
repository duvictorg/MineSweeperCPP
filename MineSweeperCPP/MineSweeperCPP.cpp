#include <iostream>
#include <vector>

#include "Board.h"

using namespace std;

int main()
{
    //Initialisation variables
    int SizeBoard = 9;
    int NombreBombes = 7;
    vector<vector<int>> BoardCache = GenerationBoard(SizeBoard, NombreBombes);
    vector<vector<int>> BoardJoueur = BoardCache;
    //Initialisation du Board
    BoardCache = PlacementBombes(BoardCache, NombreBombes, SizeBoard);
    BoardCache = CompteBombes(BoardCache, SizeBoard);

    //Affiche le board
    for (int NumLigne = 0; NumLigne < SizeBoard; NumLigne++) 
    {
        for (int NumColonne = 0; NumColonne < SizeBoard; NumColonne++)
        {
            //vérifie si c'est autre chose que un numéro et affiche correctement selon la table ascii
            if (BoardJoueur[NumLigne][NumColonne] > 9) {
                cout << "[" << static_cast<char>(BoardJoueur[NumLigne][NumColonne]) << "]";
            }
            else {
                cout << "[" << BoardJoueur[NumLigne][NumColonne] << "]";
            }
            
        }
        cout << " < " << NumLigne << endl;
    }
    for (int j = 0; j < SizeBoard; j++){
        cout << " ^ ";  
    }
    cout << endl;

    return 0;

}