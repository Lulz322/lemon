#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include <stdlib.h>
#include "../libft/includes/libft.h"
#include "ft_printf.h"

enum	e_bool { false, true };

# define _BOOL	typedef enum e_bool bool

_BOOL;

#define _ERROR_NOTIS_SET(ex) if(ex == false) {ft_printf("MRED(ERROR IN ROMMS/LINKS)\n");return(false);}
#define _ERROR_NOTIS_LINE(ex) if(ex == false) {ft_printf("MRED(ERROR IN LINE)\n");return(false);}
#define _ERROR_NOTIS_ROOM(ex) if(ex == false) {ft_printf("MRED(ERROR IN ROOM)\n");return(false);}
#define _ERROR_MALLOC(ex)	if(ex == NULL) {ft_printf("MRED(ERROR IN ALLOCATION MEMMORY)\n");exit(0);}

typedef struct  s_global
{
	int	atns;
	int room_counter;
	int link_counter;
	int counter;
	int first_room;
	int last_room;
}	t_global;

t_global g_global;

int g_room_id;

typedef struct  s_rooms
{
	struct s_rooms *next;
	struct s_rooms *prev;
	char	*name;
	int 	x_coord;
	int 	y_coord;
	int 	room_id;
	int 	index;
	int		mode; // 0 - similar room | 1 - start | 2 - end
}     t_rooms;


typedef struct	s_truba
{
	struct	s_truba *next;
	struct  s_truba *prev;
	int			room_id;
}				t_truba;

typedef struct s_way
{
	struct s_way 	*next;
	struct s_way 	*prev;
	int				len;
	t_truba			*list;
	bool			is_end;
}					t_way;


typedef struct s_links
{
	struct s_links *next;
	struct s_links *prev;
	int				first_room_id;
	int 			second_room_id;
}				t_links;
t_links *g_links;

bool set_rooms_and_links(t_rooms **rooms, t_links **links);
void add_data(t_rooms **start, char *data, int x, int y);
#endif //LEM_IN_LEM_IN_H
