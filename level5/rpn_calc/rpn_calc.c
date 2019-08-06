#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
//ah i hate this one
int	ispace(char c)
{
	return (c == ' ');//you need help if you dont know what this does
}

int	isop(char c)
{
	return (c == '+' ||
			c == '-' ||
			c == '/' ||
			c == '*' ||
			c == '%');//nesting if statements in return
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
	return (i % j);//convert chars to arithmetic and returns result
}

int	rpn(char *s)
{
	int		i;//counter
	int		stk[100];//stack. this technically limits the program as it doesnt use link lists for the stack but if you haave over 100 numbers in your sum and youre using this calculator youre in the wrong field of study

	i = 0;//where all good counters start
	stk[0] = 0;//initialise stk[0] to 0 as we will use it as the counter for the stack, meaning stk[stk[0]] is the top of the stack
	while (s[i])
	{
		if (!isop(s[i]) && !ispace(s[i]) && !isnum(s[i]))//check invalid input
			return (0);
		if (isop(s[i]))//check if we have an operator
		{
			if (!(s[i] == '-' && isnum(s[i + 1])))//checks if we have a negative number or operator
			{
				if (stk[0] < 2)//if theres only 1 num on stackwe cant do an operation
					return (0);
				stk[0]--;//pop the stack since we "deleting" 2 and "adding" 1 to the stack
				if ((s[i] == '/' || s[i] == '%') && stk[stk[0] + 1] == 0)//testing for /or% by zero cause thats not a thing
					return (0);
				stk[stk[0]] = op(stk[stk[0]], stk[stk[0] + 1], s[i]);//finally after all that error checking do the operation on the top 2 nums on the stack with the number lower on the stack being before the operator
			}
			i++;
		}
		if (isnum(s[i]))
		{
			stk[0]++;//if we have a number increase stack count
			stk[stk[0]] = atoi(s + i);//push onto the stack. atoi takes care of the number length and all that. catches an error by being invalid char since atoi stops after digits
			if (s[i - 1] == '-')//negatify the number if it so be
				stk[stk[0]] *= -1;
			while (isnum(s[i]))//catch up our counter to the end of the number
				i++;
		}
		if (ispace(s[i]))//skip over spaces
			i++;
	}
		if (stk[0] != 1)//there should only be 1 number in the stack after a good string
			return (0);
}

int	main(int ac, char **av)
{
	int i;
	
	i = (ac != 2) ? 0 : rpn(av[1]);
	(i) ? printf("Error\n") : printf("%i\n", i);//newline for graphical goodness
	return (0);
}
