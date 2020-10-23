#include <stdio.h>

#include <vector>
#include <algorithm>
#include <queue>

bool cmp(const std::pair<int, int> &a, const std::pair<int ,int> &b) {
    return a.first > b.first;
}

int get_minimum_stop(int L, int P, std::vector<std::pair<int, int> > &stop){
    std::priority_queue<int> Q;
    stop.push_back(std::make_pair(0,0));
    std::sort(stop.begin(),stop.end(),cmp);
    int min = 0;
    int dis = 0;
    for (int i = 0; i < stop.size(); i++)
    {
        dis = L - stop[i].first;
        if (!Q.empty() && P < dis)
        {
            P += Q.top();
            Q.pop();
            min ++;
        }

        if (Q.empty() && P < dis){
			return -1;
		}

        L = stop[i].first;
        P = P - dis;
        Q.push(stop[i].second);
    }
    return min;
}

int main(){
	std::vector<std::pair<int, int> > stop;
	int L = 25;
	int P = 16;
	int distance;
	int fuel;
	stop.push_back(std::make_pair(15, 2));
    stop.push_back(std::make_pair(11, 5));
    stop.push_back(std::make_pair(10, 3));
    stop.push_back(std::make_pair(4, 4));
	printf("%d\n", get_minimum_stop(L, P, stop));
	return 0;
}
