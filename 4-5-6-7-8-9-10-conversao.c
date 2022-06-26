 
/*
Metodos e functions: cparaf(), fparac(), 
*/
#include<stdio.h>

//Temperature
float cparaf(float c){
    int f = (9*c+160)/5;
    return f;
}
float fparac(float f){
    float c=(f-32)*5/9;
    return c;
}
//Lenght
float polparacent(float pol){
    float cent=pol*2.54;
    return cent;
}
float polparam(float pol){
    float m=pol*0.0254;
    return m;
}
float pesparacent(float pes){
    float cent=pes*30.48;
    return cent;
}
float pesparam(float pes){
    float m=pes*0.3048;
    return m;
}
float mparapol(float m){
    float pol=m*39.3700787402;
    return pol;
}
float mparapes(float m){
    float pes= m*3.280839895;
    return pes;
}
float centparapol(float cent){
    float pol=cent/2.54;
    return pol;
}
float centparapes(float cent){
    float pes=cent*0.0328084;
    return pes;
}
//Weight
float libparagram(float lib){
    float gram= lib*453.59237;
    return gram;
} 
float libparakgram(float lib){
    float kgram=lib*0.45359237;
    return kgram;
}
float oncaparagram(float onca){
    float gram=onca*28.349523125;
    return gram;
}
float oncaparakgram(float onca){
    float kgram=onca*0.0283495231;
    return kgram;
}
float gramparalib(float gram){
    float lib = gram*0.0022046226;
    return lib;
}
float kgramparalib(float kgram){
    float lib = kgram*2.2046226218;
    return lib;
}
float gramparaonca(float gram){
    float onca=gram*0.0352739619;
    return onca;
}
float kgramparaonca(float kgram){
    float onca=kgram*35.2739619496;
    return onca;
}
//Volume
float galparalitro(float gal){
    float litro=gal*3.785411784;
    return litro;
}
float galparaml(float gal){
    float ml=gal*3785.411784;
    return ml;
}
float cupsparalitro(float cups){
    float litro=cups*0.2365882365;
    return litro;
}
float cupsparaml(float cups){
    float ml=cups*236.5882365;
    return ml;
}
float litroparagal(float litro){
    float gal=litro*0.2641720524;
    return gal;
}
float litroparacups(float litro){
    float cups=litro*4.2267528377;
    return cups;
}
float mlparagal(float ml){
    float gal=ml*0.0002641721;
    return gal;
}
float mlparacups(float ml){
    float cups=ml*0.0042267528;
    return cups;
}
//---------------------------------------------------------------------------------------------------------------------------
void temperatura(){
    char op[]="  ";
    float unidade;
    do{
    printf("Escolhar as opcoes:\n [1]Grau Celsius para Fahrenheit\n [2]Fahrenheit para Grau Celsius\n [0]Sair\n>>");
    scanf("%s",op);
    if(op[0]=='1'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",cparaf(unidade));
    }else if(op[0]=='2'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",fparac(unidade));
    } 
    }while(op[0]!='0');
    op[0]='m';

}

void distancia(){
    char op[]="  ";
    float unidade;
    do{
    printf("Escolhar as opcoes:\n [1]Polegadas para Centimetros\n [2]Polegadas para Metros\n [3]Pes para Centimetros\n [4]Pes para Metros \n [5]Metros para Polegadas\n [6]Metros para Pes\n [7]Centimetros para Polegadas\n [8]Centimetros para Pes\n [0]Sair\n>>");
    scanf("%s",op);
    if(op[0]=='1'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",polparacent(unidade));
    }
    else if(op[0]=='2'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",polparam(unidade));
    } 
    else if(op[0]=='3'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",pesparacent(unidade));
    } 
    else if(op[0]=='4'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",pesparam(unidade));
    } 
    else if(op[0]=='5'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",mparapol(unidade));
    } 
    else if(op[0]=='6'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",mparapes(unidade));
    } 
    else if(op[0]=='7'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",centparapol(unidade));
    } 
    else if(op[0]=='8'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",centparapes(unidade));
    } 

    }while(op[0]!='0');
    op[0]='m';

}

void peso(){
    char op[]="  ";
    float unidade;
    do{
    printf("Escolhar as opcoes:\n [1]Libras para Gramas\n [2]Libras para Quilogramas\n [3]Oncas para Gramas\n [4]Oncas para Quilogramas \n [5]Gramas para Libras\n [6]Gramas para Oncas\n [7]Quilogramas para Libras\n [8]Quilogramas para Oncas\n [0]Sair\n>>");
    scanf("%s",op);
    if(op[0]=='1'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",libparagram(unidade));
    }
    else if(op[0]=='2'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",libparakgram(unidade));
    } 
    else if(op[0]=='3'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",oncaparagram(unidade));
    } 
    else if(op[0]=='4'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",oncaparakgram(unidade));
    } 
    else if(op[0]=='5'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",gramparalib(unidade));
    } 
    else if(op[0]=='6'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",gramparaonca(unidade));
    } 
    else if(op[0]=='7'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",kgramparalib(unidade));
    } 
    else if(op[0]=='8'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",kgramparaonca(unidade));
    } 

    }while(op[0]!='0');
    op[0]='m';

}

void volume(){
    char op[]="  ";
    float unidade;
    do{
    printf("Escolhar as opcoes:\n [1]Galao para Litro\n [2]Galao para Mililitros\n [3]Xicaras para Litros\n [4]Xicaras para Mililitros \n [5]Litros para Galao\n [6]Litros para Xicaras\n [7]Mililitros para Galao\n [8]Mililitros para Xicaras\n [0]Sair\n>>");
    scanf("%s",op);
    if(op[0]=='1'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",galparalitro(unidade));
    }
    else if(op[0]=='2'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",galparaml(unidade));
    } 
    else if(op[0]=='3'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",cupsparalitro(unidade));
    } 
    else if(op[0]=='4'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",cupsparaml(unidade));
    } 
    else if(op[0]=='5'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",litroparagal(unidade));
    } 
    else if(op[0]=='6'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",litroparacups(unidade));
    } 
    else if(op[0]=='7'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",mlparagal(unidade));
    } 
    else if(op[0]=='8'){
        printf("\nDigite o valor: ");
        scanf("%f",&unidade);
        printf("Resultado: %f\n\n",mlparacups(unidade));
    } 

    }while(op[0]!='0');
    op[0]='m';

}
//---------------------------------------------------------------------------------------------------------------------------



int main(){
char op[]="  ";
do{
        printf("Escolha um tipo de conversao:\n [1]Temperatura\n [2]Distancias\n [3]Peso\n [4]Volume\n [0]Sair\n>>");
        scanf("%s",op);
        if (op[0]=='1'){
            temperatura();
        }else if(op[0]=='2'){
            distancia();
        }else if(op[0]=='3'){
            peso();
        }else if(op[0]=='4'){
            volume();
        }
}while(op[0]!='0');
    return 0 ;

}

