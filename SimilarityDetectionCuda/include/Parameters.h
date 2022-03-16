//Parameters.h

#ifndef _PARAMETERS_H_
#define _PARAMETERS_H_

class Parameters {
	static unsigned int hash_base;
	static unsigned int minimum_match_length;
	static double		cutoff_treshold;
	
	static unsigned int max_token_vector_size;
public:
	static unsigned int getHashBase();
	static void setHashBase(unsigned int hashBase);
	static unsigned int getMinimumMatchLength();
	static void setMinimumMatchLength(unsigned int minimumMatchLength);
	static double getCutoffTreshold();
	static void	setCutoffTreshold(double);
	
	static unsigned int getMaxTokenVectorSize();
	static void setMaxTokenVectorSize(unsigned int maxTokenVectorSize);
private:
	Parameters(){}
};

#endif
