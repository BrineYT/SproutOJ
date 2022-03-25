short queried[1500];
void initialize(int N) {
    for (int i = 0; i < N; i++) queried[i] = 0;
}
int hasEdge(int a, int b) {
    return ++queried[(a > b ? a : b)] == (a > b ? a : b);
}