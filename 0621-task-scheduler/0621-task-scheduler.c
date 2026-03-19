int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};
    int cooldown[26] = {0};

    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    int time = 0;

    while (1) {
        int done = 1;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                done = 0;
                break;
            }
        }
        if (done) break;

        int taskIndex = -1;
        int maxFreq = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0 && cooldown[i] == 0 && freq[i] > maxFreq) {
                maxFreq = freq[i];
                taskIndex = i;
            }
        }

        if (taskIndex != -1) {
            freq[taskIndex]--;
            cooldown[taskIndex] = n + 1;
        }

        for (int i = 0; i < 26; i++) {
            if (cooldown[i] > 0)
                cooldown[i]--;
        }

        time++;
    }

    return time;
}