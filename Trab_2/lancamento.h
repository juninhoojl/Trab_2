//
//  lancamento.h
//  Trab_2
//
//  Created by José Luiz Junior on 04/04/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#ifndef lancamento_h
#define lancamento_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Para considerar o angulo -45 e + 45
//Recalcular a distancia minima que precisa ser atingida


//Retorna distancia maxima

//Retorna a distancia maxima que o projetil atingiu, e se atingiu pelo menos a distancia que o alvo esta, confere se a altura na distancia do alvo foi no intervalo certo (no caso, entre 0 e 300m)
float distancia(float v0, float v, float a);


float dmax(float v0, float o);

//Decompoe no eixo y
float vy(float v, float o);

//Decompoe no eixo x
float vx(float v, float o);


//Calcula a distancia que o projetil tem que atingir no minimo, mesmo que o alvo seja fixo (150m) no caso de colocar alguma angulacao lateral, -45 a 45. no caso
float dalvo(float o);

//Mudar escopo, mas tem que ter uma funcao que confere
// Se a altura na distancia do alvo foi ok
int acertou(int a);



#endif /* lancamento_h */
