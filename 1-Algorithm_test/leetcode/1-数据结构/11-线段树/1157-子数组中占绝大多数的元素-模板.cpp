#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// class MajorityChecker {
// public:
// 	vector<int> arr;
//     MajorityChecker(vector<int>& arr) {
// 		this->arr = arr;
//     }
    
// 	// O(n)	遍历并且找到，超时, 24/32	
//     // int query(int left, int right, int threshold) {
// 	// 	unordered_map<int,int> umap;
// 	// 	for(int i = left;i <= right;i++){
// 	// 		umap[arr[i]]++;
// 	// 	}
// 	// 	// PrintUnorder_Map(umap);
// 	// 	for(auto it : umap){
// 	// 		if(it.second >= threshold)
// 	// 			return it.first;
// 	// 	}
// 	// 	return -1;
//     // }

// 	// O(n)	但是用数组，31/32
// 	int query(int left, int right, int threshold) {
// 		int umap[20001] = {0};
// 		for(int i = left;i <= right;i++){
// 			umap[arr[i]]++;
// 		}
// 		// PrintUnorder_Map(umap);
// 		for(int i = 0;i < 20001;i++){
// 			if(umap[i] >= threshold)
// 				return i;
// 		}
// 		return -1;
//     }

// };




struct Node {
    Node(int x = 0, int cnt = 0): x(x), cnt(cnt) {}
    Node& operator+=(const Node& that) {
        if (x == that.x) {
            cnt += that.cnt;
        }
        else if (cnt >= that.cnt) {
            cnt -= that.cnt;
        }
        else {
            x = that.x;
            cnt = that.cnt - cnt;
        }
        return *this;
    }

    int x, cnt;
};



class STree{

};

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr): arr(arr) {
        n = arr.size();
        for (int i = 0; i < n; ++i) {
            loc[arr[i]].push_back(i);
        }

        tree.resize(n * 4);
        seg_build(0, 0, n - 1);
    }
    
    int query(int left, int right, int threshold) {
        Node ans;
        seg_query(0, 0, n - 1, left, right, ans);
        vector<int>& pos = loc[ans.x];
        int occ = upper_bound(pos.begin(), pos.end(), right) - lower_bound(pos.begin(), pos.end(), left);
        return (occ >= threshold ? ans.x : -1);
    }

private:
    int n;
    const vector<int>& arr;
    unordered_map<int, vector<int>> loc;
    vector<Node> tree;

    void seg_build(int id, int l, int r) {
        if (l == r) {
            tree[id] = {arr[l], 1};
            return;
        }

        int mid = (l + r) / 2;
        seg_build(id * 2 + 1, l, mid);
        seg_build(id * 2 + 2, mid + 1, r);
        tree[id] += tree[id * 2 + 1];
        tree[id] += tree[id * 2 + 2];
    }

    void seg_query(int id, int l, int r, int ql, int qr, Node& ans) {
        if (l > qr || r < ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            ans += tree[id];
            return;
        }

        int mid = (l + r) / 2;
        seg_query(id * 2 + 1, l, mid, ql, qr, ans);
        seg_query(id * 2 + 2, mid + 1, r, ql, qr, ans);
    }
};



		
int main() {
	vector<int> arr = {1, 1, 2, 2, 1, 1};
	MajorityChecker* obj = new MajorityChecker(arr);
	
	cout << obj->query(0, 5, 4) << endl;cout << "-----------------" << endl;
	cout << obj->query(0, 3, 3) << endl;cout << "-----------------" << endl;
	cout << obj->query(2, 3, 2) << endl;cout << "-----------------" << endl;

	return 0;
}



