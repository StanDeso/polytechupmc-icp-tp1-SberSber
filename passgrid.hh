#include <iostream>
#include <cstdlib>

class PassGrid{
	
  int lig ;
  int col ;
  char ** grid;
  
public:
	PassGrid(int x, int y){	
    this -> lig = y;
    this -> col = x;
    char ** tab = new char*[y];	

    for (int i = 0; i < y; i++) 
      tab[i] = new char[x];
			
    for (int i = 0; i < y; i++)
      for(int j = 0; j < x; j++)
	tab[i][j] = rand()% 94 + 33;
					
    grid = tab;
 };
	
void print(){	
  for(int i = 0; i < lig; i++){
    for(int j = 0; j < col; j++)
      std::cout << " " << grid[i][j] << " ";       			
    std::cout << std::endl;		
  }
};

void reset(){
    for(int i = 0; i < lig; i++)
      for(int j = 0; j < col; j++)
	grid[i][j] = rand()% 94 + 33;
 };
		
~PassGrid(){
	for(int i = 0; i < lig; i++)
		delete(grid[i]);
	
	delete(grid);
};

};
