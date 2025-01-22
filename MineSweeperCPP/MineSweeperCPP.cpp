#include <iostream>
#include <vector>
#include <stdlib.h> 

#include "Board.h"
#include "Affichage.h"

using namespace std;

int main()
{
    //Initialisation variables
    int SizeBoard = -1;
    int NombreBombes = -1;
    int ChoixPosY;
    int ChoixPosX;
    vector<vector<int>> Positions;
    bool EnVie = true;
    bool *ChangeVie = &EnVie;
    setlocale(LC_ALL, "fr_FR.UTF-8");




    //Demande utilisateur (Temporaire)
    while (SizeBoard <= 0 or NombreBombes <= 0 or SizeBoard > 50) {
        cout << "Valeurs positives et non nulles" << endl;
        cout << "Se mettre en plein écran pour les grands boards (50 MAX)" << endl;
        cout << "Taille du board ? : ";
        cin >> SizeBoard;
        cout << "Nombre de bombes ? : ";
        cin >> NombreBombes;
        system("cls");
    }

    //Initialisation du Board
    vector<vector<int>> BoardCache(SizeBoard, vector<int>(SizeBoard, '#'));
    vector<vector<int>> BoardJoueur = BoardCache;
    BoardCache = PlacementBombes(BoardCache, NombreBombes, SizeBoard);
    BoardCache = CompteBombes(BoardCache, SizeBoard);

    //Loop de jeu (Temporaire)
    while (EnVie){
        AfficheBoard(BoardCache, BoardJoueur, SizeBoard);
        cout << endl;
        cout << "Quel est votre coup ? ";
        cout << endl;
        cout << "Position en hauteur ? (Aide à droite) : ";
        cin >> ChoixPosY;
        cout << endl;
        cout << "Position en Largeur ? (de gauche à droite) : ";
        cin >> ChoixPosX;
        Positions = RevelationBoard(BoardCache, ChoixPosY, ChoixPosX);
        BoardJoueur = ModifieBoard(BoardCache, BoardJoueur, Positions, ChangeVie, NombreBombes);
    }

    return 0;

}