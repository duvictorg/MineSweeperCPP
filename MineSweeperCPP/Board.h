#include <vector>
#ifndef BOARD
#define BOARD

std::vector<std::vector<int>> GenerationBoard(int SizeBoard, int NombreBombes);
std::vector<std::vector<int>> CompteBombes(std::vector<std::vector<int>> Board);

#endif