#include "points_segments.h"

int* ps_naive(int s, int p, int** segments, int* points){
  int count = 0;
  int* naive_arr = malloc(sizeof(int) * p);
  for(int i = 0; i < p; i++){
    for(int j = 0; j < s; j++){
      if(points[i] >= segments[j][0] && points[i] <= segments[j][1]){
        count++;
      }
    }
    naive_arr[i] = count;
    count = 0;
  }
  return naive_arr;
}
