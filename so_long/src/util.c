#include "so_long.h"

int	so_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *ch)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(ch) + 1));
	if (!tmp)
		so_error("fail malloc");
	ft_strlcpy(tmp, ch, ft_strlen(ch) + 1);
	return (tmp);
}

void	ft_putchar(char n)
{
	write(1, &n, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
	}	
}
