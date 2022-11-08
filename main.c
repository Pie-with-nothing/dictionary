#include "laba4_head.h"
#include <stdio.h>
int main(int argc, char const* argv[]){
    char *first_key = (char *)"first";
    float first_value = 1.34;
    char *second_key = (char *)"second";
    char second_value = 'a';
    char *third_key = (char *)"third";
    int third_value = -21;
    char *fourth_key = (char *)"fourth";
    char *fourth_value = (char *)"qwasec1234";

    dictionary *D = create_dictionary();
    add_elem(D, first_key, &first_value, sizeof(float), FLOAT);
    add_elem(D, second_key, &second_value, sizeof(char), CHAR);
    add_elem(D, third_key, &third_value, sizeof(int), INT);
    add_elem(D, fourth_key, &fourth_value, sizeof(char *), STRING);
    print_dictionary(D);

    printf("\n");

    copy_keyvalue(find_elem(D, second_key), find_elem(D, first_key));
    printf("first elem == second elem?: %d\n", match_keyvalue(find_elem(D, first_key), find_elem(D, second_key)));
    printf("first elem == fourth elem?: %d\n", match_keyvalue(find_elem(D, first_key), find_elem(D, fourth_key)));
    delete_elem(D, third_key);
    print_dictionary(D);
    delete_dictionary(D);
    //getc(stdin);
    return 0;
}