#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include "Heap.h"

typedef pair<float, string> Interaction;

using namespace std;
int main(int argc, char const *argv[]) {
	// Heap<int> heap(100);
	// heap.push(0);
	// heap.push(1230);
	// heap.push(3420);
	// heap.push(12);
	// heap.push(13);
	// heap.push(2);
	// heap.push(1);
	// heap.push(5);
	// // cout << heap;

	// int size = heap.getLength();
	// for (int i = 0; i < size; i++) {
	// 	cout << heap.top() << " ";
	// 	heap.pop();
	// }
	// cout << endl;
	// heap.print(8);

	// vector<int> v;
	// Heap<int> h(1001);
	// for (int i = 0; i < 100; i++) {
	// 	int r = rand();
	// 	v.push_back(r % 1123);
	// 	h.push(r % 1123);
	// }
	// Heap<int> heap(v);
	// while(heap.getLength() > 0) {
	// 	cout << heap.top() << " ";
	// 	heap.pop();
	// }
	// cout << endl;
	// heap.print(10);

	int K = 10;
	float sbThreshold = 12.1;
	// Heap<Interaction> interactions(100000);
	ifstream infile("./tr_fold_0.csv");

	unordered_map<string, Heap<Interaction>> protToSbLigands;
	string ligandID, protID, _;
	float affinityScore;
	infile >> _ >> _ >> _ >> _ >> _;
	for (int i = 0; i < 19710; ++i) {
		infile >> ligandID >> _ >> protID >> _ >> affinityScore;
		Interaction interaction = make_pair(affinityScore, ligandID);
		if (interaction.first > sbThreshold) {
			Heap<Interaction>& heap = protToSbLigands[protID];
			heap.push(interaction);
			if (heap.size() > K) {
				heap.pop();
			}
		}
	}

	for (auto& protIDandHeap : protToSbLigands) {
		string protID = protIDandHeap.first;
		Heap<Interaction>& h = protIDandHeap.second;
		while (h.size() > 0) {
			// cout << h.top().first << " " << h.top().second << " ";
 			h.pop();
 		}
 		// cout << endl;
	}

	for (auto protIDandHeap : protToSbLigands) {
		string protID = protIDandHeap.first;
		Heap<Interaction> h = protIDandHeap.second;
		while (h.size() > 0) {
			cout << h.top().first << " " << h.top().second << " ";
 			h.pop();
 		}
 		// cout << endl;
	}

	// for (int i = 0; i < 10; i++) {
	// 	cout << Interactions.top().first << " "; 
	// 	Interactions.pop();
	// }
	return 0;
}