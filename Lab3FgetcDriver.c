/************************* 
*Mauricio Fortune
*CPSC 2311 F22 Section 01
*mafortu@g.clemson.edu
*************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Lab3Fgetc.h"



int main( int argc, char *argv[])
{
   
   //If an input file is passed in from command line
   //argc should be equal to 2
   assert(argc==2);

   //If an input file is passed from command line it will be the 
   //second argument in the argv[] array
   FILE* input = fopen(argv[1], "r");

   //Make sure the file is actually open
   assert(input != NULL);

   start(input);

   return 0;
}