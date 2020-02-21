import java.util.Scanner;

public class Main
{
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] starQuantity = new int[N];
        for (int i = 0; i < N; i++)
            starQuantity[N - 1 - i] = 1 + 2 * i;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                System.out.print(" ");
            }

            for (int j = 0; j < starQuantity[i]; j++)
            {
                System.out.print("*");
            }

            System.out.println("");
        }
    }
}
