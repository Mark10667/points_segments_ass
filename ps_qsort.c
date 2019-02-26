#include "points_segments.h"

struct point{
  int position;
  int index;
  char* name;
}Point;

int compare(const void * pointone, const void * pointtwo){
  struct point * a = (struct point *)pointone;
  struct point * b = (struct point *)pointtwo;
  int c = a->position;
  int d = b->position;
  return c - d;
}

int ps_qsort(int s, int p, int** segments, int* points){
  struct point* point_arr = malloc(sizeof(Point)*(s*2 + p));
  int count = 0;
  for(int i = 0; i < p; i++){
    (point_arr[i]).position = points[i];
    (point_arr[i]).index = i;
    (point_arr[i]).name = "point";
  }
  for(int i = 0; i < s; i++){
    (point_arr[i+p]).position = segments[i][0];
    (point_arr[i]).index = i;
    (point_arr[i+p]).name = "start";
  }
  for(int i = 0; i < s; i++){
    (point_arr[i+p+s]).position = segments[i][1];
    (point_arr[i]).index = i;
    (point_arr[i+p+s]).name = "end";
  }

  // puts("get here 3");
  // for (int i=0; i < s*2 + p; i++){
  //   puts("get here 4");
  //   printf("%d %s",point_arr[i].position, point_arr[i].name);
  // }
  qsort(point_arr, s*2 + p, sizeof(Point), compare);

  // for (int i=0; i < s*2 + p; i++){
  //   puts("get here 5");
  //   printf("%d %s",point_arr[i].position, point_arr[i].name);
  // }
  for(int i = 0; i < s*2 + p; i++){
    if(strcmp(((point_arr[i]).name), "start") == 0){
      count++;
    }
    if(strcmp(((point_arr[i]).name), "point") == 0){
      q_result[(point_arr[i]).index] = count;
    }
    if(strcmp(((point_arr[i]).name), "end") == 0){
      count--;
    }
  }
  // for (int i=0; i < p; i++){
  //   //puts("get here 6");
  //   printf("In qsort, The point %d contains %d segments\n", i+1, q_result[i]);
  // }
  //puts("\n");
  free(point_arr);

  return 0;
}
