#include "../includes/lem_in.h"
//#include "../includes/ft_printf.h"

int main(void)
{
    t_rooms *qwe;
    t_links *za_sho;
    qwe = NULL;
    za_sho = NULL;

	g_room_id = 1;
	_ERROR_NOTIS_SET(set_rooms_and_links(&qwe, &za_sho));
	return 0;
}