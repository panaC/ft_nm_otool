#include <ft_printf.h>
#include "common.h"

int       s_swap(t_boo state)
{
  static t_boo   value = false;

  if (state != undef)
    value = state;
  return (value);
}

int       s_b64(t_boo state)
{
  static t_boo   value = false;

  if (state != undef)
  {
    value = state;
    ft_printf("b64:%d", value);
  }
  return (value);
}