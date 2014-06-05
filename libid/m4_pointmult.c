static void	end(double* res)
{
	int	i;

	if (res[3] != 0)
	{
		i = 0;
		while (i < 4)
		{
			res[i] = res[i] / res[3];
			i = i + 1;
		}
	}

}

void		m4_pointmult(double* res, double point[4], double mat[4][4])
{
	int	i;
	int	j;
	double	val;

	i = 0;
	while (i < 4)
	{
		val = 0;
		j = 0;
		while (j < 4)
		{
			val = val + mat[i][j] * point[j];
			j = j + 1;
		}
		res[i] = val;
		i = i + 1;
	}
	end(res);
}
