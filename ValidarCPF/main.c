#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

main(){
    setlocale(LC_ALL, "Portuguese");
    {char cpf[15]  ,rep[4];
    int icpf[11];//conversao do cpf para int
    int i;
    int soma=0;
    int s=0;
    int cpf1;
    int cpf2;
    int dig1;
    int dig2;
    int cond;//numero de caracteres digitados
    do{
            i=0;      cpf1=0;       dig2=0;
            soma=0;   cpf2=0;       cond=0;
            s=0;      dig1=0;


    printf("Digite seu cpf:");


    gets(cpf);              //salvar pontos e traços.
    cond=strlen(cpf);       //contar numeros de caracteres digitados.


    //converção
        for(i=0;i<cond;i++){
            if(cpf[i]!='.'&& cpf[i]!='-'){
                icpf[s]=cpf[i]-48;     // tudo que nao tiver pontos e traços caira nessa funçao, o primeiro digito caira dentro de icpf
                s++;
            }
        }

     //Calculo do digito 1
     if(icpf[0]!=icpf[1] && icpf[2]!=icpf[3] && icpf[4]!=icpf[5]){          //numeros repetidos são invalidos.


    for(i=0;i<9;i++){ //primeiro digito
        soma+=icpf[i]*(10-i); //soma=soma+icpf  na primeira vez o i vale zero, na segunda o i vale 1...
    }

    cpf1=soma%11;    //resto do calculo

    if(cpf1==0 || cpf1==1){
            dig1=0; //digito 1=0
    }
    else{
        dig1=11-cpf1;// digito 1 igual a 11 menos o resto que é o cpf 1
    }


    //Calculo do segundo digito
    soma=0;     //soma ja foi utilizada no primeiro digito e agr sera usada novamente
    for(i=0;i<10;i++){  //segundo digito
        soma+=icpf[i]*(11-i); //ultimo digito
    }
    cpf2=soma%11;//resto da soma

    if(cpf2==0 || cpf2==1){//se o resto é zero ou 1
        dig2=0;//o digito 2 é igual a zero
    }

    else
    {
        dig2=11-cpf2;//se nao o digito 2 é igual a 11 menos menos cpf2
    }
    if(icpf[9]==dig1 && icpf[10]==dig2){//se icpf, primeiro digito (nono) for igual a dig1 e icp digito 10 for igual a dig2 o cpf é valido
        printf("cpf válido\n");
        printf("deseja continuar digite 'SIM' e para encerrar digite 'NÃO': " );
        gets(rep);
    }

    else
    {
        printf("cpf inválido\n\n");
        printf("deseja continuar digite 'SIM' e para encerrar digite 'NÃO': " );
        gets(rep);
    }
    }

    else
    {
        printf("cpf iválido\n\n");
        printf("deseja continuar digite 'SIM' e para encerrar digite 'NÃO': "  );
        gets(rep);
    }

}while(strcmp(strlwr(rep),"sim")==0);  //converter tudo para minusculo e repetir.
    }

    }

