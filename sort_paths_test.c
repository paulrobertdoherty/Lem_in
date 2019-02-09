#include "lem_in.h"

int main(int argc, char **argv) {
	t_list *l = NULL;
	for (int i = 1; i < argc; i++) {
		t_list	*ta = (t_list *)malloc(sizeof(t_list));
		ta->content = NULL;
		ta->content_size = atoi(argv[i]);
		ta->next = NULL;
		ft_lstadd(&l, ta);
	}
	sort_paths(l);
	t_list *i = l;
	while (i)
	{
		printf("%zu\n", i->content_size);
		i = i->next;
	}
	return 0;
}

