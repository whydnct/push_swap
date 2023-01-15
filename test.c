#include <unistd.h>

int main()
{
	write(1, &"aa", 2);
}