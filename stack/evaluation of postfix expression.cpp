int evaluatePostfix(string &str)
{
    stack <int> s;

    for(int i=0; i<str.length(); i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            s.push(str[i]-'0');
        }
        else
        {
            int x=s.top();
            s.pop();
            int y=s.top();
            s.pop();

            if(str[i]=='+')
            {
                s.push(y+x);
            }
            else if(str[i]=='-')
            {
                s.push(y-x);
            }
            else if(str[i]=='*')
            {
                s.push(y*x);
            }
            else if(str[i]=='/')
            {
                s.push(y/x);
            }
        }
    }
    return s.top();
}
