#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void cipherbykey(char plaintext[500], int key);
int checkalphakey(char alphakey[100], char plaintext[500]);
void cipherbyalpha(char input[500], char alphakey[100]);
void decipherbykey(char ciphertext[500], int key);
void decipherbyalpha(char input[500], char alphakey[100]);
int main()
{
    char choice;
    char way;
    int key;
    char alphakey[100];
    char plaintext[500];
    char ciphertext[500];
    
    printf("\nWelcome to a basic cryptography tool.\n\nIn computer science, cryptography refers to secure information and communication techniques derived from mathematical concepts and a set of rule-based calculations called algorithms, to transform messages in ways that are hard to decipher.\n\nHere we are not going to use complex algorithms. We will use a key to encrypt or decrypt a text. We can choose the way we want to cipher/decipher.\n\nIf we choose to encrypt a message with a numeric key, for instance 5, then all the alphabets will be shifted five places to its right.\nFor example: if we have text:ABC and a key of 5, then the encrypted text will be:FGH. Notice how A is added plus 5 resulting in the letter F and so on.\n\nSimilarly, if we use alphabetical keys then while defining keys, we have to define all 26 characters that we want to use. None of the characters in key should repeat. Based on the sequence/place of the keys, the text will be encrypted. It is pretty much with encrypting. For decrypting, it is the same logic. The only difference is that now we are trying to decipher the encrypted text to find its value.\n\nLet's get started with the tool.");
    printf("First choose if you want to cipher or decipher.\nTo cipher, press C. To decipher, press D\n\n");
    scanf("%c", &choice);

    //for cipher

    if (((int)choice == 67) || ((int)choice == 99))
    {
        //prompt user for the plain text

        printf("\nEnter the text you want to cipher: \n");
        getchar();
        scanf("%[^\n]s", plaintext);
        
        printf("\nIf you want to encrypt via numeric key, press A or if via alphabetical, press B.\n");
        getchar();
        scanf("%c", &way);

        //for numeric key
        if (((int)way == 65) || ((int)way == 97))
        {
            printf("\nPlease enter a numeric key:\n");
            scanf("%d",&key);
            if (isalnum(key))
            {
                printf("Make sure the key is nummeric. Terminating..\n");
                return 1;
            }
            else
            {
                cipherbykey(plaintext, key);
            }
        }

        //for alphabetical key
        else if (((int)way == 66) || ((int)way == 98))
        {
            //prompt user for the key
            printf("\nPlease enter 26 alphabetical keys:\n");
            getchar();
            scanf("%[^\n]s", alphakey);
            int p = checkalphakey(alphakey, plaintext);
            if (p != 1)
            {
                cipherbyalpha(plaintext, alphakey);
            }          
        }
        else
        {
            printf("\nInvalid way.\nTerminating...\n");
            return 1;
        }
    }

    //to decipher
    else if (((int)choice == 68) || ((int)choice == 100))
    {
        printf("\nEnter the text you want to decipher: \n");
        getchar();
        scanf("%[^\n]s", ciphertext);
        
        printf("\n Here you can decrypt with the help of numeric key only\n");

        //for numeric key
        printf("\nPlease enter a numeric key:\n");
        scanf("%d",&key);
        if (isalnum(key))
        {
            printf("Make sure the key is nummeric. Terminating..\n");
            return 1;
        }
        else
        {
            decipherbykey(ciphertext, key);
        }
    }
    else
    {
        printf("\nIncorrect option.\n");
        printf("Terminating....\n");
    }
}

void cipherbykey(char plaintext[500], int key)
{
    char input[500];
    //Iterate over each character of the plaintext
        for (int i = 0, len = strlen(plaintext); i < len; i++)
        {
            // Incase of uppercase
            if (isupper(plaintext[i]))
            {
                input[i] = (((plaintext[i] - 'A') + key) % 26) + 'A';
            }

            //Incase of lowercase
            else if (islower(plaintext[i]))
            {
                input[i] = (((plaintext[i] - 'a') + key) % 26) + 'a';
            }

            //Incase of other characters
            else
            {
                input[i] = plaintext[i];
            }
        }
        printf("\nCiphertext: \n\n%s\n\n", input);
}

void cipherbyalpha(char input[500], char alphakey[100])
{
    for (int i = 0, len = strlen(input); i < len; i++)
        {
            // Incase of uppercase
            if (isupper(input[i]))
            {
                input[i] = toupper(alphakey[input[i] - 'A']);
            }

            //Incase of lowercase
            else if (islower(input[i]))
            {
                input[i] = tolower(alphakey[input[i] - 'a']);
            }
            else
            {
                input[i] = input[i];
            }
        }
        //Print out the rotated text
        printf("\nCiphertext: \n\n%s\n\n", input);
}

int checkalphakey(char alphakey[100], char plaintext[500])
{
    //Check the total number of the key
            if ((strlen(alphakey) != 26))
            {
                printf("\n\nKey must contain 26 characters. Terminating..\n");
                return 1;
            }
            else
            {
                //Iterate over the provided argument to make sure all characters are alphabets
                for (int i = 0, len = strlen(plaintext); i < len; i++)
                {   
                    if (isdigit(alphakey[i]))
                    {
                        printf("Make sure the key contains only alphabets. Terminating..\n");
                        return 1;
                    }
                }

                //Iterate over the provided arguement to see if the characters are repeated
                for (int l = 0; l <= strlen(alphakey); l++)
                {
                    for (int j = 0; j < l; j++)
                    {
                        if (tolower(alphakey[j]) == tolower(alphakey[l]))
                        {
                            printf("\nKey must not contain repeated characters. Terminating..\n");
                            return 1;
                        }

                    }
                }
            }
}

void decipherbykey(char ciphertext[500], int key)
{
    char input[500];
    //Iterate over each character of the plaintext
        for (int i = 0, len = strlen(ciphertext); i < len; i++)
        {
            // Incase of uppercase
            if (isupper(ciphertext[i]))
            {
                input[i] = (((ciphertext[i] - ('A' - key)) % 26) + 'A');
            }

            //Incase of lowercase
            else if (islower(ciphertext[i]))
            {
                input[i] = (((ciphertext[i] - ('a' - key)) % 26) + 'a');
            }

            //Incase of other characters
            else
            {
                input[i] = ciphertext[i];
            }
        }
        printf("\nDeciphertext: \n\n%s\n\n", input);
}

//some examples you can try
//key: VCHPRZGJNTLSKFBDQWAXEUYMOI
// plain text: hello, world
//cipher text: jrssb, ybwsp

//plain: hello, world
//key: 13
//cipher: uryyb, jbeyq
