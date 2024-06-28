bool isSubsequence(char* s, char* t) {
    if (!s[0] && !t[0]) {
        return 1;
    }

    int sub_i = 0;
    for (int i = 0; t[i]; ++i) {
        sub_i += (t[i] == s[sub_i]);
        if (!s[sub_i]) {
            return 1;
        }
    }
    return 0;
}
