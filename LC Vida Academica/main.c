//
//  main.c
//  LC Vida Academica
//
//  Created by Daniel Terra on 31/10/11.
//  Copyright 2011 Daniel Terra Propaganda Digital. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "Universidades.h"
#include "telasPadronizadas.h"


int main (int argc, const char * argv[])
{
    //Primeira tela para apresentar o que é o software e quem o desenvolveu.
    telasApresentacao();
    
    //Verificar se existe alguma Universidade cadastrada, se tiver lista em um menu, se não tiver abre a tela de cadastro.
    if(verificaUniversidades() == 0){
        //listarUniversidades();
    }else{
        //addUniversidade();
    }
    return 0;
}