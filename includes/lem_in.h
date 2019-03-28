/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:42:13 by iruban            #+#    #+#             */
/*   Updated: 2019/03/27 14:42:15 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "stdlib.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# define ER_START			"\033[41m"
# define ER_END				"\033[40m"
# define F_WAY g_global.link_way
# define S_WAY g_global.no_link_way
# define ERROR(ex) {ft_printf("%s%s%s\n",ER_START,ex,ER_END);exit(0);};
# define _PARS(ex) {if (!ex){errrorrororo();}};
# define _AFLAG {if (g_global.second_algo == true){ta_nu_ladno();}}
# define _ERROR_NOTIS_SET(ex) if(!ex) {ERROR("ERROR IN ROMMS/LINKS")}
# define _ERROR_NOTIS_LINE(ex) if(!ex) {ERROR("MRED(ERROR IN LINE)")}
# define _ERROR_NOTIS_ROOM(ex) if(!ex) {ERROR("MRED(ERROR IN ROOM)")}
# define _ERROR_MALLOC(ex)	if(!(ex)) {ERROR("ERROR IN ALLOCATION MEMMORY")}
# define _ERROR_MSG {ft_printf("MRED(ERROR IN INPUT DATA)\n");exit(0);}
# define _ERROR_NOTIS_LINK(ex) if(!ex) {ERROR("ERROR IN ROOM")}
# define _ERROR_NOTIS_INDEX(ex) if(!ex) {ERROR("MRED(ERROR IN ROOM)")}
# define _ERROR_NOTIS_WAY(ex) if(!ex) {ERROR("MRED(ERROR IN WAY)");
# define DEL(ex) {delete_way(ex);return (set_way());};
# define CREATE(ex) {room = create_elem_room(ex);}
# define CHANGE {links->room->is_in_queue = true;links->room->prev_room = room;}
# define PRP_NEXT {reset_rooms_in_queue();}
# define R_U_R {reset_used_rooms();}
# define PREPARE(ex) {ex = create_list_of_rooms(g_global.end);PRP_NEXT}
# define CLEAR {reset_rooms_in_queue();R_U_R}
# define KOSTIL(ex) if (!ex){pustit_jukov(g_global.no_link_way);exit(0);};
# define DEL_AND_SET(ex, ex2) {ex2 = set_room(ex);free_queue(ex);}
# define _FIRST(ex) {while((ex = first_algo())){create_ways(&F_WAY, ex);}}
# define _SECOND(ex) {while((ex = second_algo())){create_ways(&S_WAY, ex);}}
# define CHANGE_TWO {g_global.ant_counter++;create_ant(way->way);}
# define ANTS(ex) {one_step();new_ants(ex);}
# define _SET_FIRST_WAY {if(!group_ways()){ERROR("ERROR")}};
# define _SET_SECOND_WAY {if(!group_ways_two()){ERROR("ERROR")}};
# define _SET_DATA(n1, n2) {set_cvars(n1, n2);check_first_last_room();}
# define _PRINT {if (set_eff(F_WAY) <= set_eff(S_WAY)){pustit_jukov(F_WAY);}}
# define _PRINT_T {if (set_eff(F_WAY) > set_eff(S_WAY)){pustit_jukov(S_WAY);}};
# define _PUSH {if (links->room->links->room != room){is_pushed = true;}};
# define _F_IF_YO(ex, ex1) {_ADD(ex, ex1);CHANGE;};
# define _ADD(ex, ex1) {add_room_in_queue(ex, ex1);};
# define _F_IF(ex, ex1, ex2, ex3) if(ex || !ex1){_ADD(ex2, ex3);CHANGE;_PUSH;}


enum	e_bool { false, true };

# define _BOOL	typedef enum e_bool bool

_BOOL;

int						g_room_id;

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	struct s_rooms		*links;
	struct s_room		*prev_room;
	bool				is_used;
	bool				is_in_queue;
}						t_room;

typedef struct			s_links
{
	struct s_links		*next;
	struct s_links		*prev;
	int					first_room_id;
	int					second_room_id;
}						t_links;

typedef struct			s_global_algo
{
	int					atns;
	int					room_counter;
	int					link_counter;
	int					counter;
	int					first_room;
	int					last_room;
	t_links				*save;
}						t_global_algo;

t_global_algo			g_global_algo;

typedef struct			s_rooms_algo
{
	struct s_rooms_algo	*next;
	struct s_rooms_algo	*prev;
	char				*name;
	int					x_coord;
	int					y_coord;
	int					room_id;
	int					index;
	int					mode;
}						t_rooms_algo;

typedef struct			s_rooms
{
	t_room				*room;
	struct s_rooms		*prev;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_ways
{
	t_rooms				*way;
	struct s_ways		*prev;
	struct s_ways		*next;
}						t_ways;
typedef struct			s_ants
{
	int					ant_id;
	t_rooms				*position;
	struct s_ants		*prev;
	struct s_ants		*next;
}						t_ants;

typedef struct			s_global
{
	int					ants;
	int					ant_counter;
	t_rooms				*ways;
	t_room				*start;
	t_room				*end;
	bool				color_mode;
	bool				print_pathes;
	bool				print_steps;
	bool				non_print;
	bool				second_algo;
	t_ways				*no_link_way;
	t_ways				*link_way;
	t_ants				*c_ants;
}						t_global;

t_global				g_global;

void					set_cvars(int mode, int i);
int						input_data(char **line);
t_room					*create_elem_room(char *line);
void					add_room_in_queue(t_rooms **list, t_room *node);
bool					create_room(t_rooms **list, t_room *node);
t_rooms					*create_list_of_rooms(t_room *first_node);
void					add_data(t_rooms_algo **start,
						char *data, int x, int y);
void					add_data_link(t_links **start, int x, int y);
void					change_mode(t_rooms_algo *qwe, int mode);
void					create_link(char *line, int i);
int						way_len(t_rooms *list);
void					delete_way(t_rooms *path);
void					create_ways(t_ways **list, t_rooms *path);
void					pustit_jukov(t_ways *qqq);
void					print_steps();
bool					set_rooms_and_links(t_rooms_algo **rooms,
						t_links **links);
void					print_pathes(t_ways *list);
void					print_total_steps(int total);
void					create_ant(t_rooms *room);
void					remove_ant(t_ants *ant);
t_rooms					*do_first_path();
t_rooms					*do_second_path();
t_ants					*create_list_of_ants(t_rooms *room);
void					reset_rooms_in_queue();
t_rooms					*first_algo();
void					first_algo_l(t_rooms *links,
						t_rooms **queue, t_room *prev);
void					second_algo_l(t_rooms *links,
						t_rooms **queue, t_room *prev);
t_rooms					*second_algo();
void					free_queue(t_rooms **way);
t_room					*set_room(t_rooms **way);
void					check_first_last_room(void);
void					rooms_mode(char *line, int *mode, int i);
int						set_eff(t_ways *list);
int						ta_nu_ladno(void);
int						find_mode_two(t_rooms_algo *rooms);
int						find_mode_one(t_rooms_algo *rooms);
void					print_data(t_rooms_algo *begin);
bool					set_indexes(t_links *links, t_rooms_algo *rooms);
int						check_comment(char *line);
void					check_errors_in_room(char *line, char **array);
void					check_room_for_index(t_rooms_algo **rooms,
						t_links **start,
						int save_id, int set_index);
void					color_on(int id);
bool					kostil(void);
bool					error_case(t_rooms *new, t_room *room);
bool					group_ways_two();
bool					group_ways();
void		reset_used_rooms(void);
#endif
