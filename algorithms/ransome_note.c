bool canConstruct(char* ransomNote, char* magazine) {
    int magMap[256] = {0};
    while (*magazine) {
        magMap[*magazine++]++;
    }

    while (*ransomNote) {
        if (magMap[*ransomNote] == 0) {
            return 0;
        } else {
            magMap[*ransomNote++]--;
        }
    }
    return 1;
}
