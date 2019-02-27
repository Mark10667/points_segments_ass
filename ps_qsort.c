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
  if(c == d){
    if(strcmp(a->name, "start") == 0 ){
      return -1;
    }
    if(strcmp(b->name, "start") == 0 ){
      return 1;
    }
    if(strcmp(a->name, "end") == 0  ){
      return 1;
    }
    if(strcmp(b->name, "end") == 0 ){
      return -1;
    }
  }
  return c - d;
}

int* ps_qsort(int s, int p, int** segments, int* points){
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


  qsort(point_arr, s*2 + p, sizeof(Point), compare);

  int* qsort_arr = malloc(sizeof(int)*p);
  for(int i = 0; i < s*2 + p; i++){
    if(strcmp(((point_arr[i]).name), "start") == 0){
      count++;
    }
    if(strcmp(((point_arr[i]).name), "point") == 0){
      qsort_arr[(point_arr[i]).index] = count;
    }
    if(strcmp(((point_arr[i]).name), "end") == 0){
      count--;
    }
  }

  free(point_arr);

  return qsort_arr;
}
