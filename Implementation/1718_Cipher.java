import java.util.*;
import java.lang.String;

public class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        String normalSentence = sc.nextLine();
        String cipherKey = sc.next();

        char[] resultantSentence = new char[normalSentence.length()];

        sc.close();

        for(int i = 0 ; i < normalSentence.length() ; i++)
            if(normalSentence.charAt(i) == ' ')
            {
                resultantSentence[i] = ' ';
            }
            else if((int)normalSentence.charAt(i) > (int)cipherKey.charAt(i % cipherKey.length()))
            {
                resultantSentence[i] = (char)(96 + (normalSentence.charAt(i) - cipherKey.charAt(i % cipherKey.length())));
            }
            else
            {
                resultantSentence[i] = (char)(122 - ((cipherKey.charAt(i % cipherKey.length()) - normalSentence.charAt(i))));
            }

        for(int i = 0 ; i < resultantSentence.length ; i++)
            System.out.print(resultantSentence[i]);

        //char a = 97;
        //char z = 122;
    }
}
