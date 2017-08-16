#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int n, k;
	while (cin >> n) {
		cin >> k;
		int getInput, totalServer = 1， currentLoad = 0;
		queue<int> referenceStartPoint;
		for (int i = 0; i < n; i++) {
			cin >> getInput;
			referenceStartPoint.push(getInput);
			if (getInput >= referenceStartPoint.front() + 1000) {//新的不必并行处理的任务
				referenceStartPoint.pop();
			}
			else {//需要并行处理
				currentLoad++;
			}
			if (currentLoad > totalServer*k)//即时负载超过并行处理量
				totalServer++;
		}
		cout << totalServer << endl;
	}
	return 0;
}