import java.util.Scanner;

public class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int answer = 0;

        for (int i = 0; i < N; i++)
        {
            int T = sc.nextInt();
            for (int j = 0; j < T; j++)
                answer += sc.nextInt();

            System.out.println(answer);
            answer = 0;
        }
    }
}
