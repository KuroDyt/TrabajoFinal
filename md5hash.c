#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void md5hash(unsigned char pass[64],unsigned char key[16], unsigned int *res);

int minum(float a);

float absolute(float num);

int main(){
    unsigned char password[64], keyc[16] = {'k','l','g','s','f','c','g','q','j','g','r','c','x','d','k','q'}, keya[16];
    unsigned int response[4], test[4] = {1,2,3,4};
    void *datas[8];
    int j = 0;
    char c, username[10];/*
    printf("test of hash\n");
    read(0,password,64);
    md5hash(password, keyc, &response[0]);*/
    
    FILE *fb = fopen("passwd.db", "w");
    
    for(int i = 1; ;i++){
        bzero(password, 64);
        printf("Entrada id %d\n", i);
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);
        md5hash(password, keyc, &response[0]);
        putc('|', fb);
        putc((i+48), fb);
        putc('|', fb);
        for(j = 0; j < 10; j++){
            if(username[j] == '\n')break;
        }
        fwrite(username, sizeof(char), j, fb);
        putc('|', fb);
        fwrite(response, sizeof(unsigned int), 4, fb);
        for(int p = 0; p < 4; p++)printf("%x\n", response[p]);
        putc('\n', fb);
        printf("Desea agregar otra entrada?Y/n");
        getchar();
        scanf("%c",&c);
        if((c == 'n')||(c == 'N')){
            break;
        }
    }
    fclose(fb);
    /*
    FILE *fp = fopen("test.txt", "w+");
    if(!fp){
        printf("Error\n");
        exit(0);
    }
    fwrite(keyc, sizeof(unsigned char), 16, fp);
    fprintf(fp, "|");
    fwrite(response, sizeof(unsigned int), 4, fp);
    printf("Test write\n");
    fclose(fp);
    FILE *fa = fopen("test.txt", "r+");
    if(!fa){
        printf("Error\n");
        exit(0);
    }
    for(int i = 0; i < 20; i++){
        c = fgetc(fa);
        if(c == '|') break;
        else keya[i] = c;
    }
    fread(test, sizeof(unsigned int), 4, fa);
    fclose(fa);
    printf("Test read\n");
    for(int i = 0; i < 4; i++){
        if(response[i] != test[i]) printf("Error on byte %d\n", i);
        else printf("%x = %x\n", response[i], test[i]);
    }
    datas[0] = &keyc;
    datas[1] = &keya;
    printf("%s = %s", datas[0], datas[1]);
    unsigned char a[64], c[8], d[8];
    long int e; 
    int i, b, z;
    printf ("Before bzero\n");
    bzero(&a, 64);
    printf("Before read\n");
    read(0, &a, 64);
    printf("Before loop\n");
    for(i = 0; i < sizeof(a); i++){
        if(a[i] == 10)break;
        printf("%d %c %x\n", a[i], a[i], a[i]);
    }
    for(int x = 0; x < ((64-i)-8) ; x++){ 
        a[i+x] = (unsigned char)(rand() % 256);
        printf("%d %c %x\n", a[i+x], a[i+x], a[i+x]);
    }
    for(int x = 0; x < 8; x++){
        printf("%d %c %x\n", a[(i+((64-i)-8))+x], a[(i+((64-i)-8))+x], a[(i+((64-i)-8))+x]);
    }
    printf("%s \n %d %d\n", a, i, (64 - i));
    printf("\n\n");
    i = 0;
    i =  (a[0] << 24) | (a[1] << 16) | (a[2] << 8) | a[3];
    b =  (a[4] << 24) | (a[5] << 16) | (a[6] << 8) | a[7];
    z = i^b;
    printf("%x %x %x %lx\n",i,b,z,e);
    printf("%ld\n", sizeof(long int));
    memcpy(&c, &z, sizeof(int));
    for (int x = 0; x < 4; x++)
    {
        d[x] = c[3-x];
    }
    for (int x = 0; x < 8; x++)
    {
        printf("%d %x\n",d[x], d[x]);
    }
    for (int x = 0; x < 4; x++)
    {
        printf("%d %x\n",c[x], c[x]);
    }
    */
    exit(0);
}


void md5hash(unsigned char pass[64], unsigned char key[16], unsigned int *res){
    unsigned int bits[16], keys[4], trans = 0, f = 0,g = 0,i = 0, x = 0, k[64], s[64] = {7,12,17,22,7,12,17,22,7,12,17,22,5,9,14,20,5,9,14,20,5,9,14,20,4,11,16,23,4,11,16,23,4,11,16,23,6,10,15,21,6,10,15,21,6,10,15,21};
    for(i = 0; i < 64; i++){
        if(pass[i] == 10)break;
    }
    for(x = 0; x < (64-i) ; x++){ 
        pass[i+x+1] = 0;
    }
    x = 0;
    for(i = 0; i < 64; i = i+4){
        bits[x] = (pass[i] << 24) | (pass[i+1] << 16) | (pass[i+2]  << 8)  |  pass[i+3];
        x = x + 1;
    }
    for(i = 0, x = 0; i < 16; i = i + 4){
        keys[x] = (key[i] << 24) | (key[i+1] << 16) | (key[i+2]  << 8)  |  key[i+3];
        x = x + 1;
    }
    
    for(i = 0; i < 64; i++){
        k[i] = (unsigned int)minum(232 * absolute(sin(i+1)));
    }
    
    for(i = 0; i < 64; i++){
        if((i >= 0)&&(i <= 15)){
            f = (keys[1] & keys[2]) | ((~keys[1]) & keys[3]);
            g = i;
        }
        else if(i <= 31){
            f = (keys[3] & keys[1]) | (keys[2] & (~keys[3]));
            g = ((5*i)+1) % 16;
        }
        else if(i <= 47){
            f = keys[1] ^ keys[2] ^ keys[3];
            g = ((3*i)+5) % 16;
         }
        else if(i <= 63){
            f = keys[2] ^ (keys[1] | (~keys[3]));
            g = (7*i) % 16;
        }
        trans =  keys[3];
        keys[3] = keys[2];
        keys[2] = keys[1];
        keys[1] = keys[1] + ((keys[0] + f + k[i] + bits[g]) << s[i]);
        keys[0] = trans;
    }
    memcpy(res, &keys, sizeof(keys));
}

int minum(float a){
    int b;
    if(a < 0){
        b = ((int)a)-1;
    }
    else{
        b = (int)a;
    }
    return(b);
}

float absolute(float num){
    float b;
    if(num < 0){
        b = num * (-1);
    }
    else{
        b = num;
    }
    return(b);
}
