#include <iostream>
#include <vector>

using namespace std;


struct segment_tree {
    vector<int> st, lz;
    int orig_size;
    int rv;

    segment_tree(const vector<int>& in_arr) {
        orig_size = in_arr.size();
        st.assign(in_arr.size() * 4, 0);
        lz.assign(in_arr.size() * 4, 0);
        build(in_arr, 0, 0, in_arr.size() - 1);
    }

    int op(int a, int b) {
        // for MIN tree
        //rv = 10000; // max possible value
        //return min(a, b);

        // for MAX tree
        rv = -10000; //min possible value
        return max(a, b);
        
        // for SUM tree
        //rv = 0; // 0 value
        //return a + b;
    }
    void build(const vector<int>& in_arr, int idx, int seg_start, int seg_end) {
        if(seg_start == seg_end) {
            st[idx] = in_arr[seg_start];
        } else {
            build(in_arr, idx * 2 + 1, seg_start, (seg_end + seg_start)/2);
            build(in_arr, idx * 2 + 2, (seg_end + seg_start)/2 + 1, seg_end);
            st[idx] = op(st[idx * 2 + 1],  st[idx * 2 + 2]);
        }
    }

    int req(int start, int end) {
        return req(start, end, 0, 0, orig_size - 1);
    }

    int req(int start, int end, int idx, int seg_start, int seg_end) {
        if(lz[idx]) {
            st[idx] += (seg_end - seg_start + 1) * lz[idx];
            lz[idx*2 + 1] += lz[idx];
            lz[idx*2 + 2] += lz[idx];
            lz[idx] = 0;
        }

        if(seg_start > end || seg_end < start) {
            return rv;
        } else if(seg_start >= start && seg_end <= end) {
            return st[idx];
        } else {
            return op(req(start, end, idx * 2 + 1, seg_start, (seg_end + seg_start)/2),
                    req(start, end, idx * 2 + 2, (seg_end + seg_start)/2 + 1, seg_end));
        }
    }

    void add(int idx, int value) {
        add(idx, idx, value, 0, 0, orig_size - 1);
    }

    void add(int start, int end, int value) {
        add(start, end, value, 0, 0, orig_size - 1);
    }

    void add(int start, int end, int value, int idx, int seg_start, int seg_end) {
        if(seg_start > end || seg_end < start) {
            return;
        } else if(seg_start >= start && seg_end <= end) {
            st[idx] += (seg_end - seg_start + 1) * value;
            lz[idx*2 + 1] += value;
            lz[idx*2 + 2] += value;
        } else {
            add(start, end, value, idx * 2 + 1, seg_start, (seg_end + seg_start)/2);
            add(start, end, value, idx * 2 + 2, (seg_end + seg_start)/2 + 1, seg_end);
            st[idx] = op(st[idx*2 + 1], st[idx*2 +2]);
        }
    }
};


int main() {
    vector<int> myv({ 1, -4, 5});
    segment_tree myst(myv);
    myst.add(2, -9);
    cout << myst.req(1, 2) << endl;
}