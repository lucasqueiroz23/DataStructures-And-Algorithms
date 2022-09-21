#include <stdlib.h>
///HASH UNIVERSAL
//a funcao hashU transforma uma string em um inteiro
int hashU(char *v, int m)
{
    int h,a=31415,b=27183; //a e b sao aleatorios
    for(h = 0; *v!='\0'; v++)
    {
        a = a*b%(m-1);
        h = (a*h + *v)%m;
    }
    return h;
}

///MACROS DE HASH
#define hash(v,m)(v%m) /// ok para M primo
//#define hash(v,m)(618033*(unsigned)v % m)

///Implementacao de referencia de HT
typedef struct Item
{
    int chave;
    long e1,e2;
    long elemento;

} Item;
Item NULLItem = {0,0,0,0}; ///HT PARA IMPLEMENTACAO

#define key(x) (x.chave)
#define less(a,b) (key(a) < key(b))
#define eq(a,b) (a==b)
#define null(a) ( key ( ht[a] ) == key(NULLItem))


static int N,M; ///M eh o tamanho da ht, N eh a quantidade de elementos na tabela
static Item *ht; ///hashtable


///INICIALIZCAO DE HASHTABLE
void HtInit (int max)
{
    int i;
    N = 0, M = 2*max;
    ht = malloc(sizeof(Item)*M);
    for(i = 0; i<M; i++)
        ht[i] = NULLItem;
}

///A FUNCAO HtCount RETORNA A QUANTIDADE DE ELEMENTOS DA ht
int HtCount()
{
    return N;
}

///INSERE ELEMENTOS NA HT
void HtInsert(Item item)
{
    int v = key(item);
    int i = hash(v,M);
    while(!null(i))
        i = (i+1)%M;
    ht[i] = item;
    N++;
}

///BUSCA UM ELEMENTO NA HT
Item Htsearch(int v) //v eh a chave, nao necessariamente eh int
{
    int i = hash(v,M);
    while(!null(i))
        if(eq(v,key(ht[i])))
            return ht[i];
        else
            i = (i+1)%M;
    return NULLItem;
}

