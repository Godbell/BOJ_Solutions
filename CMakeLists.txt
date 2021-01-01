cmake_minimum_required(VERSION 3.17)
project(BOJ_Solutions)

set(CMAKE_CXX_STANDARD 14)

add_executable(BOJ_Solutions
        BruteForce/1251_WordSplit.cpp
        BruteForce/2309_SevenHobbits.cpp
        BruteForce/2798_BlackJack.cpp
        Dijkstra/1261_AlgoSpot.cpp
        DynamicProgramming/1003_Fibonacci.cpp
        DynamicProgramming/11053_LIS.cpp
        DynamicProgramming/11722_SIS.cpp
        DynamicProgramming/1699_squareSum.cpp
        DynamicProgramming/17626_FourSqrs.cpp
        DynamicProgramming/2293_coin1.cpp
        DynamicProgramming/9095_sum123.cpp
        Graph/1004_LittlePrince.cpp
        Graph/1005_ACMCraft.cpp
        Graph/1260_DFSandBFS.cpp
        Graph/13460_BizEscape2.cpp
        Graph/13460_BizEscape2_RT1.cpp
        Graph/SOMA.cpp
        Greedy/11047_coin0.cpp
        Greedy/1826_FuelFilling_FAILED.cpp
        Greedy/2437_Scale.cpp
        Greedy/5585_Charge.cpp
        Implementation/2875_ContestORIntern.cpp
        Implementation/2960_EratosSleve.cpp
        Math/1002_Turret.cpp
        Math/10872_Factorial.cpp
        Math/1110_AdditionCycle.c
        Math/11653_PrimeFactorization.cpp
        Math/1722_OrderOfP_FAILED.cpp
        Math/2863_isThisRation.cpp
        Math/2884_AlarmClock.cpp
        Math/4948_BertrandPostulate.cpp
        Math/5073_TriAndThreeA.c
        Math/9506_SumOfDeviders.cpp
        Search/1300_KthNumber.cpp
        Search/1316_groupWordChecker.cpp
        Sort/1427_sortInside.cpp)
