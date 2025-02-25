cout << "AFTER" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }