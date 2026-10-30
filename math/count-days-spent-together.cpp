class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> monthdays = {0, 31, 28, 31, 30, 31, 30,
                                 31, 31, 30, 31, 30, 31};

        int a1 = stoi(arriveAlice.substr(0, 2));
        int a2 = stoi(arriveAlice.substr(3, 2));
        int a3 = stoi(leaveAlice.substr(0, 2));
        int a4 = stoi(leaveAlice.substr(3, 2));

        int b1 = stoi(arriveBob.substr(0, 2));
        int b2 = stoi(arriveBob.substr(3, 2));
        int b3 = stoi(leaveBob.substr(0, 2));
        int b4 = stoi(leaveBob.substr(3, 2));

        int startA = a2, startB = b2;
        int endA = a4, endB = b4;

        for (int i = 1; i < a1; i++) startA += monthdays[i];
        for (int i = 1; i < b1; i++) startB += monthdays[i];
        for (int i = 1; i < a3; i++) endA += monthdays[i];
        for (int i = 1; i < b3; i++) endB += monthdays[i];

        int start = max(startA, startB);
        int end = min(endA, endB);

        return max(0, end - start + 1);
    }
};