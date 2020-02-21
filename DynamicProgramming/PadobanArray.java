import java.util.*;

public class PadobanArray {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        long[] array = new long[101];

        array[0] = 0;
        array[1] = 1;
        array[2] = 1;
        array[3] = 1;
        array[4] = 2;
        array[5] = 2;
        array[6] = 3;

        for(int i = 7 ; i <= 100 ; i++)
            array[i] = array[i-1] + array[i-5];

        int T = sc.nextInt();
        for(int i = 0 ; i < T ; i++)
        {
            int N = sc.nextInt();
            System.out.println(array[N]);
        }
    }
}
