#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
   public:
    /** initialize your data structure here. */
    vector<int> minHeap, maxHeap;
    greater<int> cmp;

    MedianFinder() {}

    void addNum(int num) {
        int t;
        if (maxHeap.size()) {
            if (num < maxHeap.front()) {
                t = maxHeap.front();
                pop_heap(maxHeap.begin(), maxHeap.end());
                maxHeap[maxHeap.size() - 1] = num;
                push_heap(maxHeap.begin(), maxHeap.end());
                num = t;
            }
        }
        minHeap.push_back(num);
        push_heap(minHeap.begin(), minHeap.end(), cmp);
        if (minHeap.size() > maxHeap.size() + 1) {
            int x = minHeap.front();
            pop_heap(minHeap.begin(), minHeap.end(), cmp);
            minHeap.pop_back();
            maxHeap.push_back(x);
            push_heap(maxHeap.begin(), maxHeap.end());
        }
    }

    double findMedian() {
        if (minHeap.size() > maxHeap.size())
            return minHeap.front();
        else
            return (minHeap.front() + maxHeap.front()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */