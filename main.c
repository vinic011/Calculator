#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct celula celula;
typedef celula* pont;

struct celula
{
    int num;
    pont prox;
};
typedef pont numero;

numero Ler();
void Escrever(numero);
numero Soma(numero,numero);
numero Mult(numero,numero);


int main()
{
    numero a,b;
    printf("Digite o numero grande a ser analisado:\n");

    a = Ler();
    if(a->prox->num == -1)
    {
        printf("\nA cadeia deve conter apenas algarismos numericos");
        return 0;
    }

    printf("Digite o numero grande a ser analisado:\n");
    b = Ler();
    if(b->prox->num == -1)
    {
        printf("\nA cadeia deve conter apenas algarismos numericos");
        return 0;
    }
    numero c = Soma(a,b);
    printf("Valor da soma: ");
    Escrever(c);

    numero d = Mult(a,b);
    printf("\nValor da multiplicacao: ");
    Escrever(d);

    printf("\n\n");
    system("pause");
    return 0;
}

numero Ler()
{
    //Declarações
    numero inicial;
    numero cur;
    int i = 0;
    int j =0;
    char g[100];
    char f[100];
    char aux[4]= {'0','0','0','0'};
    char h;

    //Usuario escreve a cadeia
    scanf("%s",f);
    int k = strlen(f);

    //Para retornar -1 quando não for algarismo numerico
    for (i = 0; i<k; i++)
    {
        if(f[i]!='0'&&f[i]!='1'&&f[i]!='2'&&f[i]!='3'&&f[i]!='4'
                &&f[i]!='5'&&f[i]!='6'&&f[i]!='7'&&f[i]!='8'&&f[i]!='9')
        {
            cur->num = -1;
            cur->prox = NULL;
            return inicial;
        }
    }

    //retirar algarismos 0 do inicio
    for(i=0; f[i] == '0'; i++)
    {
        j++;
    }
    k = k-j;

    for(i=0; i<k ; i++)
    {
        g[i] = f[i+j];
    }

    //Inversão da ordem que o usuário digitou
    for(i = 0; i<=k/2 -1; i++)
    {
        h = g[i];
        g[i] = g[k-1-i];
        g[k-1-i] = h;
    }
    g[k]='\0';

    //alocação dinâmica
    inicial = (pont) malloc (sizeof (celula));
    cur = (pont) malloc (sizeof (celula));
    inicial->prox = cur;


    for (i = 0; i < k; i+=4)
    {
        //String aux pegar de 4 em 4
        if(i<k)
        {
            aux[3] = g[i];
        }
        if(i+1<k)
        {
            aux[2] = g[i+1];
        }
        if(i+2<k)
        {
            aux[1] = g[i+2];
        }
        if(i+3<k)
        {
            aux[0] = g[i+3];
        }
        //print dos numeros digitados de 4 em 4
        aux[4] = '\0';
        cur->num = atoi(aux);
        //zerando os aux
        aux[0]= '0';
        aux[1]= '0';
        aux[2]= '0';
        aux[3]= '0';
        //Alocação do próximo + ir para o próximo
        cur->prox = (pont) malloc (sizeof (celula));
        cur = cur->prox;
    }
    cur->prox = NULL;

    return inicial;
}

void Escrever(numero p)
{
    //Declarações
    numero q;
    int i = 0;
    int j;

    int ordenar[100];
    char aux[100];
    char *paux = aux;

    q = p->prox;

    //inversão das ordens dos números para o print
    while(q->prox != NULL)
    {
        ordenar[i] = q->num;
        i++;
        q = q->prox;
    }
    paux += sprintf(paux, "%d", ordenar[i-1]);
    for(j=i-2; j>=0; j--)
    {
        if((ordenar[j]>-1)&&(ordenar[j]<10))
        {
            paux += sprintf(paux, "000%d", ordenar[j]);
        }
        if((ordenar[j]>9)&&(ordenar[j]<100))
        {
            paux += sprintf(paux, "00%d", ordenar[j]);
        }
        if((ordenar[j]>99)&&(ordenar[j]<1000))
        {
            paux += sprintf(paux, "0%d", ordenar[j]);
        }
        if((ordenar[j]>999)&&(ordenar[j]<10000))
        {
            paux += sprintf(paux, "%d", ordenar[j]);
        }
    }
    printf("%s",aux);
}

numero Soma(numero a,numero b)
{
    numero soma,r;
    soma = (pont) malloc (sizeof (celula));
    r = (pont) malloc (sizeof (celula));
    soma->prox = r;
    numero x,y;
    x = a->prox;
    y = b->prox;
    int aux;
    int carrysomar = 0;
    int carryguardar = 0;

    while(x->prox!=NULL && y->prox!=NULL)
  	{
      aux =0;
      carrysomar = carryguardar;
      aux = x->num + y->num + carrysomar;
      if(aux>=10000)
      {
        aux = aux - 10000;
        carryguardar = 1;
      }
      else
      {
        carryguardar = 0;
      }
      r->num = aux;
      r->prox = (pont) malloc (sizeof (celula));
      r = r->prox;
      x = x->prox;
      y = y->prox;
    }

    while(x->prox!=NULL && y->prox==NULL)
  	{
      aux =0;
      carrysomar = carryguardar;
      aux = x->num + carrysomar;
      if(aux>=10000)
      {
        aux = aux - 10000;
        carryguardar = 1;
      }
      else
      {
        carryguardar = 0;
      }
      r->num = aux;
      r->prox = (pont) malloc (sizeof (celula));
      r = r->prox;
      x = x->prox;
    }

    while(x->prox==NULL && y->prox!=NULL)
  	{
      aux =0;
      carrysomar = carryguardar;
      aux = y->num + carrysomar;
      if(aux>=10000)
      {
        aux = aux - 10000;
        carryguardar = 1;
      }
      else
      {
        carryguardar = 0;
      }
      r->num = aux;
      r->prox = (pont) malloc (sizeof (celula));
      r = r->prox;
      y = y->prox;
    }

  if(carryguardar == 1)
 	{
    aux = 1;
    r->num = aux;
    r->prox = (pont) malloc (sizeof (celula));
    r = r->prox;
  }
    r->prox = NULL;
    return soma;
}

numero Mult(numero a,numero b)
{
    numero m;
    m=(pont) malloc (sizeof(celula));
    m->prox=(pont) malloc (sizeof(celula));
    m->prox->num=0;
    m->prox->prox=NULL;
    //numero para apontar no a
    numero x;
    x = a->prox;
    //i vai contar quantas casas de 0 devo colocar
    int i = 0;
    int j;
    int aux;
    numero sss=(pont) malloc (sizeof (celula));
    numero h, y;
    while(x->prox!=NULL)
    {
        //zerar os carrys
        int carryguardar = 0;
        int carrysomar = 0;
        //y para apontar em
        y = b->prox; h=sss;
        //h é a multiplicação parcial, a ser somada para conseguir a mult fin
        h->prox = (pont) malloc (sizeof (celula));
        h = h->prox;
        //completar 0000 do h
        for(j=0; j<i; j++)
        {
            h->num = 0;
            h->prox = (pont) malloc (sizeof (celula));
            h = h->prox;
        }

        //sem considerar o último termo da structure
        while(y->prox!=NULL)
        {
            aux = 0;
            carrysomar = carryguardar;
            aux = (x->num)*(y->num) + carrysomar;
            
            if(aux>=10000)
            {
                carryguardar = (aux - aux%10000)/10000;
                aux = aux%10000;
            }
            h->num = aux;
            h->prox = (pont) malloc (sizeof (celula));
            h = h->prox;
            y = y->prox;

        }
        //Ultimo termo, caso exista carry
        if(carryguardar!=0)
        {
            h->num = carryguardar;
            h->prox = (pont) malloc (sizeof (celula));
            h = h->prox;
        }
        h->prox = NULL;
        //somar o h no numero n
        m = Soma(m,sss);
        i++;
        x = x->prox;
    }
    return m;
}