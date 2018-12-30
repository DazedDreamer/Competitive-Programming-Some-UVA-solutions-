#include <iostream>
#include <vector>


using namespace std;

int digits[10] = {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011,
                  0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011};


int lim;
int match;
vector<int> inputs;

void solve(int inputindex, int digitindex, int burntmask) {
    if (inputindex == lim) {
        match = 1;
        return;
    }

    if (!(inputs[inputindex] & burntmask)) //  check if the burnt segments match/are off
        if (((digits[digitindex] ^ inputs[inputindex]) & inputs[inputindex]) == 0) // get dissimilarities and then check  - i) if the input representation matches the digit representation exactly OR ii)if the burnt segments are off in the input rather than the real digit
            solve(inputindex + 1, digitindex - 1, (digits[digitindex] ^ inputs[inputindex]) | burntmask); // update the burntmask

}


int main() {

    int n;
    char line[20];
    while (scanf("%d", &n) && n) {
        inputs.clear();
        lim = n;
        while (n--) {
            scanf("%s", line);

            int bitmask = 0;

            for (int i = 0; i < 7; i++) {
                if (line[i] == 'Y') {
                    bitmask |= (1 << (6 - i));
                }
            }

            inputs.push_back(bitmask);
        }

        // solve
        match = 0;
        for (int i = 9; i >= (lim - 1) && !match; i--) {
            solve(0, i, 0);
        }

        if(match) printf("MATCH\n");
        else printf("MISMATCH\n");
    }

}
