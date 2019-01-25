#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include <stdlib.h>
#include "../libft/includes/libft.h"

enum	e_bool { false, true };

# define _BOOL	typedef enum e_bool bool

_BOOL;

#define _ERROR_NOTIS(ex) if(ex == false) {return(ft_printf("MRED(ERROR)\n"));}

typedef struct s_cvars_lem
{
	bool	start;
	bool	finish;
	int		ants;
}				t_cvars_lem;

t_cvars_lem g_cvars_lem;

bool	set_cvars(void);

#endif //LEM_IN_LEM_IN_H
