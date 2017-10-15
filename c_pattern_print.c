/* Ultra Legends : pattern print */
#include<stdio.h>
int main()
{
	char sbuf[1024];
	char pbuf =sbuf;
	memset(sbuf, 0, sizeof(sbuf));
	for(i=0;i<4;i++)
	{
		pbuf++ = '*';
		printf("%s\n",sbuf);
		pbuf++ = ' ';
	}
	return 0;
}
