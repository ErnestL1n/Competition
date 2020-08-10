//題2:https://judge.csie.ncku.edu.tw/problems/5
//模擬題
#include <stdio.h>

int main()
{
  int wind_speed;
  int legel=0;
  while(legel==0){
  scanf("%d", &wind_speed);
  if(1<=wind_speed<=100)
	  legel=1;
  }

  if(wind_speed < 1)
    printf("Calm\n");
  else if(wind_speed < 4)
    printf("Light air\n");
  else if(wind_speed < 28)
    printf("Breeze\n");
  else if(wind_speed < 48)
    printf("Gale\n");
  else if(wind_speed <= 63)
    printf("Storm\n");
  else 
    printf("Hurricane\n");

  return 0;
}