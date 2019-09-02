#include <iostream>
#include <vector>
#include <unordered_map>
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
    int C, R;
    while (cin >> C)
    {
        if (C == 0)
            break;
        DisjointSets ds(C);
        cin >> R;
        unordered_map<string, int> number_map;

        for (int i = 0; i < C; i++)
        {
            string name;
            cin >> name;
            number_map[name] = i;
        }

        while (R--)
        {
            string name1, name2;
            cin >> name1 >> name2;
            ds.join(number_map[name1], number_map[name2]);
        }
        cout << ds.get_max_size() << endl;
    }
    return 0;
}
