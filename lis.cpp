#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> v;
	int val;

	cout << "enter a list of numbers, pressing enter after each entry" << endl;

	cin >> val;

	while (val != 0){
		v.push_back(val);
		cin >> val;

	}

	cout << "The sequence you entered is: " << endl;
	for (int i = 0; i < v.size(); i++){
		cout << v.at(i) << " ";

	}

	cout << endl;

	int graph[v.size()];

	for (int i = 0; i < v.size(); i ++){
		graph[i] = 1;
	}

	for(int i = 1; i < v.size(); i++){
		for (int j = 0; j < i; j++){
			if(v.at(j) < v.at(i)){
				if(graph[j] >= graph[i]){
					graph[i] = 1 + graph[j];
					//cout << graph[i] << endl;
				}
			}
		}
	}

	int max = 0;

	for (int i = 1; i < v.size(); i++){
		if (graph[i-1] > graph[i]){
			max = graph[i-1];
		} else{
			max = graph[i];
		}
	}

	cout << "Max is " << max << endl;

	return 0;


}