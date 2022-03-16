//bison_util.cpp

#include "bison_util.h"
#include <vector>
using namespace std;

vector<TokenId> tid_buffer;

void 	b_util_tid_buffer_insert(TokenId tid) {
	tid_buffer.push_back(tid);
}

TokenId b_util_tid_buffer_remove() {
	TokenId tid = tid_buffer[0];
	tid_buffer.erase(tid_buffer.begin());
	return tid;
}

int 	b_util_tid_buffer_empty() {
	return tid_buffer.empty();
}

void 	b_util_tid_buffer_clear(){
	tid_buffer.clear();
}