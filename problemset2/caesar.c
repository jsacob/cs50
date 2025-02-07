//formula for encrypting with caesar C(i)=(P(i)+K)MOD26
//formula for unencrypting with caesar P(i)=(C(i)-K+26)MOD26

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
    printf("plaintext: ");
    char *word = get_word();  
    printf("deciphertext: ");
    char *reverse_word = get_word();      

    // Encryption logic
    for (int i = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) {
            char base = isupper(word[i]) ? 'A' : 'a';
            int index = word[i] - base;
            int new_index = (index + key) % 26;
            word[i] = base + new_index;
        }
    }

    for (int i = 0; i < strlen(reverse_word); i++){
        if (isalpha(reverse_word[i])) {
            char base = isupper(reverse_word[i]) ? 'A' : 'a';
            int index = reverse_word[i] - base;
            int old_index = (index - key + 26) % 26;
            reverse_word[i] = base + old_index;
        }
    }
   
    printf("ciphertext: %s\n", word);  
    printf("deciphertext: %s\n", reverse_word);
    return 0;
}
