/************************* 
*Mauricio Fortune
*CPSC 2311 F22 Section 01
*mafortu@g.clemson.edu
*************************/ 

#include <stdio.h>
#include "Lab3Fgetc.h"


void start(FILE* in){

    char curChar;

    //Go until it reaches the EOF
    while(fscanf(in, "%c", &curChar) == 1){

        //A '/' marks the bginning of a comment
        if(curChar == '/'){
            
            rcomment(in);

            //Get next character
            fscanf(in, "%c", &curChar);

        }

        //Not a comment, print
        printf("%c", curChar);
    }

    return;
}

//See what type of comment it is
void rcomment(FILE* in){

    // Variable that takes in the character fgetc returns
    char curChar;

    // Get the next character
    fscanf(in, "%c", &curChar);

    //Determine the type of comment and call the associated function
    if(curChar == '*')
    {
        //Multi-line coment '/*'
        skipM_comment(in);
    }

    //Single-line comment
    else
    {
        skipS_comment(in);
    }

    return;
}

//Skip Multi-line comment
void skipM_comment(FILE* in){

    //Counter and current character
    char curChar;
    int checker = 0;

    // read till it gets to the end of the multi-line comment
    while(checker != 2){

        //Reset counter
        checker = 0;

        //Go to character before
        fseek(in, -1, SEEK_CUR);

        //Get the next character
        fscanf(in, "%c", &curChar);

        //Check if at the end of comment
        if(curChar == '*'){
            checker += 1;
        }

        //Get next character and check if at the end of comment
        fscanf(in, "%c", &curChar);
        if(curChar == '/'){
            checker += 1;
        }
    
    }
    printf("\n");
    return;
}


void skipS_comment(FILE* in){

    char curChar;

    //Check till end of comment
    while(curChar != '\n'){
        fscanf(in, "%c", &curChar);
    }
    
    //Go to previous character
    fseek(in, -1, SEEK_CUR);
    return;
}