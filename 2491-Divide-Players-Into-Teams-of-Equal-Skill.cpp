class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        if(skill.size()==2)
        {
            return skill[0]*skill[1];
        }
        int sum=skill[0]+skill[skill.size()-1];
        int l=0;
        int h=skill.size()-1;
         long long res=skill[0]*skill[skill.size()-1];
        l++;
        h--;
       
        while(l<h)
        {
            if(skill[l]+skill[h]!=sum)
            return -1;
            res+=skill[l]*skill[h]*1ll;
            l++;
            h--;
        }
        return res;
    }
};