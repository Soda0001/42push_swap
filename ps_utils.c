t_strategy	decide_algo(char *first_arg)
{
	if (ft_strcmp(first_arg, "--simple") == 0)
		return (STRAT_SIMPLE);
	else if (ft_strcmp(first_arg, "--medium") == 0)
		return (STRAT_MEDIUM);
	else if (ft_strcmp(first_arg, "--complex") == 0)
		return (STRAT_COMPLEX);
	else
		return (STRAT_ADAPTIVE);
}
void	run_algo(t_strategy strategy)
{
	if (strategy == STRAT_SIMPLE)
		// simple
	else if (strategy == STRAT_MEDIUM)
		// medium
	else if (strategy == STRAT_COMPLEX)
		// complex
	else if (strategy == STRAT_ADAPTIVE)
		// adaptive
}
