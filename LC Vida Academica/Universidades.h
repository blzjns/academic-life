//
//  Universidades.h
//  LC Vida Academica
//
//  Created by Daniel Terra on 31/10/11.
//  Copyright 2011 Daniel Terra Propaganda Digital. All rights reserved.
//

#ifndef LC_Vida_Academica_Universidades_h
#define LC_Vida_Academica_Universidades_h

#define QtdInstituicoes 3


#endif


FILE *bdUniversidades;
int addUniversidade(void);
int listarUniversidades(void);
int pesquisaUniversidade(int CodigoProcurado);
int verificaUniversidades(void);


//Estrutura de Dados
typedef struct{
    int cod;
    char nome[30];
    int limiteDeFaltas;
    float notaMinima;
    float tempoDeDuracaoDasAulas;
    char email[40];
} instituicao;
//Fim da Estrutura da Dados


int addUniversidade(void){
    //Essa função recebe os dados da nova Universidade e insere no arquivo binário selecionado um novo registro de faculdade ao final do Vetor.
    instituicao universidade;
    printf("\nNome da Universidade: ");
    fpurge(stdin);
    gets(universidade.nome);
    printf("\nNota mínima de provação: ");
    scanf("%f",&universidade.notaMinima);
    printf("\nTempo de duração das aulas: ");
    scanf("%f",&universidade.tempoDeDuracaoDasAulas);
    printf("\nLimite de falta: ");
    scanf("%i",&universidade.limiteDeFaltas);
    printf("\nE-mail da Secretaria: ");
    fpurge(stdin);
    gets(universidade.email);
    
    bdUniversidades = fopen("bdUniversidades.bin","ab"); //Cria o arquivo se ele não existir e abre para a inserção de dados.
    if(bdUniversidades){
        printf("Salvando dados...");
        fwrite(&bdUniversidades, sizeof(instituicao),1,bdUniversidades);//Insere os dados no arquivo fwrite(endereços dos dados, tamanho que ele vai gravar, quantidade de registros a ser gravados, variável que guarda o endereço do arquivo binário).
        fclose(bdUniversidades); //Encerra a transmissão de dados.
        printf("Dados salvos.");
        return 0;
    } else{
        return 1;
    }
    fclose(bdUniversidades);
}

int listarUniversidades(){
    printf("Listando universidades...\n\n\n");
    instituicao Universidade;
    bdUniversidades = fopen("bdUniversidades.bin","rb");
    rewind(bdUniversidades); //Para mostrar do começo ao final.
    fread(&Universidade, sizeof(instituicao),1,bdUniversidades); //Faz a primeira leitura
    if(feof(bdUniversidades)){
        printf("Nenhuma faculdade cadastrada.");
    }else{
        while(!feof(bdUniversidades)){
            printf("Cod: %i",Universidade.cod);
            printf("Nome: %s",Universidade.nome);
            printf("Limite de Faltas: %i",Universidade.limiteDeFaltas);
            printf("Nota mínima: %f",Universidade.notaMinima);
            printf("Tempo de duração das aulas: %f",Universidade.tempoDeDuracaoDasAulas);
            printf("E-mail da Secretaria: %s",Universidade.email);
            fread(&Universidade, sizeof(instituicao),1,bdUniversidades);
        }
    }
    fclose(bdUniversidades);
    return 0;
}

int pesquisaUniversidade(int CodigoProcurado){
    int posicao=0;
    instituicao Universidade;
    bdUniversidades = fopen("bdUniversidades.bin","rb");
    rewind(bdUniversidades); //Para mostrar do começo ao final.
    fread(&Universidade, sizeof(instituicao),1,bdUniversidades); //Faz a primeira leitura
    if(feof(bdUniversidades)){
        printf("Nenhuma faculdade cadastrada.");
    }else{
        while(!feof(bdUniversidades)){
            if(CodigoProcurado == Universidade.cod){
                break;
            }else{
                fread(&Universidade, sizeof(instituicao),1,bdUniversidades);
            }
        }
        fseek(bdUniversidades, posicao*sizeof(instituicao),SEEK_SET);
        fread(&Universidade, sizeof(instituicao),1,bdUniversidades);
        printf("Cod: %i",Universidade.cod);
        printf("Nome: %s",Universidade.nome);
        printf("Limite de Faltas: %i",Universidade.limiteDeFaltas);
        printf("Nota mínima: %f",Universidade.notaMinima);
        printf("Tempo de duração das aulas: %f",Universidade.tempoDeDuracaoDasAulas);
        printf("E-mail da Secretaria: %s",Universidade.email);
    }
    fclose(bdUniversidades);
    return 0;
}

int verificaUniversidades(){
    instituicao Universidade;
    bdUniversidades = fopen("bdUniversidades.bin","rb");
    printf("\nRebobinando...");
    rewind(bdUniversidades); //Para mostrar do começo ao final.
    printf("\nLendo arquivo...");
    fread(&Universidade, sizeof(instituicao),1,bdUniversidades); //Faz a primeira leitura
    printf("\nArquivo lido com sucesso.");
    if(feof(bdUniversidades)){
        printf("\nNenhuma universidade no arquivo.");
        //Nenhuma faculdade cadastrada.
        fclose(bdUniversidades);
        return 1;
    }else{
        printf("\nForam encontradas entradas.");
        //Existem faculdades cadastradas.
        fclose(bdUniversidades);
        return 0;
    }
}