//
//  lancamento.c
//  Trab_2
//
//  Created by José Luiz Junior on 04/04/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include "lancamento.h"


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

float dalvo(float o){
    
    
    return 0.0;
}
