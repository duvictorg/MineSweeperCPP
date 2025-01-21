#include <iostream>
#include <vector>
#include <tuple>
#include "Board.h"
using namespace std;

vector<vector<int>> GenerationBoard(int SizeBoard, int NombreBombes){
	//Fonction de cr�ation du board en donnant une taille sp�cifi�e et le nombre de bombes
	//La fonction cr�e le vecteur de vecteurs en remplissant de #, puis al�atoirement place les bombes
	//La fonction appellera ensuite uen fonction pour compter les bombes et placer les num�ros
	//Elle renverra enfin le board cr��e, de 1 � 9 les nombres et B les positions de bombes et si 0 alors vide
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
	//G�n�re deux nombres al�atoires entre 0 et SizeBoard qui seront la position de la bombe
	//Si une bombe est d�j� � la position relancer la position al�atoire
	return Board;
}

vector<vector<int>> CompteBombes(std::vector<std::vector<int>> Board){
	//La fonction prend un board avec des bombes
	//Parcourt le vecteur de vecteur et compte pour chaque num�ro le nombre de bombes voisines
	//renvoie le board avec les num�ros
	return Board;
}

vector<tuple<int>> RevelationBoard(std::vector<std::vector<int>> Board, int ChoixPosX, int ChoixPosY){
	//La fonction prend le board et le choix de position � r�v�ler et renvoie un vecteur de tuples de Positions � r�v�ler
	vector<tuple<int>> Positions;
	return Positions;
}
