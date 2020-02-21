import java.util.*;
import java.lang.Math;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        double R = sc.nextDouble();

        System.out.format("%.6f%n", R * R * Math.PI);
        System.out.format("%.6f%n", 2.0 * R * R);
    }
}