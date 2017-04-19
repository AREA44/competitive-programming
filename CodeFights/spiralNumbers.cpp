// Construct a square matrix with a size N × N containing integers from 1 to N * N in a spiral order, starting from top-left and in clockwise direction.
// Example
// For n = 3, the output should be
// spiralNumbers(n) = [[1, 2, 3],
//                     [8, 9, 4],
//                     [7, 6, 5]]

std::vector<std::vector<int>> spiralNumbers(int n) {
    std::vector<std::vector<int>> answer;
    std::vector<int> tmp(n);
    for(int i=0;i<n;i++) answer.push_back(tmp);
    int row=n-1,col=n-1,x=0,y=0,cnt=1;
    
    while(row>=0 && col>=0){
        for(int i=0;i<col;i++)
            answer[x][y++]=cnt++;
 
        for(int i=0;i<row;i++)
            answer[x++][y]=cnt++;
 
        for(int i=0;i<col;i++)
            answer[x][y--]=cnt++;
        
        for(int i=0;i<row;i++)
            answer[x--][y]=cnt++;
        x++;
        y++;
        row=row-2;
        col=col-2;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(answer[i][j]==0)
                answer[i][j]=n*n;
    return answer;
}
