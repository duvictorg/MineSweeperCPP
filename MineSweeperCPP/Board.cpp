#include <iostream>
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

vector<vector<int>> PlacementBombes(std::vector<std::vector<int>> Board, int NombreBombes, int SizeBoard)
{
	//La fonction prend un board vide
	//Génère deux nombres aléatoires entre 0 et SizeBoard qui seront la position de la bombe
	//Si une bombe est déjà à la position relancer la position aléatoire
	return Board;
}

vector<vector<int>> CompteBombes(std::vector<std::vector<int>> Board){
	//La fonction prend un board avec des bombes
	//Parcourt le vecteur de vecteur et compte pour chaque numéro le nombre de bombes voisines
	//renvoie le board avec les numéros
	return Board;
}

vector<tuple<int>> RevelationBoard(std::vector<std::vector<int>> Board, int ChoixPosX, int ChoixPosY){
	//La fonction prend le board et le choix de position à révéler et renvoie un vecteur de tuples de Positions à révéler
	vector<tuple<int>> Positions;
	return Positions;
}
