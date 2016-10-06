#ifndef PATH_H
#define PATH_H
#include <cstdlib>

using namespace std;

class Path{
	
	int length;
	int * chemin;	
	int * start;
	
	
public :
	char * password;
	Path(int n, size_t hmax, size_t wmax);
	bool test_coord(int dir, int hmax, int wmax, int * coord);
	void print();
	int getLength();
	int * getPath();
	int * getStart();
	~Path();	
};

#endif

