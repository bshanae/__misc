void		ft_list_remove_if
			(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	**ptr;
	t_list	*iter;

	if (!begin_list)
		return ;
	ptr = begin_list;
	iter = *ptr;
	while (iter)
	{
		if (!cmp(iter->data, data_ref))
		{
			printf("ptr = %d, iter = %d\n", TO_INT(*ptr), TO_INT(iter));
			*ptr = iter->next;
			free(iter);
			iter = *ptr;
		}
		if (iter)
		{
			ptr = &iter->next;
			iter = iter->next;
		}
	}
}
