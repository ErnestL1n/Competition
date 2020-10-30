#include <stdio.h>

int main()
{
  int wind_speed;

  scanf("%d", &wind_speed);

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