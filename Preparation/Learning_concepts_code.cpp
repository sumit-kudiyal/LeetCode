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
