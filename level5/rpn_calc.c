#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

int	ispace(char c)
{
	return (c == ' ');
}

int	isop(char c)
{
	return (c == '+' ||
			c == '-' ||
			c == '/' ||
			c == '*' ||
			c == '%');
}

int isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int	op(int i, int j, char c)
{
	if (c == '+')
		return (i + j);
	if (c == '-')
		return (i - j);
	if (c == '*')
		return (i * j);
	if (c == '/')
		return (i / j);
	return (i % j);
}

int	main(int ac, char **av)
{
	char	*s;
	int		i;
	int		stk[100];

	if (ac != 2)
	{
		printf("Error\n");
		return (0);
	}
	i = 0;
	s = av[1];
	stk[0] = 0;
	while (s[i])
	{
		if (!isop(s[i]) && !ispace(s[i]) && !isnum(s[i]))
		{
			printf("Error\n");
			return (0);
		}
		if (isop(s[i]))
		{
			if (!(s[i] == '-' && isnum(s[i + 1])))
			{
				if (stk[0] < 2)
				{
					printf("Error\n");
					return (0);
				}
				stk[0]--;
				if ((s[i] == '/' || s[i] == '%') && stk[stk[0] + 1] == 0)
				{
					printf("Error\n");
					return (0);
				}
				stk[stk[0]] = op(stk[stk[0]], stk[stk[0] + 1], s[i]);
			}
			i++;
		}
		if (isnum(s[i]))
		{
			stk[0]++;
			stk[stk[0]] = atoi(s + i);
			if (s[i - 1] == '-')
				stk[stk[0]] *= -1;
			while (isnum(s[i]))
				i++;
		}
		if (ispace(s[i]))
			i++;
	}
	if (stk[0] != 1)
	{
		printf("Error\n");
		return (0);
	}
	printf("%i\n", stk[1]);
	return (0);
}
