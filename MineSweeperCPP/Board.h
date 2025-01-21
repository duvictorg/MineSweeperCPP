#include <vector>
#include <tuple>
#ifndef BOARD
#define BOARD

std::vector<std::vector<int>> GenerationBoard(int SizeBoard, int NombreBombes);
std::vector<std::vector<int>> PlacementBombes(std::vector<std::vector<int>> Board, int NombreBombes, int SizeBoard);
std::vector<std::vector<int>> CompteBombes(std::vector<std::vector<int>> Board, int SizeBoard);
std::vector<std::tuple<int>> RevelationBoard(std::vector<std::vector<int>> Board, int ChoixPosX, int ChoixPosY);

#endif