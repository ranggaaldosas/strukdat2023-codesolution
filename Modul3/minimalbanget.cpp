#include <iostream>
#include <string>

using namespace std;

// Minimum node n(h) = 1 + n(h-1) + n(h-2), untuk h>=2 dengan +1 di awal sebagai root node
int minNodesInAVL[31];

void min_nodes()
{
    minNodesInAVL[0] = 1;
    minNodesInAVL[1] = 2;

    for (int i = 2; i <= 30; ++i)
    {
        minNodesInAVL[i] = 1 + minNodesInAVL[i - 1] + minNodesInAVL[i - 2];
    }
}

int main()
{
    min_nodes();

    while (true)
    {
        string input;
        getline(cin, input);

        if (input == "DONE")
        {
            break;
        }

        int H = stoi(input);
        if (H < 0 || H > 30)
        {
            cout << "salah bro" << endl;
            continue;
        }

        cout << minNodesInAVL[H] << endl;
    }

    return 0;
}
