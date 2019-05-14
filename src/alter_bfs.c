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
	t_link		*tmp_queue;

	link = room->link;
	tmp_queue = farm->queue;
	while (link != NULL)
	{
		if (link->rm->fl == 0)
		{
			while (tmp_queue->next != NULL)
			{
				tmp_queue = tmp_queue->next;
				printf("tut\n");
			}
			tmp_queue->next = (t_link *)ft_memalloc(sizeof(t_link));
			tmp_queue->next->rm = link->rm;
			// in_queue_end(farm, link->rm);
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

int			bfs(t_lem *farm, t_room *end, t_room *start)
{
	t_link		*tmp_queue;

	start->level = 1;
	start->fl = 1;
	farm->queue = (t_link *)ft_memalloc(sizeof(t_link));
	farm->queue->rm = start;
	while (farm->queue && farm->queue->rm != end)
	{
		work_room(farm->queue->rm, farm);
		tmp_queue = farm->queue;
		farm->queue = farm->queue->next;
		free(tmp_queue);
		tmp_queue = NULL;
	}
	return (end->way == NULL ? 0 : 1);
}
