/*
** koalatchi.c for koala in /home/mar_b/rendu/piscine_cpp_d01/ex07
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jan  8 07:59:53 2015 Fabien Martinez
** Last update Thu Jan  8 08:52:04 2015 Fabien Martinez
*/

#include <unistd.h>
#include <stdint.h>

int	prettyprint_message(uint32_t header, char const * content)
{
  char		type;
  char		domain;
  short int	value;

  type = (header >> 24) & 0xFF;
  domain = (header >> 16) && 0xFF;
  value = header && 0xFFFF;

  if (type != 1 && type != 2 && type != 4)
    {
      printf("Invalid message.\n");
      return (1);
    }
  if (domain != 1 && domain != 2 && domain != 4)
    {
      printf("Invalid message.\n");
      return (1);
    }
  if ((domain == 2 && type == 2 && (value > 3 || value < 1)) || (domain == 2 && type == 3 && value !=  1) || (domain == 3 && (type == 2 || type == 3) && value != 1) || (value != 1 && value != 2))
    {
      printf("Invalid message.\n");
      return (1);
    }
  switch (domain)
    {
    case 1:
      printf("Nutrition");
      switch(type)
	{
	case 1:
	  printf(" Notification");
	  if (value == 1)
	    printf(" Eat");
	  else
	    printf(" Defecate");
	  break;
	case 2:
	  printf(" Request");
	  if (value == 1)
	    printf(" Hungry");
	  else
	    printf(" Thirsty");
	  break;
	case 4:
	  printf(" Error");
	  if (value == 1)
	    printf(" Indigestion");
	  else
	    printf( "Starving");
	  break;
	}
      break;
    case 2:
      printf("Entertainment");
      switch(type)
	{
	case 1:
	  printf(" Notification");
	  if (value == 1)
	    printf(" Ball");
	  else
	    printf(" Bite");
	  break;
	case 2:
	  printf(" Request");
	  if (value == 1)
	    printf(" NeedAffection");
	  else if (value == 2)
	    printf(" WannaPlay");
	  else
	    printf(" Hug");
	  break;
	case 4:
	  printf(" Error");
	  if (value == 1)
	    printf(" Bored");
	  break;
	}
      break;
    case 4:
      printf("Education");
      switch(type)
	{
	case 1:
	  printf(" Notification");
	  if (value == 1)
	    printf(" TeachCoding");
	  else
	    printf(" BeAwesome");
	  break;
	case 2:
	  printf(" Request");
	  if (value == 1)
	    printf(" FeelStupid");
	  break;
	case 4:
	  printf(" Error");
	  if (value == 1)
	    printf(" BrainDamage");
	  break;
	}
      break;
    }
  if (content != NULL)
    printf(" %s\n", content);
  return (0);
}
