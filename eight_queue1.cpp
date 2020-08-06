
#include<stdio.h>

#define line 8
int chess[line][line];
int cas=0;
int xx,yy;
int check(int i,int j){
    int k;
    for(k=0;k<line;k++)
    {
        if(chess[i][k]==1) 
            return 0;//0=不能放
    }

    for(k=0;k<line;k++)
    {
        if(chess[k][j]==1) 
            return 0;
    }

    for(k=-line;k<=line;k++)
    {   //两对角线
        if(i+k>=0&&i+k<line&&j+k>=0&&j+k<line)//从左上到右下对角线
            if(chess[i+k][j+k]==1) 
                return 0;
        if(i-k>=0&&i-k<line&&j+k>=0&&j+k<line)//从左下到右上对角线
            if(chess[i-k][j+k]==1) 
            return 0;
    }
    return 1;
}

void queen(int i,int j){
    if(j>=line)
    {
        return ;
    }
    if(check(i,j)==1)
    {   //如果能放
        chess[i][j]=1;//放皇后
        if(i==line-1)
        {   //如果是最后一行，记录情况
            cas++;
            // /*下面是输出每种棋盘结果，供测试*/   
            //     for (xx=0;xx<8;xx++) 
            //         for(yy=0;yy<8;yy++)
            //         { 
            //             printf("%d",chess[xx][yy]); 
            //             if(yy==7) 
            //                 printf("\n"); 
            //         } 
            //     printf("\n");     
            // /*上面是输出结果*/
        }
        else
        {
            queen(i+1,0);//不是最后一行就分析下一行
        }
    }
    chess[i][j]=0;//如果此位置不能放，就置空（0），判断旁边的格子。
    //如果此位置能放，走到这里就意味着上面的代码全部执行了，把皇后拿走（置零），再讨论其他情况，拿旁边位置试探。
    queen(i,j+1);
}
#define LINE 8
int CHESS[8][8];
int cat = 0;
void eight_queue(int i,int j);
bool Check(int i,int j);
int main()
{
    eight_queue(0,0);
    printf("%d\n",cat);
    return 0;
}


bool Check(int i,int j)
{
    //遍历之前所有的行，看看这个位置能不能放皇后
    //1.同行
    for ( int p = 0; p < LINE; p++)
    {
        if(CHESS[i][p] == 1)
            return 0;
    }
    //2.同列
    for ( int p = 0; p < LINE; p++)
    {
        if(CHESS[p][j] == 1)
            return 0;
    }
    
    //3.同对角线的分两种，斜上和斜下
    for (int p = -LINE; p <= LINE; p++)
    {
        if(i+p>=0 && i+p<LINE && j+p>=0 && j+p<LINE)
        {
            if(CHESS[i+p][j+p] == 1)
                return 0;
        }

        if(i-p>=0 && i-p<LINE && j+p>=0 && j+p<LINE)
        {
            if(CHESS[i-p][j+p] == 1)
                return 0;
        }
    }
    return 1;
}
void eight_queue(int i,int j)
{
    if(j >= LINE)
        return;
    if(Check(i,j) == 1)
    {
        CHESS[i][j] = 1;
        if(i == LINE - 1)//满足八个都放下了
        {
            cat ++;
        }
        else
        {
            eight_queue(i+1,0);
        }
    }
    CHESS[i][j] = 0;//回溯
    eight_queue(i,j+1);
}