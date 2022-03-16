//Program.h

#ifndef _PROGRAM_H_
#define _PROGRAM_H_

#include <vector>
#include <string>
#include <map>

#include <cstdint>
using namespace std;

class Token;

typedef pair<unsigned int, unsigned int> 		HTP;  //hash to position
typedef multimap<unsigned int, unsigned int> 	HTPMap;


class Program {
	string 			        name;
	vector<Token*> 	        tokens;
	
	vector<uint32_t>        tokenIds;
	
	vector<unsigned int> 	kgramHashes;
	HTPMap 			        htpMap;
public:
	Program(string);
	Program(string, vector<Token*>);
	~Program(){}

	HTPMap& getHtpMap();
	void setHtpMap(HTPMap htpMap);

	vector<unsigned int>& getKgramHashes();
	void setKgramHashes(vector<unsigned int> kgramHashes);

	string& getName() ;
	void setName(string name);

	vector<Token*>& getTokens();
	void setTokens(vector<Token*>& tokens);

	vector<uint32_t>& getTokenIds();
	void setTokenIds(vector<uint32_t>& tokenIds);
	
	unsigned int getNumberOfTokens();
	void unmarkAllTokens();
};


#endif
