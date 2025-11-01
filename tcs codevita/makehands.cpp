#include <bits/stdc++.h>
using namespace std;

struct Card {
    int value;
    int suit;
};

int getValue(const string &s) {
    if (s == "A") return 1;
    if (s == "J") return 11;
    if (s == "Q") return 12;
    if (s == "K") return 13;
    return stoi(s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Card> p1, p2;
    for (int i = 0; i < N; ++i) {
        string c1, c2;
        int s1, s2;
        cin >> c1 >> s1 >> c2 >> s2;
        p1.push_back({getValue(c1), s1});
        p2.push_back({getValue(c2), s2});
    }

    vector<int> suitOrder(4);
    for (int i = 0; i < 4; ++i) cin >> suitOrder[i];

    unordered_map<int, int> priority;
    for (int i = 0; i < 4; ++i)
        priority[suitOrder[i]] = 4 - i;

    auto rearrange = [&](vector<Card> &deck) {
        sort(deck.begin(), deck.end(), [&](const Card &a, const Card &b) {
            if (a.value != b.value) return a.value < b.value;
            return priority[a.suit] < priority[b.suit];
        });
    };

    rearrange(p1);
    rearrange(p2);

    deque<Card> deck1(p1.begin(), p1.end());
    deque<Card> deck2(p2.begin(), p2.end());
    vector<Card> hand;
    bool turn = 0; // 0 - Vaishnavi, 1 - Suraj

    while (!deck1.empty() || !deck2.empty()) {
        if (turn == 0) { // Vaishnavi
            if (deck1.empty()) break;
            Card c = deck1.front(); deck1.pop_front();
            if (!hand.empty()) {
                Card top = hand.back();
                if (c.value == top.value && priority[c.suit] > priority[top.suit]) {
                    hand.push_back(c);
                    rearrange(hand);
                    for (auto &x : hand) deck1.push_back(x);
                    hand.clear();
                    turn = 0;
                    continue;
                }
            }
            hand.push_back(c);
            turn = 1;
        } else { // Suraj
            if (deck2.empty()) break;
            Card c = deck2.front(); deck2.pop_front();
            if (!hand.empty()) {
                Card top = hand.back();
                if (c.value == top.value && priority[c.suit] > priority[top.suit]) {
                    hand.push_back(c);
                    rearrange(hand);
                    for (auto &x : hand) deck2.push_back(x);
                    hand.clear();
                    turn = 1;
                    continue;
                }
            }
            hand.push_back(c);
            turn = 0;
        }
    }

    if (deck1.empty() && deck2.empty())
        cout << "TIE";
    else if (!deck1.empty())
        cout << "WINNER";
    else
        cout << "LOSER";

    return 0;
}
