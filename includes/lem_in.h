#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include <stdlib.h>
#include "../libft/includes/libft.h"

enum	e_bool { false, true };

# define _BOOL	typedef enum e_bool bool

_BOOL;

#define _ERROR_NOTIS(ex) if(ex == false) {return(ft_printf("MRED(ERROR)\n"));}

typedef struct  s_global
{
	int	atns;
	int room_counter;
	int link_counter;
}	t_global;

t_global g_global;


typedef struct  s_rooms
{
	struct s_rooms *next;
	struct s_rooms *prev;
	char	*name;
	int 	x_coord;
	int 	y_coord;
	bool	link;
}     t_rooms;

bool	set_cvars(void);
t_rooms  *create_elem(char *data, int x, int y);
void add_data(t_rooms **start, char *data, int x, int y);
void print_data(t_rooms *begin);
void free_list(t_rooms *begin);



#endif //LEM_IN_LEM_IN_H
