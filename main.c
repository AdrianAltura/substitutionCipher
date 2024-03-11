#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encipher(char plaintext[], char key[]);

int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) < 26){
        printf("Key must contain 26 characters\n");
        return 1;
    }

    for (int key = 0; key < strlen(argv[1]); key++){
        if (!(isalpha(argv[1][key]))){
            printf("Usage: ./substitution Key must contain alphabetic characters.\n");
            return 1;
        }
    }

    for (int i = 0; i < strlen(argv[1]); i++){
        for (int j = 0; j < strlen(argv[1]); j++){
            if (j != i){
                if (argv[1][i] == argv[1][j]){
                    printf("Usage: ./substitution Key must not contain repeated characters\n");
                    return 1;
                }
            }
        }
    }

    char plaintext[50000];

    printf("Plaintext: ");
    fgets(plaintext, 50000, stdin);

    // to check if key, key length and plaintext are correct.
    // printf("key: %s\n", key);
    // printf("%lu\n", strlen(key));
    // printf("Plaintext: %s\n", plaintext);

    encipher(plaintext, argv[1]);

}

void encipher(char plaintext[], char key[]){

    int letterKey = 0;
    int len = strlen(plaintext);
    char ciphertext[len];

    for (int i = 0; i < len; i++){
        if (isalpha(plaintext[i])){
            if (isupper(plaintext[i])){
                letterKey = 25 - ('Z' - plaintext[i]);
                ciphertext[i] = toupper(key[letterKey]);
            }

            else if (islower(plaintext[i])){
                letterKey = 25 - ('z' - plaintext[i]);
                ciphertext[i] = tolower(key[letterKey]);
            }
        }

        else{
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len] = '\0';
    printf("ciphertext: %s", ciphertext);
}

//todo

//get key DONE
//validate key DONE
    // check for key length DONE
    // check for non-alphabetical characters DONE
    // check for repeated characters DONE
//get plaintext DONE
//encipher DONE
//print ciphertext DONE
