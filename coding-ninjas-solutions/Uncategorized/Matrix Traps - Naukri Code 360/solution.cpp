int matrixTraps(int N, int M, vector<vector<int>> &Matrix)
{
    queue<pair<int, int>> q;

    vector<vector<int>> visited(N, vector<int>(M, 0));

    // Put all boundary 0s into queue
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (i == 0 || j == 0 || i == N - 1 || j == M - 1) {
                if (Matrix[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
    }

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while (!q.empty()) {

        int nrow = q.front().first;
        int ncol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int row = nrow + delrow[i];
            int col = ncol + delcol[i];

            if (row >= 0 && row < N &&
                col >= 0 && col < M &&
                !visited[row][col] &&
                Matrix[row][col] == 0) {

                q.push({row, col});
                visited[row][col] = 1;
            }
        }
    }

    int cnt = 0;

    // Unvisited 0s are trap cells
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (Matrix[i][j] == 0 && !visited[i][j]) {
                cnt++;
            }
        }
    }

    return cnt;
}
