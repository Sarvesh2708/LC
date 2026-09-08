string getAlienLanguage(vector<string> &dictionary, int k)
{
    // Write your code here.
    vector<vector<int>>adj(k);
    for(int i=0;i<dictionary.size()-1;i++){
        string s1 = dictionary[i];
        string s2 = dictionary[i+1];
        int len = min(s1.size(),s2.size());
        for(int j=0;j<len;j++){
            if(s1[j]!=s2[j]){
                int u = s1[j]-'a';
                int v = s2[j]-'a';
                adj[u].push_back(v);
                break;
            }
        }
    }

    //calculate the indegree
    vector<int> indegree(k,0);
    for(int i=0;i<k;i++){
        for(auto it:adj[i]){
            indegree[it]++;

        }
    }

    // topological sort
    queue<int>q;
    for(int i=0;i<k;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    string ans;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans+= char(node+'a');
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }

        }
    }
    return ans;

}