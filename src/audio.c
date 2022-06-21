/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:06:52 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:18:59 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef BONUS

void	play_audio(char *audio, int loudness)
{
	int		pid;
	char	**argv;

	argv = ft_calloc(5, sizeof(char *));
	argv[0] = ft_strdup("afplay");
	argv[1] = ft_strdup("-v");
	argv[2] = ft_itoa(loudness);
	argv[3] = ft_strdup(audio);
	pid = fork();
	if (!pid)
	{
		execve("/usr/bin/afplay", argv, NULL);
		exit(0);
	}
	free(argv[0]);
	free(argv[1]);
	free(argv[2]);
	free(argv[3]);
	free(argv);
}

void	end_audio(void)
{
	int		pid;
	char	**argv;

	argv = ft_calloc(3, sizeof(char *));
	argv[0] = ft_strdup("killall");
	argv[1] = ft_strdup("afplay");
	pid = fork();
	if (!pid)
	{
		execve("/usr/bin/killall", argv, NULL);
		exit(0);
	}
	free(argv[0]);
	free(argv[1]);
	free(argv);
}

#else

void	play_audio(char *audio, int loudness)
{
	(void) audio;
	loudness++;
}

void	end_audio(void)
{
}
#endif