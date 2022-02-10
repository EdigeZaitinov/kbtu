#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//2b
char encrypt(char c); 

char decrypt(char c); 

char dprt(char c); 

char cprt(char c); 

char my_get(char c); 
char quit(char c); 

char censor(char c) {
    if(c == '!')
        return '.';
    else
        return c;
}

//2a
char* map(char *array, int array_length, char (*f) (char)){
    char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
    char c;
    getchar();
    for (int i = 0; i < array_length; i++)
    {
        c = f(array[i]);
        //if (c!='\n')
        mapped_array[i] = c;
    }
    return mapped_array;
}

struct fun_desc {
    char *name;
    char (*fun)(char);
};

int main(int argc, char **argv){
    char *carray = (char *)malloc(5 * sizeof(char));
    strcpy(carray, "");
    int bounds = 0;
    int choosenOption = 0;
    struct fun_desc menu[] = { { "Censor", censor }, { "Encrypt", encrypt }, { "Decrypt", decrypt }, { "Print dec", dprt },
                               { "Print string", cprt },{ "Get string", my_get },{ "Quit", quit },{"Junk", menu},{ NULL, NULL } };

    printf("Please choose a function:\n");
    for (int i = 0; menu[i].name!=NULL; i++)
    {
        printf("%d) %s\n",i,menu[i].name);
        bounds++;
    }
    printf("Option: ");
    choosenOption = getchar() - '0';
    while (choosenOption<bounds && choosenOption >=0) //in bounds
    {
        printf("Within bounds\n");
        strcpy(carray, map(carray,5,menu[choosenOption].fun));
        printf("Done\n\n");
        for (int i = 0; menu[i].name!=NULL; i++)
        {
            printf("%d) %s\n",i,menu[i].name);
        }
        printf("Option: ");
        choosenOption = getchar() - '0';
    }
    printf("Not within bounds\n");
}


char encrypt(char c){
    if( c >= 0x20 && c <= 0x7e) {
        // c is in range
        c=c+3;
    }
    return c;
}
char decrypt(char c){
    if( c >= 0x20 && c <= 0x7e) {
        // c is in the range
        c=c-3;
    }
    return c;
}
char dprt(char c){
    printf("%d\n",c);
    return c;
}
char cprt(char c){
    if( c >= 0x20 && c <= 0x7e) {
        // c is in the range
        printf("%c\n", c);
    }
    else
    {
        printf(".\n");
    }
    return c;
}
char my_get(char c){
    c=fgetc(stdin);
    return c;
}

char quit(char c){
    exit(0);
}
