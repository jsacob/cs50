#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int get_key() {
    int key;
    char term;
    printf("key: ");
    
    while (scanf("%d%c", &key, &term) != 2 || term != '\n') {
        while (getchar() != '\n'); 
        printf("key must be a number\n");
        printf("key: ");
    }
    // printf("%d\n", key);
    return key; 
}

char* get_word() {
    printf("word: ");
    char *user_input = malloc(50 * sizeof(char));
    if(user_input == NULL){
        printf("Memory allocation failed\n");
    }
    while (fgets(user_input, 50, stdin) != NULL) {
        int i = 0;
        if (!isalpha(user_input[i])) {
            printf("all characters must be letters: ");
            continue;
        } else {
            // printf("%s", user_input);
            break;
        }
        i++;
    }
    return user_input;
}

int main() {
    char *s = "abcdefghijklmnopqrstuvwxyz";
    char arr[27];
    strcpy(arr, s);
    int key = get_key();
    char *word = get_word();
    // char *reverse_word = get_word();

    int char_count = 0;
    for (int i = 0; i < strlen(word); i++){
            //encrypting message
            int index = word[i] - 'a';
            int new_index = (index + key) %26; //formula C(i)=(P(i)+k)mod26
            word[i] = arr[new_index]; 
    }
//     for(int i = 0; i < strlen(reverse_word); i++){
//         if(isalpha(word[i])){
//             char_count++;
//             //unecrypting message
//             int reverse_index = reverse_word[i] - 'a';
//             int old_index = (reverse_index - key + 26) %26; //formula P(i)=(C(i)-k+26)%26
//             reverse_word[i] = arr[old_index];
//     }
// }
    printf("after shift: %s\n", word);
    // printf("revese shift: %s\n", reverse_word); 
    return 0;
}
