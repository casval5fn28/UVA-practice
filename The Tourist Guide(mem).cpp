// [問題描述]
// Mr. G. 在孟加拉國的一家旅遊公司工作。他當前的任務是帶一些遊客去一個遙遠的城市。和所有國家一樣，
// 一些城市之間有雙向道路。每對相鄰城市之間都有一條公交線路，每條線路都規定了自己最大乘客數目。Mr.
// G. 有一份包含城市間道路狀況和公交車最大載客容量的地圖。
//
// 往往無法一次性地將所有乘客帶往目的地。例如，在下面 7 個城市的地圖中，邊代表道路，每條邊上的數字
// 代表這條道路上公交車的最大載客量。
//
//                   60
//            [2]--------[5]
//           /   \          \
//       30/      \25        \20
//       /    10   \    35    \
//     [1]--------[4]--------[7]
//      \         /          /
//     15\      / 40       /30
//        \   /          /
//         [3]--------[6]
//               20
//
// 如果 Mr. G. 要將 99 位乘客從城市 1 帶到城市 7，則至少需要往返 5 次（他必須陪同每一群遊客）。
// 最佳路線是 1 - 2 - 4 - 7。
//
// 幫助 Mr. G. 找出將所有遊客帶到目的地，且往返次數最少的線路。
//
// [輸入]
// 輸入包含若幹組數據。每組數據的第一行有兩個整數 N （N <= 100） 和 R，分別表示城市的數量和道路
// 的數量。接下來的 R 行有 3 個整數 （C1，C2，P），其中 C1 和 C2 為城市編號，P（P > 1） 是該
// 道路上公交車的最大載客量。各城市編號為 1 ～ N 的連續整數。第 R + 1 行包含 3 個整數 （S，D，
// T），分別表示出發城市，目的城市的編號和遊客的數量。N = R = 0 時輸入結束。
//
// [輸出]
// 對於每組輸入數據，按照樣例格式先輸出一行數據編號，接下來在單獨的一行中輸出最少的往返次數。在每組
// 數據的輸出後打印一個空行。
//
// [樣例輸入]
// 7 10
// 1 2 30
// 1 3 15
// 1 4 10
// 2 4 25
// 2 5 60
// 3 4 40
// 3 6 20
// 4 7 35
// 5 7 20
// 6 7 30
// 1 7 99
// 0 0
//
// [樣例輸出]
// Scenario #1
// Minimum Number of Trips = 5
//
// [解題方法]
// 應用 Floyd-Warshall 算法可以方便的計算 Maxmin 距離從而可以容易的解決本題。***注意導遊必須陪同***
// 每一群遊客的意思是假設公交線路載客量為 C，則一次能載遊客為 C - 1，因為包括了導遊，則往返的次數
// 應該是 P / （C - 1） + （P % （C - 1） ？ 1 ： 0），同時不要忘了在每次輸出後加空行。


#include <bits/stdc++.h>

using namespace std;

#define MAXV 101 //記好
#define INT_MAX -1 //記好

// 記好 !!
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

// 鄰接矩陣 , 記好 !!
struct graph{
	int weight[MAXV][MAXV];
	int v_num;
};//有";"

// 讀入圖的數據，city 為城市數，road 為公交路線數。
// 記好 !!
void create_graph(graph * g, int city, int road){
	int cfirst, csecond, passengers;

    // 都從1開始
	for (int i = 1; i < MAXV; i++){ // 從1 !!!
        for (int j = 1; j < MAXV; j++){ // 從1 !!!
            g->weight[i][j] = INT_MAX;
        }
    }

	g->v_num = city;

	for (int r = 0; r < road; r++){
		cin >> cfirst >> csecond >> passengers;
        //兩組 !!
		g->weight[cfirst][csecond] = passengers;
		g->weight[csecond][cfirst] = passengers;
	}
}

// 利用 Floyd-Warshall 算法計算 Maxmin 距離。
// int & 記好 !!
int floyd_warshall(graph * g, int cstart, int cend){
	int vertices = g->v_num;

    //同個點沒路
	for (int i = 1; i <= vertices; i++){ // 用 <= !!!
        g->weight[i][i] = 0;
    }
	
    // 都從1開始
	for (int k = 1; k <= vertices; k++){// k , <= !!
        for (int i = 1; i <= vertices; i++){//<= !!
            for (int j = 1; j <= vertices; j++){//<= !!
                // 順序記好 !!
                g->weight[i][j] = max( g->weight[i][j],
                    min(g->weight[i][k], g->weight[k][j]) );
            }
        }
    }
		
	return g->weight[cstart][cend];// 記得 !!
}

int main(){
	int city, road;
	int cstart, cend, passenger;
	int trip, testcase = 1;// 別忘 !!
	graph g;

	while (cin >> city >> road){
        if(city == 0 || road == 0){
            break;
        }
		// 讀入圖的數據。
		create_graph(&g, city, road);// 記好 !!

		// 讀入起始城市和終點城市及遊客數量 , 位置重要**********
		cin >> cstart >> cend >> passenger;
		// 利用 Floyd-Warshall 算法計算 Maxmin 距離。
		
		int maxmin = floyd_warshall(&g, cstart, cend) - 1; // 別忘記 - 1 !!*****************

		// 若不能整除，則需要多一次往返。
		trip = passenger / maxmin + (passenger % maxmin ? 1 : 0);// 記好 !!

		// 注意輸出空行。
		cout << "Scenario #" << testcase++ << "\n";// 不要忘記++
		cout << "Minimum Number of Trips = " << trip << "\n" << "\n";//注意空行
	}

	return 0;
}