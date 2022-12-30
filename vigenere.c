#include<string.h>
#include <stdio.h>
//prototype de la fonction de chiffrement.La fonction prend en paramètre le text,la clé,et le text à chiffré.
void vigEncoding(const char * text,const char * key, char* cipherText);

//prototype de la fonction de dechiffrement.
//elle prend en paramètre un text chiddré et une clé.Puis se charge d'effectuer le dechiffrement.
void vigDeconding(const char * ciphertext,const char * key,char *text);
//la fonction principales
int main(){
    char text[100]="« je suis en train de réaliser un compte rendu !";
    char ct[100];
    char plaintext[100];
    vigEncoding(text,"bonjour",ct);
    vigDeconding(ct,"bonjour",plaintext);
    printf("text = %s\n",text);
    printf("ct =%s\n ",ct);
    
    printf("===========================\n");
    printf("plaintext =%s \n",plaintext);
    return 0;
}


//implementation de la fonction d'encodage
void vigEncoding(const char * text,const char * key, char* cipherText){
    unsigned int i=0;
    int size=strlen(key);
    for(i=0;text[i]!='\0';i++){
        //on va verifier si le text courant est compris entre 'a' et 'z',
        if((text[i]>='a'&& text[i]<='z')){
            //calculer le rang du nouveau caractère par lequel on va remplacer le caractère courant de text
            int rang=(text[i]+key[i%size]-2*'a')%26;
            cipherText[i]='a'+rang;
        }else if((text[i]>='A'&& text[i]<='Z')){//on test cette fois ci les majuscules
            //calculer le rang du nouveau caractère par lequel on va remplacer le caractère courant de text
            int rang=(text[i]+key[i%size]-'a'-'A')%26;//-'a' celui de la clé et -A celui du text
            cipherText[i]='A'+rang;
        }else{
            cipherText[i]=text[i];
        }
    }
    //quand on aura terminer de faire tout ça on ajourte le caractère chaine de fin de caractère à cipher text
    cipherText[i]='\0';
}

void vigDeconding(const char * ciphertext,const char * key,char *text){
   //on va juste calculer l'inverse de la clé ensuite on appelle la fonction vigénèreEncoding qu'on a coder plus haut 
   unsigned int i;
   unsigned int size=strlen(key);
   //l'inverse de la clé,c'est la chaine de caractère qui va contenir l'inverse de la clé
   char keyTemp[size+1];//on lui stocke tous les caractères de la clé + 1 pour stocker le caractère de fin de chaine
   //on va à present construire l'inverse de la clé
   for(i=0;key[i]!=0;i++){//on parcours la clé
    //on calcule premièrement le rang
    int rang=(26-(key[i]-'a'))%26;
    keyTemp[i]=rang+'a';
   }
   keyTemp[i]='\0'; //on stocke le caractère de fin de ligne pour marque la fin
    //ensuite on appelle la fonction vigénèreEcoding ,on lui donne comme paramètre cipherText,keyTemp,et text
    //elle va sec charger de nous dechiffrer cipherText avec l'inverse de la clé
    vigEncoding(ciphertext,keyTemp,text);
    //l'instruction en haut revient tout simplement à chiffre cipherText une deuxième fois avec l'inverse de la clé puis le resultat sera stocké dans text.
}
