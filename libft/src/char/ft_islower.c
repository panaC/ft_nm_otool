/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:14:14 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 12:17:42 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_islower(int c)
{
	if (c > 96 && c < 123)
		return (1);
	return (0);
}
