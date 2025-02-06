#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int get_key(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        exit(1); 
    }

   
    int key = atoi(argv[1]);
    if (key < 0 || key > 25) {  
        printf("key must be between 0 and 25\n");
        exit(1); 
    }
    return key;
}

char* get_word() {
    printf("plaintext: ");
    char *user_input = malloc(50 * sizeof(char));
    if (user_input == NULL) {
        printf("Memory allocation failed\n");
        exit(1); 
    }
    fgets(user_input, 50, stdin);
    user_input[strcspn(user_input, "\n")] = '\0'; 
    return user_input;
}

int main(int argc, char *argv[]) {
    int key = get_key(argc, argv);  
    char *word = get_word();        

    // Encryption logic
    for (int i = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) {
            char base = isupper(word[i]) ? 'A' : 'a';
            int index = word[i] - base;
            int new_index = (index + key) % 26;
            word[i] = base + new_index;
        }
    }

   
    printf("ciphertext: %s\n", word);  
    return 0;
}
