#include <stdio.h>

int main()
{
	int N, cnt = 0, recall;

	scanf("%d", &N);
	recall = N;
	
	do
	{
        if (N < 10)
		    N = N * 10 + N;
	    else 
            N = (N%10) * 10 + (N/10 + N%10)%10;
        
	    cnt++;
	    
	} while (N != recall);
	
	printf("%d", cnt);
	
	return 0;
}