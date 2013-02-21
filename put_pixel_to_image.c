/*
** put_pixel_to_image.c for 106bombyx in /home/corjon_l//projets/All
** 
** Made by lysandre corjon
** Login   <corjon_l@epitech.net>
** 
** Started on  Thu Feb 21 18:41:29 2013 lysandre corjon
** Last update Thu Feb 21 18:41:32 2013 lysandre corjon
*/

#include <stdlib.h>
#include <mlx.h>
#include "bombyx.h"

int	gere_expose(t_img *img)
{
  mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
  return (0);
}

int	gere_key(int keycode, t_img *img)
{
  if (keycode == 65307)
    {
      my_putstr("Echap !\n");
      exit(0);
    }
  else if (keycode == 65362)
    {
      gere_expose(img);
    }
  else if (keycode == 65364)
    {
      gere_expose(img);
    }
  return (0);
}

void	put_pixel_to_image(t_img *ptr, int x, int y, int color)
{
  int	i;

  if (ptr->endian == 0)
    {
      i = (ptr->sizeline * y) + (x * (ptr->bpp / 8));
      ptr->data[i] = mlx_get_color_value(ptr->mlx_ptr, color);
      ptr->data[i + 1] = mlx_get_color_value(ptr->mlx_ptr, color >> 8);
      ptr->data[i + 2] = mlx_get_color_value(ptr->mlx_ptr, color >> 16);
    }
  else
    {
      i = (ptr->sizeline * y) + (x * (ptr->bpp / 8));
      ptr->data[i] = mlx_get_color_value(ptr->mlx_ptr, color >> 16);
      ptr->data[i + 1] = mlx_get_color_value(ptr->mlx_ptr, color >> 8);
      ptr->data[i + 2] = mlx_get_color_value(ptr->mlx_ptr, color);
    }
}
