void remove(char *s, char    x)
{
    if(!s || *s == '\0' || x == '\0')
        return;
    
    int len = strlen(s);

    int a = 0, b = 0;
    while( b < len )
    {
        if(s[b] == x)
            ++b;
        else
            s[a++] = s[b++];
    }

    return;
}


//因为题目中：十进制正整数,  所以下面不对异常输入做校验
std::string minus_hp(const std::string &A, const std::string &B)
{
    string a, b;
    int comp = A.compare(B);
    if( comp == 0)
        return string("0");
    else if( comp < 0)
    {
        a = B;
        b = A;
    }
    else
    {
        a = A;
        b = B;
    }

    string res;
    int up = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while( i >= 0 && j >= 0 )
    {
        int x = a[i];
        int y = b[j];

        if(up == 0)
        {
            if(x < y)
            {
                up = 10;
                res = to_string(up + x - y) + res;
            }
            else
            {
                res = to_string( x - y) + res;
            }
        }
        else
        {
            if(x - 1 < y)
            {
                up = 10;
                res = to_string(up + x - 1 - y) + res;
            }
            else
            {
                res = to_string( x - 1 - y) + res;
            }
        }

        --i;
        --j;
    }

    if(i >= 0)
    {
        if(up > 0)
        {
            if(a[0] - 1 > 0)
                res = to_string( a[0] - 1 ) + res;
        }
        else
            res = to_string( a[0] ) + res;
    }

    return res;
}


int MaximumCopy(const std::vector<size_t> &s, size_t C, size_t &start_index, size_t &end_index);
{
    if(s.empty() )
        reuturn C;
    if( *min_element(s.begin(), s.end() ) > C )
        return -1;

    int n = s.size();


    vector< int> dp(n, 0);
    dp[0] = s[0];
    for( int i = 1; i < n; ++i)
    {
        dp[i] = dp[i-1] + s[i];
    }

    int imax = 0, b = 0, e = 0;
    for( int i = 1; i < n; ++i)
    {
        for( int j = 0; j <= i; ++j)
        {
            int sum = dp[i] - dp[j] ;
            if(sum <= C)
            {
                if(imax < sum)
                {
                    imax = sum ;
                    start_index = j;
                    end_index = i;
                }
            }
        }
    }

    return imax;
}

//每个子进程结束时会发SIGCHLD信号
int sig()
{
    //捕获信号，
    printf("pid=%d, exited");
}

int func()
{
    int pid1 = 0, pid2 = 0, pid3 = 0;

    int i = 0;
    pid1 = fork();
    if(pid1 == 0)
    {
        printf("pid=%d forked", pid1);

        pid2 = fork();
        if(pid2 == 0)
        {
            printf("pid=%d forked", pid2);
            
            pid3 = fork();
            if(pid3 == 0)
            {
                printf("pid=%d forked", pid3);

                //每个子进程结束时会发SIGCHLD信号

            }
            else if( pid3 > 0)
            {
                printf("pid=%d hello world", pid3);
            }
        }
        else if( pid2 > 0)
        {
            printf("pid=%d hello world", pid2);
        }

    }
    else if( pid1 > 0)
    {
        printf("pid=%d hello world", pid1);
    }


    for( int i = 0; i <  pid.size(); ++i)
    {
        wait(pid[i]);
        
    }
}


void reverse(unsigned int **dst_bitmap, int m, int n, const int **src_bitmap);
{

}

for( map<int, bool> ::iterator it = .begin(); it != .end(); ++it)
{
    int pid = it->first;
}