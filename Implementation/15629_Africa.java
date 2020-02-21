import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int cost = 0;
        boolean SAexists = false;
        boolean ZIexists = false;
        boolean ZAexists = false;
        String plan;

        for(int i = 0 ; i < N ; i++)
        {
            plan = sc.next();
            switch (plan)
            {
                case "botswana" : //보츠와나
                    cost += 0; //무비자 90일
                    break;

                case "ethiopia" : //에티오피아
                    cost += 50; //도착비자 $50
                    break;

                case "kenya" : //케냐
                    cost += 50; //1회 입국 $50
                    break;

                case "namibia" : //나미비아
                    if(SAexists) cost += 40; //남아공 거치면 $40
                    else cost += 140; //대행사 $140
                    break;

                case "south-africa" : //남아공
                    SAexists = true;
                    cost += 0; //무비자 30일
                    break;

                case "tanzania" : //탄자니아
                    cost += 50; //1회 입국 $50
                    break;

                case "zambia" : //잠비아

                    ZAexists = true;
                    if(ZIexists)
                        cost += 20 + 0; //잠비아-짐바브웨
                    else cost += 50; //1회 입국 $50
                    break;

                case "zimbabwe" : //짐바브웨

                    ZIexists = true;
                    if(ZAexists)
                        cost += 0; //잠비아-짐바브웨
                    else cost += 30; //1회 입국 $30
                    break;
            }

            if(!plan.equals("zambia") && !plan.equals("zimbabwe"))
            {
                ZAexists = false;
                ZIexists = false;
            }

        }

        System.out.println(cost);

    }
}
