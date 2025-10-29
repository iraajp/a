#include <stdio.h>
#include <string.h>
#define d 256

// Time Complexity: Average O(n + m) with rolling hash (n=txt, m=pat); Worst-case O(n*m) with many hash collisions. Space: O(1)

// Algorithm: Rabin-Karp (rolling-hash string search)

void search(char pat[], char txt[], int q) {
    int M = strlen(pat), N = strlen(txt);
    if (M == 0 || N == 0 || M > N) return;
    int p = 0, t = 0, h = 1;
    for (int i = 0; i < M - 1; i++) h = (h * d) % q;
    for (int i = 0; i < M; i++) {
        p = (d * p + (unsigned char)pat[i]) % q;
        t = (d * t + (unsigned char)txt[i]) % q;
    }
    for (int i = 0; i <= N - M; i++) {
        if (p == t && strncmp(txt + i, pat, M) == 0)
            printf("Pattern found at index %d\n", i);
        if (i < N - M) {
            t = (d * (t - (unsigned char)txt[i] * h) + (unsigned char)txt[i + M]) % q;
            if (t < 0) t += q;
        }
    }
}

int main() {
    char txt[100], pat[100];
    printf("Enter the text: ");
    if (!fgets(txt, sizeof(txt), stdin)) return 0;
    printf("Enter the pattern: ");
    if (!fgets(pat, sizeof(pat), stdin)) return 0;
    txt[strcspn(txt, "\n")] = 0;
    pat[strcspn(pat, "\n")] = 0;
    search(pat, txt, 101);
    return 0;
}
