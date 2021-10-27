#include <stdio.h>/*Standard input and output library*/
#include <ctype.h>/*Standard Library declares several functions that are useful for testing and mapping characters.*/
#include <string.h>/*Standard Library defines one variable type, one macro, and various functions for manipulating arrays of characters.*/
#include <stdlib.h>/*Stdard define in the library to indicate unsuccessful or successful terrmination*/

#define MAX_MSG 80/*defne max characters can be included in the message*/

/*
    Student Number: 041019930
    Name: Dadallage Samarasinghe
    Course: C Programming Language.
    Assignment: Lab 02
    Description: Program that encrypt a message.
*/

/*Recalling method encrypt*/
void encrypt(char* text, int key);

/*main method creation*/
int main () {

/*Variable declaration*/
int key, status, temp;
char text[MAX_MSG];

/*Print statement to output enter message*/
printf("Enter message to Encrypt: ");
fgets(text, MAX_MSG, stdin);/*fgets method to get user input message*/

/*if condition to determine user input message charater limit*/
if(strlen(text) >= 79) {
    printf("Invalid message!");/*error message to display for wrong character limit*/
    return EXIT_FAILURE;/*return statement for the unsuccessful program termination*/
}
printf("Enter rotation key: ");
status = scanf("%d", &key);

/*while condition for the userr input rotation key value*/
while (status != 1) {
    while ((temp = getchar()) != EOF && temp != '\n') {
        printf("Error - key must be in range 0 and 26. Try again.");
        status = scanf("%d", &key);
    }
}
/*if condition for user input key value to determine it's within the range*/
if(key < 0 || key > 26) {
    do{
        printf("Error - key must be in range 0 and 26. Try again.");
        scanf("%d", &key);
    }while(key < 0 || key > 26);
   encrypt(text, key);
    }else if(key >= 0 && key <= 26){/*else if to print out the encrypted message if the key value is within the range*/
        encrypt(text, key);
    }
    return EXIT_SUCCESS;/*return statement for the successful program termination*/
}

/*Void method created to convert the user input message to encrypted message*/
void encrypt(char* text, int key) {
    /*for loop created for the charaters in text message*/
    for(int i =0; i < strlen(text); i++) {
        if(isupper(text[i])){/*if condition created for the uppercase letters*/
            text[i] = ((text[i] - 65 + key) % 26) + 65;/**/
        }else if(islower(text[i])){/*else if condition created for the uppercase letters*/
            text[i] = ((text[i] - 97 + key) % 26) + 97;
        }
    }
    printf("Encrypting message (key = %d): %s",key, text);/*print statement to display the encrypted message*/
}/*end of main method*/
