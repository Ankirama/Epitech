/*
** my_perror2.c for my_perror in /home/mar_b/rendu/Piscine-C-Jour_13/cat
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Mar 26 16:06:24 2014 Fabien Martinez
** Last update Wed Mar 26 17:53:51 2014 Fabien Martinez
*/

#include "my.h"

void	my_part5(int i)
{
  char	*tab[23];

  tab[0] = "Socket operation on non-socket";
  tab[1] = "Destination address required";
  tab[2] = "Message too long";
  tab[3] = "Protocol wrong type for socket";
  tab[4] = "Protocol not available";
  tab[5] = "Protocol not supported";
  tab[6] = "Socket type not supported";
  tab[7] = "Operation not supported";
  tab[8] = "Protocol family not supported";
  tab[9] = "Address family not supported by protocol";
  tab[10] = "Address already in use";
  tab[11] = "Cannot assign requested address";
  tab[12] = "Network is down";
  tab[13] = "Network is unreachable";
  tab[14] = "Network dropped connection on reset";
  tab[15] = "Software caused connection abort";
  tab[16] = "Connection reset by peer";
  tab[17] = "No buffer space available";
  tab[18] = "Transport endpoint is already connected";
  tab[19] = "Transport endpoint is not connected";
  tab[20] = "Cannot send after transport endpoint shutdown";
  tab[21] = "Too many references: cannot splice";
  my_putstr(tab[i]);
}

void	my_part6(int i)
{
  char	*tab[23];

  tab[0] = "Connection timed out";
  tab[1] = "Connection refused";
  tab[2] = "Host is down";
  tab[3] = "No route to host";
  tab[4] = "Operation already in progress";
  tab[5] = "Operation now in progress";
  tab[6] = "Stale file handle";
  tab[7] = "Structure needs cleaning";
  tab[8] = "Not a XENIX named type file";
  tab[9] = "No XENIX semaphores available";
  tab[10] = "Is a named type file";
  tab[11] = "Remote I/O error";
  tab[12] = "Disk quota exceeded";
  tab[13] = "No medium found";
  tab[14] = "Wrong medium type";
  tab[15] = "Operation canceled";
  tab[16] = "Required key not available";
  tab[17] = "Key has expired";
  tab[18] = "Key has been revoked";
  tab[19] = "Key was rejected by service";
  tab[20] = "Owner died";
  tab[21] = "State not recoverable";
  my_putstr(tab[i]);
}

void	my_part7(int i)
{
  char	*tab[2];

  tab[0] = "Operation not possible due to RF-kill";
  tab[1] = "Memory page has hardware error";
  my_putstr(tab[i]);
}
