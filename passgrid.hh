#ifndef PASSGRID_H
#define PASSGRID_H
#include "path.hh"

using namespace std;

class PassGrid{
	
  int lig ;
  int col ;
  char ** grid;
  
public:
	PassGrid(int x, int y);
	void print();
	void reset();
	const char * generate(Path  * chemin);
	int getLig();
	int getCol();
	char ** getGrid();
	~PassGrid();
};

#endif
