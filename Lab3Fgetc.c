/************************* 

*Mauricio Fortune

*CPSC 2311 

*************************/ 


#include <stdio.h>

#include "Lab3Fgetc.h"



void start(FILE* in){


    int curChar;

    //Get the first character
    curChar = fgetc(in);

    //Go until it reaches the end of file
    while(curChar != EOF){

        //A '/' marks the beginning of a comment
        if(curChar == '/'){
            

            rcomment(in);

            //Get the next character
            curChar = fgetc(in);
        }

        // Not a comment, print
        printf("%c", curChar);
        curChar = fgetc(in);
    }

    return;
}

//See what kind of comment it is
void rcomment(FILE* in){


    // Variable that takes in the character fgetc returns
    int curChar;

    // Get the next character
    curChar = fgetc(in);


    //Multi-line comment '/*'
    if(curChar == '*'){
        skipM_comment(in);
    }
    
    //Single-line comment
    else{
        skipS_comment(in);
    }

    return;
}

//Skip Multi-line comment
void skipM_comment(FILE* in){

    //Counter and current character
    int curChar, checker = 0;

    //Read over the entire comment
    while(checker != 2){

        //Reset counter
        checker = 0;
        
        //Go to the character before
        fseek(in, -1, SEEK_CUR);

        //Get next character
        curChar = fgetc(in);

        //Check if at the end of comment
        if(curChar == '*'){
            //First part of end of multi-
            //line comment increment counter
            checker += 1;
        }

        //Check next character to see if
        // at end of multi-line
        if(fgetc(in) == '/'){
            checker += 1;
        }
    }
    
    //Print newline where comment is in input
    printf("\n");

    return;

}


void skipS_comment(FILE* in){

    //Current character
    int curChar;


    //Check for end of single comment which is
    //a newline character
    while(curChar != '\n'){

        //Get next character
        curChar = fgetc(in);
    }

    //Go to previous character
    fseek(in, -1, SEEK_CUR);

    return;
}
