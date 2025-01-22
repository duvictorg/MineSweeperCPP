#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include "Board.h"
#include "Affichage.h"
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

vector<vector<int>> RevelationBoard(vector<vector<int>> Board, int ChoixPosY, int ChoixPosX){
	//La fonction prend le board et le choix de position à révéler et renvoie un vecteur de vecteurs de Positions à révéler
	vector<vector<int>> Positions = { {ChoixPosY,ChoixPosX} };
	vector<vector<int>> ZeroCheck;
	vector<int> PosActuelle;
	int SizeBoard = Board.size();

	//si case vide
	if (Board[ChoixPosY][ChoixPosX] == ' ') {
		//on met la position actuelle avec notre choix de départ et on rajoute à liste de zéros
		PosActuelle.push_back(ChoixPosY);
		PosActuelle.push_back(ChoixPosX);
		ZeroCheck.push_back(PosActuelle);

		//tant que la liste de 0 n'est pas vide
		while (ZeroCheck.size() != 0)
		{
			//on update les positions de départ
			ChoixPosY = ZeroCheck[0][0];
			ChoixPosX = ZeroCheck[0][1];

			//on parcourt les voisins et soit même
			for (int i = -1; i < 2; i++){
				for (int j = -1; j < 2; j++){

					//vérification de non sortie du board
					if ((ChoixPosY + i != -1) and (ChoixPosY + i != SizeBoard) and (ChoixPosX + j != -1) and (ChoixPosX + j != SizeBoard)) {

						//le vecteur de position actuelle est reset et mis à la position qu'on regarde
						PosActuelle.clear();
						PosActuelle.push_back(ChoixPosY+i);
						PosActuelle.push_back(ChoixPosX+j);

						//si la position n'a pas été déjà révélée on l'ajoute aux positions à révéler et si c'est une case vide on ajoute à la liste des 0
						if (count(Positions.begin(), Positions.end(), PosActuelle) == 0) {
							Positions.push_back(PosActuelle);
							if (Board[ChoixPosY + i][ChoixPosX + j] == ' ') {
								ZeroCheck.push_back(PosActuelle);
							}
						}
					}
				}
			}

			//on supprime le 0 qu'on vient de regarder
			ZeroCheck.erase(ZeroCheck.begin());
		}
	}

	return Positions;
}
vector<vector<int>> ModifieBoard(vector<vector<int>> BoardCache, vector<vector<int>> BoardJoueur, vector<vector<int>> Positions, bool *EnVie, int NombreBombes){
	//La fonction prend un vecteur de vecteurs en entrée et copie les valeurs aux positions du premier Board dans le deuxième et renvoie le Board Joueur
	int NbCasesCachees = 0;
	int Wait;
	for (int index = 0; index < Positions.size(); index++)
	{
		BoardJoueur[Positions[index][0]][Positions[index][1]] = BoardCache[Positions[index][0]][Positions[index][1]];
		if (BoardJoueur[Positions[index][0]][Positions[index][1]] == 'B') {
			*EnVie = false;
			system("cls");
			BoardJoueur[Positions[index][0]][Positions[index][1]] = 'X';
			AfficheBoard(BoardJoueur, BoardCache, BoardCache.size());
			cout << "PERDU !";
			cin >> Wait;
		}

	}
	for (int NumLigne = 0; NumLigne < BoardCache.size(); NumLigne++) {
		NbCasesCachees = NbCasesCachees + count(BoardJoueur[NumLigne].begin(), BoardJoueur[NumLigne].end(), '#');
	}
	 
	if (NbCasesCachees == NombreBombes) {
		*EnVie = false;
		system("cls");
		AfficheBoard(BoardJoueur, BoardCache, BoardCache.size());
		cout << "GAGNE !";
		cin >> Wait;
	}
	return BoardJoueur;
}