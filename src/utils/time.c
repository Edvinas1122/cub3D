/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:06:37 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:06:38 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long long	set_time(void)
{
	struct timeval	time;
	long long		time_stamp;

	gettimeofday(&time, NULL);
	time_stamp = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time.tv_usec);
}
