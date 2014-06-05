#include "clean.h"
#include "init.h"
#include "env.h"
#include "run.h"

int	main(int argc, char** argv)
{
	t_env	env;

	if (init(argc, argv, &env) || run(&env))
	{
		clean(&env);
		return (-1);
	}
	id_print("\n");
	clean(&env);
	return (0);
}
