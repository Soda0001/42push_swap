int	main(int ac, char **av)
{
	t_strategy strategy;

	strategy = decide_algo(av[1]);
	run_algo(strategy);
	return(0);
}