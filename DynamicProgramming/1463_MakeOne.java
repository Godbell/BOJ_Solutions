import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] mem = new int[N+1];
        int[] tab = {0,0,1,1,2,3};

        if(N < 6)
            for(int i = 0 ; i <= N ; i++)
                mem[i] = tab[i];
        else
            for(int i = 0 ; i < 6 ; i++)
                mem[i] = tab[i];

        if(N >= 6)
            for (int i = 6; i <= N; i++)
            {
                if (i % 3 == 0 && i % 2 == 0)
                {
                    mem[i] = Math.min(Math.min(1 + mem[i / 3], 1 + mem[i / 2]), 1 + mem[i - 1]);
                }
                else if (i % 3 == 0 && i % 2 != 0)
                {
                    mem[i] = Math.min(1 + mem[i / 3], 1 + mem[i - 1]);
                }
                else if (i % 3 != 0 && i % 2 == 0)
                {
                    mem[i] = Math.min(1 + mem[i / 2], 1 + mem[i - 1]);
                }
                else if(i % 3 != 0 && i % 2 != 0)
                    mem[i] = mem[i - 1] + 1;

            }

        System.out.println(mem[N]);
    }
}
