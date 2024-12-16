class Solution
{
public:
    int beautifulSplits(vector<int> &nums)
    {
        int n = nums.size(), i, j, ans = 0;
        vector<int> lcp(n), a(n);
        for (i = n - 1; i; i--)
        {
            for (j = 0; j < n; j++)
            {
                if (nums[i] == nums[j])
                    if (j + 1 == n)
                        lcp[j] = 1;
                    else
                        lcp[j] = lcp[j + 1] + 1;
                else
                    lcp[j] = 0;
                if (j > i && lcp[j] >= j - i)
                {
                    ans++;
                    if (j >= 2 * i)
                        a[i]++;
                }
            }
        }
        for (j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
                if (j + 1 == n)
                    lcp[j] = 1;
                else
                    lcp[j] = lcp[j + 1] + 1;
            else
                lcp[j] = 0;
            if (j > i && 2 * j < n && lcp[j] >= j - i)
                ans += n - j * 2 - a[j];
        }
        return ans;
    }
};