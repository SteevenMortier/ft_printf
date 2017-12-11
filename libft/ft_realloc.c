//
// Created by Steeven MORTIER on 11/30/17.
//

#include <libft.h>

void    *ft_realloc(void **ptr, size_t oldsize, size_t newsize)
{
        void    *freshptr;

        if (!(freshptr = ft_memalloc(sizeof(char) * newsize)))
                return (NULL);
        if (*ptr)
        {
                ft_memcpy(freshptr, *ptr, oldsize);
                ft_memdel(ptr);
        }
        return (freshptr);
}

