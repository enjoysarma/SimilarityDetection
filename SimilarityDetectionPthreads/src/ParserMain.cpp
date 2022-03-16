//Parser.cpp

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

extern void yyparse();
extern void yyrestart(FILE*);

void parse(vector<string> inputFiles) {
	for(int i = 0; i < inputFiles.size(); i++) {
		FILE *f = fopen(inputFiles[i].c_str(), "r");
			if(!f) {
				perror(inputFiles[i].c_str());
				throw exception();
			}
			yyrestart(f);
			yyparse();
			fclose(f);
		}
}
