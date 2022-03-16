//KarpRabin.h

#ifndef _KARPRABIN_H_
#define _KARPRABIN_H_

#include <vector>

class Program;
class Token;

class KarpRabin {
	static unsigned int init_hash(std::vector<Token*>& t);
public:
	static void hash(Program*);
};


#endif
