vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans(n, -1);
        
        stack <int> s;
        
        for(int i=0; i<n; i++) {
            while(!s.empty() && arr[s.top()] < arr[i]) {
                ans[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
        
        //if vector not initialized with -1
        // while(!s.empty()){
        //     ans[s.top()] = -1;
        //         s.pop();
        // }
        
        return ans;
    }
