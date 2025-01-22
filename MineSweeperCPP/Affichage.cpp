#include <vector>
#include <iostream>
#include <sstream>
#include "Affichage.h"

using namespace std;

void AfficheBoard(const vector<vector<int>>& BoardCache, const vector<vector<int>>& BoardJoueur, int SizeBoard) {
	//Affiche le board
	ostringstream output;
	for (int NumLigne = 0; NumLigne < SizeBoard; NumLigne++){
		for (auto& Case : BoardJoueur[NumLigne]) {
			//vérifie si c'est autre chose que un numéro et affiche correctement selon la table ascii
			if (Case > 9) {
				output << "[" << static_cast<char>(Case) << "]";
			}
			else {
				output << "[" << Case << "]";
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