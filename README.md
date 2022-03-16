# SimilarityDetection
RKR-GST source code similarity detection system project

This is the official repository of the RKR-GST based source code plagiarism detection system developed at the University of Belgrade, School of Electrical Engineering.

# Contents

1. Overview
2. Compilation
3. Execution and testing 
4. References

# Overview

RKR-GST based source code plagiarism detection system is an academic effort to explore performance improvements of source code similarity detection system. Beside sequential implementation, CPU-based (Pthreads) and GPU-based (CUDA) implementations are available. 

# Compilation

CMAKE is used to compile the project.
    
If "build" folder is not present in the installation directory, create one and run the following command:
cmake $PATH_TO_CMakeLists.txt_FILE - run this command from inside the build directory.
    
	cmake ../

This will generate a Makefile and all other neccessary files in the "build" directory.
Next step is to execute make from inside build directory.
  
	make
  
# Execution and testing

To execute, run "app" executable with following arguments:
    
    $1: path to the folder with all programs that need to be compared
    $2: path to the output folder for results of the sequential version of the program
    $3: path to the output_folder for results of the CPU/GPU version of the program

If fewer arguments are passed, the application will ask for the arguments interactively.
	
Test suite is available in tests folder with micro, mini and full packages available. Each package consists of selected student projects, consisting of ~1000 or more lines of code. Tests are given in compressed tarball. Before proceeding, decompress them with the following command:

	tar -xjf test_suite.tar.bz2

# References
	
If you wish to cite our RKR-GST based source code plagiarism detection system in an academic publication, please use the following reference:

1. Mišić, Marko J., Jelica Ž. Protić, and Milo V. Tomašević. "Improving source code plagiarism detection: Lessons learned." 2017 25th Telecommunication Forum (TELFOR). IEEE, 2017.