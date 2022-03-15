//Program.h

#ifndef _PROGRAM_H_
#define _PROGRAM_H_

#include <vector>
#include <string>
#include <map>
using namespace std;

class Token;

typedef pair<unsigned long long, unsigned int> 		HTP;  //hash to position
typedef multimap<unsigned long long, unsigned int> 	HTPMap;


class Program {
	string 			name;
	vector<Token*> 	tokens;
	vector<unsigned long long> 	kgramHashes;
	HTPMap 			htpMap;
public:
	Program(string);
	Program(string, vector<Token*>);
	~Program(){}

	HTPMap& getHtpMap();
	void setHtpMap(HTPMap htpMap);

	vector<unsigned long long>& getKgramHashes();
	void setKgramHashes(vector<unsigned long long> kgramHashes);

	string& getName() ;
	void setName(string name);

	vector<Token*>& getTokens();
	void setTokens(vector<Token*>& tokens);

	unsigned int getNumberOfTokens();
	void unmarkAllTokens();
};


#endif
