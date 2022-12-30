#include<stdio.h>
//prototype de la fonction chiffrement de Cesar avec comme paramètre respective le message à chiffrer,la clé et le message chiffré
void cesarEncoding(const char* message,short key,char *cipherText);

//prototype de la fonction de dechiffrement de Cesar avec comme paramètre respective 
void cesarDecoding(const char* cipherText,short key,char *plaintext);

int main(){
    char msg[100]=" je suis en train de realiser un compte rendu";
    char cpt[1000];
    char ppt[100];
    //il y a en tout 25 clé dans le chiffrement de cesar
    cesarEncoding(msg,12,cpt);
    printf("cpt =%s \n",cpt);
    printf("===============================\n");
    cesarDecoding(cpt,12,ppt);
    printf("ppt = %s \n ",ppt);
    return 0;
}

//ici commence l'implementation de la fonction
void cesarEncoding(const char* message,short key,char *cipherText){
    unsigned int i=0;//pour parcourir la chaine de caractère message
    short rang;//pour calculer le rang d'une lettre dans l'alphabet
    //cette boucle parcoure la chaine de caractère
    while(message[i]!='\0'){
        //on teste si le caractère courant est miniscule
        if(message[i]>='a'&&message[i]<='z'){
            //si cette condition est verifiée,alors on calcul son rang dans l'alphabet
            rang=message[i]-'a';//on obtient le rang de cet caractère dans l'alphabet
            rang=(rang+key)%26;//ensuite le nouveau rang.Le MODULO 26 pour recommencer à partir de a quand on arrive à z
            //cette instruction permet de s'assurer que le rang ne soit jamais inferieur à zeros.
            if(rang<=0){
                rang+=26;
            }
            //ensuite on ajoute le resultat dans cipherText
            cipherText[i]='a'+rang;
        }else if(message[i]>='A'&&message[i]<='Z'){
            //si cette condition est verifiée,alors on calcul son rang dans l'alphabet
            rang=message[i]-'A';//on obtient le rang de cet caractère dans l'alphabet
            rang=(rang+key)%26;//ensuite le nouveau rang.Le MODULO 26 pour recommencer à partir de a quand on arrive à z
            //cette instruction permet de s'assurer que le rang ne soit jamais inferieur à zeros.
            if(rang<=0){
                rang+=26;
            }
            //ensuite on ajoute le resultat dans cipherText
            cipherText[i]='a'+rang;
        }else{
            //si le programme arrive jusqu'ici,ça veut dire que le caractère n'est ni une lettre majuscule,ni une lettre minuscule
            cipherText[i]=message[i];
        }

        i++;//pour passer au caractère suivant.
    }
    //après la boucle while,on ajoute un caractère de fin de chaine à notre text ainsi chiffré
    cipherText[i]='\0';
}

//implementation du corps de la fonction de dechiffrement
void cesarDecoding(const char *cipherText, short key, char *plaintext){
    //quand on chiffre,on ajoute la clé et quand on dechiffre,on fait l'operation invese le moins
    //nous allons donc appeler la fonction de chiffrement avec l'invese de la clé
    cesarEncoding(cipherText,-key,plaintext);
}
