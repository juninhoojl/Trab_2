//
//  main.c
//  Trab_2
//
//  Created by José Luiz Junior on 28/03/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//Para considerar o angulo -45 e + 45
//Recalcular a distancia minima que precisa ser atingida



//Retorna distancia maxima
float distancia(float v0, float v, float a);

//Retorna
float vx(float v, float o);
float vy(float v, float o);
float dmax(float v0, float o);
float dalvo(float o);

int main(int argc, const char * argv[]) {
    
    
    printf("Valor = %f\n", dmax(300, 15));
    
    
    return 0;
}


float dalvo(float o){
    
    
    
    
    return 0.0;
}






float distancia(float v0, float v, float a){
    float dist = (pow(v0, 2) - pow(v, 2))/(2*a);
    return dist;
}

float dmax(float v0, float o){
    return (pow(v0, 2)*(sin(2*((o/180)*M_PI))))/9.8;
}

float vy(float v, float o){
    return v*sin(((o/180)*M_PI));
}

float vx(float v, float o){
    return v*cos(((o/180)*M_PI));
}
