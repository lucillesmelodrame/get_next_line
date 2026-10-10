#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*substr = my_substr("hello\nwo", 0, 6);
	char	*substr1 = my_substr("hello\nwo", 6, 2);
	printf("%s\n%s\n", substr, substr1);
}
