#include "lem_in.h"

void		in_queue_end(t_lem *farm, t_room *room)
{
	t_link		*elem;

	if (farm->queue != NULL)
	{
		while (farm->queue->next != NULL)
			farm->queue = farm->queue->next;
		elem = (t_link *)ft_memalloc(sizeof(t_link));
		farm->queue->next = elem;
		elem->rm = room;
	}
	else
	{
		farm->queue = (t_link *)ft_memalloc(sizeof(t_link));
		farm->queue->rm = room;
	}
	room->fl = 1;
}

t_room		*first_from_queue(t_lem *farm)
{
	t_link		*tmp_queue;
	t_room		*room;

	if (farm->queue == NULL)
		return (NULL);
	room = farm->queue->rm;
	tmp_queue = farm->queue->next;
	free(farm->queue);
	farm->queue = tmp_queue;
	return (room);
}

void		back_way(t_room *end, char *start)
{
	printf("way: ");
	while (ft_strcmp(end->nm, start) != 0)
	{
		printf("%s-", end->nm);
		end = end->way;
	}
	printf("%s\n", end->nm);
}

void		work_room(t_room *room, t_lem *farm)
{
	t_link		*link;

	link = room->link;
	while (link != NULL)
	{
		if (link->rm->fl == 0)
		{

			in_queue_end(farm, link->rm);
			link->rm->way = room;
			link->rm->level = room->level + 1;
		}
		link = link->next;
	}
}

void		show_queue(t_link *queue)
{
	while (queue != NULL)
	{
		printf("[%s] ", queue->rm->nm);
		queue = queue->next;
	}
	printf("\n");
}

int			bfs(t_lem *farm, t_room *end, t_room *room)
{
	room->level = 1;
	room->fl = 1;
	// printf("end---------------- %s\n", end->nm);
	// show_queue(end->link);
	printf("--------------: %s\n", end->nm);

	while (farm->queue || room)
	{
		printf("room: %s\n", room->nm);

		// if (room != end)
		// {
			work_room(room, farm);
		// }
		show_queue(farm->queue);
		if (room == end)
		{
			back_way(end, farm->start);
			return (1);
		}
		room = first_from_queue(farm);
	}
	printf("room: %p\n", room);
	return (0);
}
