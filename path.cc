#include "path.hh"
#include "passgrid.hh"
#include <iostream>
#include <cstdlib>
#include <ctime>

// ----------------------------- CONSTRUCTEUR ----------------------------------
/* Entrée : taille du chemin, en entier
 * 			limites de la grille, en entier (size_t)
 * Sortie : génération d'un chemin dans la grille
 * */
Path::Path(int n, size_t hmax, size_t wmax){
		
		this -> length = n-1;
		int * coord_start = new int[2];
		int * coord = new int[2];
		int direction;
		bool test;
		int * tab = new int[this->length];
	
		// On génère une coordonnée de départ aléatoirement
		coord_start[0] = rand()% hmax;
		coord_start[1] = rand()% wmax; 
		this -> start = coord_start;
		
		// On affecte les coordonnées de départ aux coordonnées courantes 
		coord[0] = coord_start[0];
		coord[1] = coord_start[1];
		
		// On remplit tab avec des entiers, correspondant à des directions
		for(int i = 0; i < n-1; i++){
			test = false;
			while(test == false){
				direction = rand()%8 ;
				test = test_coord(direction, hmax, wmax, coord);
			}
			tab[i] = direction;
		}		
		
		// On affecte tab au chemin
		this -> chemin = tab;
		
		char * mdp = new char[n];
		this -> password = mdp;
		
		delete[] (coord);
	
}
 

// -----------------------------------------------------------------------------
// Entrée : rien
// Sortie : affichage du chemin de manière compréhensible par l'utilisateur
void Path::print(){
		
		const char *tab[8] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
		
		cout << endl;
		cout << "********* PATH *********" << endl;
		cout << "Start : (" << start[0]+1 
								<< "," << start[1]+1 << ")" << endl;
		cout << "Path : ";
		for(int i = 0; i < this -> length ; i++)
				cout << tab[this -> chemin[i]] << ".";
				
		cout << endl;	
		cout << "************************" << endl;
}

// -----------------------------------------------------------------------------
/* Entrée : indice de direction, en entier (entre 0 et 7);
 * 			coordonnées courantes sur la grille, en entier;
 * 			limites de la grille, en entier;
 * 			pointeur sur les coordonnées courantes;
 * Sortie : Test si l'implémentation directionnelle est possible:	
 * 			retourne FAUX si les limites de la grille sont ateintes
 * 			Sinon : actualise les coordonnées courantes et retourne VRAI
 */ 
bool Path::test_coord(int dir, int hmax, int wmax, int * coord){
		switch(dir){
			case 0 : // Nord
				if(coord[0] == 0) return false;	
				else{coord[0] --; return true;}
				break;				
			case 1 : // Nord Est
				if(coord[0] == 0 || coord[1] == (wmax-1)) return false;
				else{coord[0] --; coord[1] ++; return true;}
				break;
			case 2 : // Est
				if(coord[1] == (wmax-1)) return false;
				else{coord[1] ++; return true;}
				break;
			case 3 : // Sud Est
				if(coord[0] == (hmax-1) || coord[1] == (wmax-1)) return false;
				else{coord[0] ++; coord[1] ++; return true;}
				break;
			case 4 : // Sud
				if(coord[0] == (hmax-1)) return false;
				else{coord[0] ++; return true;}
				break;
			case 5 : // Sud Ouest
				if(coord[0] == (hmax-1) || coord[1] == 0) return false;
				else{coord[0] ++; coord[1] --; return true;}
				break;
			case 6: // Ouest
				if(coord[1] == 0) return false;
				else{coord[1] --; return true;}
				break;
			case 7: // Nord Ouest
				if(coord[0] == 0 || coord[1] == 0) return false;	
				else{coord[0] --; coord[1] --; return true;}
				break;
			default : return false;
		}
		return true;
}

// ---------------------------- DESTRUCTEUR ------------------------------------

Path::~Path(){
	delete[] (chemin);
	delete[] (start);	
	delete[] (password);
}

// -------------------------- ACCESSEURS EN LECTURE ----------------------------

int Path:: getLength(){
	return (this -> length);
}

int * Path:: getPath(){
	return (this -> chemin);
}

int * Path:: getStart(){
	return (this -> start);
}

// -----------------------------------------------------------------------------
	

