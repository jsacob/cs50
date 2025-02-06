#include <stdio.h>

int main() {
   char buffer[50];

   printf("Enter a string: ");
   if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    size_t bufflen = sizeof(buffer);
        if(bufflen != '\0'){
            printf("string is too long");
        } else{


        printf("%zu %s", bufflen, buffer);
    }
    }
    
   return 0;
   } 

