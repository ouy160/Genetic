/* 
 * File:   main.c
 * Author: alex
 *
 * Created on 7 marzo 2012, 16.28
 */
#define POP_DIM 100
#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

/*
 * 
 */
int main(int argc, char** argv) {
    /* Dichiarazione variabili */
    
    FILE *fp;
    int row,col,pieces,i,j;
    int **colors,line[4];
    char ***solution;
    population_t *population;

    
    /*Lettura dimensioni della matrice e allocazione del vettore dei pezzi*/
    fp=fopen("pieces_05x05.txt","r");
    fscanf(fp,"%d%d",&row,&col);
    pieces=row*col;
    colors=build_colors(pieces);
    
    /*Riempimento matrice dei pezzi con i colori dei singoli pezzi*/
    
    for(i=0;i<pieces;i++){
        fscanf(fp,"%d%d%d%d",&line[0],&line[1],&line[2],&line[3]);
        for(j=0;j<4;j++){
                colors[i][j]=line[j];
        }
    }
    
    /*test_colors(colors,pieces);*/
    population=build_population(colors,pieces,row,col);
    solution=(char ***)build_solution(colors,row,col);
    random_solution_generation(solution,colors,pieces,row,col);
    test_solution(solution,row,col);
    
    
    
    return (EXIT_SUCCESS);
}
