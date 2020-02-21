import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        //while(true) { //테스트용 무한루프

            Scanner sc = new Scanner(System.in);
            int N = sc.nextInt();

            int[] dynamic = new int[N + 1];
            int[] defaultab = {-1, -1, -1, 1, -1, 1, 2, -1, 2, 3, 2};

            if (N <= 10) {
                System.out.println(defaultab[N]);
                return;
            }
            else
                for (int i = 0; i <= 10; i++)
                    dynamic[i] = defaultab[i];

            for (int i = 11; i <= N; i++)

                if(dynamic[i-5] != -1 && dynamic[i-3] != -1)
                    dynamic[i] = 1 + Math.min(dynamic[i - 3], dynamic[i - 5]);

                else if(dynamic[i-5] == -1 && dynamic[i-3] != -1)
                    dynamic[i] = 1 + dynamic[i-3];

                else if(dynamic[i-5] != -1 && dynamic[i-3] == -1)
                    dynamic[i] = 1 + dynamic[i-5];

            System.out.println(dynamic[N]);

        //}
    }
}
