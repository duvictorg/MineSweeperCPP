#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;

vector<vector<int>> GenerationBoard(int SizeBoard, int NombreBombes){
	//Fonction de cr�ation du board en donnant une taille sp�cifi�e et le nombre de bombes
	//La fonction cr�e le vecteur de vecteurs en remplissant de 0, puis al�atoirement place les bombes
	//La fonction appellera ensuite uen fonction pour compter les bombes et placer les num�ros
	//Elle renverra enfin le board cr��e, de 0 � 9 les nombres et B les positions de bombes
	vector<vector<int>> Board;

	for (int NumLigne = 0; NumLigne < SizeBoard; NumLigne++) 
	{
		vector<int> VectorLigne;

		for (int NumColonne = 0; NumColonne < SizeBoard; NumColonne++) 
		{
			VectorLigne.push_back(0);
		}

		Board.push_back(VectorLigne);
	}
	return Board;

}

vector<vector<int>> CompteBombes(std::vector<std::vector<int>> Board){
	//La fonction prend un board avec des bombes
	//Parcourt le vecteur de vecteur et compte pour chaque num�ro le nombre de bombes voisines
	//renvoie le board avec les num�ros

}
