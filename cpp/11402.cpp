#include <iostream>
#include <vector>

using namespace std;

struct SegmentTree {

    SegmentTree(const vector<int>& in_arr) {
        orig_size = in_arr.size();
        st.assign(in_arr.size() * 4, 0);
        lz.assign(in_arr.size() * 4, 0);
        // recursive build
        build(in_arr, 0, 0, in_arr.size() - 1);
    }

    int rsq(int start, int end) {
        return rsq(start, end, 0, 0, orig_size - 1);
    }

    // add value to element with index idx
    void flip(int idx) {
        flip(idx, idx, 0, 0, orig_size - 1);
    }

    // add value to all element in the range [idx_start .. idx_end]
    void flip(int idx_start, int idx_end) {
        flip(idx_start, idx_end, 0, 0, orig_size - 1);
    }

    void dump() {
        for(int i = 0; i < st.size(); i++)
            cout << st[i] << " ";
        cout << endl;

        for(int i = 0; i < lz.size(); i++)
            cout << lz[i] << " ";
        cout << endl;
    }

    private:
        vector<int> st, lz;
        int orig_size;

        // recursive build
        void build(const vector<int>& in_arr, int idx, int seg_start, int seg_end) {
            if(seg_start == seg_end) {
                st[idx] = in_arr[seg_start];
            } else {
                build(in_arr, idx * 2 + 1, seg_start, (seg_end + seg_start)/2);
                build(in_arr, idx * 2 + 2, (seg_end + seg_start)/2 + 1, seg_end);
                st[idx] = st[idx * 2 + 1] + st[idx * 2 + 2];
            }
        }
        // recursive rsq
        int rsq(int start, int end, int idx, int seg_start, int seg_end) {
            //cout << "rsq seg " << seg_start << " " << seg_end << endl;
            // if we have lazy value, propogate it
            if(lz[idx]) {
                //cout << "have lazy in seg " << seg_start << " " << seg_end << endl;
                st[idx] = ((seg_end - seg_start + 1) - st[idx]);
                lz[idx*2 + 1] ^= 1;
                lz[idx*2 + 2] ^= 1;
                lz[idx] = 0;
            }

            if(seg_start > end || seg_end < start) {
                return 0;
            } else if(seg_start >= start && seg_end <= end) {
                return st[idx];
            } else {
                return rsq(start, end, idx * 2 + 1, seg_start, (seg_end + seg_start)/2) +
                        rsq(start, end, idx * 2 + 2, (seg_end + seg_start)/2 + 1, seg_end);
            }
        }


        // recursive range add
        void flip(int add_idx_start, int add_idx_end, int st_idx, int seg_start, int seg_end) {

            // cout << "rage " << seg_start << " " << seg_end << endl;
            if(seg_start > add_idx_end || seg_end < add_idx_start) {
                return;
            } else if(seg_start >= add_idx_start && seg_end <= add_idx_end) {
                lz[st_idx] ^= 1;
                if(lz[st_idx]) {
                    st[st_idx] = ((seg_end - seg_start + 1) - st[st_idx]);
                    lz[st_idx*2 + 1] ^= 1;
                    lz[st_idx*2 + 2] ^= 1;
                    lz[st_idx] = 0;
                }

            } else {
                flip(add_idx_start, add_idx_end, st_idx * 2 + 1, seg_start, (seg_end + seg_start)/2);
                flip(add_idx_start, add_idx_end, st_idx * 2 + 2, (seg_end + seg_start)/2 + 1, seg_end);

                st[st_idx] = st[st_idx*2 + 1] + st[st_idx*2 + 2];

            }
        }
};

int main() {
    vector<int> myv({ 1,0,0,0,0,1,1,0,0,1,1 });
    SegmentTree myft(myv);
    
    //cout << myft.rsq(0, 0) << endl;
    //cout << myft.rsq(1, 1) << endl;
    //cout << myft.rsq(2, 2) << endl;
    //cout << myft.rsq(0, 10) << endl;

    myft.flip(1, 4);
    cout << myft.rsq(0, 10) << endl;


    myft.flip(7, 8);
    cout << myft.rsq(0, 10) << endl;

    myft.flip(0, 10);
    cout << myft.rsq(0, 10) << endl;

    myft.flip(0, 10);
    cout << myft.rsq(0, 10) << endl;


    //myft.dump();
    
   

    
}