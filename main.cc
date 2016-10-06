#include "passgrid.hh"
#include "path.hh"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
 
using namespace std;


int main(int argc, char * argv[])
{
	if(argc > 2){
		cout << "Erreur: trop d'arguments" << endl;
		return 0;		
	}
	srand(time(NULL));
	PassGrid pg(4,5);
	pg.print();  
	pg.reset();
	std::cout << std::endl;
	pg.print();
  
	Path c(5,4,5);
	
	c.print();
	cout << "Password : " << pg.generate(&c) << endl;

	// Écriture de la grille dans une image SVG
	// Il est nécessaire de fournir un nom de fichier .svg
	// Parfois,l'écriture ne semble pas fonctionner, il faut alors relancer le programme
	// On supposera ici que le fichier passé en paramètre est un fichier au format ".svg"
	if (argc != 1){
		
		char ** tempGrid = pg.getGrid();
		const char * file = argv[1];
		ofstream fichier(file, ios::out | ios::trunc);
		if(fichier){
			fichier <<"<svg viewBox = \"0 0" << 100*(pg.getCol()+2) << 100*(pg.getLig()+2) <<"\" version = \"1.1\">" << endl;
	
			for(int i = 0; i < pg.getLig(); i++){
				for(int j = 0; j < pg.getCol(); j++){
					
					// Mise en place des rectangles de couleurs
					fichier <<"<rect x=\"" << j*100 << "\" y=\"" << i*100 
							<< "\" width=\"" << 100 << "\" height=\"" << 100 
							<<"\" fill=\"black\" stroke=\"rgb(44, 193, 0)\" stroke-width=\"" 
							<< 5 << "\" />" << endl;
					
					// Mise en place du texte
					fichier << "<text x=\"" << (2*j+1)*50-10 << "\" y=\"" << (2*i+1)*50+5 
							<< "\" fill=\"rgb(44, 193, 0)\" font-size=\"" << 30 << "\">" << endl;
					
					fichier << "<tspan font-family = \"arial\">" << endl;
					fichier << tempGrid[i][j] << endl;
					fichier << "</tspan>" << endl;
					fichier << "</text>" << endl;
				}
			}
			
			
			fichier <<"</svg>" << endl;
			fichier.close();
		} else cerr << "Erreur: Impossible d'ouvrir le fichier" << endl;
	}
	
}
