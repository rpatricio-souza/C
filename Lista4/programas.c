#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "programas.h"
const int anoAtual=2019;

void programa01(){
    float a, b;
    printf("1o numero: ");
    scanf("%f", &a);
    printf("2o numero: ");
    scanf("%f", &b);

    if(a>b)
        printf("Maior valor = %.2f", a);
    else
        printf("Maior valor = %.2f", b);
}

void programa02(){
    double num;
    printf("Digite um numero: ");
    scanf("%lf", &num);

    if(num>0)
        printf("\nRaiz quadrada de %.2lf = %.2lf\n", num, sqrt(num));
    else
        printf("\nNumero Invalido!\n");
}

void programa03(){
    double num;
    printf("Digite um numero real: ");
    scanf("%lf", &num);

    if(num>0)
        printf("\nRaiz quadrada de %.2lf = %.2lf", num, sqrt(num));
    else
        printf("\n%.2lf ao quadrado = %.2lf\n", num, num*num);
}

void programa04(){
    double num;
    printf("Digite um numero: ");
    scanf("%lf", &num);

    if(num>0){
        printf("\n%.2lf ao quadrado = %.2lf\n", num, num*num);
        printf("Raiz quadrada de %.2lf = %.2lf\n", num, sqrt(num));
    }
}

void programa05(){
    int num;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    if(num%2==0)
        printf("\n%d e par!\n", num);
    else
        printf("\n%d e impar!\n", num);
}

void programa06(){
    int a, b;
    printf("1o numero inteiro: ");
    scanf("%d", &a);
    printf("2o numero inteiro: ");
    scanf("%d", &b);

    if(a>b)
        printf("Maior valor = %d\n%d - %d = %d\n", a, a, b, a-b);
    else
        printf("Maior valor = %d\n%d - %d = %d\n", b, b, a, b-a);
}

void programa07(){
    float a, b;
    printf("1o numero: ");
    scanf("%f", &a);
    printf("2o numero: ");
    scanf("%f", &b);

    if(a>b)
        printf("\nMaior valor = %.2f\n", a);
    else if(b>a)
        printf("\nMaior valor = %.2f\n", b);
    else
        printf("\nNumeros iguais\n");
}

void programa08(){
    float nota, media=0;
    int i;
    printf("Digite 2 notas para um aluno:");
    for(i=1;i<3;i++){
        printf("\n%da nota: ", i);
        scanf("%f", &nota);
        if(nota<0.0 || nota>10.0){
            printf("\nValor Invalido!\n");
            break;
        }
        media+=nota;
    }
    if(i==3)
        printf("\nMedia do aluno = %.2f\n", media/(i-1));
}

void programa09(){
    float salario, prestacao;
    printf("Digite seu salario: R$");
    scanf("%f", &salario);
    printf("\nDigite o valor da prestacao do emprestimo: R$");
    scanf("%f", &prestacao);
    if(salario*0.2<prestacao)
        printf("\nEmprestimo nao concedido!\n");
    else
        printf("\nEmprestimo concedido!\n");
}

void programa10(){
    float h;
    char s;
    printf("Digite sua altura: ");
    scanf("%f", &h);
    printf("Digite seu sexo: ");
    s = getch();
    if(s!='F' && s!='f' && s!='M' && s!='m')
        printf("\nValor Invalido!\n");
    else if(s=='F' || s=='f')
        printf("\nPeso ideal = %.2fkg\n", (62.1*h)-44.7);
    else
        printf("\nPeso ideal = %.2fkg\n", (72.7*h)-58);
}

//-48
void programa11(){
    int num, soma=0;
    printf("Digite um numero inteiro maior que zero: ");
    scanf("%d", &num);

    if(num>0){
        if(num>=1000){
            soma+=num/1000;
            num=num%1000;
        }
        if(num>=100){
            soma+=num/100;
            num=num%100;
        }
        if(num>=10){
            soma+=num/10;
            num=num%10;
        }
        if(num>0){
            soma+=num;
        }
        printf("\nSoma dos termos = %d\n", soma);
    }
    else
        printf("\nNumero Invalido\n");
}

void programa12(){
    int num;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    if(num>0)
        printf("\nLogaritmo de %d = %lf\n", num, log10f(num));
    else
        printf("\nNumero Invalido!\n");
}

void programa13(){
    float media=0, nota;
    int i;
    printf("Digite 3 notas para um aluno:\n");
    for(i=1;i<4;i++){
        printf("%da nota: ", i);
        scanf("%f", &nota);
        if(i==3)
            media+=2*nota;
        else
            media+=nota;
    }
    media=media/(1+1+2);
    printf("\nMedia ponderada = %.2f\n", media);
    if(media>6.0)
        printf("APROVADO!\n");
    else
        printf("REPROVADO!\n");
}

void programa14(){
    float nota, media=0;
    int i;
    printf("Digite 3 notas para um aluno:\n");
    for(i=1;i<4;i++){
        printf("%da nota: ", i);
        scanf("%f", &nota);
        if(nota<0.0 || nota>10.0){
            printf("\nValor Invalido!\n");
            break;
        }
        if(i==1)
            media+=nota*2;
        if(i==2)
            media+=nota*3;
        if(i==3)
            media+=nota*5;
    }
    if(i==4){
        media=media/(2+3+5);
        printf("\nMedia do aluno = %.2f\n", media);

        if(media>=5.0)
            printf("APROVADO!\n");
        else if(media>=3)
            printf("RECUPERACAO!\n");
        else
            printf("REPROVADO!\n");
    }
}

void programa15(){
    int dia;
    printf("Digite um numero entre 1 e 7: ");
    scanf("%d", &dia);
    switch(dia){
        case 1:
            printf("\nDomingo.\n");
            break;
        case 2:
            printf("\Segunda-Feira.\n");
            break;
        case 3:
            printf("\Terca-Feira.\n");
            break;
        case 4:
            printf("\Quarta-Feira.\n");
            break;
        case 5:
            printf("\nQuinta-Feira.\n");
            break;
        case 6:
            printf("\nSexta-Feira.\n");
            break;
        case 7:
            printf("\nSabado.\n");
            break;
        default: printf("\nEscolha Invalida!\n");
    }
}

void programa16(){
    int mes;
    printf("Digite um numero entre 1 e 12: ");
    scanf("%d", &mes);
    switch(mes){
        case 1:
            printf("\nJaneiro.\n");
            break;
        case 2:
            printf("\nFevereiro.\n");
            break;
        case 3:
            printf("\nMarco.\n");
            break;
        case 4:
            printf("\nAbril.\n");
            break;
        case 5:
            printf("\nMaio.\n");
            break;
        case 6:
            printf("\nJunho.\n");
            break;
        case 7:
            printf("\nJulho.\n");
            break;
        case 8:
            printf("\nAgosto.\n");
            break;
        case 9:
            printf("\nSetembro.\n");
            break;
        case 10:
            printf("\nOutubro.\n");
            break;
        case 11:
            printf("\nNovembro.\n");
            break;
        case 12:
            printf("\nDezembro.\n");
            break;
        default: printf("\nEscolha Invalida!\n");
    }
}

int programa17(){
    float bmaior, bmenor, h;
    printf("Area do trapezio:");
    printf("\nDigite a base maior: ");
    scanf("%f", &bmaior);
    if(bmaior<=0){
        printf("\nValor Invalido\n");
        return 0;
    }
    printf("Digite a base menor: ");
    scanf("%f", &bmenor);
    if(bmenor<=0){
        printf("\nValor Invalido\n");
        return 0;
    }
    printf("Digite a altura: ");
    scanf("%f", &h);
    printf("\nArea do trapezio = %.2f\n", ((bmaior+bmenor)*h)/2);
    return 0;
}

void programa18(){
    int operacao;
    float a, b;
    printf("Selecione uma operacao:");
    printf("\n1) Soma;");
    printf("\n2) Subtracao;");
    printf("\n3) Multiplicacao;");
    printf("\n4) Divisao;");
    printf("\nEscolha: ");
    scanf("%d", &operacao);

    if(operacao>0 && operacao<5){
        printf("Digite o 1o numero: ");
        scanf("%f", &a);
        printf("Digite o 2o numero: ");
        scanf("%f", &b);
    }
    switch(operacao){
    case 1:
        printf("\n%.2f + %.2f = %.2f\n", a, b, a+b);
        break;
    case 2:
        printf("\n%.2f - %.2f = %.2f\n", a, b, a-b);
        break;
    case 3:
        printf("\n%.2f * %.2f = %.2f\n", a, b, a*b);
        break;
    case 4:
        printf("\n%.2f / %.2f = %.2f\n", a, b, a/b);
        break;
    default: printf("\nEscolha Invalida!\n");
    }
}

void programa19(){
    int num;
    printf("Digite um inteiro: ");
    scanf("%d", &num);
    if(num%3==0 && num%5==0)
        printf("\n%d e divisivel por 3 e 5 ao mesmo tempo...\n", num);
    else if(num%3==0)
        printf("\n%d e divisivel por 3.\n", num);
    else if(num%5==0)
        printf("\n%d e divisivel por 5.\n", num);
}

void programa20(){
    float a, b, c;
    printf("Digite o 1o lado do triangulo: ");
    scanf("%f", &a);
    printf("Digite o 2o lado do triangulo: ");
    scanf("%f", &b);
    printf("Digite o 3o lado do triangulo: ");
    scanf("%f", &c);

    if ((fabs(b - c) < a && a < b + c) && (fabs(a - c) < b && b < a + c) && (fabs(a - b) < c && c < a + b)){
        printf("\nAs retas informadas podem formar um triangulo!");

        if (a == b && a == c)
            printf("\nO triangulo formado e Equilatero!");
        else if ((a == b && b != c) || (a == c && c != b) || (b == c && c != a))
            printf("\nO triangulo formado e Isosceles!");
        else
            printf("\nO triangulo formado e Escaleno!");
    }
    else
        printf("Os valores informados nao formam um triangulo!");
}

void programa21(){
    int operacao;
    float a, b;
    printf("Selecione uma operacao:");
    printf("\n1- Soma de 2 numeros.");
    printf("\n2- Diferenca entre 2 numeros (maior pelo menor).");
    printf("\n3- Produto entre 2 numeros.");
    printf("\n4- Divisao entre 2 numeros (o denominador nao pode ser zero).");
    printf("\nOpcao: ");
    scanf("%d", &operacao);

    if(operacao>0 && operacao<5){
        printf("Digite o 1o numero: ");
        scanf("%f", &a);
        printf("Digite o 2o numero: ");
        scanf("%f", &b);
    }
    switch(operacao){
    case 1:
        printf("\n%.2f + %.2f = %.2f\n", a, b, a+b);
        break;
    case 2:
        if(a>b)
            printf("\n%.2f - %.2f = %.2f\n", a, b, a-b);
        else
            printf("\n%.2f - %.2f = %.2f\n", b, a, b-a);
        break;
    case 3:
        printf("\n%.2f * %.2f = %.2f\n", a, b, a*b);
        break;
    case 4:
        if(b!=0)
            printf("\n%.2f / %.2f = %.2f\n", a, b, a/b);
        else
            printf("\nNao e possivel dividir por 0\n");
        break;
    default: printf("\nEscolha Invalida!\n");
    }
}

void programa22(){
    int idade, tempoServico;
    printf("Dados do Trabalhador:");
    printf("\nIdade: ");
    scanf("%d", &idade);
    printf("\nTempo de Servico: ");
    scanf("%d", &tempoServico);
    if(idade>=65 || tempoServico>=30 || (idade>=60 && tempoServico>=25))
        printf("\nO trabalhador pode se aposentar!\n");
    else
        printf("\nO trabalhador nao pode se aposentar ainda...\n");
}

int programa23(ano){
    if(ano%400==0 || (ano%4==0 && ano%100!=0))
        return 1;
    else
        return 0;
}

void programa24(){
    float valor;
    int destino;

    printf("Digite o valor do produto: R$");
    scanf("%f", &valor);
    printf("Selecione o estado de destino:");
    printf("\n1- MG");
    printf("\n2- SP");
    printf("\n3- RJ");
    printf("\n4- MS");
    printf("\nEscolha: ");
    scanf("%d", &destino);

    switch(destino){
    case 1:
        printf("\nValor final do produto: R$%.2f\n", valor*1.07);
        break;
    case 2:
        printf("\nValor final do produto: R$%.2f\n", valor*1.12);
        break;
    case 3:
        printf("\nValor final do produto: R$%.2f\n", valor*1.15);
        break;
    case 4:
        printf("\nValor final do produto: R$%.2f\n", valor*1.08);
        break;
    default: printf("\nERRO! Estado Invalido\n");
    }
}

void programa25(){
    float a, b, c, x1, x2, delta;
    printf("Digite o valor de a: ");
    scanf("%f", &a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);
    printf("Digite o valor de c: ");
    scanf("%f", &c);

    delta = b*b -(4*a*c);
    if(delta<0)
        printf("\nNao existe raiz.\n");
    else if(delta==0){
        x1 = (-b + sqrt(delta))/(2*a);
        printf("\nRaiz unica: x = %.2f\n", x1);
    }
    else {
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
        printf("\nx1 = %.2f\nx2 = %.2f\n", x1, x2);
    }
}

void programa26(){
    float distancia, consumo, rendimento;
    printf("Digite a distancia percorrida: ");
    scanf("%f", &distancia);
    printf("Digite quantos litros gastou nesse percurso: ");
    scanf("%f", &consumo);
    rendimento=distancia/consumo;
    printf("\nRendimento do carro = %.2fkm/l", rendimento);
    if(rendimento<8)
        printf("\nVenda o carro!\n");
    else if(rendimento<=14)
        printf("\nEconomico!\n");
    else
        printf("\nSuper Economico!\n");
}

void programa27(){
    int idade;
    printf("Digite a idade do nadador: ");
    scanf("%d", &idade);
    printf("\nCategoria\n");
    if(idade>4 && idade<8)
        printf("Infantil A\n");
    else if(idade<11)
        printf("Infantil B\n");
    else if(idade<14)
        printf("Juvenil A\n");
    else if(idade<18)
        printf("Juvenil B\n");
    else
        printf("Senior\n");
}

void programa28(){
    float x, y, z;
    char opcao;
    printf("Digite 3 numeros:\n");
    printf("1o: ");
    scanf("%f", &x);
    printf("1o: ");
    scanf("%f", &y);
    printf("1o: ");
    scanf("%f", &z);

    printf("\nSelecione uma media:");
    printf("\n(a) Geometrica");
    printf("\n(b) Ponderada");
    printf("\n(c) Harmonica");
    printf("\n(d) Aritmetica");
    printf("\nOpcao: ");
    opcao = getch();

    switch(opcao){
    case 'a':
        printf("\nMedia Geometrica = %.2lf\n", pow((x*y*z),(1.0/3.0)));
        break;
    case 'b':
        printf("\nMedia Ponderada = %.2f\n", (x+2*y+3*z)/6);
        break;
    case 'c':
        printf("\nMedia Harmonica = %.2f\n", 1/(1/x+1/y+1/z));
        break;
    case 'd':
        printf("\nMedia Aritmetica = %.2f\n", (x+y+z)/3);
        break;
    default: printf("\nOpcao Invalida!\n");
    }
}

void programa29(){
    int a, b, r, acertos=0, i;
    srand(time(NULL));
    for(i=1;i<6;i++){
        a=(rand()%99)+1;
        b=(rand()%99)+1;
        printf("\nQuanto e %d + %d\nSua resposta: ", a, b);
        scanf("%d", &r);
        if(r==(a+b)){
            printf("Acertou!\n");
            acertos++;
        }
        else
            printf("Errou...\nResposta correta: %d\n", a+b);
    }
    printf("\nAcertos = %d\n", acertos);
}

void programa30(){
    float v[3], aux;
    int i;
    printf("Digite 3 numeros\n");
    for(i=0;i<3;i++){
        printf("%do: ", i+1);
        scanf("%f", &v[i]);
    }
    for(i=0;i<2;i++){
        if(v[i]>v[i+1]){
            aux=v[i+1];
            v[i+1]=v[i];
            v[i]=aux;
        }
    }
    printf("\nVetor ordenado: ");
    for(i=0;i<3;i++)
        printf("%.1f, ", v[i]);
}

void programa31(){
    float h, w;
    printf("Digite sua altura (m): ");
    scanf("%f", &h);
    printf("Digite seu peso (kg): ");
    scanf("%f", &w);
    printf("\nVoce esta na categoria: ");
    if(h<1.2){
        if(w<=60.0)
            printf("A\n");
        else if(w<=90.0)
            printf("D\n");
        else
            printf("G\n");
    }
    else if(h<=1.7){
        if(w<=60.0)
            printf("B\n");
        else if(w<=90.0)
            printf("E\n");
        else
            printf("H\n");
    }
    else{
        if(w<=60.0)
            printf("C\n");
        else if(w<=90.0)
            printf("F\n");
        else
            printf("I\n");
    }
}

void programa32(){
    int cod, qtd;
    printf("Especificacao       Codigo  Preco\n");
    printf("Cachorro Quente     100     1.20\n");
    printf("Bauru Simples       101     1.30\n");
    printf("Bauru com Ovo       102     1.50\n");
    printf("Hamburguer          103     1.20\n");
    printf("Cheeseburguer       104     1.70\n");
    printf("Suco                105     2.20\n");
    printf("Refrigerante        106     1.00\n");
    printf("Digite o codigo do lanche: ");
    scanf("%d", &cod);

    if(cod>=100 && cod<107){
        printf("Digite a quantidade de lanches: ");
        scanf("%d", &qtd);
        printf("\nValor total: ");
    }

    switch(cod){
    case 100:
        printf("%.2f\n", qtd*1.2);
        break;
    case 101:
        printf("%.2f\n", qtd*1.3);
        break;
    case 102:
        printf("%.2f\n", qtd*1.5);
        break;
    case 103:
        printf("%.2f\n", qtd*1.2);
        break;
    case 104:
        printf("%.2f\n", qtd*1.7);
        break;
    case 105:
        printf("%.2f\n", qtd*2.2);
        break;
    case 106:
        printf("%.2f\n", qtd*1.0);
        break;
    default: printf("\nLanche Inexistente!\n");
    }
}

void programa33(){
    float preco;
    printf("Digite o valor do produto: R$");
    scanf("%f", &preco);
    if(preco<=50.0)
        printf("\nAumento de 5%%\nNovo preco = R$%.2f\n", preco*1.05);
    else if(preco<=100.0)
        printf("\nAumento de 10%%\nNovo preco = R$%.2f\n", preco*1.10);
    else
        printf("\nAumento de 15%%\nNovo preco = R$%.2f\n", preco*1.15);
}

void programa34(){
    float nota;
    int faltas;
    printf("Digite a nota do aluno: ");
    scanf("%f", &nota);
    printf("Digite a numero de faltas do aluno: ");
    scanf("%d", &faltas);
    printf("\nConceito: ");
    if(nota>=9.0){
        if(faltas<21)
            printf("A\n");
        else
            printf("B\n");
    }
    else if(nota>=7.5){
        if(faltas<21)
            printf("B\n");
        else
            printf("C\n");
    }
    else if(nota>=5.0){
        if(faltas<21)
            printf("C\n");
        else
            printf("D\n");
    }
    else if(nota>=4.0){
        if(faltas<21)
            printf("D\n");
        else
            printf("E\n");
    }
    else
        printf("E\n");
}

void programa35(){
    int dia, mes, ano, valido=1;
    printf("Digite uma data:\n");
    printf("Dia: ");
    scanf("%d", &dia);
    printf("Mes: ");
    scanf("%d", &mes);
    printf("Ano: ");
    scanf("%d", &ano);
    if(ano>anoAtual)
        valido=0;
    if((mes<1 || mes>12) && valido==1)
        valido=0;
    if(valido==1){
        if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
            if(dia<1 || dia>31)
                valido=0;
        }
        else if(mes==4 || mes==6 || mes==9 || mes==11){
            if(dia<1 || dia>30)
                valido=0;
        }
        else if(mes==2){
            if(programa23(ano))
                if(dia<1 || dia>29)
                    valido=0;
            else
                if(dia<1 || dia>28)
                    valido=0;
        }
    }
    if(valido)
        printf("\nData Valida!\n");
    else
        printf("\nData Invalida...\n");
}

void programa36(){
    float venda;
    printf("Digite o valor da venda mensal: R$");
    scanf("%f", &venda);
    if(venda>=100000.0)
        printf("\nComissao = R$%.2f\n", venda*0.16+700);
    else if(venda>=80000.0)
        printf("\nComissao = R$%.2f\n", venda*0.14+650);
    else if(venda>=60000.0)
        printf("\nComissao = R$%.2f\n", venda*0.14+600);
    else if(venda>=40000.0)
        printf("\nComissao = R$%.2f\n", venda*0.14+550);
    else if(venda>=20000.0)
        printf("\nComissao = R$%.2f\n", venda*0.14+500);
    else
        printf("\nComissao = R$%.2f\n", venda*0.14+400);
}

void programa37(){
    int hEntrada, mEntrada, hPartida, mPartida, minutos=0, horas=0;
    float total=0;

    printf("Digite a hora da entrada (hh:mm): ");
    scanf("%d:%d", &hEntrada, &mEntrada);
    printf("Digite a hora da partida (hh:mm): ");
    scanf("%d:%d", &hPartida, &mPartida);

    if(hEntrada<hPartida || (hEntrada==hPartida && mEntrada<=mPartida))
        minutos=(hPartida*60+mPartida)-(hEntrada*60+mEntrada);
    else
        minutos=24*60-((hEntrada*60+mEntrada)-(hPartida*60+mPartida));
    while(minutos>60){
        minutos-=60;
        horas++;
        if(horas<3)
            total+=1.0;
        else if(horas<5)
            total+=1.4;
        else
            total+=2.0;
    }
    printf("\nTempo no estacionamento = %dh%dmin\n", horas, minutos);
    if(minutos>0){
        horas++;
        if(horas<3)
            total+=1.0;
        else if(horas<5)
            total+=1.4;
        else
            total+=2.0;
    }
    printf("Total a pagar = R$%.2f\n", total);
}

void programa38(){
    int dia, mes, ano, valido=1;
    printf("Digite sua data de nascimento:\n");
    printf("Dia: ");
    scanf("%d", &dia);
    printf("Mes: ");
    scanf("%d", &mes);
    printf("Ano: ");
    scanf("%d", &ano);
    if(ano>anoAtual)
        valido=0;
    if((mes<1 || mes>12) && valido==1)
        valido=0;
    if(valido==1){
        if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
            if(dia<1 || dia>31)
                valido=0;
        }
        else if(mes==4 || mes==6 || mes==9 || mes==11){
            if(dia<1 || dia>30)
                valido=0;
        }
        else if(mes==2){
            if(programa23(ano))
                if(dia<1 || dia>29)
                    valido=0;
            else
                if(dia<1 || dia>28)
                    valido=0;
        }
    }
    if(valido)
        printf("\nData Valida!\n");
    else
        printf("\nData Invalida...\n");
}

char* bonus(int tempo){
    if(tempo<1)
        return "Sem bonus";
    else if(tempo<4)
        return "100";
    else if(tempo<7)
        return "200";
    else if(tempo<11)
        return "300";
    else
        return "500";
}

void programa39(){
    float salario;
    int tempo;
    printf("Digite o salario do funcionario: R$");
    scanf("%f", &salario);
    printf("Digite o tempo de servico (em anos): ");
    scanf("%d", &tempo);
    if(salario<=500.0)
        printf("Novo Salario = R$%.2f\nBonus = %s", salario*1.25, bonus(tempo));
    else if(salario<=1000.0)
        printf("Novo Salario = R$%.2f\nBonus = %s", salario*1.20, bonus(tempo));
    else if(salario<=1500.0)
        printf("Novo Salario = R$%.2f\nBonus = %s", salario*1.15, bonus(tempo));
    else if(salario<=2000.0)
        printf("Novo Salario = R$%.2f\nBonus = %s", salario*1.10, bonus(tempo));
    else
        printf("Novo Salario = R$%.2f (Sem reajuste)\nBonus = R$%s", salario, bonus(tempo));
}

void programa40(){
    float custoFabrica, comissao, imposto;
    printf("Digite o custo de Fabrica do carro: R$");
    scanf("%f", &custoFabrica);
    if(custoFabrica<=12000.0){
        comissao=custoFabrica*0.05;
        imposto=0.0;
    }
    else if(custoFabrica<=25000.0){
        comissao=custoFabrica*0.10;
        imposto=custoFabrica*0.15;
    }
    else{
        comissao=custoFabrica*0.15;
        imposto=custoFabrica*0.20;
    }
    printf("\nComissao do Distribuidor = R$%.2f", comissao);
    printf("\nImpostos                 = R$%.2f", imposto);
    printf("\nValor total              = R$%.2f\n", custoFabrica+comissao+imposto);
}

void programa41(){
    float h, w, imc;
    printf("Digite sua altura (m): ");
    scanf("%f", &h);
    printf("Digite seu peso  (kg): ");
    scanf("%f", &w);
    imc=w/(h*h);
    if(imc<18.5)
        printf("\nAbaixo do Peso.\n");
    else if(imc<25.0)
        printf("\nSaudavel.\n");
    else if(imc<30.0)
        printf("\nPeso em Excesso.\n");
    else if(imc<35.0)
        printf("\nObesidade Grau I.\n");
    else if(imc<40.0)
        printf("\nObesidade Grau II (severa).\n");
    else
        printf("\nObesidade Grau III (morbida).\n");
}
