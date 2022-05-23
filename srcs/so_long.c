#include "so_long.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	t_vars	vars;
	t_data	img;
	int i;
	
	i =250;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIND_W, WIND_H, "So Long");
	img.img = mlx_new_image(vars.mlx, WIND_W, WIND_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i != 750)
	{
		my_mlx_pixel_put(&img, i, 200, 0x00FF0000);
		i++;
	}
	ft_printf("\n\e[0;31mWRONG NUMBER OF ARGUMENTS!\n\n");
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
