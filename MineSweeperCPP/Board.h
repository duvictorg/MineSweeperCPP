#include <vector>
#ifndef BOARD
#define BOARD

std::vector<std::vector<int>> PlacementBombes(std::vector<std::vector<int>> Board, int NombreBombes, int SizeBoard);
std::vector<std::vector<int>> CompteBombes(std::vector<std::vector<int>> Board, int SizeBoard);
std::vector<std::vector<int>> RevelationBoard(const std::vector<std::vector<int>>& Board, int ChoixPosX, int ChoixPosY);
std::vector<std::vector<int>> ModifieBoard(std::vector<std::vector<int>> BoardCache, std::vector<std::vector<int>> BoardJoueur, const std::vector<std::vector<int>>& Positions, bool *EnVie, int NombreBombes);


#endif