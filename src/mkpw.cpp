#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>

char characters[62] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
long length;

int main(int argc, char** argv[])
{
    srand(time(NULL));
    if(argc < 2) {
        printf("Usage: Generates a random password \nArguments: mkpw [length of password] \n");
        printf("Press the ENTER key to continue...");
        while(fgetc(stdin) != 0x0a);
        return 0;
    }
    else if(argc > 1) {
        length = strtol(argv[1], NULL, 10);
        if(length < 1) {
           printf("Password length cannot be less then 1 \n");
           return 1;
        }
        for(int i = 0; i < length; i++) {
            unsigned int selection = rand() % sizeof(characters);
            printf("%c", characters[selection]);
        }
        printf("\n");
    }
    return 0;
}
