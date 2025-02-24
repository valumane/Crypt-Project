#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 256



// Fonction de génération de clé à partir d'une phrase secrète
void generate_key(const char *phrase, unsigned char *key, size_t *key_length) {
    size_t phrase_length = strlen(phrase);
    *key_length = (phrase_length > MAX_KEY_SIZE) ? MAX_KEY_SIZE : phrase_length;
    
    // Mélange basique des caractères de la phrase pour générer une clé
    for (size_t i = 0; i < *key_length; i++) {
        key[i] = (phrase[i] + (i * 31)) % 256; // Transformation simple pour rendre la clé plus chaotique
    }
}

int main() {
    char phrase[MAX_KEY_SIZE];
    unsigned char key[MAX_KEY_SIZE];
    size_t key_length;
    
    printf("Entrez votre phrase secrète : ");
    fgets(phrase, MAX_KEY_SIZE, stdin);
    phrase[strcspn(phrase, "\n")] = 0; // Supprimer le saut de ligne
    
    generate_key(phrase, key, &key_length);
    
    printf("Clé générée (%zu octets) :\n", key_length);
    for (size_t i = 0; i < key_length; i++) {
        printf("%02X ", key[i]);
    }
    printf("\n");
    
    return 0;
}
