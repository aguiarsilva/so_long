/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:20:18 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/18 11:20:18 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

long   ft_atol(const char *str)
{
    long        res;
    int         sign;

    res = 0;
    sign = 1;
    while((*str == 32) || (*str >= 9 && *str <= 13))
        str++;
    if ((*str == '-') || (*str == '+'))
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return (res * sign);
}