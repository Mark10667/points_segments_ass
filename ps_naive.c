#include "points_segments.h"

int ps_naive(int s, int p, int** segments, int* points){
  int count = 0;
  for(int i = 0; i < p; i++){
    for(int j = 0; j < s; j++){
      if(points[i] >= segments[j][0] && points[i] <= segments[j][1]){
        count++;
      }
    }
    n_result[i] = count;
    count = 0;
  }
  // for (int i=0; i < p; i++){
  //   //puts("get here 6");
  //   printf("In naive, The point %d contains %d segments\n", i+1, n_result[i]);
  // }
  return 0;
}
