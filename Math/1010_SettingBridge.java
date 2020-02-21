import java.util.*;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        long[][] dp  = new long [30 + 1][30 + 1];
        long[][] mem = new long [30 + 1][30 + 1];

        for (int i = 1; i <= 30; i++) //N
        {
            for(int j = i ; j <= 30 ; j++) //M
            {
                if(i == 1)
                {
                    dp[i][j] = j;
                }
                else if(i==j)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }
            }
        }

        int T = sc.nextInt();

        for(int i = 0 ; i < T ; i++)
        {
            int N = sc.nextInt();
            int M = sc.nextInt();
            System.out.println(dp[N][M]);
        }

    }
}