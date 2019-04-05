//
//  main.c
//  Projetil
//
//  Created by José Luiz Junior on 05/04/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "calculo.h"

int main(int argc, const char * argv[]) {
    
    //VARIAVEIS
    float ang, vel, angvis, dist, g = 9.8, distpontos;
    float alcH, alcV;
    int N, i, pontuacaoatacante = 0, pontuacaodefensor = 0, x = 0, y = 0, areacastelo, op;
    
    do{
        //CATAPULTA
        printf("Digite a distancia da catapulta ate o castelo: ");
        scanf(" %f",&dist);
        
        //CASTELO
        
        areacastelo =  300 * 300;
        
        //A area do castelo possui 300m x 300m, ent„o as coordenadas do castelo ser: o X(150,0), X(-150,0), Y(0,150), Y(0,-150)
        //o centro do castelo ficara na origem (0,0)
        //A catapulta estar· a um determinada distancia do castelo, portanto, para calcular a COORDENADA DO PROJ…TIL no eixo X,
        //basta pegar a distancia da catapulta (negativa, pois sempre est· do lado esquerdo do castelo) + -150 (ponto limite mais prox)
        //e adicionar no resultado do alcance horizontal
        
        while((abs(x) > 150) || (abs(y) > 150)){ //verifica se o modulo dos valores digitados pra x e y estao no limite
            fflush(stdin);
            printf("Digite o ponto X e Y da coordenada do alvo (-150 < x & y < 150): ");
            scanf("%d %d",&x,&y);
            
            if(abs(x) < 150 && abs(y) < 150){
                break;
            }
        }
        
        printf("As coordenadas (x,y) digitadas para o alvo foram: %d %d\n",x,y);
        
        fflush(stdin);
        printf("Digite a quantidade de lancamentos: ");
        scanf(" %d",&N);
        
        for(i=0;i<N;i++){
            printf("Digite o angulo de inclinacao do arremesso %d: ",i+1);
            scanf("%f",&ang);
            printf("Digite a velocidade inicial %d: ",i+1);
            scanf("%f",&vel);
            
            
            printf("Digite o angulo de visada %d: ",i+1);
            scanf(" %f",&angvis);
            
            if(fabs(angvis) > 45){    //verifica se o modulo do valor digitado pra o angulo de visada esta no limite
                while(fabs(angvis) > 45){
                    fflush(stdin);
                    printf("Digite o angulo de visada %d: ",i+1);
                    scanf(" %f",&angvis);
                    
                    if(fabs(angvis) < 45){
                        break;
                    }
                }
            }
            
            
            if((-45 < angvis) && (angvis < 0)){
                ang = -1 * ang;
            }
            
            
            printf("\n\n");
            
            //radianos = (angulo * 3.1415)/180;       //transforma o angulo em radianos
            
            alcH = ((vel * vel) * (cos(ang) * sin(ang))/g);          //alcance horizontal do projÈtil
            alcV = ((vel * vel) * (sin(ang) * sin(ang)))/(2*g);        //alcance vertical do projÈtil
            
            distpontos = sqrt(pow(x-alcH,2) + pow(y-alcV,2)); //calcula distancia do alvo e onde o projÈtil atingiu
            //distpontos = sqrt(((x-alcancehorizontal) * (x-alcancehorizontal))   + ((y-alcancevertical) * (y-alcancevertical)));
            
            //DISTRIBUI OS PONTOS PARA O ATACANTE E O DEFENSOR
            if(distpontos == 0){
                pontuacaoatacante += 1000;
            }else{
                if(distpontos < 0 && dist < 1){
                    pontuacaoatacante += 500;
                    pontuacaodefensor += 500;
                }else{
                    if(distpontos > 1 && distpontos < 3){
                        pontuacaoatacante += 200;
                        pontuacaodefensor += 100;
                    }else{
                        if(distpontos > 3 && distpontos < 5){
                            pontuacaoatacante += 100;
                            pontuacaodefensor += 50;
                        }else{
                            if(distpontos > 5){
                                pontuacaoatacante += 0;
                                pontuacaodefensor += 20;
                            }
                        }
                    }
                }
            }
        }
        
        printf("Tabela final da pontuacao:  \n");
        printf("Atacante:\t%d\n",pontuacaoatacante);
        printf("Defensor:\t%d\n\n\n",pontuacaodefensor);
        
        do{
            printf("Deseja continuar? \n");
            printf("1- Sim\n");
            printf("2- Nao\n");
            printf("Digite a sua opcao: ");
            scanf("%d",&op);
            
            if(op == 1){
                
            }else{
                if(op == 2){
                    
                    printf("\n                 --------------------------------------------------------------------------------- \n");
                    printf("\t\t| Obrigado por usar o simulador de projeteis!                                     |\n");
                    printf("\t\t| Programa criado para o exercicio Dx02 de CIC 510 - Fund. de Fisica para Comp.   |\n");
                    printf("                | ------------------------------------------------------------------------------- |\n");
                    printf("\t\t| Desenvolvido por:                                                               |\n");
                    printf("\t\t| Rafael Greca Vieira - 2018000434                                                |\n");
                    printf("\t\t| Leonardo Vieira Ferreira - 2018009799                                           |\n");
                    printf("                 --------------------------------------------------------------------------------- \n");
                    printf("Pressione qualquer tecla para sair: \n");
                    
                    exit(0);
                }
            }
            
        }while(op < 1 || op > 3);
        
    }while(op == 1);    //se op==1, o programa ser· zerado e executado novamente
    


    
    printf("\n     █████╗ ██╗    ██╗   ██╗ ██████╗     ███████╗██████╗ ██████╗  █████╗ ██████╗  ██████╗\n");
    printf("    ██╔══██╗██║    ██║   ██║██╔═══██╗    ██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔═══██╗\n");
    printf("    ███████║██║    ██║   ██║██║   ██║    █████╗  ██████╔╝██████╔╝███████║██║  ██║██║   ██║\n");
    printf("    ██╔══██║██║    ╚██╗ ██╔╝██║   ██║    ██╔══╝  ██╔══██╗██╔══██╗██╔══██║██║  ██║██║   ██║\n");
    printf("    ██║  ██║███████╗╚████╔╝ ╚██████╔╝    ███████╗██║  ██║██║  ██║██║  ██║██████╔╝╚██████╔╝\n");
    printf("    ╚═╝  ╚═╝╚══════╝ ╚═══╝   ╚═════╝     ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝  ╚═════╝\n\n");

    printf("\n     █████╗ ██╗    ██╗   ██╗ ██████╗      █████╗ ████████╗██╗███╗   ██╗ ██████╗ ██╗██████╗  ██████╗\n");
    printf("    ██╔══██╗██║    ██║   ██║██╔═══██╗    ██╔══██╗╚══██╔══╝██║████╗  ██║██╔════╝ ██║██╔══██╗██╔═══██╗\n");
    printf("    ███████║██║    ██║   ██║██║   ██║    ███████║   ██║   ██║██╔██╗ ██║██║  ███╗██║██║  ██║██║   ██║\n");
    printf("    ██╔══██║██║    ╚██╗ ██╔╝██║   ██║    ██╔══██║   ██║   ██║██║╚██╗██║██║   ██║██║██║  ██║██║   ██║\n");
    printf("    ██║  ██║███████╗╚████╔╝ ╚██████╔╝    ██║  ██║   ██║   ██║██║ ╚████║╚██████╔╝██║██████╔╝╚██████╔╝\n");
    printf("    ╚═╝  ╚═╝╚══════╝ ╚═══╝   ╚═════╝     ╚═╝  ╚═╝   ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═════╝  ╚═════╝\n\n");

    
    return 0;
}









