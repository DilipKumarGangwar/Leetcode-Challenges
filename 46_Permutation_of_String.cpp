#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
int x=0;
void printPermutationsUtil(string str, int start, int end)
{
    if(start == end )
    {
        cout<<str<<endl;
        x++;
        return ;
    }

    unordered_set<char> s;
    for(int i=start; i <= end;i++)
    {
      if((i!=start) && (str[start] == str[i]))
      {
         //cout<<start<<" "<<i<<endl;
         continue;
      }
       //if (s.find(str[i]) != s.end())
       //   continue;
      //  s.insert(str[i]);  
       swap(str[start],str[i]);
       printPermutationsUtil(str, start+1,end);
       swap(str[start],str[i]);
    }
    
}

void printPermutations(string str)
{
   int length = str.size(); 
   printPermutationsUtil(str,0,length-1);

}

int main()
{
   string str = "ABAC";
   printPermutations(str);
   cout<<x;
   return 0;
}
