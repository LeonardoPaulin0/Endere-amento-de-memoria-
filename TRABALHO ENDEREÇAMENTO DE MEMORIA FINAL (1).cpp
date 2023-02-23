/*
    CONTAS PARA TESTAR O CODIGO 
    
    N = 256             N = 2097152            N = 131072           N = 128           N = 1024 
    M = 64              M = 2048               M = 1024             M = 128           M = 128
    E = 8               E = 21                 E = 17               E = 7             E = 10
    T = 2^14 = 2 KB     T = 2^32 = 512 MB      T = 2^27 = 16 MB     T = 2^14 = 2 KB   T = 2^17 = 16 KB
    
     */

#include <iostream>
#include <math.h>

using namespace std;

 
int main(){
	
	int i=2, i2=0, expoenteN=0, expoenteM=0, expoenteT=0, quant=0, M, E=0, N=0;
	string simbolo, valor1, valor2,  tamanho, operacao;
	double T=0;
      
      do{
     i=2, i2=0, expoenteN=0, expoenteM=0, expoenteT=0, quant=0;
     double T=0, M, E=0, N=0;
     
        // PEDINDO PARA O USUARIO INFOMAR QUAIS SERAM AS ENTRADAS 
			cout<<"\n -----------CALCULADORA DE ENDERECAMENTOS DE MEMORIA ----------\n ***Por favor insiras os valores corretos e seguindos os exemplos*** "<<endl;
			cout<<" Digite as iniciais (em maiusculas) dos valores que seram fornecidos\n sera necessario apenas 2 valores   \n\n M - N - E - T \n  Exem: T E "<<endl;
	        cin >>valor1>>valor2;
	        
	    // VERIFICANDO SE O USUARIO INSERIU OS VALORES DE N e E, QUE NAO CONSEGUIMOS CALCULAR PQ AS BASES SAO IGUAIS
	    if(valor1 == "N" and valor2 == "E" or valor2 == "E" and valor1 == "N")
	    	cout<<"Nao eh possivel cacular "<<endl;
	    	exit;
	    
	    // CALCULO SE O USUARIO INSERIR OS VALORES DE M e N 
	    if(valor1 == "M" and valor2 == "N" or valor2 == "M" and valor1 == "N"){
	
	cout<<"Digite o valor de M "<<endl;
	cin>>M;
	cout<<"Digite o valor de N "<<endl;
	cin>>N;
	//CALCULANDO O EXPOENTE DO VALOR DE M
	while (i <= M){
	i *= 2;
	expoenteM++;
	}
	i = 2;
	//CALCULANDO O EXPOENTE DO VALOR DE N
	while (i <= N){
	i *= 2;
	expoenteN++;
	}
	// RESULTADO DO VALOR DE E
       E = expoenteN;
       
    // SOMANDO O EXPOENTE DE M e N PARA SABER O EXPOENTE DE T 
    expoenteT = expoenteM + expoenteN;
    
    //CALCULANDO O VALOR BRUTO DE T
	 T = pow(2,expoenteT);
	
	// CALCULANDO QUAL VAI SER A SUA BASE, KB OU MB OU GB ...
	 if (T > 1024)
	    T /= 8;
	while(T > 1024){
         T /= 1024;
         quant = quant + 1;
     } 
       if (quant == 1)
          simbolo = "kB";
       if(quant == 2)
          simbolo = "MB";
       if(quant == 3)
          simbolo = "GB";
       if(quant == 4)
          simbolo = "TB";
}
      // CALCULO SE O USUARIO INSERIR OS VALORES DE M e T  
     if(valor1 == "T" and valor2 == "M" or valor2 == "T" and valor1 == "M"){
	 
	 // USUARIO DEVERA INSERIR O VALOR DE T E SUA BASE
 	       cout<<"Digite os valores de T e seu simbolo. Exem: 8 GB "<<endl;
		   cin>>T>>simbolo;
		   cout<<"Digite o valor de M "<<endl;
	       cin>>M;
			
			// CALCLANDO O EXPOENTE DOS VALORES T E M
			while(i <= M){
			i *= 2;
			expoenteM++;
			}
		    i=2;
			while(i <= T){
			i *= 2;
			expoenteT++;
			}
			
	        // CALCULANDO O EXPOENTE DA BASE QUE FOI INSERIDA PELO USUARIO E JA SOMANDO 3 DOS 2^3. QUANDO DIVIDIMOS POR 8.
	     	if (simbolo == "KB")
			   expoenteT += 13;
			if (simbolo == "MB")
			   expoenteT += 23;
		    if (simbolo == "GB")
		       expoenteT += 33;
		    if (simbolo == "TB")
		       expoenteT += 43;
		       
		       // SUBTRAINDO OS EXPOENTES DOS VALORES FORNECIDOS PARA SABER O VALOR DE E
		    E = expoenteT - expoenteM;
		    
		    //CALCULANDO O VALOR DE N 
		    N = pow(2,E);
	    
}
	   // CALCULO SE O USUARIO INSERIR OS VALORES DE T e E 
	 if(valor1 == "T" and valor2 == "E" or valor2 == "T" and valor1 == "E"){
		  
		   // USUARIO DEVERA INSERIR O VALOR DE T E SUA BASE
		   cout<<"Digite os valores de T e seu simbolo exem '8 GB' ou '2 KB'.... "<<endl;
		   cin>>T>>simbolo;
		   cout<<"Digite o valor de E "<<endl;
		   cin>>E;
		   
		   //CALCULANDO O EXPOENTE DE T 
		    while(i <= T){
			i *= 2;
			expoenteT++;
			}
	     // CALCULANDO O EXPOENTE DA BASE DO VALOR DE T 
	     	if (simbolo == "KB")
			   expoenteT += 13;
			if (simbolo == "MB")
			   expoenteT += 23;
		    if (simbolo == "GB")
		       expoenteT += 33;
		    if (simbolo == "TB")
		       expoenteT += 43;
		       
		    // SUBTRAINDO OS EXPOENTES DOS VALORES FORNECIDOS PARA SABER O EXPOENTE DE M
		    expoenteM = expoenteT - E;
		
		    
		    //MULTIPLICANDO 2 ELEVADO A 'E' PARA SABER O VALOR DE N
		    N = pow(2,E);
		    
		    //MULTIPLICANDO 2 ELEVADO AO EXPOENTE DE M PARA SABER O VALOR DE M
		    M = pow(2, expoenteM);
		    
	}
	  // CÁLCULO SE O USUARIO INSERIR OS VALORES DE T E N 
	   if(valor1 == "T" and valor2 == "N" or valor2 == "T" and valor1 == "N"){
		   cout<<"Digite os valores de T e seu simbolo exem 8 GB "<<endl;
		   cin>>T>>simbolo;
		   cout<<"Digite o valor de N em bits "<<endl;
	       cin>>N;
		
		  //CALCULANDO OS EXPOENTES DE T
	       while (i <= T){
			i *= 2;
			expoenteT++;
			}
            i = 2;
        //CALCULANDO O EXPOENTE DE N
			 while (i <= N){
			i *= 2;
			expoenteN++;
			}
			
		//CALCULANDO O EXPOENTE DA BASE DE T QUE O USUARIO INSERIU
	    	if (simbolo == "KB")
			   expoenteT += 13;
			if (simbolo == "MB")
			   expoenteT += 23;
		    if (simbolo == "GB")
		       expoenteT += 33;
		    if (simbolo == "TB")
		       expoenteT += 43;
		    // DEFININDO O RESULTADO DE E 
	     	E = expoenteN;
		
		// SUBTRAINDO OS EXPOENTES DE T E N PARA SABER O EXPOENTE DE M
		expoenteM = expoenteT - expoenteN;
		
		//CALCULANDO O VALOR DE M
		M = pow(2, expoenteM);

}
   //   SE O USUARIO INSERIR OS VALORES DE M e E FAÇA
	if(valor1 == "E" and valor2 == "M" or valor2 == "E" and valor1 == "M"){
 	
	 		cout<<"Digite o valor de M "<<endl;
	     	cin>>M;
 		    cout<<"Digite o valor de E "<<endl;
		    cin>>E;
		
		// CALCULANDO O EXPOENTE DE M
 	      while(i <= M){
			i *= 2;
			expoenteM++;
			}
		    // SOMANDO O EXPOENTE DE M COM O E PARA SABER O EXPOENTE DE T 
		     expoenteT = expoenteM + E;
		     
		     //CALCULANDO O VALOR EM BITS DE T
 		     T = pow(2, expoenteT);
 		     
 		     //DIVIDINDO O VALOR EM BITS DE T
 		     T /= 8;
 		     // DIVIDINDO POR 1024 E CONTANDO QUANTAS VESES VAI DIVIDIR
 		     while (T >= 1024){
                 T /= 1024;
                 quant++;
		    }
		    //VALOR DA QUANTIDADE DE VESES QUE FOR DIVIDIR POR 1024, SERÁ USADO PARA DESCOBRIR A BASE DO VALOR DE T
   		   if (quant == 1)
	          simbolo = "kB";
	       if(quant == 2)
	          simbolo = "MB";
	       if(quant == 3)
	          simbolo = "GB";
	       if(quant == 4)
	          simbolo = "TB";
 	        // CALCULANDO O VALOR DE N 
 	         N = pow(2,E);
    }

     cout<<"\n"" N = "<<N<<endl;
     cout<<" M = "<<M<<endl;
     cout<<" e = "<<E<<endl;
     cout<<" T = 2^"<<expoenteT<<" = "<<T<<" "<<simbolo<<endl;
     
     cout<<"Relizar outra operação?? [S]im ou [N]ao"<<endl;
     cin>>operacao;
     
      //ESTRUTURA DE REPETIÇAO PARA QUE O USUARIO POSSA REALIZAR OUTRA OPERAÇÃO EM SEGUIDA
      }while (operacao != "N");
return 0;

}
