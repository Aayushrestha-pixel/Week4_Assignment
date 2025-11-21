#include <string.h>
#include <ctype.h>

// function to convert string to uppercase
void to_uppercase(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}