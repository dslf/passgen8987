#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LOWER 1
#define UPPER 2
#define DIGIT 4
#define SPECI 8

void shuffle_combined(char *combi, int len){
    int j, temp;
    srand(time(NULL));
	for (int i = 0; i < len; i++){
		j = i + rand() % ((len)-i);		
        temp = combi[i]; 
		combi[i] = combi[j];
		combi[j] = temp;
	}
}

int main(){
    int bit_mask = LOWER+UPPER+DIGIT+SPECI;
    int passwd_length = 20;
    int passwd_numbers = 20;

    char array_lower_case[] = "abcdefghijklmnopqrstuvwxyz";
    char array_upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char array_digits[] = "0123456789";
    char array_specials[] = "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";
    char *combined;

    combined = malloc(sizeof(char));
    if (!combined) {
        printf("alloc err\n");
        return 1;
    }
    *combined = '\0';

    if (bit_mask & LOWER) {
        char *temp;
        temp = realloc(combined, strlen(combined) + strlen(array_lower_case) + 1);
        if (!temp) {
            free(combined);
            printf("err lower realloc\n");
            return 1;
        }
        combined = temp;
        strcat(combined, array_lower_case);
    }

    if (bit_mask & UPPER) {
        char *temp;
        temp = realloc(combined, strlen(combined) + strlen(array_upper_case) + 1);
        if (!temp) {
            free(combined);
            printf("err upper realloc\n");
            return 1;
        }
        combined = temp;
        strcat(combined, array_upper_case);
    }

    if (bit_mask & DIGIT) {
        char *temp;
        temp = realloc(combined, strlen(combined) + strlen(array_digits) + 1);
        if (!temp) {
            free(combined);
            printf("err digit realloc\n");
            return 1;
        }
        combined = temp;
        strcat(combined, array_digits);
    }

    if (bit_mask & SPECI) {
        char *temp;
        temp = realloc(combined, strlen(combined) + strlen(array_specials) + 1);
        if (!temp) {
            free(combined);
            printf("err special realloc\n");
            return 1;
        }
        combined = temp;
        strcat(combined, array_specials);
    }
    
    int buffer_length = strlen(combined);

    srand(time(NULL));
    int len = strlen(combined);
    for (int i = 0; i < passwd_numbers; i++){
        shuffle_combined(combined, len);
        for (int j = 0; j < passwd_length; j++){
            putchar(combined[rand() % buffer_length]);
        }
    printf("\n");
    }
    free(combined);
}