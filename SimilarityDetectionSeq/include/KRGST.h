//KRGST.h

#ifndef _KRGST_H_
#define _KRGST_H_

#include "Tile.h"
#include <vector>
using namespace std;

class Program;
class ProgramPair;

class KRGST {
public:
	static ProgramPair* compare(Program* pa, Program *pb);
private:
	static void swap(Program*& pa, Program*& pb);
	static void addMatch(vector<Tile>&, Tile);
};


#endif
