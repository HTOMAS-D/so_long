#include "so_long.h"

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
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "So Long");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i != 750)
	{
		my_mlx_pixel_put(&img, i, 200, 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
