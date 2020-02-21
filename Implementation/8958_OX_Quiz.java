import java.util.*;
import java.lang.String;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        String OXQuiz;

        for(int i = 0 ; i < T && sc.hasNext(); i++) //테스트케이스
        {
            OXQuiz = sc.next();
            int OsInARow = 0;
            int finalScore = 0;

            for(int j = 0 ; j < OXQuiz.length() ; j++)
                if(OXQuiz.charAt(j) == 'O')
                {
                    OsInARow++;
                    if(j < OXQuiz.length() - 1 && OXQuiz.charAt(j + 1) == 'X')
                    {
                        finalScore += OsInARow * (OsInARow + 1) / 2;
                        OsInARow = 0;
                    }
                    else if(j == OXQuiz.length() - 1)
                    {
                        finalScore += OsInARow * (OsInARow + 1) / 2;
                    }
                }

            System.out.println(finalScore);
        }
    }
}