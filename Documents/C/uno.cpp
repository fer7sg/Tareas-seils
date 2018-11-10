#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>
int main(){
    char abc[25]={'A','B','C','D','E','F','G','H','I','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},letras[5];
    char  matriz[6][6];
    int i, aux = 0,j;
    float o[5],auxi = 0.0;
    for(i=1;i<6;i++){
      for(j=1;j<6;j++){
         matriz[i][j]=abc[aux];
         aux++;
      }
    }
    scanf("%s",letras);
    
    
    for(i=0;i<5;i++){ //para pasar a mayusclas las letras
       letras[i] = toupper(letras[i]);
       if(letras[i]=='\xA4')
        letras[i]='\xA5';
   }      
    
    for(i=0;i<5;i++){//para dar posiciones a las letras
      if(letras[i]=='J')
            o[i]=8.5;
      else if(letras[i]=='\xA5')
            o[i]=12.5;
      else
       for(j=0;j<25;j++)
         if(abc[j]==letras[i])
            o[i]=j;
    }
          
    for(i = 0; i<4; i++){ //se ordena o en orden numerico
        if(o[i] > o[i+1]){
           auxi = o[i+1];
           o[i+1]=o[i];
           o[i]=auxi;
           i=-1;
        }
    }
    int t;
    for(i=0;i<6;i++){ //se llena la matriz en orden alfabetico
       if(i==0){
          for(j=1;j<6;j++){
              if(o[j-1]==8.5)
                 matriz[i][j]='J';
              else if(o[j-1]==12.5)
                 matriz[i][j]='\xA5';
              else {
                   t = (int)o[j-1];
                 matriz[i][j]=abc[t];
              }
          }
       }
       else{
          if(o[i-1]==8.5)
               matriz[i][0]='J';
          else if(o[i-1]==12.5)
               matriz[i][0]='\xA5';
          else {
              t = (int)o[i-1];
              matriz[i][0]=abc[t];
          }
       }
    }
    
    for(i=0;i<6;i++){ //imprime matriz
      for(j=0;j<6;j++){
         printf("%c",matriz[i][j]);
      }
      printf("\n");
    }
   ////            CODIFICAR
    int p=0,b,p1,p2;
    char palabra[100], res[100],s;
    scanf(" %[^\n]",&palabra);
    printf("\n%s",palabra);
    for(i=0;i<strlen(palabra);i++){ //compara la palabra en mayusculas
        if(palabra[i]=='J'||palabra[i]=='j')
              palabra[i] = 'I';
        else if (palabra[i] == '\xA4'||palabra[i] == '\xA5')
             palabra[i] = 'N';
        else 
             palabra[i] = toupper(palabra[i]);
    }

    
    for(b=0;b<strlen(palabra);b++){ //codifica
     if(palabra[b]!='\xFF'){
       for(i=1;i<6;i++){
          for(j=1;j<6;j++){
            if(palabra[b]==matriz[i][j]){
              res[p]=matriz[i][0];
              res[p+1]=matriz[0][j];
              p=p+2;
            }
          }
        }
      }
    }
    printf("\n%s\n",res);
    //DECODIFICA
    char respu[100];
    int q=0;
    scanf("%s",palabra);
    for(b=0;b<strlen(palabra);b=b+2){
       for(i=0;i<6;i++){
          if(i==0){
             for(j=1;j<6;j++){
                if(matriz[0][j]==palabra[b+1]){
                   p1=j;
                }
             }
          }
          else{
             if(matriz[i][0]==palabra[b]){
                 p2=i;
             }
          }
       }
       respu[q]=matriz[p2][p1];
       q++;
    }
    printf("\%s",respu);
    getchar();
    getchar();
    return 0;
}
