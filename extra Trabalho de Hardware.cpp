#include <iostream>
#include <math.h>

using namespace std;

  double N, M, bits=0;
  int i, decimal1=1,decimal2=1, numBits=1,numN=2, numM=2,soma=0,e=0;  
  int quant=0;
  string tamanho;
  
int main()
{
     cout<<" Digite a quantidade maxima de celulas[N]"<<endl;
     cin >> N;
     
     cout<<"Digite a quantidade de Bits por celulas[M]"<<endl;
     cin >> M;
     
            //calculando os expoentes dos valores fornecidos pelo usuario 
     while(numN < N ){
     numN *= 2;
     decimal1++;
     }
     while(numM < M){
       numM *= 2;
       decimal2++;
     } 
     
     //calculando  o Tamanho 
     e = decimal1;
     soma = decimal1 + decimal2;
     bits = pow(2,soma);
     
     bits = bits / 8;
     
     //verificando qual vai ser o tamanho e dividindo por 1024
     while(bits > 1024){
         bits = bits / 1024;
         quant++;
     }
     
       if (quant == 1)
           tamanho = "K";
       if(quant == 2)
          tamanho = "M";
       if(quant == 3)
          tamanho = "G";
       if(quant == 4)
          tamanho = "T";

     cout<<"\n"" N = "<<N<<endl;
     cout<<" M = "<<M<<endl;
     cout<<" e = "<<e<<endl;
     cout<<" T = 2^"<<soma<<" = "<<bits<<" "<<tamanho<<"B"<<endl;
     
     
     
     
    system("PAUSE");
    return 0;
}
