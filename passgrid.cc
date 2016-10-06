#include "passgrid.hh"
#include "path.hh"
#include <iostream>
#include <cstdlib>
#include <ctime>

// ----------------------------- CONSTRUCTEUR ----------------------------------
// Entrée : nb de lignes, en entiers; nb de colonne, en entier
// Sortie : génération d'une grille
PassGrid::PassGrid(int x, int y){	
		this -> lig = x;
		this -> col = y;
    
		char ** tab = new char*[x];	
		for (int i = 0; i < x; i++) 
			tab[i] = new char[y];
			
		for (int i = 0; i < x; i++)
			for(int j = 0; j < y; j++)
				tab[i][j] = rand()% 94 + 33;
					
		this -> grid = tab;
	}
	
// -----------------------------------------------------------------------------
// Entrée : rien
// Sortie : affichage de la grille générée
void PassGrid::print(){	
  for(int i = 0; i < lig; i++){
    for(int j = 0; j < col; j++)
      cout << " " << grid[i][j] << " ";       			
    cout << endl;		
  }
}

// -----------------------------------------------------------------------------
// Entrée : pointeur sur chemin
// Sortie : mot de passe généré dans la grille grâce au chemin 
const char * PassGrid :: generate(Path * chemin){
	
		int size = chemin -> getLength();
		int *path = chemin -> getPath();
		int *start = chemin -> getStart();
		int * coord = new int[2];
		
		coord[0] = start[0];
		coord[1] = start[1];
		chemin -> password[0] = this -> grid [coord[0]] [coord[1]];
		
	
		for(int i = 0; i < size; i++){
			// Mise a jour de coord[0] et coord[1]
			chemin -> test_coord(path[i], this -> lig, this -> col, coord);
			chemin -> password[i+1] = this -> grid[coord[0]][coord[1]];
		}
			
		delete[] (coord);
		return chemin -> password;
};
// En exécutant le programme avec valgrind, on trouve une erreur lors de l'appel à la fonction generate.
// Les paramètres ont été modifiés afin de procéder à un passage par adresse, dans le but de limiter les fuites mémoires.

// -----------------------------------------------------------------------------
// Entrée : rien
// Sortie : génération d'une nouvelle grille
void PassGrid::reset(){
    for(int i = 0; i < lig; i++)
      for(int j = 0; j < col; j++)
	grid[i][j] = rand()% 94 + 33;
 }
		
// ---------------------------- DESTRUCTEUR ------------------------------------	
		
PassGrid::~PassGrid(){
	for(int i = 0; i < lig; i++)
		delete[](grid[i]);
	
	delete[](grid);
}

// -------------------------- ACCESSEURS EN LECTURE ----------------------------

int PassGrid:: getLig(){
	return (this -> lig);
}

int PassGrid:: getCol(){
	return (this -> col);
}

char ** PassGrid:: getGrid(){
	return (this -> grid);
}

// -----------------------------------------------------------------------------

