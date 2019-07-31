#include <unistd.h>

int mtch(char c, char x)
{
    if (c == '(' && x == ')')
        return (1);
    if (c == '{' && x == '}')
        return (1);
    if (c == '[' && x == ']')
        return (1);
    return (0);
}

int brack(char *s)
{
    int stk[100];
    int i;

    i = -1;
    stk[0] = 0;
    while (s[++i])
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stk[++stk[0]] = s[i];
        else if (mtch(stk[stk[0]], s[i]))
            stk[0]--;
        else if ((s[i] == ')' || s[i] == ']' || s[i] == '}') && !stk[0])
            return (0);
    if (stk[0])
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac)
        (brack(av[i++])) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
    if (ac == 1)
        write (1, "\n", 1);
    return (0);
}