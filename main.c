#include ".\include\avl.h"         //https://github.com/edpfacom/libfacom
#include ".\include\cjson\cJSON.h" //https://github.com/DaveGamble/cJSON
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

titem *aloca_municipio(int cod_ibge, int cod_uf, int siafi_id, int ddd, int capital, char *nome_municipio, char *fuso, float latitude, float longitude)
{

    tmunicipio *municipio = malloc(sizeof(tmunicipio));

    municipio->cod_ibge = cod_ibge;
    municipio->cod_uf = cod_uf;
    municipio->siafi_id = siafi_id;
    municipio->ddd = ddd;
    municipio->capital = capital;
    strcpy(municipio->nome_municipio, nome_municipio);
    strcpy(municipio->fuso, fuso);
    municipio->latitude = latitude;
    municipio->longitude = longitude;

    titem *aux = (titem *)malloc(sizeof(titem));
    aux->reg = municipio;
    aux->prox = NULL;
    return aux;
}

void lerjson(tnode **avl_nome, tnode **avl_ddd, tnode **avl_coduf, tnode **avl_longi, tnode **avl_lati)
{
    // Abre o arquivo
    FILE *json = fopen("municipios.json", "r");

    // Obter o tamanho do arquivo
    fseek(json, 0, SEEK_END);
    long tamanho = ftell(json);
    fseek(json, 0, SEEK_SET);

    // Ler o conteúdo do arquivo
    char *conteudo = (char *)malloc(tamanho + 1);
    fread(conteudo, 1, tamanho, json);
    fclose(json);

    // Adicionar terminador de string
    conteudo[tamanho] = '\0';

    // Analisar o JSON
    cJSON *raiz = cJSON_Parse(conteudo);
    free(conteudo);

    cJSON *objeto = raiz->child;
    char aux[100];

    while (objeto != NULL)
    {

        cJSON *cod_ibge = cJSON_GetObjectItem(objeto, "codigo_ibge");
        cJSON *nome = cJSON_GetObjectItem(objeto, "nome");
        cJSON *fuso = cJSON_GetObjectItem(objeto, "fuso_horario");
        cJSON *siafi_id = cJSON_GetObjectItem(objeto, "siafi_id");
        cJSON *cod_uf = cJSON_GetObjectItem(objeto, "codigo_uf");
        cJSON *ddd = cJSON_GetObjectItem(objeto, "ddd");
        cJSON *capital = cJSON_GetObjectItem(objeto, "capital");
        cJSON *lati = cJSON_GetObjectItem(objeto, "latitude");
        cJSON *longi = cJSON_GetObjectItem(objeto, "longitude");

        avl_insere_nome(avl_nome, NULL, aloca_municipio(cod_ibge->valueint, cod_uf->valueint, siafi_id->valueint, ddd->valueint, capital->valueint, nome->valuestring, fuso->valuestring, lati->valuedouble, longi->valuedouble));
        avl_insere_ddd(avl_ddd, NULL, aloca_municipio(cod_ibge->valueint, cod_uf->valueint, siafi_id->valueint, ddd->valueint, capital->valueint, nome->valuestring, fuso->valuestring, lati->valuedouble, longi->valuedouble));
        avl_insere_coduf(avl_coduf, NULL, aloca_municipio(cod_ibge->valueint, cod_uf->valueint, siafi_id->valueint, ddd->valueint, capital->valueint, nome->valuestring, fuso->valuestring, lati->valuedouble, longi->valuedouble));
        avl_insere_longi(avl_longi, NULL, aloca_municipio(cod_ibge->valueint, cod_uf->valueint, siafi_id->valueint, ddd->valueint, capital->valueint, nome->valuestring, fuso->valuestring, lati->valuedouble, longi->valuedouble));
        avl_insere_lati(avl_lati, NULL, aloca_municipio(cod_ibge->valueint, cod_uf->valueint, siafi_id->valueint, ddd->valueint, capital->valueint, nome->valuestring, fuso->valuestring, lati->valuedouble, longi->valuedouble));
        objeto = objeto->next;
    }

    cJSON_Delete(raiz);
}

void interseccao(tbusca *l1, tbusca **res)
{
    if (*res == NULL){

        (*res) = l1;
       
    }else{
        tbusca *ult = NULL;
        tbusca *r = NULL;

        for (tbusca *no1 = (*res); no1 != NULL; no1 = no1->prox)
        {
            for (tbusca *no2 = l1; no2 != NULL; no2 = no2->prox)
            {
                titem *item1 = no1->item;
                while (item1 != NULL)
                {
                    titem *item2 = no2->item;
                    while (item2 != NULL)
                    {
                        if (item1->reg->cod_ibge == item2->reg->cod_ibge)
                        {
                            tbusca *x = (tbusca *)malloc(sizeof(tbusca));
                            x->item = item1;
                            x->prox = NULL;
                            if (r == NULL)
                            {
                                r = x;
                            }
                            else
                            {
                                ult->prox = x;
                            }
                            ult = x;
                            break;
                        }
                        item2 = item2->prox;
                    }
                    item1 = item1->prox;
                }
            }
        }
        (*res) = r;
    }
}

void imprime_res(tbusca *res)
{
 
        int x = 1;
        for (tbusca *i = res; i != NULL; i = i->prox)
        {
            printf("%d - NOME: %s | CAPITAL: %d| CODIGO IBGE: %d | DDD: %d | CODIGO UF: %d | LONGITUDE: %.2f | LATITUDE: %.2f | SIAFI ID: %d | FUSO: %s\n",x, i->item->reg->nome_municipio, i->item->reg->capital, i->item->reg->cod_ibge, i->item->reg->ddd, i->item->reg->cod_uf, i->item->reg->longitude, i->item->reg->latitude, i->item->reg->siafi_id, i->item->reg->fuso);
            x++;
        }

}

void imprime_res2(tbusca *res)
{
    tbusca *count = res;
    while (count != NULL)
    {
        int x = 1;
        for (titem*i = count->item; i != NULL; i = i->prox)
        {
            printf("%d - NOME: %s | CAPITAL: %d| CODIGO IBGE: %d | DDD: %d | CODIGO UF: %d | LONGITUDE: %.2f | LATITUDE: %.2f | SIAFI ID: %d | FUSO: %s\n",x, i->reg->nome_municipio, i->reg->capital, i->reg->cod_ibge, i->reg->ddd, i->reg->cod_uf, i->reg->longitude, i->reg->latitude, i->reg->siafi_id, i->reg->fuso);
            x++;
        }
        count = count->prox;
    }
}

void interface(tnode **avl_nome, tnode **avl_ddd, tnode **avl_coduf, tnode **avl_longi, tnode **avl_lati)
{

    int opx;
    int run;
    while (1)
    {

        tbusca *busca_ddd = NULL;
        tbusca *busca_nome = NULL;
        tbusca *busca_coduf = NULL;
        tbusca *busca_longi = NULL;
        tbusca *busca_lati = NULL;
        tbusca *res = NULL;
        printf("RANGE QUERY CIDADES MAIS PROXIMAS\n");
        printf("1 - BUSCA | 2 - GUIA | 0 - ENCERRAR PROGRAMA\n");
        scanf("%d", &run);

        printf("\e[1;1H\e[2J");
        if (run == 1)
        {
            printf("QUANTAS AVLs DESEJA UTILIZAR? [MAX 5]\n");
            int avln = 0;
            int avlop[] = {-1, -1, -1, -1, -1};
            scanf("%d", &avln);

            for (int i = 0; i < avln; i++)
            {
                printf("ESCOLHA A %dª AVL\n1 - NOME | 2 - DDD | 3 - CODIGO UF\n4- LONGITUDE | 5 - LATITUDE\n", i);
                scanf("%d", &opx);
                avlop[opx - 1] = 1;
            }
            printf("\e[1;1H\e[2J");
            if (avlop[0] == 1)
            {
                char temp[30];
                printf("INSIRA O NOME A SER BUSCADO\n");
                scanf("%s", temp);

                avl_RQ_nome(&(*avl_nome), temp, &busca_nome);
                interseccao(busca_nome, &res);
            }
            if (avlop[1] == 1)
            {
                int t, t2;
                printf("INSIRA O RANGE DE DDD A SER BUSCADO\n");
                scanf("%d %d", &t, &t2);
                avl_RQ_ddd(&(*avl_ddd), t, t2, &busca_ddd);
                interseccao(busca_ddd, &res);
            }
            if (avlop[2] == 1)
            {
                int t, t2;
                printf("INSIRA O RANGE DE CODIGO UF A SER BUSCADO\n");
                scanf("%d %d", &t, &t2);
                avl_RQ_coduf(&(*avl_coduf), t, t2, &busca_coduf);
                interseccao(busca_coduf, &res);
            }
            if (avlop[3] == 1)
            {
                float t, t2;
                printf("INSIRA O RANGE DA LONGITUDE A SER BUSCADO\n");
                scanf("%f %f", &t, &t2);
                avl_RQ_longi(&(*avl_longi), t, t2, &busca_longi);
                interseccao(busca_longi, &res);
            }
            if (avlop[4] == 1)
            {
                float t, t2;
                printf("INSIRA O RANGE A LATITUDE A SER BUSCADO\n");
                scanf("%f %f", &t, &t2);
                avl_RQ_lati(&(*avl_lati), t, t2, &busca_lati);
                interseccao(busca_lati, &res);
            }
            printf("\e[1;1H\e[2J");
            if (avlop[3]  == 1 || avlop[4] == 1 || (avlop[1] == 1 && avlop[2] == 1)) imprime_res(res); else imprime_res2(res);
            printf("\n\n");
        }
        else if (run == 2)
        {
            printf("NOTA: NAO E POSSIVEL REALIZAR BUSCA POR INTERVALO DE NOME E NAO FUNCIONA PELA INTERFACE\nNAO EXISTE LONGITUDE MAIOR QUE -31 CADASTRADA\nA MAIOR LATITUDE POSTIVA E 4.60314\nCASO BUSCA == -> INSIRA O VALOR MIN E MAX IGUAIS\nCASO BUSCA INTERVALO -> INSIRA EM MIN E MAX OS LIMITES DA BUSCA\nCASO BUSCA <= -> INSIRA MIN COMO 0 E MAX O LIMITE MAXIMO\nCASO BUSCA >= -> INSIRA MAX COMO 0 E MIN COMO O LIMITE MINIMO\n\n");
        }
        else
            break;
    }
}

int main()
{

    tnode *avl_nome = NULL;
    tnode *avl_ddd = NULL;
    tnode *avl_coduf = NULL;
    tnode *avl_longi = NULL;
    tnode *avl_lati = NULL;

    lerjson(&avl_nome, &avl_ddd, &avl_coduf, &avl_longi, &avl_lati);
    interface(&avl_nome, &avl_ddd, &avl_coduf, &avl_longi, &avl_lati);

}
