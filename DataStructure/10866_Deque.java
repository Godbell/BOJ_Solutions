import java.util.*;
import java.lang.String;

public class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String inputText;
        ArrayList<Integer> deque = new ArrayList<>();

        int inputNum;

        for(int i = 0 ; i < N ; i++)
        {
            inputText = sc.next();

            switch (inputText)
            {
                case "push_front":
                    inputNum = sc.nextInt();
                    deque.add(0, inputNum);
                    break;

                case "push_back":
                    inputNum = sc.nextInt();
                    deque.add(inputNum);
                    break;

                case "pop_front":
                    if(deque.size() != 0)
                    {
                        System.out.println(deque.get(0));
                        deque.remove(0);
                    }
                    else
                        System.out.println(-1);
                    break;

                case "pop_back":
                    if(deque.size() != 0)
                    {
                        System.out.println(deque.get(deque.size() - 1));
                        deque.remove(deque.size() - 1);
                    }
                    else
                        System.out.println(-1);
                    break;

                case "size":
                    System.out.println(deque.size());
                    break;

                case "empty":
                    if(deque.size() != 0)
                    {
                        System.out.println(0);
                    }
                    else
                        System.out.println(1);
                    break;

                case "front":
                    if(deque.size() != 0)
                    {
                        System.out.println(deque.get(0));
                    }
                    else
                    System.out.println(-1);
                    break;

                case "back":
                    if(deque.size() != 0)
                    {
                        System.out.println(deque.get(deque.size() - 1));
                    }
                    else
                        System.out.println(-1);
                    break;
            }
        }
    }
}
