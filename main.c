#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int a = 53;

    printf("__%d\n", ft_printf("%x", a));
    return (0);
}