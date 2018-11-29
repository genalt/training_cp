#include <iostream>
#include <vector>
using namespace std;

struct DisjointSets
{

    DisjointSets(int in_size)
    {

        size.assign(in_size, 1);
        height.assign(in_size, 1);

        for (int i = 0; i < in_size; i++)
            root.push_back(i);

        max_size = 1;
    }

    int find(int idx1)
    {

        if (root[idx1] == idx1)
            return idx1;

        int new_root = find(root[idx1]);

        root[idx1] = new_root;
        return new_root;
    }

    void join(int idx1, int idx2)
    {
        int root1 = find(idx1);
        int root2 = find(idx2);

        //cout << "join " << idx1 << " " << idx2 << endl;

        //cout << "parent " << root1 << " " << root2 << endl;
        //cout << "sizes " << size[root1] << " " << size[root2] << endl;

        if (root1 == root2)
            return;

        if (height[root1] >= height[root2])
        {
            root[root2] = root1;
            size[root1] += size[root2];

            if (height[root1] == height[root2])
                height[root1]++;

            if (size[root1] > max_size)
                max_size = size[root1];
        }
        else
        {
            root[root1] = root2;
            size[root2] += size[root1];

            if (size[root2] > max_size)
                max_size = size[root2];
        }

        //cout << "max size = " << max_size << endl;
    }

    int get_max_size()
    {
        return max_size;
    }

  private:
    vector<int> root;
    vector<int> height;
    vector<int> size;

    int max_size;
};

int main()
{

    int T, N, M;
    cin >> T;

    while (T--)
    {

        cin >> N >> M;

        DisjointSets ds(N);

        while (M--)
        {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            ds.join(tmp1 - 1, tmp2 - 1);
        }

        cout << ds.get_max_size() << endl;
    }
    return 0;
}
