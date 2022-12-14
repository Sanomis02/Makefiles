# Makefiles
Repository consisting of projects that have Makefile for compiling
Projects include 2 directories, one of which contains a makefile that has incorrect syntax/malfunction and the other does not contain any Makefiles

# Requirements

Requirements for the program directory:

Create a Makefile for 'calculator'
*The program consists of three .c files: 'main.c', 'maths.c', 'usage.c'. The main file is 'main.c'
*For each .c file, an .o file must be created
*It is not possible to change the program code

Requirements for the library directory:

Write a Makefile for the library and the program that uses the library
*The program will consist of only the 'main.c' file
*The library will consist of 'file_reader.c' and 'file_reader.h' files
*The file 'example_text.txt' is used in the application
*By default, the Makefile must compile both the program and the library
*A separate target must be described in the Makefile, which tends to compile the library independently of the program
*The Makefile must create .o files for the library and the program
