// 1. Find duplicate in an array. Use Floyd's Tortoise Hare Algo for cycle detection.
int findDuplicate(vector<int>& nums)
{
        int n=nums.size();
        int h=nums[0],t=nums[0];
        do{
            h=nums[nums[h]];
            t=nums[t];
        }while(t!=h);

        t=nums[0];  // Reset the first one to start point.
        while(t!=h)
        {
            t=nums[t];
            h=nums[h];
        }

        return t;
}
// 2. Sort an array of 0’s 1’s 2’s without using extra space or sorting algo. This is done by dutch natoinal flag algo.

void sortColors(vector<int>& nums) {
        int n=nums.size();
        int high=n-1;
        int low=0;
        int mid=0;
        while(mid <= high)
        {
            if(nums[mid]==0)
                swap(nums[low++],nums[mid++]);
            else if(nums[mid]==1)
                mid++;
            else
                swap(nums[mid],nums[high--]);

        }

// 5. Kadane's Algorithm. Maximum Subarray Sum.

int maxSubArray(vector<int>& nums) {
        int sum=0;
        int t=nums[0];
        for(auto i:nums){
            sum += i;
            t=max(sum,t);
            if(sum<0) sum=0;
        }

        return t;
    }

// Boyre Moore's Voting Algorithm. Majority Element

int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int res=0,count=0;
        for(auto x:nums){
            if(count==0)
                res=x;
            if(x==res)
                count++;
            else
                count--;
        }
        return res;
    }
// Majority Element More advanced version return all element with occurrance greater than n/3

vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int num1=-1,num2=-1,count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(num1==nums[i]) count1++;
            else if(num2==nums[i]) count2++;
            else if(count1==0)
            {
                num1=nums[i];
                count1=1;
            }
            else if(count2==0)
            {
                num2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> res;
        count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==num1)
                count1++;
            else if(nums[i]==num2)
                count2++;
        }
        if(count1 > n/3)
            res.push_back(num1);
        if(count2 > n/3)
            res.push_back(num2);

        return res;
    }


//7. Set Zeroes. Given a 2d matrix set all values in column and row as zero if we find zero value.

    void setZeroes(vector<vector<int>>& matrix) {
        int col1=1;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0) col1=0;
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0)
                    matrix[i][0]=matrix[0][j]=0;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=1;j--){
                if(matrix[i][0]==0 or matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(col1==0)matrix[i][0]=0;
        }
    }

//8 Pascal triangle Easy implementation not doing code here.
//9.



//12. Next Permutation: Find the next permutation of given array of numbes.
void nextPermutation(vector<int>& nums) {
        int n=nums.size(),k,l;
        for(k=n-2;k>=0;k--){
            if(nums[k]<nums[k+1])
                break;
        }
        if(k<0)
            reverse(nums.begin(),nums.end());
        else
        {
            for(l=n-1;l>k;l--){
                if(nums[k]<nums[l])
                    break;
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
 }


//Unique path from start to end can be found using dp and also binomial formulae:

class Solution {
    public:
        int uniquePaths(int m, int n) {
            int N = n + m - 2;// how much steps we need to do
            int k = m - 1; // number of steps that need to go down
            double res = 1;
            // here we calculate the total possible path number
            // Combination(N, k) = n! / (k!(n - k)!)
            // reduce the numerator and denominator and get
            // C = ( (n - k + 1) * (n - k + 2) * ... * n ) / k!
            for (int i = 1; i <= k; i++)
                res = res * (N - k + i) / i;
            return (int)res;
        }
    };


 //2 SUM

vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) {
        int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
        if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
            result.push_back(hash[numberToFind] + 1);
            result.push_back(i + 1);
            return result;
        }

            //number was not found. Put it in the map.
        hash[numbers[i]] = i;
    }
    return result;
}

// 4 Sum: Approach is to sort the array followed by using two pointer and applying 2Sum technique.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        if(n==0)
            return res;
        sort(nums.begin(),nums.end());  //sorting the array
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target_2= target-nums[i]-nums[j];
                int front = j+1;            //first pointer
                int back  = n-1;            //second pointer
                while(front<back){
                    int two_sum= nums[front]+nums[back];
                    if(two_sum < target_2)front++;
                    else if(two_sum > target_2) back--;
                    else{
                        vector<int> temp(4,0);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[front];
                        temp[3]=nums[back];
                        res.push_back(temp);

                        while(front<back && temp[2]==nums[front])++front;   //Checking for duplicate values

                        while(front<back && temp[3]==nums[back])--back;     //Again checking for duplicates
                    }

                }
                while(j+1<n && nums[j]==nums[j+1])++j;      // if the values are repeating we will skip those values and increment j
            }
            while(i+1<n && nums[i]==nums[i+1])++i;          // if the values are repeating we will skip those values and increment i
        }
        return res;
    }

};


// 21. Longest Consequtive Sequence : Approach:
/* 1. Use a hash map to store boundary information of consecutive sequence for each element;
                                      there are 4 cases when a new element i reached:

                                      neither i+1 nor i-1 has been seen: m[i]=1;
                                      both i+1 and i-1 have been seen: extend m[i+m[i+1]] and m[i-m[i-1]] to each other;
                                      only i+1 has been seen: extend m[i+m[i+1]] and m[i] to each other;
                                      only i-1 has been seen: extend m[i-m[i-1]] and m[i] to each other.
*/

int longestConsecutive(vector<int> &num) {
    unordered_map<int, int> m;
    int r = 0;
    for (int i : num) {
        if (m[i]) continue;
        r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
        /*
            for detailed explanation see the first comment at
            https://leetcode.com/problems/longest-consecutive-sequence/discuss/41088/Possibly-shortest-cpp-solution-only-6-lines.
            Here we are checking in array for both left side and right side if left side is not present we can start calculationg if right is present and left is also present then it will come in other longer seq so not required to calculate it over.
        */
    }
    return r;
}


//22. Longest Subarray with 0 sum

int maxLen(int arr[], int n)
{
    // Map to store the previous sums
    unordered_map<int, int> presum;

    int sum = 0; // Initialize the sum of elements
    int max_len = 0; // Initialize result

    // Traverse through the given array
    for (int i = 0; i < n; i++) {
        // Add current element to sum
        sum += arr[i];

        if (arr[i] == 0 && max_len == 0)
            max_len = 1;
        if (sum == 0)
            max_len = i + 1;

        // Look for this sum in Hash table
        if (presum.find(sum) != presum.end()) {
            // If this sum is seen before, then update max_len
            max_len = max(max_len, i - presum[sum]);
        }
        else {
            // Else insert this sum with index in hash table
            presum[sum] = i;
        }
    }

    return max_len;
}

//23.Count number of subarrays with given XOR:

// Returns count of subarrays of arr with XOR
// value equals to m
long long subarrayXor(int arr[], int n, int m)
{
    long long ans = 0; // Initialize answer to be returned

    // Create a prefix xor-sum array such that
    // xorArr[i] has value equal to XOR
    // of all elements in arr[0 ..... i]
    int* xorArr = new int[n];

    // Create map that stores number of prefix array
    // elements corresponding to a XOR value
    unordered_map<int, int> mp;

    // Initialize first element of prefix array
    xorArr[0] = arr[0];

    // Computing the prefix array.
    for (int i = 1; i < n; i++)
        xorArr[i] = xorArr[i - 1] ^ arr[i];

    // Calculate the answer
    for (int i = 0; i < n; i++) {
        // Find XOR of current prefix with m.
        int tmp = m ^ xorArr[i];

        // If above XOR exists in map, then there
        // is another previous prefix with same
        // XOR, i.e., there is a subarray ending
        // at i with XOR equal to m.
        ans = ans + ((long long)mp[tmp]);

        // If this subarray has XOR equal to m itself.
        if (xorArr[i] == m)
            ans++;

        // Add the XOR of this subarray to the map
        mp[xorArr[i]]++;
    }

    // Return total count of subarrays having XOR of
    // elements as given value m
    return ans;
}


// Longest Substring Without Repeating Characters: Source Leetcode Prob No. 3

int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int start=-1,maxlen=0;
        map<char,int> mp;

        for(int i=0;i<n;i++)
        {
            if(mp.count(s[i])!=0)
                start=max(start,mp[s[i]]);

            mp[s[i]]=i;
            maxlen=max(maxlen,i-start);

        }
        return maxlen;
    }

// Day 4 Completed.

// Reverse a linked list :
// Iterative Approach
ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* temp=NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        head=prev;
        return head;
    }
// Recursive approach
 ListNode* reverseList(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;

        ListNode* x = reverseList(head->next);

        head->next->next=head;
        head->next = NULL;
        return x;
    }

//Reversing a linked list from given position start and end:

ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL or m==n)
            return head;
        ListNode *dummy= new ListNode(0),*pre=dummy,*cur;
        dummy->next= head;
        for(int i=0;i<m-1;i++)
            pre=pre->next;

        cur=pre->next;
        for(int i=0;i<n-m;i++){
            ListNode *temp=pre-> next;
            pre->next= cur->next;
            cur->next = cur->next->next;
            pre->next->next=temp;
        }

        return dummy->next;

    }

//26.  Find middle of Linked List:
ListNode* middleNode(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast && fast->next )
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
//27. Simple while loop for which the pointer will point to smaller values in both the list.

//28. Optimized one pass approach for removing nth node from end.

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start=new ListNode(0);
        start->next =head;
        ListNode *fast=start;
        ListNode *slow=start;
        for(int i=1;i<=n+1;i++){
            fast=fast->next;
        }
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }

        slow->next= slow->next->next;
        return start->next;
    }


//29. Delete Node from LL when a node value is given.
void deleteNode(ListNode* node)
    {
            auto *n=node->next;
           *node=*n;
            delete n;

    }

//30. Add two numbers of LL:

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode res(0), *p =&res;
        int c=0;
        while(l1 or l2 or c){
            if(l1) c += l1->val , l1=l1->next;
            if(l2) c += l2->val,  l2=l2->next;
            p->next = new ListNode(c%10);
            c=c/10;
            p=p->next;
        }

        return res.next;
    }

