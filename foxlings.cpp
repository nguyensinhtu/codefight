#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct subsets{
	int parent;
	int rank;
};

int find(subsets sub[], int x){
	if (x != sub[x].parent){
		sub[x].parent = find(sub, sub[x].parent);
	}

	return sub[x].parent;
}

void Union(subsets sub[], int x, int y){
	int xroot = find(sub, x);
	int yroot = find(sub, y);
	if (sub[xroot].rank < sub[yroot].rank){
		sub[xroot].parent = yroot;
	}
	else if (sub[xroot].parent > sub[yroot].parent)
		sub[yroot].parent = xroot;
	else{
		sub[yroot].parent = xroot;
		sub[xroot].rank++;
	}
}

int T, M;
vector<int> a;

int main() {
	freopen("input.txt", "r", stdin);
	// freopen("output1.txt", "w", stdout);

	cin >> T >> M;
	subsets *sub = new subsets[T + 1];
	for (int i = 1; i <= T; i++){
		sub[i].parent = i;
		sub[i].rank = 0;
	}

	for (int i = 0; i < M; ++i){
		int a, b;
		cin >> a >> b;
		Union(sub, a, b);
	}


	int count = 0;
	for (int i = 1; i <= T; ++i){
		a.push_back(find(sub, i));
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < a.size() - 1; ++i){
		if (a[i + 1] > a[i])
			count++;
	}

	cout << count + 1 << endl;
	return 0;
}
