class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        ans={}
        for i in arr:
            if i in ans.keys():
                ans[i]+=1
            else:
                ans[i]=1
        ans1=set()
        ans2=[]
        for i in ans.values():
            ans1.add(i)
            ans2.append(i)
        if len(ans1)==len(ans2):
            return True
        else:
            return False