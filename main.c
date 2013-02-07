#include <SDL/SDL.h>

#include "libid/lib.h"
#include "env.h"
#include "init.h"
#include "run.h"

int	main(int argc, char** argv)
{
	t_env	env;

	if (init(argc, argv, &env))
	{
		id_print("Error in init\n");
		return (1);
	}
	if (run(&env))
	{
		id_print("Error in runtime\n");
		return (1);
	}
	return (0);
}
