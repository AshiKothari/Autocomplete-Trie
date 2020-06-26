#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
struct tri
{
  tri *c[256];//child
  bool ie;//isEndOfWord
  tri()
  {
      for(int i=0;i<256;i++)
      {
          c[i]=NULL;
          ie=false;
      }
  }
};
bool searchs(tri *root,string s)
{
    tri *cur=root;
    for(int i=0;i<s.size();i++)
    {
        if(cur->c[s[i]]==NULL)
        return false;
        cur=cur->c[s[i]];
    }
    return (cur!=NULL && cur->ie);
}
void inserts(tri *root, string s)
{
    tri *cur=root;
    for(int i=0;i<s.size();i++)
    {
        if(cur->c[s[i]]==NULL)
        {
            cur->c[s[i]]=new tri();
        }
        cur=cur->c[s[i]];
    }
    cur->ie=true;
    return;
}
bool lastnode(tri* root)
{
    for(int i=0;i<256;i++)
    {
        if(root->c[i])
            return false;
    }
    return true;
}
void suggest(tri *root,string s)
{
    if(root->ie==true)
    {
        cout<<s<<endl;
    }
    if(lastnode(root)==true)
        return;
    for(int i=0;i<256;i++)
    {
        if(root->c[i])
        {
            s.push_back(i);
            suggest(root->c[i],s);
            s.pop_back();
        }
    }
}
int suggestions(tri *root, string s)
{
    tri *cur=root;
    for(int i=0;i<s.size();i++)
    {
        if(cur->c[s[i]]==NULL)
            return 0;
        cur=cur->c[s[i]];
    }
    bool isword=0,islast=0;
    if(cur->ie==true)
        isword=true;
    if(lastnode(cur)==true)
        islast=true;
    if(isword && islast)
    {
        cout<<s<<endl;
        return -1;
    }
    if(!islast)
    {
        string pred=s;
        suggest(cur,pred);
        return 1;
    }
}
int main() {
	    tri* root = new tri();
        inserts(root, "play");
        inserts(root, "dog");
        inserts(root, "played");
        inserts(root, "cat");
        inserts(root, "a");
        inserts(root, "playing");
        inserts(root, "plaque");
        inserts(root, "plant");
        inserts(root, "plays");
        //cout<<searchs(root,"ca");
        int comp = suggestions(root, "pla");
        if (comp == -1)
            cout << "Ooops! There are no other strings found with this prefix\n";
        else if (comp == 0)
            cout << "No string found with this prefix\n";
	    cout<<"\n";
	return 0;
}
