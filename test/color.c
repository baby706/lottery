#include "base.h"
#include "color.h"

int main(void)
{
	
	UNDERLINE;
	RED;
	printf("this is a red");
	END;
	printf("\n");
	
	
	REVERSE;
	printf("this is a test");
	
	END;
	printf("\n");
	
	CLEAR;
	printf("THE WORLD IS VERY CLEAR\n");
	END;
	
	
	return 0;
}
