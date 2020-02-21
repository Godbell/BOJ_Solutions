import java.util.*;

public class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        long[][] numberOfPNs = new long[90 + 1][2];

        numberOfPNs[1][0] = 0;  //끝자리에 0이 오는 경우의 수
        numberOfPNs[1][1] = 1;  //끝자리에 1이 오는 경우의 수
        //1

        numberOfPNs[2][0] = 1;
        numberOfPNs[2][1] = 0;
        //10

        numberOfPNs[3][0] = 1;
        numberOfPNs[3][1] = 1;
        //101
        //100

        for(int i = 4 ; i <= N ; i++ )
        {
            numberOfPNs[i][0] = numberOfPNs[i-1][0] + numberOfPNs[i-1][1];
            numberOfPNs[i][1] = numberOfPNs[i-1][0];
        }

        System.out.println(numberOfPNs[N][0] + numberOfPNs[N][1]);
    }
}