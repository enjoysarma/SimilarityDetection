//main.cpp

#include "Program.h"
#include "ProgramPair.h"
#include "KarpRabin.h"
#include "KRGST.h"
#include "GST_mod.h"
#include "Table.h"
#include "Token.h"
#include "Scope.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "string_tokens.h"
#include <fstream>
#include <dirent.h>
#include <cstring>
#include <cstdlib>
#include <sstream>

#include <chrono>
using namespace std;
using namespace std::chrono;


void parse(vector<string>);

void hash(vector<Program*>& programs) {
	for( unsigned i = 0; i < programs.size(); ++i ) {
		KarpRabin::hash(programs[i]);
	}
}

vector<ProgramPair*> compare(vector<Program*>& programs) {
    vector<ProgramPair*> program_pairs;
    ::hash(programs);
    for (unsigned int i = 0; i < programs.size(); ++i)
        for (unsigned int j = i + 1; j < programs.size(); ++j) {
            ProgramPair *pp = KRGST::compare(programs[i], programs[j]);
            pp->estimateSimilarity();
            program_pairs.push_back(pp);
        }
    return program_pairs;
}

void writeReport(vector<ProgramPair*> ppairs, string path) {
	for( unsigned int i = 0; i < ppairs.size(); ++i ) {
		ProgramPair *pp = ppairs[i];
		string outputFileName = string(pp->getFirst()->getName() + "-" + pp->getSecond()->getName() + ".txt");
		ofstream fout((path + "/" + outputFileName).c_str());

		if(fout.is_open() == false) {
			cout << "cant open file" << endl;
		}

		fout << "FirstProgram: " 	<< pp->getFirst()->getName() 	<< endl;
		fout << "SecondProgram: "	<< pp->getSecond()->getName() 	<< endl;
		fout << "Similarity: " 	<< pp->getSimilarity() * 100 << "%" << endl;
		fout << "\nOverlaping Lines: " << endl << endl;

		vector<Tile>& tiles = pp->getTiles();
		for ( unsigned int j = 0; j < tiles.size(); ++j ) {
			fout << "F: " << pp->getFirst()->getTokens()[tiles[j].fpi]->getLineNumber() << " - ";
			fout << pp->getFirst()->getTokens()[ tiles[j].fpi + tiles[j].len - 1]->getLineNumber() << "\t";
			fout << "S: " << pp->getSecond()->getTokens()[tiles[j].spi]->getLineNumber() << " - ";
			fout << pp->getSecond()->getTokens()[ tiles[j].spi + tiles[j].len - 1]->getLineNumber() << endl;
		}
	}
}

vector<string> readDirectory(string path) {
	vector<string> files;
	struct dirent *entry;
	DIR *dp;

	dp = opendir(path.c_str());
	if (dp == NULL) {
		perror("opendir");
		throw exception();
	}

	while((entry = readdir(dp))) {
		if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
		files.push_back(path + "/" + entry->d_name);
	}
	closedir(dp);
	return files;
}

void checkDir(string dir) {
	DIR* dp = opendir(dir.c_str());
		if (dp == NULL) {
			perror("opendir");
			throw exception();
		}
	closedir(dp);
}

void writeStatus(vector<ProgramPair*> ppairs, string path) {
	ofstream ffout[10];
	string result("_results");
	string txt(".txt");

	for(int j = 0; j < 10; j++) {
		stringstream ss;
		ss << j*10;
		string str1 = ss.str();
		ss.str("");
		ss << (j+1)*10;
		string str2 = ss.str();

		string s(path + "/" + result + str1 + "-" + str2 + txt);
		ffout[j].open(s.c_str(), ofstream::out);
		for(int i = 0; i < ppairs.size(); ++i) {
			if( j*10 <= ppairs[i]->getSimilarity()*100 && ppairs[i]->getSimilarity() * 100 < (j+1)*10) {
				ffout[j] << ppairs[i]->getFirst()->getName() << "-" << ppairs[i]->getSecond()->getName() << "\t" << ppairs[i]->getSimilarity() * 100 << endl;
			}
		}

		ffout[j].close();
	}
}

int main(int argc, char** argv) {



	try{
		string inputDir, outputDir1, outputDir2;
		if(argc < 3) {
			cout << "Input directory name: ";
			cin >> inputDir;
			cout << "Output directory name: ";
			cin >> outputDir1;
		} else {
			inputDir = string(argv[1]);
			outputDir1 = string(argv[2]);
		}
		checkDir(inputDir);
		checkDir(outputDir1);

		vector<string> inputFiles = readDirectory(inputDir);

		parse(inputFiles);

		vector<Program*> programs;
		vector<Scope*> scopes = Table::getProgramScopes();
		vector<ProgramPair*> pp1;

		for(int i = 0; i < inputFiles.size(); i++) {
			string name = inputFiles[i].substr(inputFiles[i].find_last_of('/')+1);
			programs.push_back(new Program(name, scopes[i]->getTokens()));
		}
		
		if(programs.size() > 1) {

			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			pp1 = compare(programs);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();

			auto duration = duration_cast<milliseconds>(t2 - t1).count();

			cout << "Duration of method1: " << duration << "[ms]" << endl;

			writeReport(pp1, outputDir1);
			writeStatus(pp1, outputDir1);

		} else {
			cout << "At least 2 input files are needed" << endl;
		}

		Table::finish();

		for(int i = 0; i < programs.size(); i++) delete programs[i];
		for (int i = 0; i < pp1.size(); i++) {
			delete pp1[i];
		}

	}catch(exception e) {
		cout << "Exception " << e.what() << endl;
	}
}














