#include <vector>
#include <iostream>
#include <sstream>
#include "Affichage.h"

using namespace std;

void AfficheBoard(const vector<vector<int>>& BoardCache, const vector<vector<int>>& BoardJoueur, int SizeBoard) {
	//Affiche le board
	ostringstream output;
	for (int NumLigne = 0; NumLigne < SizeBoard; NumLigne++)
	{
		for (int NumColonne = 0; NumColonne < SizeBoard; NumColonne++)
		{
			//vérifie si c'est autre chose que un numéro et affiche correctement selon la table ascii
			if (BoardJoueur[NumLigne][NumColonne] > 9) {
				output << "[" << static_cast<char>(BoardJoueur[NumLigne][NumColonne]) << "]";
			}
			else {
				output << "[" << BoardJoueur[NumLigne][NumColonne] << "]";
			}

		}
		output << " < " << NumLigne << "\n";
	}
	for (int j = 0; j < SizeBoard; j++) {
		output << " ^ ";
	}
	output << "\n";
	cout << output.str();
}