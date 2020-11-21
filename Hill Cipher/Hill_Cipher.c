// Hill cypher limited to 2x2 key
#include<stdio.h>

void HillEncrypt(char msg[],int key[][2],int len){
    int txt[2] , i;
    char cipher[len] , ind = 0;
    for(i=0;i<len;i+=2){
        txt[0] = msg[i] - 'a';
        txt[1] = msg[i+1] - 'a';

        cipher[ind] = txt[0] * key[0][0] + txt[1] * key[0][1];
        cipher[ind] = cipher[ind] % 26;
        ind += 1;
        cipher[ind] = txt[0] * key[1][0] + txt[1] * key[1][1];
        cipher[ind] = cipher[ind] % 26;
        ind += 1;
    }

    // printing cipher text
    for(i = 0 ; i < len ; ++i){
        printf("%c",cipher[i]+'a');
    }
}

void HillDencrypt(char msg[],int KeyInverse[][2],int len){
    int txt[2] , i;
    char plain[len] , ind = 0;
    for(i=0;i<len;i+=2){
        txt[0] = msg[i] - 'a';
        txt[1] = msg[i+1] - 'a';
        plain[ind] = (txt[0] * KeyInverse[0][0] + txt[1] * KeyInverse[0][1])%26;
        ind += 1;
        plain[ind] = (txt[0] * KeyInverse[1][0] + txt[1] * KeyInverse[1][1])%26;
        ind += 1;
    }

    // printing plain text
    for(i = 0 ; i < len ; ++i){
        printf("%c",plain[i]+'a');
    }
}


void main(){
    int key[2][2] = {
        {3,3},
        {2,5}
    };
    int key_inverse[2][2] = {
        {15,17},
        {20,9}
    };

    char message[] = "helpme";
    char cypher[] = "hiatws";
    int len = sizeof(message) / sizeof(message[0]);
    
    HillEncrypt(message,key,len-1);
    printf("\n");
    HillDencrypt(cypher,key_inverse,len-1);


}