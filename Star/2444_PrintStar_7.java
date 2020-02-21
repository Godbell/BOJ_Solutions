import java.util.Scanner;

public class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        for(int i = 0 ; i < 2 * N - 1 ; i++)
        {
            if( i < N )
            {
                for(int j = 0 ; j < 2 * (N - 1) / 2 - i ; j++)
                    System.out.print(" ");

                for(int j = 0 ; j < 2 * (i + 1) - 1 ; j++)
                    System.out.print("*");

            }
            else if( N <= i )
            {
                for(int j = 0 ; j < i - N + 1; j++)
                    System.out.print(" ");

                for(int j = 0 ; j < 2 * N - 1 - 2 * (i - (N -1)) ; j++)
                    System.out.print("*");
            }

            System.out.println("");

        }
    }
}