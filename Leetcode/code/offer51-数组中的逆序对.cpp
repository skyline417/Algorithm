/*
题意：数组中的逆序对
思路：归并排序
*/

class Solution {
public:

    int merge(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;

        int mid = l + r >> 1;
        int res = merge(nums, l, mid) + merge(nums, mid + 1, r);

        vector<int> temp;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r)
            if (nums[i] <= nums[j]) temp.push_back(nums[i ++ ]);
            else {
                temp.push_back(nums[j ++ ]);
                res += mid - i + 1;
            }
        while (i <= mid) temp.push_back(nums[i ++ ]);
        while (j <= r) temp.push_back(nums[j ++ ]);

        int k = l;
        for (auto x : temp) nums[k ++ ] = x;

        return res;
    }

    int inversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size() - 1);
    }
};

//20220410第二次写
class Solution {
public:
    int res=0;
    int tmp[50005];
    int merge_sort(vector<int>& q, int l, int r){
        if(l>=r) return 0; //l>=r 和quick sort一样
        int mid = (l + r) >> 1;
        res=merge_sort(q, l, mid)+merge_sort(q, mid+1, r); //注意res要加上两边逆序对数量的和
        
        //合并 统计跨两段的逆序对数量
        int cnt=0, i=l, j=mid+1;
        while(i<=mid && j<=r){ //合理的while循环
            if(q[i]<=q[j]) tmp[cnt++]=q[i++];
            else{
                res+=mid-i+1; // 当q[i]>q[j] -> q[i~mid]都是 q[j]的逆序
                tmp[cnt++]=q[j++];
            }
        }
        while(i<=mid) tmp[cnt++]=q[i++];
        while(j<=r) tmp[cnt++]=q[j++];

        for(int i=l,j=0;i<=r;++i,++j) q[i]=tmp[j]; //注意i是从l到r

        return res;
    }
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums,0,nums.size()-1);
    }
};