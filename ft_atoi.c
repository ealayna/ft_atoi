void ft_katoi(char *s, int *i, int k)
{
    if (!(*s >= '0' && *s <= '9'))
        return ;
    k = *s - '0';
    *i = (*i) * 10 +  k;
    ft_katoi(s + 1, i, k);

}

size_t ft_spaces(char *s)
{
    return(*s == '\t' || *s == '\n' || *s == '\v' || *s == '\f' ||
           *s == '\r' || *s == ' ' ? 1 + ft_spaces(s + 1) : 0);
}

int ft_atoi(char *s)
{
    int i = 0;
    int k = 1;

    s += ft_spaces(s);
    if (*s == '-')
    {
        k = -1;
        ft_katoi(s + 1, &i, k);
    }
    else if (*s == '+')
        ft_katoi(s + 1, &i, k);
    else
        ft_katoi(s, &i, k);
    return(i * k);
}
