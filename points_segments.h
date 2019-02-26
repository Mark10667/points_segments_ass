#ifndef POINTS_SEGMENTS_H
#define POINTS_SEGMENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void * pointone, const void * pointtwo);
int ps_qsort(int s, int p, int** segments, int* points);

void print_array(int *arr, int size);
void print_array_2D(int **arr, int rows, int cols);

int ps_naive(int s, int p, int** segments, int* points);

extern int* q_result;
extern int* n_result;

#endif
