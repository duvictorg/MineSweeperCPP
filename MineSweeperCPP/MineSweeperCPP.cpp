#include <iostream>
#include <vector>

#include "Board.h"

using namespace std;

int main()
{
    //Initialisation variables
    int SizeBoard = 10;
    int NombreBombes = 30;
    vector<vector<int>> BoardCache = GenerationBoard(SizeBoard, NombreBombes);
    vector<vector<int>> BoardJoueur = BoardCache;

    //Affiche le board caché (pour l'instant)
    for (int NumLigne = 0; NumLigne < SizeBoard; NumLigne++) 
    {
        for (int NumColonne = 0; NumColonne < SizeBoard; NumColonne++)
        {
            cout << "[" << static_cast<char>(BoardCache[NumLigne][NumColonne]) << "]";
        }
        cout << " < " << NumLigne << endl;
    }
    for (int j = 0; j < SizeBoard; j++){
        cout << " ^ ";  
    }
    cout << endl;

    return 0;

}