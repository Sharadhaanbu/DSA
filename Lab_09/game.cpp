#include <iostream>
#include <vector>

using namespace std;

int solve() {
    int k, q;
    cin >> k >> q;

    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    vector<int> n_values(q);
    for (int i = 0; i < q; ++i) {
        cin >> n_values[i];
    }

    for (int n : n_values) {
        vector<int> players(n);
        for (int i = 0; i < n; ++i) {
            players[i] = i + 1;
        }

        while (true) {
            vector<int> to_remove;
            for (int index : a) {
                if (index <= players.size()) {
                    to_remove.push_back(players[index - 1]);
                }
            }

            if (to_remove.empty()) {
                cout << players.size() << " ";
                break;
            }

            vector<int> new_players;
            for (int player : players) {
                bool remove = false;
                for (int removed_player : to_remove) {
                    if (player == removed_player) {
                        remove = true;
                        break;
                    }
                }
                if (!remove) {
                    new_players.push_back(player);
                }
            }
            players = new_players;
        }
    }
    cout << endl;

    return 0;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}