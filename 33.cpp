// 33. Search in Rotated Sorted Array

/*





Thoughts & Observation:
Contraints:
1. O(log n) -> We cannot loop through the array to find the pivot k
2. We have to use only binary search here

Steps:
1. Binary search minimum num to find pivot

Pseudocode:
n = nums.size()
l = 0, r = n-1
m = (l+r)/2
while(l<r)
  if nums[m] > nums[r]
    Pivot at the right ([4,5,6,7,0,1,2])
    l = m+1
  else
    Pivot at the left ([6,7,0,1,2,4,5])
    r = m


Example:
[4,5,6,7,0,1,2]
1. l = 0, r = 6, m = 3
Pivot at the right -> l = 4, r = 6
2. l = 4, r = 6, m = 5
Pivot at the left -> l = 4, r = 5
4. l = 4, r = 5, m = 4
Pivot at the left -> l = 4, r = 4

piv = l

2. Check the number range
if (nums[piv] > target) return -1
if (nums[piv] < target && nums[n-1] > target) l = piv, r = n-1
if (nums[piv] < target && nums[n-1] < target) l = 0, r = piv -1

3. Do a normal binary search for number



*/

class Solution {
public:
  int search(vector<int>& nums, int target) {
    // Variable declaration
    int n = nums.size();
    int l=0,r=n-1;

    // Binary search minimum num to find pivot
    while(l<r){
        int m=(l+r)/2;
        if(nums[m]>nums[r]) l=m+1;
        else r=m;
    }

    // Set pivot
    // Check the number range
    int p=l;
    if(nums[p] > target) return -1;
    else if (nums[p] == target) return p;
    else if(nums[p] < target && nums[n-1] >= target){
      l = p;
      r = n-1;
    }
    else if(nums[p] < target && nums[n-1] < target){
      l = 0;
      r = p-1;
    }

    // Do a normal binary search for number
    while(l<r){
        int m=(l+r)/2;
        if(nums[m]<target) l=m+1;
        else r=m;
    }
    if(nums[l]==target) return l;
    return -1;
  }
};