#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <tuple>
#include "Board.h"
using namespace std;

vector<vector<int>> GenerationBoard(int SizeBoard, int NombreBombes){
	//Fonction de création du board en donnant une taille spécifiée et le nombre de bombes
	//La fonction crée le vecteur de vecteurs en remplissant de #, puis aléatoirement place les bombes
	//La fonction appellera ensuite uen fonction pour compter les bombes et placer les numéros
	//Elle renverra enfin le board créée, de 1 à 9 les nombres et B les positions de bombes et si 0 alors vide
	vector<vector<int>> Board;

	for (int NumLigne = 0; NumLigne < SizeBoard; NumLigne++) 
	{
		vector<int> VectorLigne;

		for (int NumColonne = 0; NumColonne < SizeBoard; NumColonne++) 
		{
			VectorLigne.push_back('#');
		}

		Board.push_back(VectorLigne);
	}

	return Board;

}

vector<vector<int>> PlacementBombes(vector<vector<int>> Board, int NombreBombes, int SizeBoard)
{
	//La fonction prend un board vide
	//Génère deux nombres aléatoires entre 0 et SizeBoard qui seront la position de la bombe
	//Si une bombe est déjà à la position relancer la position aléatoire
	if (NombreBombes > SizeBoard * SizeBoard) {
		NombreBombes = SizeBoard * SizeBoard - 1;
	}

	// Générateur de nombres aléatoires (par GPT)
	random_device rd; // Entropie matérielle
	mt19937 gen(rd()); // Générateur Mersenne Twister
	uniform_int_distribution<> distrib(0, SizeBoard - 1);

	int NumeroBombe = 0;
	while (NumeroBombe < NombreBombes) {
		int PosX = distrib(gen);
		int PosY = distrib(gen);
		if (Board[PosY][PosX] != 'B') {
			Board[PosY][PosX] = 'B';
			NumeroBombe++;
		}
	}
	return Board;
}

vector<vector<int>> CompteBombes(vector<vector<int>> Board, int SizeBoard){
	//La fonction prend un board avec des bombes
	//Parcourt le vecteur de vecteur et sur chaque bombe rajoute 1 au compteur de chaque case voisine sans bombe
	//Puis uen fois fini remplace tous les # par du vide
	//renvoie le board avec les numéros
	for (int NumLigne = 0; NumLigne < SizeBoard; NumLigne++)
	{
		for (int NumColonne = 0; NumColonne < SizeBoard; NumColonne++)
		{
			if (Board[NumLigne][NumColonne] == 'B') {
				for (int i = -1; i < 2; i++)
				{
					for (int j = -1; j < 2; j++) 
					{
						if ((NumLigne + i != -1) and (NumLigne + i != SizeBoard) and (NumColonne + j != -1) and (NumColonne + j != SizeBoard)) {
							if (Board[NumLigne+i][NumColonne+j] != 'B' and Board[NumLigne + i][NumColonne + j] == '#') {
								Board[NumLigne+i][NumColonne+j] = 1;
							}
							else if (Board[NumLigne + i][NumColonne + j] != 'B' and Board[NumLigne + i][NumColonne + j] != '#') {
								Board[NumLigne+i][NumColonne+j] = Board[NumLigne+i][NumColonne+j] + 1;
							}
						}
					}
				}
			}
		}
	}
	//remplacer tous les # par le vide
	for (int NumLigne = 0; NumLigne < SizeBoard; NumLigne++) 
	{
		replace(Board[NumLigne].begin(), Board[NumLigne].end(), '#', ' ');
	}
	return Board;
}

vector<vector<int>> RevelationBoard(vector<vector<int>> Board, int ChoixPosX, int ChoixPosY){
	//La fonction prend le board et le choix de position à révéler et renvoie un vecteur de vecteurs de Positions à révéler
	vector<vector<int>> Positions;
	return Positions;
}
vector<vector<int>> ModifieBoard(vector<vector<int>> BoardCache, vector<vector<int>> BoardJoueur, vector<vector<int>> Positions){
	//La fonction prend un vecteur de vecteurs en entrée et copie les valeurs aux positions du premier Board dans le deuxième et renvoie le Board Joueur
	for (int index = 0; index < Positions.size(); index++)
	{
		BoardJoueur[Positions[index][0]][Positions[index][1]] = BoardCache[Positions[index][0]][Positions[index][1]];
	}
	return BoardJoueur;
}
