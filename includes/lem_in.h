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
	bool	index_check;
	bool	link;
	int		mode; // 0 - similar room | 1 - start | 2 - end
}     t_rooms;


typedef struct	s_truba
{
	struct	s_truba *next;
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

bool	set_cvars(void);
t_rooms  *create_elem(char *data, int x, int y);
void add_data(t_rooms **start, char *data, int x, int y);
void print_data(t_rooms *begin);
void free_list(t_rooms *begin);
void    change_mode(t_rooms *qwe,int mode);
void add_data_link(t_links **start, int x, int y);
void print_links(t_links *begin);
void	find_way(t_rooms *rooms, t_links *links);



#endif //LEM_IN_LEM_IN_H
