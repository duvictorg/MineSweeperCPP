#include <vector>
#include <iostream>
#include "Affichage.h"

using namespace std;

void AfficheBoard(std::vector<std::vector<int>> BoardCache, std::vector<std::vector<int>> BoardJoueur, int SizeBoard) {
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
	for (int j = 0; j < SizeBoard; j++) {
		cout << " ^ ";
	}
	cout << endl;
}