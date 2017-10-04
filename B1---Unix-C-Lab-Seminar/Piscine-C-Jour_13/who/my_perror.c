/*
** my_perror.c for my_perror.c in /home/mar_b/rendu/Piscine-C-Jour_13/cat
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Mar 26 14:53:32 2014 Fabien Martinez
** Last update Wed Mar 26 17:53:40 2014 Fabien Martinez
*/

#include "my.h"
#include "my_perror.h"

void	my_print_error(int i, char *path)
{
  void	(*my_fun_error[7])(int);
  int	count;

  count = 0;
  while (i >= 22)
    {
      count += 1;
      i -= 22;
    }
  my_fun_error[0] = my_part1;
  my_fun_error[1] = my_part2;
  my_fun_error[2] = my_part3;
  my_fun_error[3] = my_part4;
  my_fun_error[4] = my_part5;
  my_fun_error[5] = my_part6;
  my_fun_error[6] = my_part7;
  my_putstr(path);
  my_putstr(" : ");
  my_fun_error[count](i);
  my_putchar('\n');
}

void	my_part1(int i)
{
  char	*tab[23];

  tab[0] = "Success";
  tab[1] = "Operation not permitted";
  tab[2] = "No such file or directory";
  tab[3] = "No such process";
  tab[4] = "Interrupted system call";
  tab[5] = "Input/output error";
  tab[6] = "No such device or address";
  tab[7] = "Argument list too long";
  tab[8] = "Exec format error";
  tab[9] = "Bad file descriptor";
  tab[10] = "No child processes";
  tab[11] = "Resource temporarily unavailable";
  tab[12] = "Cannot allocate memory";
  tab[13] = "Permission denied";
  tab[14] = "Bad address";
  tab[15] = "Block device required";
  tab[16] = "Device or resource busy";
  tab[17] = "File exists";
  tab[18] = "Invalid cross-device link";
  tab[19] = "No such device";
  tab[20] = "Not a directory";
  tab[21] = "Is a directory";
  my_putstr(tab[i]);
}

void	my_part2(int i)
{
  char	*tab[23];

  tab[0] = "Invalid argument";
  tab[1] = "Too many open files in system";
  tab[2] = "Too many open files";
  tab[3] = "Inappropriate ioctl for device";
  tab[4] = "Text file busy";
  tab[5] = "File too large";
  tab[6] = "No space left on device";
  tab[7] = "Illegal seek";
  tab[8] = "Read-only file system";
  tab[9] = "Too many links";
  tab[10] = "Broken pipe";
  tab[11] = "Numerical argument out of domain";
  tab[12] = "Numerical result out of range";
  tab[13] = "Resource deadlock avoided";
  tab[14] = "File name too long";
  tab[15] = "No locks available";
  tab[16] = "Function not implemented";
  tab[17] = "Directory not empty";
  tab[18] = "Too many levels of symbolic links";
  tab[19] = "Unknown error 41";
  tab[20] = "No message of desired type";
  tab[21] = "Identifier removed";
  my_putstr(tab[i]);
}

void	my_part3(int i)
{
  char	*tab[23];

  tab[0] = "Channel number out of range";
  tab[1] = "Level 2 not synchronized";
  tab[2] = "Level 3 halted";
  tab[3] = "Level 3 reset";
  tab[4] = "Link number out of range";
  tab[5] = "Protocol driver not attached";
  tab[6] = "No CSI structure available";
  tab[7] = "Level 2 halted";
  tab[8] = "Invalid exchange";
  tab[9] = "Invalid request descriptor";
  tab[10] = "Exchange full";
  tab[11] = "No anode";
  tab[12] = "Invalid request code";
  tab[13] = "Invalid slot";
  tab[14] = "Unknown error 58";
  tab[15] = "Bad font file format";
  tab[16] = "Device not a stream";
  tab[17] = "No data available";
  tab[18] = "Timer expired";
  tab[19] = "Out of streams resources";
  tab[20] = "Machine is not on the network";
  tab[21] = "Package not installed";
  my_putstr(tab[i]);
}

void	my_part4(int i)
{
  char	*tab[23];

  tab[0] = "Object is remote";
  tab[1] = "Link has been severed";
  tab[2] = "Advertise error";
  tab[3] = "Srmount error";
  tab[4] = "Communication error on send";
  tab[5] = "Protocol error";
  tab[6] = "Multihop attempted";
  tab[7] = "RFS specific error";
  tab[8] = "Bad message";
  tab[9] = "Value too large for defined data type";
  tab[10] = "Name not unique on network";
  tab[11] = "File descriptor in bad state";
  tab[12] = "Remote address changed";
  tab[13] = "Can not access a needed shared library";
  tab[14] = "Accessing a corrupted shared library";
  tab[15] = ".lib section in a.out corrupted";
  tab[16] = "Attempting to link in too many shared libraries";
  tab[17] = "Cannot exec a shared library directly";
  tab[18] = "Invalid or incomplete multibyte or wide character";
  tab[19] = "Interrupted system call should be restarted";
  tab[20] = "Streams pipe error";
  tab[21] = "Too many users";
  my_putstr(tab[i]);
}
