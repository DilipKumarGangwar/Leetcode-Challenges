// https://leetcode.com/problems/valid-parentheses/description/
//20- Valid Parenthesis

//Approach 1
//Using Stack
//TC = O(n)    SC = O(n)

/*
class Solution {
public:
    bool isValid(string s) {
       stack<char> st;
       char ch;
       for(auto symbol: s)    
       {
           switch(symbol)
           {
               case '(': 
               case '{':
               case '[':
                  st.push(symbol);
                  break;
               case ')':
                  if(!st.empty())
                      ch = st.top();
                  else 
                      return false;  
                  ch = st.top();
                  if(ch == '(')
                      st.pop();  
                  else 
                    return false;
                  break;       
               case '}':
                  //If the stack container is empty, st.top causes undefined behavior
                    if(!st.empty())
                      ch = st.top();
                    else 
                      return false;    
                    if(ch == '{')
                        st.pop();  
                    else 
                      return false;
                    break;  
               case ']': 
                  if(!st.empty())
                    ch = st.top();
                  else 
                    return false;   
                  ch = st.top();
                  if(ch == '[')
                      st.pop();  
                  else 
                    return false;
                  break;   
           }
       }//end of switch

       if(!st.empty()) //stack is not empty
          return false;
       return true;      

    }
};
*/


//Approach 2
//Without Stack ( Imitating Stack using a control variable)
//TC = O(n)    SC = O(1)

//Ex: ((( )))[]-valid
//  (( ))[ - invalid
//((( )) 
class Solution {
public:
    bool isValid(string s) {
       int i=-1;  //a control variable to imitate stack

       for(auto ch : s)
       {
             //whenever opening braces come, imitate push using i
             if(ch == '(' || ch == '{' || ch== '[')
                s[++i] = ch; //override over the string characters
             else if(i>=0 && ((s[i] == '(' && ch == ')') || (s[i]=='{' && ch == '}')|| (s[i]=='[' && ch == ']')) )   
             {
                 i--;
             }  
             else
              return false;

       }
       if(i==-1)
         return true;
       return false;  


    }
};

// int main()
// {
//     cout<<"Hello World";
//     cout<<isValid("()[]{}");
//     return 0;
// }